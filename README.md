# ESP32-s3 T-Dongle v3 by Lilygo Example Sketches

![image](https://github.com/ddxfish/Lilygo-T-Dongle-S3-v3-Example-Sketches/assets/6764685/b0006c79-cc8b-4960-920b-c7b7f4553a21)

## Requirements
* An ESP32-s3 T-Dongle v3 by Lilygo
You must have TFT_eSPI already working on your screen for this. 
* User_Setup.h should point to the example number 47 at: Setup47_ST7735.h
* Edit Setup47_ST7735.h
* Comment: #define ST7735_GREENTAB2
* Uncomment: #define ST7735_GREENTAB160x80 // For 160 x 80 display (BGR, inverted, 26 offset)

### Barchart Basic
This displays multiple bars in a chart. Input between 1 and 8 numbers, and the TFT will calculate the width of the bars, spacing, and display the numbers you input. No labels or text at all.

### Image Basic
Simply displays an image on the TFT screen. Uses UTFT 565 format. You convert image to UTFT and edit the variable names to match.
