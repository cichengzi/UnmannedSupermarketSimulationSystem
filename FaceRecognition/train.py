from FaceRecognition.utils import load_face_data
from FaceRecognition.config import *
import time
import copy
import torch
from torch import nn, optim
from FaceRecognition.model import get_model


def train_model(model, criterion, optimizer, loader, datasets, num_epochs=25):
    model.to(DEVICE)
    start = time.time()
    best_acc = 0.0

    for epoch in range(num_epochs):
        print(f'Epoch {epoch}/{num_epochs - 1}')
        print('-' * 10)

        model.train()
        train_loss = 0.0
        train_acc = 0

        for inputs, labels in loader:
            inputs = inputs.to(DEVICE)
            labels = labels.to(DEVICE)
            optimizer.zero_grad()

            outputs = model(inputs)
            preds = torch.argmax(outputs, dim=-1)
            loss = criterion(outputs, labels)
            loss.backward()
            optimizer.step()

            train_loss += float(loss.item() * inputs.size(0))
            train_acc += float(torch.sum(preds == labels.data))

        train_loss /= len(datasets)
        train_acc /= len(datasets)
        print(f'train loss: {train_loss:.4f}, train acc: {train_acc:.4f}')

        if train_acc > best_acc:
            best_acc = train_acc
            best_model_weights = copy.deepcopy(model[0].state_dict())
            torch.save(best_model_weights, MODEL_PATH)

    time_cost = time.time() - start
    print(f'training complete in {time_cost // 60:.0f}m {time_cost % 60:.0f}s')
    print(f'best train acc: {best_acc:.4f}')


loader, datasets = load_face_data()
model = get_model()
criterion = nn.CrossEntropyLoss()
optimizer_ft = optim.SGD(model.parameters(), lr=0.001, momentum=0.9)
train_model(model, criterion, optimizer_ft, loader, datasets, num_epochs=10)
