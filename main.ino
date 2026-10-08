#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Setup the display object connected to the standard I2C wire configuration
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200);

  // Set the specific hardware I2C pins for the Raspberry Pi Pico H
  // Default I2C0 pins: Pin GP4 is SDA, Pin GP5 is SCL
  Wire.setSDA(4);
  Wire.setSCL(5);
  Wire.begin();

  // Initialize the screen using its standard hardware address (0x3C)
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("OLED screen allocation failed"));
    while(1);
  }

  // Clear buffer and print text to the display
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 20);
  display.println(F("GitHub Sync Success!"));
  display.setCursor(0, 40);
  display.println(F("Pico H + OLED Working"));
  display.display();
}

void loop() {
  // Put your looping behavior here later
}
