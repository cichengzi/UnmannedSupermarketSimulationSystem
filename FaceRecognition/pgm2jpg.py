import os
import numpy as np
from matplotlib import pyplot as plt


for root, dirs, files in os.walk('orl_faces'):
    for file in files:
        image_path = os.path.join(root, file)
        if image_path[-4:] != '.pgm':
            continue
        image = plt.imread(image_path)
        if len(image.shape) == 2:
            image = np.array([image, image, image])
            image = image.transpose(1, 2, 0)
        new_image_path = image_path[:-4] + '.jpg'
        plt.imsave(new_image_path, image)
        os.remove(image_path)