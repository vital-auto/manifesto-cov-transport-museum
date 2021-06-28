/*

<!DOCTYPE html>
<!-- I'm using a CDN for both the p5 library and the serilaport library --> 
<html lang="en">
  <head>
    <script src="https://cdnjs.cloudflare.com/ajax/libs/p5.js/0.10.2/p5.js"></script>
   	  <script language="javascript" type="text/javascript" src="https://cdn.jsdelivr.net/npm/p5.serialserver@0.0.28/lib/p5.serialport.js"></script>
  </head>
  <body>
    <script src="sketch.js"></script>
  </body>
</html>


*/

// to go with, p5js_receiver_04  
let serial; // variable for the serial object
let bright = 0; // variable to hold the data we're sending
let dark, light; // variables to hold the bgcolor

function setup() {
  createCanvas(512, 512);
   button1 = createButton('Sequence 1');
   button1.mousePressed(sequence01);
   button2 = createButton('Sequence 2');
   button2.mousePressed(sequence02);
   button3 = createButton('Sequence 3');
   button3.mousePressed(sequence03);
  
  
  button1.position(30, 30);
  button2.position(30, 60);
  button3.position(30, 90);
  
  
  
  
  
  
  
  // define the colors
  dark = color(0);
  light = color(255, 204, 0);

  // serial constructor
  serial = new p5.SerialPort();

  // serial port to use - you'll need to change this
  serial.open('COM3');

}

function drawGradient(c1, c2) {
  noFill();
  for (let y = 0; y < height; y++) {
    let interp = map(y, 0, height, 0, 1);
    let c = lerpColor(c1, c2, interp);
    stroke(c);
    line(0, y, width, y);
  }
}

function draw() {
  drawGradient(dark, light);
  stroke(255);
  strokeWeight(3);
  noFill();
  ellipse(mouseX, mouseY, 10, 10);
}

function mouseDragged(){
 
  bright = floor(map(mouseY, 0, 512, 0, 255));
  bright = constrain(bright, 0, 255);
  //serial.write(bright);
  //console.log(bright);
}




function sequence01() {
  serial.write(1);
  console.log("seq 1");
}


function sequence02() {
  serial.write(2);
    console.log("seq 2");
}

function sequence03() {
  serial.write(3);
    console.log("seq 3");
 
}
