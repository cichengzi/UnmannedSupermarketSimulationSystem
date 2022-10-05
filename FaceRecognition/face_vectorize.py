from config import *
from model import get_best_model
import numpy as np
from torch import nn
import torch
import sys
import face_recognition
import os
from matplotlib import pyplot as plt


def get_feature(image: np.ndarray) -> np.ndarray:
    if len(image.shape) == 2:
        image = np.array([image, image, image])
    image = torch.tensor([image], dtype=torch.float32)
    model = get_best_model(40)
    model_feature = nn.Sequential(*list(model.children())[:-1])
    return model_feature(image)[0].flatten().detach().numpy()


def get_similarity(v1, v2, func_name='cos similarity'):
    if func_name == 'cos similarity':
        return np.dot(v1, v2) / np.sqrt(np.dot(v1, v1) * np.dot(v2, v2))
    return np.sqrt(np.sum(np.square(v1 - v2)))


if __name__ == '__main__':
    args = sys.argv

    base_path = '/Users/cichengzi/Desktop/code/UnmannedSupermarketSimulationSystem/FaceRecognition'
    if len(args) != 2:
        print('Invalid args!')
    else:
        image_path1 = os.path.join(base_path, args[1])
        image1 = face_recognition.load_image_file(image_path1)
        image_enc1 = np.array(face_recognition.face_encodings(image1), dtype=float).reshape(-1)
        #print(image_enc1.shape)
        best_similarity = 0.0
        best_class = None
        for root, dirs, files in os.walk(os.path.join(base_path, 'faces')):
            for file in files:
                class_name = file.split('_')[0]
                image_path2 = os.path.join(root, file)
                image2 = face_recognition.load_image_file(image_path2)
                image_enc2 = np.array(face_recognition.face_encodings(image2), dtype=float).reshape(-1)
                try:
                    current_similarity = get_similarity(image_enc1, image_enc2)
                    if current_similarity > best_similarity:
                        best_similarity = current_similarity
                        best_class = class_name
                except:
                    pass
        if best_similarity < 0.9:
            best_class = None
        with open(os.path.join(base_path, 'result.txt'), 'w') as f:
            f.write(best_class + '\n' + str(best_similarity))
