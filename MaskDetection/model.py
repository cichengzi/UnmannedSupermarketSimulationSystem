import torch
from torchvision.models import ResNet18_Weights

from config import *
from torch import nn
from torchvision import models


def get_model():
    model_ft = models.resnet18(weights=ResNet18_Weights.DEFAULT)
    num_features = model_ft.fc.in_features
    model_ft.fc = nn.Linear(num_features, 2)
    return model_ft


def get_best_model():
    model = models.resnet18()
    num_features = model.fc.in_features
    model.fc = nn.Linear(num_features, 2)
    model.load_state_dict(torch.load(model_path))
    return model
