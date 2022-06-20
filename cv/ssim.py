import cv2
import sys
from skimage.metrics import structural_similarity

def main():
    img1 = cv2.imread(sys.argv[1])
    img2 = cv2.imread(sys.argv[2])
    score = structural_similarity(img1, img2, channel_axis=2)

    print('SSIM: ', score)

if __name__ == '__main__':
    main()