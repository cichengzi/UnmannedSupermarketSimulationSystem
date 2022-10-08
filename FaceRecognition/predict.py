import os
import torch
import numpy as np
from FaceRecognition.config import *
from FaceRecognition.model import get_best_model


def face_recognition(image):
    assert len(image.shape) == 3, 'image must be 3 dimension.'
    assert type(image) == np.ndarray, 'image must be a numpy ndarray.'

    image = np.array([image])
    image = torch.tensor(image, dtype=torch.float32)

    model = get_best_model()
    feature = model(image)[0].detach().numpy()

    result = None
    for root, dirs, files in os.walk(FACE_PATH):
        for file in files:
            other_feature = model(torch.tensor([read_image(os.path.join(root, file))], dtype=torch.float32))[0].detach().numpy()
            sim = calc_sim(feature, other_feature)
            if result is None or sim > result[1]:
                name = file.split('_')[0]
                result = (name, sim)

#    if result is not None and result[1] < 0.9:
#        result = None
    return result