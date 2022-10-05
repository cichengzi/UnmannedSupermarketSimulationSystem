from config import *
from torchvision import datasets
import os
import torch


def load_face_data():
    train_dataset = datasets.ImageFolder(data_dir, data_transforms['train'])
    train_loader = torch.utils.data.DataLoader(train_dataset, batch_size=32, shuffle=True)

    train_dataset_size = len(train_dataset)
    train_class_names = train_dataset.classes
    return train_dataset, train_loader, train_dataset_size, train_class_names

