#include <Keypad.h>
#include <FastLED.h>
#include <Keyboard.h>

//For multiple key presses use Keyboard.press()

bool gReverseDirection = false;
#define NUM_LEDS 25
#define DATA_PIN 2
CRGB leds[NUM_LEDS];
#define COOLING  55
#define SPARKING 120
#define BRIGHTNESS  50
#define FRAMES_PER_SECOND 60
uint8_t gHue = 0;
int keypress = 20; // delay between keyboard press and release


// IDLE ANIMATION SETTINGS
bool idleAnimation = true; // set this to off if you don't want this to run
unsigned long previousMillis = 0;        // will store last time LEDs were updated
unsigned long interval = 900000; //

//900000; // 15 mins

int selected = 666;


const byte ROWS = 5;
const byte COLS = 5;
char hexaKeys[ROWS][COLS] = 
{

  {'0', '1', '2', '3', '4'},
  {'5', '6', '7', '8', '9'},
  {'A', 'B', 'C', 'D', 'E'},
  {'F', 'G', 'H', 'I', 'J'},
  {'K', 'L', 'M', 'N', 'O'},

};

byte colPins[COLS] = {9, 10, 16, 14, 15};
byte rowPins[ROWS] = {3, 4, 5, 6, 7};


Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);



void setup() {

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  Serial.begin(9600);
  Keyboard.begin();
}

