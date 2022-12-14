from model import get_best_model
from matplotlib import pyplot as plt
from predict import predict_mask
import sys
import os
from config import *
from PIL import Image


def mask_detection(img_path):
    model = get_best_model()
    image = Image.open(img_path)
    image = data_transforms['val'](image).numpy()
    return predict_mask(model, image)


if __name__ == '__main__':
    args = sys.argv
    base_path = '/Users/cichengzi/Desktop/code/UnmannedSupermarketSimulationSystem/MaskDetection'
    if len(args) != 2:
        print('Invalid args!')
    else:
        image_path = os.path.join(base_path, args[1])
        res = mask_detection(image_path)
        with open(os.path.join(base_path, 'result.txt'), 'w') as f:
            f.write(res)
