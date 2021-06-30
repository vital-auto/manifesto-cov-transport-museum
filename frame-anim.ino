#include <Adafruit_NeoPixel.h>
#define PIN      6
#define N_LEDS 110
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);



String playframe = "00000000000000000011100000000011110000000001111000000000111100000000011110000000001011000000000010000000000000";
String s1f1 = "00000000000000000011100000000011110000000001111000000000111100000000011110000000001011000000000010000000000000";
String s1f2 = "11111111111111111100011111111100001111111110000111111111000011111111100001111111110100111111111101111111111111";
String s1f3 ="111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111";




// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
 // pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  strip.begin();
  //Serial.print("hi");
}



// the loop function runs over and over again forever
void loop() {

  int sequence;



/* re -enable
  // reads it once and stores in variable
  if (Serial.available() > 0)
  {
    sequence = Serial.read();
  }
  */

  //dirty test hack
  sequence = 1;






  if (sequence == 1)
  {

playthisframe(s1f1,20);
playthisframe(s1f2,20);
playthisframe(s1f3,20);

/*
   
// Turn this into a function

    //copy named frame into playframe
    for (int j = 0 ; j < 59 ; j++ ) {
      playframe[j] = s1f1[j];
    }
    delay(2250);


   
    //play frame
    for (int i = 0; i < 109; i++) {

      if (playframe[i] == '1')
      {
        strip.setPixelColor(i  , 255, 255, 255); // Draw new pixel
        strip.show();
      }
      else
      {
        strip.setPixelColor(i  , 0, 0, 0); // Draw new pixel
        strip.show();
      }

    }

    delay(2250);



*/


  }













  if (sequence == 2)
  {
   // chase(strip.Color(0, 255, 0));

  }


  if (sequence == 3)
  {

    //chase(strip.Color(0, 0, 255));
    /*
        digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(100);                       // wait for a second
        digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
        delay(100);
    */

  }







}





void playthisframe(String frame,int delayframe)
{


    //copy named frame into playframe
    for (int j = 0 ; j < 109 ; j++ ) {
      playframe[j] = frame[j];
    }
   

  // Serial.print(frame);
   
    //play frame
    for (int i = 0; i < 109; i++) {
      

      if (frame[i] == '1')
      {
        strip.setPixelColor(i  , 255, 255, 255); // Draw new pixel
        strip.show();
      }
      else
      {
        strip.setPixelColor(i  , 0, 0, 0); // Draw new pixel
        strip.show();
      }

    }

 delay(delayframe); 
}


/* example array passing

 void printArray(char frame[120],int n)
{
   for (int i = 0; i < n; i++)
   {
      printf(frame[i] + " ");
   }
} 
 */


static void chase(uint32_t c) {
  for (uint16_t i = 0; i < strip.numPixels() + 4; i++) {
    strip.setPixelColor(i  , c); // Draw new pixel
    strip.setPixelColor(i - 4, 0); // Erase pixel a few steps back
    strip.show();
    delay(10);
  }
}
