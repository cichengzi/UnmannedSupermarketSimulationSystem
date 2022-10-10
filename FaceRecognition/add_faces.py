from face_vectorize import get_similarity
import cv2
from matplotlib import pyplot as plt
import face_recognition
import dlib
import os
import time
import numpy as np
import sys


def get_all_faces(image):
    detector = dlib.get_frontal_face_detector()
    gray = cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)
    dets = detector(gray, 1)
    faces = []
    for i, d in enumerate(dets):
        x1 = d.top() if d.top() > 0 else 0
        y1 = d.bottom() if d.bottom() > 0 else 0
        x2 = d.left() if d.left() > 0 else 0
        y2 = d.right() if d.right() > 0 else 0
        f = cv2.resize(gray[x1: y1, x2: y2], (256, 256))
        faces.append(f)
    return faces


def add_faces(user_name):
    print('running add faces...')
    cap = cv2.VideoCapture(0)
    cnt = 0
    for i in range(50):
        suc, img = cap.read()
        faces = get_all_faces(img)
        if len(faces) != 1:
            time.sleep(0.01)
            continue
        print(f'epoch {i + 1}, add faces...')
        face = faces[0]
        face = cv2.cvtColor(face, cv2.COLOR_GRAY2BGR)
        path = os.path.join('/Users/cichengzi/Desktop/code/UnmannedSupermarketSimulationSystem/FaceRecognition/faces', f'{user_name}_{str(cnt + 1)}.jpg')
        cnt += 1
        plt.imsave(path, face)
        if cnt == 10:
            break
    print(f'finally add {cnt} faces.')


if __name__ == '__main__':
    args = sys.argv
    if len(args) != 2:
        print('invalid argument!')
        exit(0)
    user_name = args[1]
    add_faces(user_name)