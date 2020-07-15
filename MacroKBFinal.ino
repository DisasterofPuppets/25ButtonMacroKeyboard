#include <Keypad.h>
#include <FastLED.h>
#include <Keyboard.h>

bool gReverseDirection = false;
#define NUM_LEDS 25
#define DATA_PIN 2
CRGB leds[NUM_LEDS];
#define COOLING  55
#define SPARKING 120
#define BRIGHTNESS  50
#define FRAMES_PER_SECOND 60
bool startupAnimations = true;
bool buttonAnimations = true;
uint8_t gHue = 0;
int keypress = 20; // delay between keyboard press and release
int selected = 666;
bool camState = false;
bool mState = false;
int camButton = 0;
int mButton = 0;
int anidelay = 20;

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

void setup() 

{

  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  Serial.begin(9600);
  Keyboard.begin();
 
}

void loop() 

      {
       if (startupAnimations == true)
       {
            int pick = random(0,2);
            
          
          
          if (selected == 666) // Before variable is set, play animation (ie power on)
          {
            
                if (pick == 0)
                  {
                      juggle();
                      FastLED.show();
                      delay(100);
                  }
          
               if (pick == 1)
                  {
                      sinelon();
                      FastLED.show();
                      delay(100);
                  }
             
               if (pick == 2)
                  {
                      rainbowWithGlitter();
                      FastLED.show();
                      delay(100);
                  }
            }
      }
    
FastLED.clear(); 
leds[selected] = CRGB::Blue; 
FastLED.show(); 
    
    // shows updated LED settings

/* To set button LEDs to stay off simply remove the 'selected' values in the custom keyboard definitions
 *  examples, when using a soundboard etc.
 */
          
/*Below is code you can use to perform seperate actions on specific buttons, example,              
 * you may wish to use a mute button, but you want to see if you are muted or not at any given time.
 * We can set the LED to red if it is currently muted and Green if it all good. Of course you can change 
 * the actions in the comparison to the button counts below
 *
 * We use a count to check the button has been pushed, as it can stay on while others change
 *  we are unable to clear when in the true state so we needed another variable each time the button is 
 *  pressed in the setup below we add 1, the default is 0, therefore 2 means its been pressed twice and 
 *  needs to go back to the default state. Keep in mind you will need to create a unique counter for each 
 *  custom button and increase it's value each time it is called ie (variableNAME = VariableName +1). 
 *  This needs to occur in the Key definitions below. You will also need to create a bool for the button 
 *  so we will know the button state **example for the webcam (which are set above setup)
bool camState  = false;
int camButton = 0;

 * ALSO don't forget to remove the 'selected' assignment for the specific button (otherwise it will go 
 * back to blue when the main script runs)


 /* This is a webcam button, Red LED when it is off defaults can be set at top, Green when it is on */
 
          if (selected != 666)
          {
            if (camButton >= 2 or camButton <=0) 
            {
             
              leds[10] = CRGB::Green; 
              // you need to fill in the LED number as we don't give it a 'selected' value in the custom definitions
              FastLED.show();
              camState = false;
              camButton = 0;
            }
            else if (camButton <= 1)
            {
           
              leds[10] = CRGB::Red;
              FastLED.show();
            }    

 /* This is a MUTE button, Red LED when it is ON defaults can be set at top, Green when it is OFF 
  *  Just another example, but it is the reverse in terms of colours
  */
 
            if (mButton >= 2 or mButton <=0) 
            {
   
              leds[24] = CRGB::Green; 
              FastLED.show();
              mState = true;
              mButton = 0;
            }
            else if (mButton <= 1)
            {
     
              leds[24] = CRGB::Red;
              FastLED.show();
            }    
          }
    
      
           
           
/* Testing stuff, you saw nothing...move along 
Serial.print("mButton : ");
Serial.println(mButton);
Serial.print("webCam State : ");
Serial.println(camState);
Serial.print("Mute State : ");
Serial.println(mState);
Serial.print("Selected button is :");
Serial.println(selected);
*/


//CUSTOM KEYBOARD DECLERATIONS 
 

char customKey = customKeypad.getKey();
  
if (customKey) 
  {
     switch (customKey) 
     {
        case '0':

            // LIVE
            selected = 0;   
            prudy(0);
            Serial.print("You selected F13, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_F13);
            delay(keypress);
            Keyboard.release(KEY_F13);
            break;
            
        case '1':

            // Craft Desk
            selected = 1;  
            prudy(1);
            Serial.print("You selected F14, selected is  ");
            Serial.println(selected);            
            Keyboard.press(KEY_F14);
            delay(keypress);
            Keyboard.release(KEY_F14);
            break;   
            
        case '2':

            // Raid
            //selected = 2; 
            prudy(2);
            Serial.print("You selected F15, selected is  ");
            Serial.println(selected);            
            Keyboard.press(KEY_F15);
            delay(keypress);
            Keyboard.release(KEY_F15);
            break;

        case '3':

            //Paintbrush *chatbot on/off
            //selected = 3;
            prudy(3);
            Serial.print("You selected F16, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_F16);
            delay(keypress);
            Keyboard.release(KEY_F16);
            break;

        case '4':

            //BRB
            selected = 4;
            prudy(4);
            Serial.print("You selected F17, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_F17);
            delay(keypress);
            Keyboard.release(KEY_F17);
            break;

        case '5':

            //Logitech Toggle
            //selected = 5;
            prudy(5);
            Serial.print("You selected F18, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_F18);
            delay(keypress);
            Keyboard.release(KEY_F18);
            break;

        case '6':

            // Ending
            selected = 6;  
            prudy(6);
            Serial.print("You selected F19, selected is  ");
            Serial.println(selected);        
            Keyboard.press(KEY_F19);
            delay(keypress);
            Keyboard.release(KEY_F19);
            break;

        case '7':

            // IVcam Toggle (no led)
            prudy(7);
            //selected = 7; 
            Serial.print("You selected F20, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_F20);
            delay(keypress);
            Keyboard.release(KEY_F20);
            break;

        case '8':

            // RED *chatbot on/off
            //selected = 8;  
            prudy(8);
            FastLED.show();
            Serial.print("You selected F21, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_F21);
            delay(keypress);
            Keyboard.release(KEY_F21);
            break;

        case '9':

            // Doorprize
            selected = 9;  
            prudy(9);
            FastLED.show();
            Serial.print("You selected F22, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_F22);
            delay(keypress);
            Keyboard.release(KEY_F22);
            break;

        case 'A':
        
            // Webcam Toggle
            camState = true;      
            camButton = camButton + 1;
            //prudy(10);
            Serial.print("You selected F23, selected is  ");
            Serial.println(selected); 
            Keyboard.press(KEY_F23);
            delay(keypress);
            Keyboard.release(KEY_F23);
            break;        

        case 'B':
        
            // Character Animator / PuppetCam Toggle
            //selected = 11;
            prudy(11);
            Serial.print("You selected F24, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_F24);
            delay(keypress);
            Keyboard.release(KEY_F24);
            break;   

        case 'C':
        
            //Unassigned
            //selected = 12;
            prudy(12);
            Serial.print("You selected ALT + CTRL + Numpad 1, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(225);
            delay(keypress);
            Keyboard.releaseAll();
            break;                       

        case 'D':

            // Blue *chatbot on/off
            //selected = 13;
            prudy(13);
            Serial.print("You selected ALT + CTRL + Numpad 2, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(226);
            delay(keypress);
            Keyboard.releaseAll();
            break;                                                                            

        case 'E':
        
            // Unassigned  
            //selected = 14;  
            prudy(14);
            Serial.print("You selected ALT + CTRL + Numpad 3, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(227);
            delay(keypress);
            Keyboard.releaseAll();
            break;    

        case 'F':

            // Soundboard
            //selected = 15;
            prudy(15);
            Serial.print("You selected ALT + CTRL + Numpad 4, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(228);
            delay(keypress);
            Keyboard.releaseAll();
            break;    

        case 'G':

            //BS
            //selected = 16;
            prudy(16);// 
            Serial.print("You selected ALT + CTRL + Numpad 5, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(229);
            delay(keypress);
            Keyboard.releaseAll();
            break;    

        case 'H':

            //Stamp
            //selected = 17;
            prudy(17);
            Serial.print("You selected ALT + CTRL + Numpad 6, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(230);
            delay(keypress);
            Keyboard.releaseAll();
            break;    

        case 'I':

            // GREEN *chatbot on/off
            //selected = 18;
            prudy(18);
            Serial.print("You selected ALT + CTRL + Numpad 7, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(231);
            delay(keypress);
            Keyboard.releaseAll();

            break;    

        case 'J':
        
            // Soundboard
            leds[19] = CRGB::HotPink;
            leds[selected] = CRGB::Blue; 
            prudy(19); 
            FastLED.show();
            Serial.print("You selected ALT + CTRL + Numpad 8, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(232);
            delay(keypress);
            Keyboard.releaseAll();
            break;       

        case 'K':
        
            // Soundboard
            leds[20] = CRGB::HotPink;
            prudy(20);
            leds[selected] = CRGB::Blue; 
            FastLED.show();
            Serial.print("You selected ALT + CTRL + Numpad 9, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(233);
            delay(keypress);
            Keyboard.releaseAll();
            break;  

        case 'L':
        
            // Soundboard
            leds[21] = CRGB::HotPink;
            leds[selected] = CRGB::Blue; 
            prudy(21);
            FastLED.show();
            Serial.print("You selected ALT + CTRL + Numpad 0, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(234);
            delay(keypress);
            Keyboard.releaseAll();
            break;  

        case 'M':
        
            // Soundboard
            leds[22] = CRGB::HotPink;
            leds[selected] = CRGB::Blue; 
            prudy(22);
            FastLED.show();
            Serial.print("You selected ALT + CTRL + Numpad -, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(222);
            delay(keypress);
            Keyboard.releaseAll();
            break;  

        case 'N':
        
            // Soundboard
            leds[23] = CRGB::HotPink;
            leds[selected] = CRGB::Blue;
            prudy(23);
            FastLED.show();
            Serial.print("You selected ALT + CTRL + Numpad +, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(223);
            delay(keypress);
            Keyboard.releaseAll();
            break;                                                                                                                       

        case 'O':

            // MUTE Toggle
         //   selected = 24;  
            mState = true;
            mButton = mButton +1;     
            //prudy(24); 
            Serial.print("You selected Numpad *, selected is  ");
            Serial.println(selected);
            Keyboard.press(KEY_RIGHT_ALT);
            Keyboard.press(KEY_RIGHT_CTRL);
            Keyboard.press(221);
            delay(keypress);
            Keyboard.releaseAll();
            break;                                                                                                                                   
      }
    }
}

void prudy(int button)
{

  if (buttonAnimations == true)
  {
  
          //middle 6 buttons
          if (button >= 6 and button <=8 or button >=11 and button <=13 or button >=16 and button <=18)
              {
                FastLED.clear();
                leds[button] = CRGB::Blue;
                leds[button+4] = CRGB::Yellow;
                leds[button+6] = CRGB::Yellow;
                leds[button-6] = CRGB::Yellow;
                leds[button-4] = CRGB::Yellow;
          
                leds[button+1] = CRGB::Red;
                leds[button-5] = CRGB::Red;
                leds[button-1] = CRGB::Red;
                leds[button+5] = CRGB::Red;
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Blue;
                leds[button+4] = CRGB::Yellow;
                leds[button+6] = CRGB::Yellow;
                leds[button-6] = CRGB::Yellow;
                leds[button-4] = CRGB::Yellow;
          
                leds[button+1] = CRGB::Red;
                leds[button-5] = CRGB::Red;
                leds[button-1] = CRGB::Red;
                leds[button+5] = CRGB::Red;
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Red;
                leds[button+4] = CRGB::Green;
                leds[button+6] = CRGB::Green;
                leds[button-6] = CRGB::Green;
                leds[button-4] = CRGB::Green;
                
                leds[button+1] = CRGB::Blue;
                leds[button-5] = CRGB::Blue;
                leds[button-1] = CRGB::Blue;
                leds[button+5] = CRGB::Blue;      
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Yellow;
                leds[button+4] = CRGB::Aqua;
                leds[button+6] = CRGB::Aqua;
                leds[button-6] = CRGB::Aqua;
                leds[button-4] = CRGB::Aqua;
                
                leds[button+1] = CRGB::Red;
                leds[button-5] = CRGB::Red;
                leds[button-1] = CRGB::Red;
                leds[button+5] = CRGB::Red;
                
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Green;
                leds[button+4] = CRGB::Yellow;
                leds[button+6] = CRGB::Yellow;
                leds[button-6] = CRGB::Yellow;
                leds[button-4] = CRGB::Yellow;
           
                leds[button+1] = CRGB::Blue;
                leds[button-5] = CRGB::Blue;
                leds[button-1] = CRGB::Blue;
                leds[button+5] = CRGB::Blue;     
          
                FastLED.show();
                delay(anidelay);
          
              }        
  }              

         //Top Row
          if (button >= 1 and button <= 3)
              {
                FastLED.clear();
                leds[button] = CRGB::Blue;
                leds[button+4] = CRGB::Yellow;
                leds[button+6] = CRGB::Yellow;

          
                leds[button+1] = CRGB::Red;
                leds[button-1] = CRGB::Red;
                leds[button+5] = CRGB::Red;
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Blue;
                leds[button+4] = CRGB::Yellow;
                leds[button+6] = CRGB::Yellow;

                leds[button+1] = CRGB::Red;
                leds[button-1] = CRGB::Red;
                leds[button+5] = CRGB::Red;
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Red;
                leds[button+4] = CRGB::Green;
                leds[button+6] = CRGB::Green;

                
                leds[button+1] = CRGB::Blue;
                leds[button-1] = CRGB::Blue;
                leds[button+5] = CRGB::Blue;      
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Yellow;
                leds[button+4] = CRGB::Aqua;
                leds[button+6] = CRGB::Aqua;

                
                leds[button+1] = CRGB::Red;
                leds[button-1] = CRGB::Red;
                leds[button+5] = CRGB::Red;
                
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Green;
                leds[button+4] = CRGB::Yellow;
                leds[button+6] = CRGB::Yellow;

           
                leds[button+1] = CRGB::Blue;
                leds[button-1] = CRGB::Blue;
                leds[button+5] = CRGB::Blue;     
          
                FastLED.show();
                delay(anidelay);
          
              }    

        //Bottom Row
          if (button >= 21 and button <=23)
              {
                FastLED.clear();
                leds[button] = CRGB::Blue;
                leds[button-6] = CRGB::Yellow;
                leds[button-4] = CRGB::Yellow;
          
                leds[button+1] = CRGB::Red;
                leds[button-5] = CRGB::Red;
                leds[button-1] = CRGB::Red;
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Blue;
                leds[button-6] = CRGB::Yellow;
                leds[button-4] = CRGB::Yellow;
          
                leds[button+1] = CRGB::Red;
                leds[button-5] = CRGB::Red;
                leds[button-1] = CRGB::Red;
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Red;
                leds[button-6] = CRGB::Green;
                leds[button-4] = CRGB::Green;
                
                leds[button+1] = CRGB::Blue;
                leds[button-5] = CRGB::Blue;
                leds[button-1] = CRGB::Blue;
    
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Yellow;
                leds[button-6] = CRGB::Aqua;
                leds[button-4] = CRGB::Aqua;
                
                leds[button+1] = CRGB::Red;
                leds[button-5] = CRGB::Red;
                leds[button-1] = CRGB::Red;
                
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Green;
                leds[button-6] = CRGB::Yellow;
                leds[button-4] = CRGB::Yellow;
           
                leds[button+1] = CRGB::Blue;
                leds[button-5] = CRGB::Blue;
                leds[button-1] = CRGB::Blue;
          
                FastLED.show();
                delay(anidelay);
          
              }    

        //Left Row
          if (button == 5 or button == 10 or button ==15 and button)
              {
                FastLED.clear();
                leds[button] = CRGB::Blue;
                leds[button+5] = CRGB::Yellow;
                leds[button+6] = CRGB::Yellow;
                leds[button-4] = CRGB::Yellow;
          
                leds[button+1] = CRGB::Red;
                leds[button-5] = CRGB::Red;

          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Blue;
                leds[button+5] = CRGB::Yellow;
                leds[button+6] = CRGB::Yellow;
                leds[button-4] = CRGB::Yellow;
          
                leds[button+1] = CRGB::Red;
                leds[button-5] = CRGB::Red;

          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Red;
                leds[button+5] = CRGB::Green;
                leds[button+6] = CRGB::Green;
                leds[button-4] = CRGB::Green;
                
                leds[button+1] = CRGB::Blue;
                leds[button-5] = CRGB::Blue;
  
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Yellow;
                leds[button+5] = CRGB::Aqua;
                leds[button+6] = CRGB::Aqua;
                leds[button-4] = CRGB::Aqua;
                
                leds[button+1] = CRGB::Red;
                leds[button-5] = CRGB::Red;

                
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Green;
                leds[button+5] = CRGB::Yellow;
                leds[button+6] = CRGB::Yellow;
                leds[button-4] = CRGB::Yellow;
           
                leds[button+1] = CRGB::Blue;
                leds[button-5] = CRGB::Blue;
 
          
                FastLED.show();
                delay(anidelay);
          
              }    
        //Right Row
          if (button == 9 or button == 14 or button ==19)
              {
                FastLED.clear();
                leds[button] = CRGB::Blue;
                leds[button+4] = CRGB::Yellow;
                leds[button-6] = CRGB::Yellow;

                leds[button-5] = CRGB::Red;          
                leds[button-1] = CRGB::Red;
                leds[button+5] = CRGB::Red;
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Blue;
                leds[button+4] = CRGB::Yellow;
                leds[button-6] = CRGB::Yellow;

                leds[button-5] = CRGB::Red;
                leds[button-1] = CRGB::Red;
                leds[button+5] = CRGB::Red;
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Red;
                leds[button+4] = CRGB::Green;
                leds[button-6] = CRGB::Green;

                leds[button-5] = CRGB::Blue;
                leds[button-1] = CRGB::Blue;
                leds[button+5] = CRGB::Blue;
    
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Yellow;
                leds[button+4] = CRGB::Aqua;
                leds[button-6] = CRGB::Aqua;
                
                leds[button-5] = CRGB::Red;
                leds[button-1] = CRGB::Red;
                leds[button+5] = CRGB::Red;

                
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Green;
                leds[button+4] = CRGB::Yellow;
                leds[button-6] = CRGB::Yellow;
                
                leds[button-5] = CRGB::Blue;
                leds[button-1] = CRGB::Blue;   
                leds[button+5] = CRGB::Blue;
                          
                FastLED.show();
                delay(anidelay);
          
              }    

       //Top Left Corner (0)
          if (button == 0)
              {
                FastLED.clear();
                leds[button] = CRGB::Blue;
                leds[button+6] = CRGB::Yellow;
                leds[button+1] = CRGB::Red;
                leds[button+5] = CRGB::Red;
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Blue;
                leds[button+6] = CRGB::Yellow;
                leds[button+1] = CRGB::Red;
                leds[button+5] = CRGB::Red;
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Red;
                leds[button+6] = CRGB::Green;
                leds[button+1] = CRGB::Blue;
                leds[button+5] = CRGB::Blue;      
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Yellow;
                leds[button+6] = CRGB::Aqua;
                leds[button+1] = CRGB::Red;
                leds[button+5] = CRGB::Red;
                
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Green;
                leds[button+6] = CRGB::Yellow;
           
                leds[button+1] = CRGB::Blue;
                leds[button+5] = CRGB::Blue;     
          
                FastLED.show();
                delay(anidelay);
          
              }    
      //Top Right Corner
          if (button == 4)
              {
                FastLED.clear();
                leds[button] = CRGB::Blue;
                leds[button+4] = CRGB::Yellow;
          
                leds[button-1] = CRGB::Red;
                leds[button+5] = CRGB::Red;
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Blue;
                leds[button+4] = CRGB::Yellow;

                leds[button-1] = CRGB::Red;
                leds[button+5] = CRGB::Red;
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Red;
                leds[button+4] = CRGB::Green;
              
                leds[button-1] = CRGB::Blue;
                leds[button+5] = CRGB::Blue;      
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Yellow;
                leds[button+4] = CRGB::Aqua;
               
                leds[button-1] = CRGB::Red;
                leds[button+5] = CRGB::Red;
                
                FastLED.show();
                delay(120);
          
                leds[button] = CRGB::Green;
                leds[button+4] = CRGB::Yellow;
               
                leds[button-1] = CRGB::Blue;
                leds[button+5] = CRGB::Blue;     
          
                FastLED.show();
                delay(120);
          
              }    
      //Bottom Left Corner
          if (button == 20)
              {
                FastLED.clear();
                leds[button] = CRGB::Blue;
                leds[button-4] = CRGB::Yellow;
                leds[button+1] = CRGB::Red;
                leds[button-5] = CRGB::Red;


          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Blue;
                leds[button-4] = CRGB::Yellow;
               
                leds[button+1] = CRGB::Red;
                leds[button-5] = CRGB::Red;

                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Red;
                leds[button-4] = CRGB::Green;
                
                leds[button+1] = CRGB::Blue;
                leds[button-5] = CRGB::Blue;
   
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Yellow;
                leds[button-4] = CRGB::Aqua;
                
                leds[button+1] = CRGB::Red;
                leds[button-5] = CRGB::Red;

                
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Green;
                leds[button-4] = CRGB::Yellow;
           

                leds[button-1] = CRGB::Blue;
                leds[button+5] = CRGB::Blue;     
          
                FastLED.show();
                delay(anidelay);
          
              }    
      //Bottom Right Corner
          if (button ==24)
              {
                FastLED.clear();
                leds[button] = CRGB::Blue;

                leds[button-6] = CRGB::Yellow;

          
                leds[button-5] = CRGB::Red;
                leds[button-1] = CRGB::Red;
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Blue;

                leds[button-6] = CRGB::Yellow;

          

                leds[button-5] = CRGB::Red;
                leds[button-1] = CRGB::Red;

          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Red;

                leds[button-6] = CRGB::Green;


                leds[button-5] = CRGB::Blue;
                leds[button-1] = CRGB::Blue; 
          
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Yellow;

                leds[button-6] = CRGB::Aqua;

                leds[button-5] = CRGB::Red;
                leds[button-1] = CRGB::Red;
                
                FastLED.show();
                delay(anidelay);
          
                leds[button] = CRGB::Green;
                leds[button-6] = CRGB::Yellow;
           
                leds[button-5] = CRGB::Blue;
                leds[button-1] = CRGB::Blue;
          
                FastLED.show();
                delay(anidelay);
          
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
  fill_rainbow(leds, NUM_LEDS, gHue, 7);
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
