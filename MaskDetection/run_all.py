from mask_detection import mask_detection
import cv2
from matplotlib import pyplot as plt
import dlib
import os
import time


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


def check_mask():
    print('running mask detection...')
    cap = cv2.VideoCapture(0)
    pic_path = 'temp.jpg'
    for i in range(50):
        print(f'epoch {i + 1}')
        suc, img = cap.read()
        print(img.shape)
        #cv2.imshow('Mask Detection', img)
        faces = get_all_faces(img)
        if len(faces) > 0:
            print(f'{len(faces)} faces...')
        if len(faces) != 1:
            time.sleep(0.01)
            continue
        print(f'epoch {i + 1}, mask detecting...')
        face = faces[0]
        face = cv2.cvtColor(face, cv2.COLOR_GRAY2BGR)
        plt.imsave(pic_path, face)
        if mask_detection(pic_path) == 'mask':
            if os.path.exists(pic_path):
                os.remove(pic_path)
            return True
    if os.path.exists(pic_path):
        os.remove(pic_path)
    return False


with open('/Users/cichengzi/Desktop/code/UnmannedSupermarketSimulationSystem/MaskDetection/result.txt', 'w') as f:
    f.write('mask' if check_mask() else 'without mask')
