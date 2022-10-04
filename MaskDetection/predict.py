import torch
import numpy as np
from MaskDetection.model import get_best_model


def mask_detection(image):
    assert len(image.shape) == 3, 'image must be 3 dimension.'
    assert type(image) == np.ndarray, 'image must be a numpy ndarray.'

    image = np.array([image])
    image = torch.tensor(image, dtype=torch.float32)

    model = get_best_model()

    pred = torch.argmax(model(image), dim=-1)[0]

    return 'mask' if pred == 0 else 'no mask'