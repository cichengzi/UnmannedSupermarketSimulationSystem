from face_vectorize import get_similarity
import cv2
from matplotlib import pyplot as plt
import face_recognition
import dlib
import os
import time
import numpy as np


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


def compare(image_path1='temp.jpg'):
    image1 = face_recognition.load_image_file(image_path1)
    image_enc1 = np.array(face_recognition.face_encodings(image1), dtype=float).reshape(-1)
    #print(f'image path: {image_path1}')
    best_similarity = 0.0
    best_class = None
    for root, dirs, files in os.walk('/Users/cichengzi/Desktop/code/UnmannedSupermarketSimulationSystem/FaceRecognition/faces'):
        for file in files:
            if '.jpg' not in file:
                continue
            class_name = file.split('_')[0]
            image_path2 = os.path.join(root, file)
            image2 = face_recognition.load_image_file(image_path2)
            image_enc2 = np.array(face_recognition.face_encodings(image2), dtype=float).reshape(-1)
            if image_enc2.shape[0] == 0:
                continue

            current_similarity = get_similarity(image_enc1, image_enc2)
            if current_similarity > best_similarity:
                best_similarity = current_similarity
                best_class = class_name

    if best_similarity < 0.9:
        best_class = None
    return best_class, best_similarity


def face_recognize():
    print('running face recognize...')
    cap = cv2.VideoCapture(0)
    pic_path = 'temp.jpg'
    for i in range(50):
        suc, img = cap.read()
        faces = get_all_faces(img)
        if len(faces) != 1:
            time.sleep(0.01)
            continue
        print(f'epoch {i + 1}, face recognizing...')
        face = faces[0]
        face = cv2.cvtColor(face, cv2.COLOR_GRAY2BGR)
        plt.imsave(pic_path, face)
        name, sim = compare()
        print(name, sim)
        if name is not None:
            if os.path.exists(pic_path):
                os.remove(pic_path)
            with open('/Users/cichengzi/Desktop/code/UnmannedSupermarketSimulationSystem/FaceRecognition/result.txt', 'w') as f:
                f.write(name)
            return True
    if os.path.exists(pic_path):
        os.remove(pic_path)
    return False


face_recognize()