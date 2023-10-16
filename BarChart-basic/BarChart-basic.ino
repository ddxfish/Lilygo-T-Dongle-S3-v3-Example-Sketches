// This script dynamically displays a bar chart on an 80x160 TFT screen, with bars updating every second based on input values. 
// The chart adjusts automatically when bars are added or removed, and each bar is color-coded uniquely.

#include <TFT_eSPI.h> // Include the graphics library

// Create an instance of the library
TFT_eSPI tft = TFT_eSPI();

// Define the max number of bars
#define MAX_BARS 8

// Array to hold the values for each bar
int barValues[MAX_BARS] = {0}; // initialize all to 0
int numBars = 8; // current number of bars

// Colors for the bars
uint16_t barColors[MAX_BARS] = {TFT_RED, TFT_GREEN, TFT_BLUE, TFT_PURPLE, TFT_YELLOW, TFT_PINK, TFT_ORANGE, TFT_OLIVE};

unsigned long lastUpdateTime = 0;

void setup() {
  // Initialize the display
  tft.init();
  tft.setRotation(0); // Set the rotation direction of the screen (default)
  tft.fillScreen(TFT_BLACK); // Fill screen with black
}

void loop() {
  if (millis() - lastUpdateTime >= 1000) { // update every second
    lastUpdateTime = millis();
    
    // For testing purposes, update your bars' values here. 
    // In a real application, you'd be getting these from sensors or other inputs.
    for (int i = 0; i < numBars; i++) {
      barValues[i] = random(0, 80); // Replace with real data
    }
    
    drawBars();
  }
}

void drawBars() {
  // First, clear the previous bars
  tft.fillScreen(TFT_BLACK);
  
  int spacing = 5; // spacing between bars
  if (numBars > 5){spacing = 2;} // adjust
  int totalSpacing = (numBars + 1) * spacing; // total spacing based on number of bars
  int barWidth = (80 - totalSpacing) / numBars; // dynamic bar width based on number of bars and spacing

  for (int i = 0; i < numBars; i++) {
    int barHeight = map(barValues[i], 0, 80, 0, 160); // map the value to the screen height
    int x = spacing + i * (barWidth + spacing); // x position includes spacing
    tft.fillRect(x, 160 - barHeight, barWidth, barHeight, barColors[i]); // draw the bar with its specific color
  }
}
