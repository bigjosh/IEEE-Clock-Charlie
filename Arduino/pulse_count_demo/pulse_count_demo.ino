#include <Adafruit_IS31FL3731.h>
#include <U8g2_for_Adafruit_GFX.h>
#include <Fonts/FreeMono12pt7b.h>


#define ROT_A_PIN (8)
#define ROT_B_PIN (9)
#define ROT_S_PIN (7)

#define DISPLAY_COUNT 3   // Oh C++ why do you not have a good way to get an array size?

Adafruit_IS31FL3731 displays[DISPLAY_COUNT];

U8G2_FOR_ADAFRUIT_GFX u8g2_for_adafruit_gfx;

U8G2_FOR_ADAFRUIT_GFX u8g2_for_adafruit_gfx2;


class TrippleScreen : public Adafruit_GFX {
 public:
  TrippleScreen(uint8_t x=((3*16)+4), uint8_t y=9); 
  //bool begin();
  void drawPixel(int16_t x, int16_t y, uint16_t color);
  void clear(void); // Call to start a new frame
  void show(void);   // Call to display the most recently drawn frame

 protected:
  byte frame;

};


TrippleScreen::TrippleScreen(uint8_t width, uint8_t height) : Adafruit_GFX(width, height) {
}

void TrippleScreen::show(void) {

  for (auto d : displays ) {

    d.displayFrame( frame );
    
  }
}

void TrippleScreen::drawPixel(int16_t x, int16_t y, uint16_t color) {
  
  if ( x < 16 ) {

    displays[2].drawPixel( x , y , color );

  } else if ( x>=18 && x < (18+16) ) {

    displays[1].drawPixel( x-18 , y , color );
    
  } else if ( x>=36 && x < (36+16) ) {

    displays[0].drawPixel( x-36 , y , color );
    
  }    
  
}

void TrippleScreen::clear() {

  frame++;

  if (frame>7) frame=0;

  for( auto &d : displays ) {
    d.setFrame(frame);
    d.clear();
  }
  
}


TrippleScreen trippleScreen;

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

void circles() {

  trippleScreen.clear();

  while ( !buttonPushed() );
  
  static byte r=1;

  while ( !buttonPushed() ) {
  
    trippleScreen.drawCircle( (3*16 + 4)/2  , 4 , r , 128 );

    delay(20);

    trippleScreen.drawCircle( (3*16 + 4)/2  , 4 , r-1 , 0 );
    

    r++;

    if (r>40) r=1;
    

  }  
}

void ieee( TrippleScreen &d ) {


  d.setFont();
  d.setRotation(0);
  d.setTextWrap(0);
    
  static byte step=0;

  static char *ieee = "          IEEE Spectrum";
  
/*
  while (1) { 


      d2.setCursor( -5 , 1 );
    

    
  }
*/

  while (1) {

      d.clear();
      d.setCursor( 0 - step , 1 );
      d.print( ieee);

      d.show();
      
      delay(20);

      step++;

      if (step>140) step=0;

      if (buttonPushed()) return;
      
  }
  
  
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

  Adafruit_IS31FL3731 &display = displays[0]; 

  u8g2_for_adafruit_gfx.begin(display);                 // connect u8g2 procedures to Adafruit GFX
  
  

  u8g2_for_adafruit_gfx.setFont(u8g2_font_8x13_me  );  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  u8g2_for_adafruit_gfx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8g2_for_adafruit_gfx.setFontDirection(0);            // left to right (this is default)


  u8g2_for_adafruit_gfx.setForegroundColor(128);      // apply Adafruit GFX color  

  static byte i=0;
  
  while (1) {
    
    i++;
  
    if (i==100) i=0;
      
    byte bright = 255;

    byte f=0;
  
    while (bright) {

      display.setFrame(f);
      
      display.clear();
      
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
    
      display.displayFrame(f);
      delay(10);
  
      bright /=2;

      f++;
      if (f==8) f=0;

      if (buttonPushed()) return;
    }  

  }
  
}

// Returns when button pushed

