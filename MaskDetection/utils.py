from MaskDetection.config import *
from torchvision import datasets
import os
import torch


def load_mask_data():
    train_datasets = datasets.ImageFolder(os.path.join(MASK_DATA_DIR, 'train'), TRAIN_AUG)
    val_datasets = datasets.ImageFolder(os.path.join(MASK_DATA_DIR, 'val'), VAL_AUG)
    train_loader = torch.utils.data.DataLoader(train_datasets, batch_size=32, shuffle=True)
    val_loader = torch.utils.data.DataLoader(val_datasets, batch_size=32)
    return train_loader, val_loader, train_datasets, val_datasets
