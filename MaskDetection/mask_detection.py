from model import get_best_model
from matplotlib import pyplot as plt
from predict import predict_mask


def mask_detection(image_path):
    model = get_best_model()
    image = plt.imread(image_path).transpose(2, 0, 1)
    return predict_mask(model, image)


def save_result(img_path):
    with open('result.txt', 'w') as fw:
        fw.write(mask_detection(img_path))


if __name__ == '__main__':
    with open('image_path.txt', 'r') as fr:
        image_path = fr.read()
        save_result(image_path)
