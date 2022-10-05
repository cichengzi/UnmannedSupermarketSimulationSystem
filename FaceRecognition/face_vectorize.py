from config import *
from model import get_best_model
import numpy as np
from torch import nn
import torch
from matplotlib import pyplot as plt


def get_feature(image: np.ndarray) -> np.ndarray:
    if len(image.shape) == 2:
        image = np.array([image, image, image])
    image = torch.tensor([image], dtype=torch.float32)
    model = get_best_model(40)
    model_feature = nn.Sequential(*list(model.children())[:-1])
    return model_feature(image)[0].flatten().detach().numpy()


def get_similarity(v1, v2):
    return np.dot(v1, v2) / np.sqrt(np.dot(v1, v1) * np.dot(v2, v2))


img1 = plt.imread('orl_faces/s1/1.pgm')
vec1 = get_feature(img1)
img2 = plt.imread('orl_faces/s2/2.pgm')
vec2 = get_feature(img2)
print(get_similarity(vec1, vec2))
