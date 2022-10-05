import torch
import numpy as np


def predict_mask(model, image):
    model.to('cpu')
    model.eval()
    images = torch.tensor(np.array([image]), dtype=torch.float32)
    labels = model(images).argmax(dim=-1)
    label = labels[0]
    return 'without mask' if label == 1 else 'mask'

