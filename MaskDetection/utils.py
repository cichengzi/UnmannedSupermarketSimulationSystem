from MaskDetection.config import *
from torchvision import datasets
import os
import torch


def load_mask_data():
    image_datasets = {x: datasets.ImageFolder(os.path.join(data_dir, x), data_transforms[x]) for x in ['train', 'val']}
    data_loaders = {x: torch.utils.data.DataLoader(image_datasets[x], batch_size=32, shuffle=True)
                    for x in ['train', 'val']}
    dataset_sizes = {x: len(image_datasets[x]) for x in ['train', 'val']}
    class_names = image_datasets['train'].classes
    return image_datasets, data_loaders, dataset_sizes, class_names

