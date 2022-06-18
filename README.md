# instruction

implement of image processing

reference: 

1. Image Processing and Computer Vision 7th, klchung
2. https://github.com/leimao/PPMIO

# build sample

```
make target=${sample_name}
```

# sample list

|  sample  | description  | execute  |
|  ----    | ----  | ---- |
| test_ppm_rw    | basic ppm file read/write |
| test_transform      | basic transform method of image |

## transform list

|  basic   | result | description |
|  ----    | ----  | ---- |
| PPM      | PGM | RGB image to gray image |
| RGB      | HSV |
| RGB      | YIQ |
| RGB      | YUV |

# TODO List

1. ~~file name~~
2. ~~binary mode~~
3.