import time
import copy
import torch
from torch import nn, optim
from MaskDetection import utils
from MaskDetection.config import *
from MaskDetection.model import get_model


def train_model(model, criterion, optimizer, train_loader, val_loader, train_datasets, val_datasets, num_epochs=25):
    model.to(DEVICE)
    start = time.time()
    best_model_weights = copy.deepcopy(model.state_dict())
    best_acc = 0.0

    for epoch in range(num_epochs):
        print(f'Epoch {epoch}/{num_epochs - 1}')
        print('-' * 10)

        model.train()
        train_loss = 0.0
        train_acc = 0

        for inputs, labels in train_loader:
            inputs = inputs.to(DEVICE)
            labels = labels.to(DEVICE)
            optimizer.zero_grad()

            outputs = model(inputs)
            _, preds = torch.max(outputs, 1)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()

            train_loss += float(loss.item() * inputs.size(0))
            train_acc += float(torch.sum(preds == labels.data))

        train_loss /= len(train_datasets)
        train_acc /= len(train_datasets)
        print(f'train loss: {train_loss:.4f}, train acc: {train_acc:.4f}')

        model.eval()
        val_loss = 0.0
        val_acc = 0

        for inputs, labels in val_loader:
            inputs = inputs.to(DEVICE)
            labels = labels.to(DEVICE)
            outputs = model(inputs)
            _, preds = torch.max(outputs, 1)
            loss = criterion(outputs, labels)
            val_loss += float(loss.item() * inputs.size(0))
            val_acc += float(torch.sum(preds == labels.data))

        val_loss /= len(val_datasets)
        val_acc /= len(val_datasets)
        print(f'val loss: {val_loss:.4f}, val acc: {val_acc:.4f}')

        if val_acc > best_acc:
            best_acc = val_acc
            best_model_weights = copy.deepcopy(model.state_dict())
            torch.save(best_model_weights, MODEL_PATH)

    time_cost = time.time() - start
    print(f'training complete in {time_cost // 60:.0f}m {time_cost % 60:.0f}s')
    print(f'best val acc: {best_acc:.4f}')


train_loader, val_loader, train_datasets, val_datasets = utils.load_mask_data()
model = get_model()
criterion = nn.CrossEntropyLoss()
optimizer_ft = optim.SGD(model.parameters(), lr=0.001, momentum=0.9)
train_model(model, criterion, optimizer_ft, train_loader, val_loader, train_datasets, val_datasets, num_epochs=10)
