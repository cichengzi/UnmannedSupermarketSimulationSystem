from torchvision import models
from torch import nn
import torch
from FaceRecognition.config import *


def get_model():
    model_ft = models.resnet18(pretrained=True)
    num_features = model_ft.fc.out_features
    model = nn.Sequential(model_ft, nn.Linear(num_features, 40))
    return model


def get_best_model():
    model = models.resnet18(pretrained=True)
    model.load_state_dict(torch.load(MODEL_PATH))
    return model