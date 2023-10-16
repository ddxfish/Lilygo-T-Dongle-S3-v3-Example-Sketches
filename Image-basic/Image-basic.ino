
// This is a 565 UTFT converter to make the .h file that contains the image
// adjust names and defines in the .h file to match
// http://www.rinkydinkelectronics.com/_t_doimageconverter565.php

/*
 This sketch demonstrates loading images from arrays stored in program (FLASH) memory.

 Works with TFT_eSPI library here:
 https://github.com/Bodmer/TFT_eSPI


 #########################################################################
 ###### DON'T FORGET TO UPDATE THE User_Setup.h FILE IN THE LIBRARY ######
 #########################################################################
*/

#include <TFT_eSPI.h>       // Hardware-specific library

TFT_eSPI tft = TFT_eSPI();  // Invoke custom library

// Include the header files that contain the icons
#include "kremtea.h"


long count = 0; // Loop count

void setup()
{
  Serial.begin(115200);
  tft.begin();
  tft.setRotation(0);	// landscape

  tft.fillScreen(TFT_BLACK);

  // Swap the colour byte order when rendering
  tft.setSwapBytes(true);

  // Draw the icons
  tft.pushImage(0, 0, kremWidth, kremHeight, krem);


}

void loop()
{
  

}