void fastCount() {

  
  Adafruit_IS31FL3731 &display = displays[1]; 

  u8g2_for_adafruit_gfx.begin( display );

  u8g2_for_adafruit_gfx.setFont(u8g2_font_profont10_mn   );  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  u8g2_for_adafruit_gfx.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8g2_for_adafruit_gfx.setFontDirection(0);            // left to right (this is default)
  
  // Clear all the display frames
  for( byte i=0; i<8; i++ ) {
    
    display.setFrame(i);
    display.fillScreen(0);

    
  }

  u8g2_for_adafruit_gfx.setForegroundColor(128);      // apply Adafruit GFX color  


  static unsigned int i=0;
  
  while (1) {
    
    i++;
  
    if (i==1000) i=0;
            
    display.clear();
      

    u8g2_for_adafruit_gfx.setCursor(1,6);                // start writing at this position
    //if (i<100) u8g2_for_adafruit_gfx.print('0');

    if (i<100) {
       u8g2_for_adafruit_gfx.print('0');       
    }
      
    if (i<10) {
       u8g2_for_adafruit_gfx.print('0');       
    }
      
    u8g2_for_adafruit_gfx.print(i );

    
    byte fm = ( i % 100 );
    byte fx = fm / (100/16);

    for( byte k=0; k < fx  ; k++ ) {
        display.drawPixel( k , 7 , 32 );
    }    
    
    byte sx = i / (1000/16);

    for( byte k=0; k < sx  ; k++ ) {
        display.drawPixel( k , 8 ,  32 );
    }    

    swapFrame( display );
  

    if (buttonPushed()) return;

  }
  
}


static uint8_t fadeSteps[] = { 0 , 1, 2, 3, 4, 6, 8, 10, 15, 20, 30, 40, 60 , 90 };


void fader() {

  
  Adafruit_IS31FL3731 &display = displays[2]; 

  u8g2_for_adafruit_gfx.begin(display);                 // connect u8g2 procedures to Adafruit GFX
  

  u8g2_for_adafruit_gfx2.setFont( u8g2_font_logisoso16_tn     );  // select u8g2 font from here: https://github.com/olikraus/u8g2/wiki/fntlistall
  u8g2_for_adafruit_gfx2.setFontMode(1);                 // use u8g2 transparent mode (this is default)
  u8g2_for_adafruit_gfx2.setFontDirection(1);            // left to right (this is default)
  
  // Clear all the display frames
  for( byte i=0; i<8; i++ ) {
    
    display.setFrame(i);
    display.fillScreen(0);

    
  }

    display.setFrame(0);
    display.displayFrame(0);
  

  u8g2_for_adafruit_gfx2.setForegroundColor(128);      // apply Adafruit GFX color  


  static byte last=0;
  static byte next=1;

  byte f =0;

  while (1) {
    
    for( byte fade =0 ; fade< 14 ; fade ++ ) {

      display.setFrame(f);
      display.clear();

      u8g2_for_adafruit_gfx2.setForegroundColor(fadeSteps[13-fade]);      // apply Adafruit GFX color  
      u8g2_for_adafruit_gfx2.setCursor(-1,0);                              // start writing at this position      
      u8g2_for_adafruit_gfx2.print(last);   

      u8g2_for_adafruit_gfx2.setForegroundColor(fadeSteps[fade]);      // apply Adafruit GFX color  
      u8g2_for_adafruit_gfx2.setCursor(-1,0);                              // start writing at this position      
      u8g2_for_adafruit_gfx2.print(next);   
      
      display.displayFrame(f);
      delay(10);

      f++;
      if (f==8) f=0;
      
      if (buttonPushed()) return;
    }

    last=next;
    next++;
    if (next==10) next=0;

    for(byte p=0;p<20;p++) {
      if (buttonPushed()) return;
      delay(10);      
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


  u8g2_for_adafruit_gfx2.begin( displays[2]);
  
    
}



void loop() {  

  ieee( trippleScreen );

  trippleScreen.clear();
  trippleScreen.show();


  trippleScreen.clear();
  trippleScreen.show();

  pulseCount();

  fastCount();  

  fader();
  
  //circles();

  //swirl( displays[1] );

 

} 
