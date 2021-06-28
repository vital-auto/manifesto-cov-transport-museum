//goes with p5.js to Arduino-04 https://editor.p5js.org/organised/sketches/73EnsEwxd
//This receives a byte from a p5serial server and it routes it. Its the start of trying to create a robust LED string animator. 

#include <Adafruit_NeoPixel.h>
#define PIN      6
#define N_LEDS 110
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);



char playframe[60] = "000000000000000011000000000000000000000000000000110000000000";
char s1f1[110] = "010101010101010101010101010101010101010101010101010101010101";
char s1f2[110] = "111111111111111111111111111111111111111111111111111111111111";
char s1f3[110] = "111111111111111111100000000000000000011111111111111111111111";
char s1f4[110] = "111111111111111111111111111111111111111111111111111111111111";
char s1f5[110] = "111111000000000000000000000000000000000000000000011111111111";





// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);
  strip.begin();
}



// the loop function runs over and over again forever
void loop() {

  int sequence;




  // reads it once and stores in variable
  if (Serial.available() > 0)
  {
    sequence = Serial.read();
  }

  //dirty test hack
  sequence = 1;






  if (sequence == 1)
  {





    //copy named frame into playframe
    for (int j = 0 ; j < 59 ; j++ ) {
      playframe[j] = s1f1[j];
    }
    delay(2250);

    
    
    //play frame 
    for (int i = 0; i < 59; i++) {

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

     //copy new frame into playframe
    for (int j = 0 ; j < 59 ; j++ ) {
      playframe[j] = s1f4[j];
    }

    //copy 
    for (int i = 0; i < 59; i++) {

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







  }













  if (sequence == 2)
  {
    chase(strip.Color(0, 255, 0));

  }


  if (sequence == 3)
  {

    chase(strip.Color(0, 0, 255));
    /*
        digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(100);                       // wait for a second
        digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
        delay(100);
    */

  }











}




static void chase(uint32_t c) {
  for (uint16_t i = 0; i < strip.numPixels() + 4; i++) {
    strip.setPixelColor(i  , c); // Draw new pixel
    strip.setPixelColor(i - 4, 0); // Erase pixel a few steps back
    strip.show();
    delay(10);
  }
}
