#doing all the relevant imports
import matplotlib.pyplot as plt
import matplotlib.image as mpimg
import numpy as np
import cv2

# Read in the image and convert to grayscale
image = mpimg.imread(r'Term1\2_FindingLaneLines\11_CannyToDetectLaneLines\exit-ramp.jpg')
gray = cv2.cvtColor(image, cv2.COLOR_RGB2GRAY)

# Define a kernel size for Gaussian smoothing / blurring
# Note: this step is optional as cv2.Canny() applies a 5x5 Gaussian internally
kernel_size = 3
blur_gray = cv2.GaussianBlur(gray,(kernel_size, kernel_size), 0)

# Define parameters for Canny and run it
# NOTE: if you try running this code you might want to change these!
low_threshold = 100
high_threshold = 100
edges = cv2.Canny(blur_gray, low_threshold, high_threshold)

# Display the image
plt.subplot(221)
plt.imshow(image)
plt.subplot(222)
plt.imshow(gray, cmap='gray')
plt.subplot(223)
plt.imshow(blur_gray, cmap='gray')
plt.subplot(224)
plt.imshow(edges, cmap='gray')
plt.show()