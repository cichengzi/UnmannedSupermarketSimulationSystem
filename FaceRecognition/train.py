import copy
import torch


def train_model(model, train_loader, train_dataset_size, criterion, optimizer, scheduler, device, num_epochs):
    best_model_weights = copy.deepcopy(model.state_dict())
    best_acc = 0.0

    model.to(device)

    for epoch in range(num_epochs):
        print(f'epoch {epoch + 1}/{num_epochs}')
        print('-' * 10)

        model.train()

        epoch_loss = 0.0
        epoch_corrects = 0

        for inputs, labels in train_loader:
            inputs = inputs.to(device)
            labels = labels.to(device)

            optimizer.zero_grad()

            outputs = model(inputs)
            _, preds = torch.max(outputs, 1)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()

            epoch_loss += loss.item() * inputs.size(0)
            epoch_corrects += torch.sum(preds == labels.data).item()
            scheduler.step()

            epoch_loss /= train_dataset_size
            epoch_acc = epoch_corrects / train_dataset_size

        print(f'train loss: {epoch_loss:.4f}, train acc: {epoch_acc:.4f}')

        if epoch_acc > best_acc:
            best_acc = epoch_acc
            best_model_weights = copy.deepcopy(model.state_dict())

        print()

    print(f'best train acc: {best_acc:.4f}')
    model.load_state_dict(best_model_weights)
    return model
