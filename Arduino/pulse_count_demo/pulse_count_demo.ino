#include <Adafruit_IS31FL3731.h>
#include <U8g2_for_Adafruit_GFX.h>

Adafruit_IS31FL3731 display;

U8G2_FOR_ADAFRUIT_GFX u8g2_for_adafruit_gfx;

void setup() {
  display.begin(0x74);
  u8g2_for_adafruit_gfx.begin(display);                 // connect u8g2 procedures to Adafruit GFX
  u8g2_for_adafruit_gfx.setFont(u8g2_font_8x13_me  );  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  u8g2_for_adafruit_gfx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8g2_for_adafruit_gfx.setFontDirection(0);            // left to right (this is default)

  // Clear all the display frames
  for( byte i=0; i<8; i++ ) {
    
    display.setFrame(i);
    display.fillScreen(0);

    
  }

  u8g2_for_adafruit_gfx.setForegroundColor(128);      // apply Adafruit GFX color  
  
  
}

int i=0;

byte f=0;

void swapFrame() {

  display.displayFrame( f );
  f++;
  f &=0x07;
  display.setFrame( f);
  
}

void loop() {  

/*

  u8g2_for_adafruit_gfx.setForegroundColor(0);      // apply Adafruit GFX color  
  u8g2_for_adafruit_gfx.setCursor(0,9);                // start writing at this position
  //if (i<100) u8g2_for_adafruit_gfx.print('0');
  if (i<10) {
     u8g2_for_adafruit_gfx.print('0');
    //u8g2_for_adafruit_gfx.setCursor(9,9);                // start writing at this position
     
  }
  u8g2_for_adafruit_gfx.print(i );

  u8g2_for_adafruit_gfx.setForegroundColor(128);      // apply Adafruit GFX color  

  */

  i++;

  if (i==100) i=0;

  
  byte bright = 255;

  while (bright>2) {
    
    display.fillScreen(0);
    
    u8g2_for_adafruit_gfx.setForegroundColor(bright);      // apply Adafruit GFX color  
    

    u8g2_for_adafruit_gfx.setCursor(0,9);                // start writing at this position
    //if (i<100) u8g2_for_adafruit_gfx.print('0');
    
    if (i<10) {
       u8g2_for_adafruit_gfx.print('0');
      //u8g2_for_adafruit_gfx.setCursor(9,9);                // start writing at this position
       
    }
    
    u8g2_for_adafruit_gfx.print(i );
  
    
   // u8g2_for_adafruit_gfx.setCursor(0,10);                // start writing at this position
   // u8g2_for_adafruit_gfx.print(F("Umlaut ÄÖÜ"));            // UTF-8 string with german umlaut chars
  //  display.display();                                    // make everything visible
  
    swapFrame();
    delay(10);

    bright /=2;
  }
} 
