import torch
from config import *
from torch import nn
from torchvision import models


def get_model(num_out_features):
    model_ft = models.resnet18(pretrained=True)
    num_features = model_ft.fc.in_features
    model_ft.fc = nn.Linear(num_features, num_out_features)
    return model_ft


def get_best_model(num_out_features):
    model = models.resnet18(pretrained=True)
    num_features = model.fc.in_features
    model.fc = nn.Linear(num_features, num_out_features)
    model.load_state_dict(torch.load(model_path))
    return model
