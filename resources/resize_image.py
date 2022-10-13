import cv2
import os


"""
for root, dirs, files in os.walk('../resources'):
    for file in files:
        if file[-4:] == '.jpg':
            file_path = os.path.join(root, file)
            image = cv2.imread(file_path)
            image = cv2.resize(image, (240, 240))
            cv2.imwrite(file_path, image)
"""

file_path = 'icon1.jpg'
image = cv2.imread(file_path)
image = cv2.resize(image, (240, 240))
cv2.imwrite(file_path, image)