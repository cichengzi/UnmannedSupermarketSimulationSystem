from FaceRecognition.config import *
import os
import cv2
import numpy as np
from PIL import Image
import torch


def load_face_data():
    images = []
    labels = []
    for root, dirs, files in os.walk(FACE_DATA_DIR):
        for dir in dirs:
            label = int(dir.replace('s', '')) - 1
            for rt, ds, fs in os.walk(os.path.join(root, dir)):
                for f in fs:
                    img = np.array(Image.open(os.path.join(rt, f)).resize((224, 224)))
                    img = np.array([img, img, img])
                    images.append(img)
                    labels.append(label)
    labels = np.array(labels)
    images = np.array(images)
    labels = torch.tensor(labels)
    images = torch.tensor(images, dtype=torch.float32)
    datasets = torch.utils.data.TensorDataset(images, labels)
    loader = torch.utils.data.DataLoader(datasets, batch_size=32, shuffle=True)
    return loader, datasets


def read_image(image_path):
    image = cv2.resize(cv2.imread(image_path), (224, 224))
    print(type(image))
    if len(image.shape) == 2:
        image = np.array([image, image, image])
    elif image.shape[0] != 3:
        image = torch.tensor(image).permute(2, 0, 1).numpy()
    return image


def calc_sim(v1, v2):
    return np.dot(v1, v2) / ((np.dot(v1, v1) * np.dot(v2, v2)) ** 0.5)


'''
image_path = '/Users/cichengzi/Desktop/code/22SummerPythonProject/FaceRecognition/orl_faces/s1/1.pgm'
image = read_image(image_path)
print(image.shape)
'''