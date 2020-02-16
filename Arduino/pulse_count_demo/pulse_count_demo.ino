#include <Adafruit_IS31FL3731.h>
#include <U8g2_for_Adafruit_GFX.h>



#define ROT_A_PIN (8)
#define ROT_B_PIN (9)
#define ROT_S_PIN (7)

#define DISPLAY_COUNT 3   // Oh C++ why do you not have a good way to get an array size?

Adafruit_IS31FL3731 displays[DISPLAY_COUNT];

U8G2_FOR_ADAFRUIT_GFX u8g2_for_adafruit_gfx;


void swapFrame( Adafruit_IS31FL3731 &display ) {

  static byte f=0;

  display.displayFrame( f );
  f++;
  f &=0x07;
  display.setFrame( f);
  
}

byte buttonPushed() {

  static unsigned long buttonDownTimeout=0;  // If millis() < this then dont register down again

  if ( (digitalRead( ROT_S_PIN ) == 0) && (buttonDownTimeout<millis() ) ) {

    buttonDownTimeout = millis() + 500;

    return 1;
    
  } else {

    return 0;    
    
  }

}

void ieee( Adafruit_IS31FL3731 &d ) {

  
  Adafruit_IS31FL3731 &d0 = displays[0];
  Adafruit_IS31FL3731 &d1 = displays[1];
  Adafruit_IS31FL3731 &d2 = displays[2];

  d.setTextWrap(0);
    
  static byte step=0;

  static char *ieee = "   IEEE Spectrum";
/*
  while (1) { 


      d2.setCursor( -5 , 1 );
    

    
  }
*/

  while (1) {

      d.fillScreen(0);
      d.setCursor( 0 - step , 1 );
      d.print( ieee);

      swapFrame( d );
      delay(20);

      step++;

      if (step>100) step=0;

      if (buttonPushed()) return;
      
  }
  
  
  while (!buttonPushed());  
}


void swirl(Adafruit_IS31FL3731 &ledmatrix ) {
  
  // If you're using the FeatherWing version
  //Adafruit_IS31FL3731_Wing ledmatrix = Adafruit_IS31FL3731_Wing();

// The lookup table to make the brightness changes be more visible
  static uint8_t sweep[] = {1, 2, 3, 4, 6, 8, 10, 15, 20, 30, 40, 60, 60, 40, 30, 20, 15, 10, 8, 6, 4, 3, 2, 1};

  while (1) 
    // animate over all the pixels, and set the brightness from the sweep table
    for (uint8_t incr = 0; incr < 24; incr++)
      for (uint8_t x = 0; x < 16; x++)
        for (uint8_t y = 0; y < 9; y++) {
            ledmatrix.drawPixel(x, y, sweep[(x+y+incr)%24]);
            if (buttonPushed()) return;
        }
     delay(20);
}
  

// Returns when button pushed

void pulseCount() {

  u8g2_for_adafruit_gfx.setFont(u8g2_font_8x13_me  );  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  u8g2_for_adafruit_gfx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8g2_for_adafruit_gfx.setFontDirection(0);            // left to right (this is default)

  Adafruit_IS31FL3731 &display = displays[0]; 
  

  // Clear all the display frames
  for( byte i=0; i<8; i++ ) {
    
    display.setFrame(i);
    display.fillScreen(0);

    
  }

  u8g2_for_adafruit_gfx.setForegroundColor(128);      // apply Adafruit GFX color  


  static byte i=0;
  
  while (1) {
    
    i++;
  
    if (i==100) i=0;
      
    byte bright = 255;
  
    while (bright) {
      
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
    
      swapFrame( display );
      delay(10);
  
      bright /=2;

      if (buttonPushed()) return;
    }  

  }
  
}


void setup() {

  pinMode( ROT_A_PIN , INPUT_PULLUP );
  pinMode( ROT_B_PIN , INPUT_PULLUP );
  pinMode( ROT_S_PIN , INPUT_PULLUP );


  for( auto &display : displays ) { 

    display = Adafruit_IS31FL3731();
    
  }

  displays[0].begin(0x74);
  displays[1].begin(0x75);
  displays[2].begin(0x76);

  //display.begin(0x75);
  
  u8g2_for_adafruit_gfx.begin(displays[0]);                 // connect u8g2 procedures to Adafruit GFX
  u8g2_for_adafruit_gfx.setFont(u8g2_font_8x13_me  );  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  u8g2_for_adafruit_gfx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8g2_for_adafruit_gfx.setFontDirection(0);            // left to right (this is default)

  u8g2_for_adafruit_gfx.setForegroundColor(128);      // apply Adafruit GFX color  
    
}



void loop() {  

  pulseCount();


  swirl( displays[1] );

  ieee( displays[2]);


} 
