import os
import numpy as np
from matplotlib import pyplot as plt

for root, dirs, files in os.walk('orl_faces'):
    for file in files:
        image_path = os.path.join(root, file)
        if '.DS_Store' in image_path:
            continue
        image = plt.imread(image_path)
        if len(image.shape) == 2:
            image = np.array([image, image, image])
            image = image.transpose(1, 2, 0)
        class_name = image_path.split('/')[1]
        class_id = image_path.split('/')[2].split('.')[0]
        new_image_path = f'faces/{class_name}_{class_id}.jpg'
        plt.imsave(new_image_path, image)


