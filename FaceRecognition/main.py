from model import get_model
from torch import nn, optim
from train import train_model
from utils import load_face_data
from config import *
import torch


train_dataset, train_loader, train_dataset_size, train_class_names = load_face_data()
model_ft = get_model(len(train_class_names))
print(f'num classes: {len(train_class_names)}')
device = 'mps'
num_epochs = 25
criterion = nn.CrossEntropyLoss()
optimizer_ft = optim.SGD(model_ft.parameters(), lr=1e-2, momentum=0.9)

exp_lr_scheduler = optim.lr_scheduler.StepLR(optimizer_ft, step_size=7, gamma=0.1)

model_ft = train_model(model_ft, train_loader, train_dataset_size, criterion, optimizer_ft, exp_lr_scheduler, device, num_epochs)

torch.save(model_ft.state_dict(), model_path)