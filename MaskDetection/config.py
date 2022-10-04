from torchvision import transforms

TRAIN_AUG = transforms.Compose([
    transforms.RandomResizedCrop(224),
    transforms.RandomHorizontalFlip(),
    transforms.ToTensor(),
    transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225])
])

VAL_AUG = transforms.Compose([
    transforms.Resize(256),
    transforms.CenterCrop(224),
    transforms.ToTensor(),
    transforms.Normalize([0.485, 0.456, 0.406], [0.229, 0.224, 0.225])
])

MASK_DATA_DIR = 'mask'
DEVICE = 'mps'

MODEL_PATH = '/Users/cichengzi/Desktop/code/22SummerPythonProject/MaskDetection/parameters/finetuned_model_resnet18.pth'