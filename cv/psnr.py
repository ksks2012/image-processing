import cv2
import sys
from skimage.metrics import mean_squared_error
from skimage.metrics import peak_signal_noise_ratio

def main():
    img1 = cv2.imread(sys.argv[1])
    img2 = cv2.imread(sys.argv[2])
    MSE = mean_squared_error(img1, img2)
    PSNR = peak_signal_noise_ratio(img1, img2)
    print('MSE: ', MSE)
    print('PSNR: ', PSNR)

if __name__ == '__main__':
    main()