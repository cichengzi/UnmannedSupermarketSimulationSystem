from torchvision import transforms

AUG = transforms.Compose([
    transforms.Resize(256),
    transforms.CenterCrop(224),
    transforms.ToTensor()
])

FACE_DATA_DIR = 'orl_faces'
DEVICE = 'mps'

FACE_PATH = '/Users/cichengzi/Desktop/code/22SummerPythonProject/FaceRecognition/faces'

MODEL_PATH = '/Users/cichengzi/Desktop/code/22SummerPythonProject/FaceRecognition/parameters/finetuned_model_resnet18.pth'