void loop() {

  int pick = random(0,3);


if (selected == 666) // Before variable is set, play animation (ie power on)
{
  
        if (pick == 0)
        {
            bpm();
            FastLED.show();
            delay(100);
        }
      
      if (pick == 1)
        {
            juggle();
            FastLED.show();
            delay(100);
        }

     if (pick == 2)
        {
            sinelon();
            FastLED.show();
            delay(100);
        }
   
     if (pick == 3)
        {
            rainbowWithGlitter();
            FastLED.show();
            delay(100);
        }

}

 
     FastLED.clear();
     //Set LED above last selected
     leds[selected] = CRGB::Blue;
     FastLED.show();


char customKey = customKeypad.getKey();
  
if (customKey) 
  {
     switch (customKey) 
     {
        case '0':
            selected = 0;   
            Serial.print("You selected F13, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_F13);
            delay(keypress);
            Keyboard.release(KEY_F13);
            break;
            
        case '1':
        
            selected = 1;   
            Serial.print("You selected F14, selected is  ");
            Serial.println(selected);            
            Keyboard.press(KEY_F14);
            delay(keypress);
            Keyboard.release(KEY_F14);
            break;   
            
        case '2':
        
            selected = 2; 
            Serial.print("You selected F15, selected is  ");
            Serial.println(selected);            
            Keyboard.press(KEY_F15);
            delay(keypress);
            Keyboard.release(KEY_F15);
            break;

        case '3':
        
            selected = 3;
            Serial.print("You selected F16, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_F16);
            delay(keypress);
            Keyboard.release(KEY_F16);
            break;

        case '4':
        
            selected = 4;
            Serial.print("You selected F17, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_F17);
            delay(keypress);
            Keyboard.release(KEY_F17);
            break;

        case '5':
        
            selected = 5;
            Serial.print("You selected F18, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_F18);
            delay(keypress);
            Keyboard.release(KEY_F18);
            break;

        case '6':
        
            selected = 6;  
            Serial.print("You selected F19, selected is  ");
            Serial.println(selected);        
            Keyboard.press(KEY_F19);
            delay(keypress);
            Keyboard.release(KEY_F19);
            break;

        case '7':
            
            selected = 7; 
            Serial.print("You selected F20, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_F20);
            delay(keypress);
            Keyboard.release(KEY_F20);
            break;

        case '8':
        
            selected = 8;
            Serial.print("You selected F21, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_F21);
            delay(keypress);
            Keyboard.release(KEY_F21);
            break;

        case '9':
        
            selected = 9;
            Serial.print("You selected F22, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_F22);
            delay(keypress);
            Keyboard.release(KEY_F22);
            break;

        case 'A':
            
            selected = 10;      
            Serial.print("You selected F23, selected is  ");
            Serial.println(selected); 
            Keyboard.press(KEY_F23);
            delay(keypress);
            Keyboard.release(KEY_F23);
            break;        

        case 'B':
            
            selected = 11;
            Serial.print("You selected F24, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_F24);
            delay(keypress);
            Keyboard.release(KEY_F24);
            break;   

        case 'C':
        
            selected = 12;
            Serial.print("You selected F13 + Shift, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_SHIFT); 
            Keyboard.press(KEY_F13);
            delay(keypress);
            Keyboard.release(KEY_RIGHT_SHIFT);
            Keyboard.release(KEY_F13);
            break;                       

        case 'D':
        
            selected = 13;
            Serial.print("You selected F14 + Shift, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_SHIFT); 
            Keyboard.press(KEY_F14);
            delay(keypress);
            Keyboard.release(KEY_RIGHT_SHIFT);
            Keyboard.release(KEY_F14);
            break;                                                                            

        case 'E':
        
            selected = 14;
            Serial.print("You selected F15 + Shift, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_SHIFT); 
            Keyboard.press(KEY_F15);
            delay(keypress);
            Keyboard.release(KEY_RIGHT_SHIFT);
            Keyboard.release(KEY_F15);
            break;    

        case 'F':
        
            selected = 15;
            Serial.print("You selected F16 + Shift, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_SHIFT); 
            Keyboard.press(KEY_F16);
            delay(keypress);
            Keyboard.release(KEY_RIGHT_SHIFT);
            Keyboard.release(KEY_F16);
            break;    

        case 'G':
        
            selected = 16;
            Serial.print("You selected F17 + Shift, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_SHIFT); 
            Keyboard.press(KEY_F17);
            delay(keypress);
            Keyboard.release(KEY_RIGHT_SHIFT);
            Keyboard.release(KEY_F17);
            break;    

        case 'H':
            
            selected = 17;
            Serial.print("You selected F18 + Shift, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_SHIFT); 
            Keyboard.press(KEY_F18);
            delay(keypress);
            Keyboard.release(KEY_RIGHT_SHIFT);
            Keyboard.release(KEY_F18);
            break;    

        case 'I':
        
            selected = 18;
            Serial.print("You selected F19 + Shift, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_SHIFT); 
            Keyboard.press(KEY_F19);
            delay(keypress);
            Keyboard.release(KEY_RIGHT_SHIFT);
            Keyboard.release(KEY_F19);
            break;    

        case 'J':
        
            selected = 19;
            Serial.print("You selected F20 + Shift, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_SHIFT); 
            Keyboard.press(KEY_F20);
            delay(keypress);
            Keyboard.release(KEY_RIGHT_SHIFT);
            Keyboard.release(KEY_F20);
            break;       

        case 'K':
        
            selected = 20;
            Serial.print("You selected F21 + Shift, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_SHIFT); 
            Keyboard.press(KEY_F21);
            delay(keypress);
            Keyboard.release(KEY_RIGHT_SHIFT);
            Keyboard.release(KEY_F21);
            break;  

        case 'L':
        
            selected = 21;
            Serial.print("You selected F22 + Shift, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_SHIFT); 
            Keyboard.press(KEY_F22);
            delay(keypress);
            Keyboard.release(KEY_RIGHT_SHIFT);
            Keyboard.release(KEY_F22);
            break;  

        case 'M':
        
            selected = 22;
            Serial.print("You selected F23 + Shift, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_SHIFT); 
            Keyboard.press(KEY_F23);
            Keyboard.release(KEY_RIGHT_SHIFT);
            Keyboard.release(KEY_F23);
            break;  

        case 'N':
        
            selected = 23;
            Serial.print("You selected F24 + Shift, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_SHIFT); 
            Keyboard.press(KEY_F24);
            delay(keypress);
            Keyboard.release(KEY_RIGHT_SHIFT);
            Keyboard.release(KEY_F24);
            break;                                                                                                                       

        case 'O':
        
            selected = 24;
            Serial.print("You selected F21 + Alt, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_F24);
            delay(keypress);
            Keyboard.release(KEY_RIGHT_ALT);
            Keyboard.release(KEY_F24);
            break;                                                                                                                                   
      }
    }
}

 
void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
  }
}

void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16( i+7, 0, NUM_LEDS-1 )] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}


void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16( 13, 0, NUM_LEDS-1 );
  leds[pos] += CHSV( gHue, 255, 192);
}

void rainbow() 
{
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
}


void rainbowWithGlitter() 
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(80);
}

void addGlitter( fract8 chanceOfGlitter) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}  
