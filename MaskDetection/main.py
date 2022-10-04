from model import get_model
from torch import nn, optim
from train import train_model
from utils import load_mask_data
from config import *
import torch


model_ft = get_model()
device = 'mps'
num_epochs = 5
criterion = nn.CrossEntropyLoss()
optimizer_ft = optim.SGD(model_ft.parameters(), lr=1e-3, momentum=0.9)

image_datasets, data_loaders, dataset_sizes, class_names = load_mask_data()

exp_lr_scheduler = optim.lr_scheduler.StepLR(optimizer_ft, step_size=7, gamma=0.1)

model_ft = train_model(model_ft, data_loaders, dataset_sizes, criterion, optimizer_ft, exp_lr_scheduler, device, num_epochs)

torch.save(model_ft.state_dict(), model_path)
