// Read an image file of 565 x 267 pixels and find the values 

String colorsample;
String lightframe ="";


PImage img;


void setup() {

  size(565, 267);
  img = loadImage("04.png");
  image(img, 0, 0);
  noLoop();
}



void draw()
{
// these are the points manually set and calculated for the centers of the lens / aperture that the LED is located in
  int[] xpos = {57, 57, 57, 79, 79, 78, 101, 100, 101, 123, 123, 122, 122, 145, 144, 144, 144, 144, 147, 168, 167, 168, 168, 167, 167, 167, 190, 190, 190, 190, 189, 192, 214, 214, 213, 213, 213, 213, 213, 236, 236, 236, 236, 236, 237, 259, 260, 260, 260, 259, 260, 260, 283, 283, 283, 283, 283, 284, 306, 306, 306, 306, 307, 307, 307, 330, 330, 330, 330, 330, 330, 351, 351, 353, 352, 353, 353, 353, 373, 376, 376, 376, 375, 376, 396, 396, 398, 398, 399, 399, 399, 421, 421, 421, 420, 419, 418, 442, 443, 443, 443, 465, 464, 465, 486, 486, 487, 507, 507, 505};
  int[] ypos = {139, 120, 100, 111, 130, 150, 140, 121, 101, 94, 112, 132, 151, 142, 122, 103, 89, 75, 58, 49, 67, 83, 96, 113, 132, 153, 143, 123, 104, 89, 75, 59, 50, 68, 83, 96, 114, 134, 154, 144, 124, 104, 90, 76, 59, 50, 68, 84, 97, 115, 134, 155, 144, 124, 104, 90, 76, 59, 50, 68, 84, 96, 114, 134, 154, 144, 124, 104, 90, 76, 59, 50, 67, 83, 96, 113, 133, 153, 143, 123, 103, 89, 75, 89, 49, 67, 83, 95, 113, 132, 152, 141, 121, 102, 88, 74, 58, 94, 111, 130, 151, 140, 120, 101, 110, 129, 149, 138, 119, 100};




// loop through all the positions and calculate whether we're looking at black or white
  for (int i=0; i<110; i++)
  {

    colorsample=str(color(get(int(xpos[i]), int(ypos[i]))));

    //println(ypos); 
    //lightframe=lightframe+","+colorsample;
    //println(colorsample);


    if (colorsample.equals("-1"))
    {
      lightframe=lightframe+""+"1";  //append to the lightframe string
      //println("white");
    } else
    {
      lightframe=lightframe+""+"0";
      //println("black");
    }
  }

  println(lightframe);  // show us the final lightframe string, this string will be used in the arduino code. 
}
