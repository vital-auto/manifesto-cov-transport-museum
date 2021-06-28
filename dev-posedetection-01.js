/* https://www.youtube.com/watch?v=OIo-DIOkNVg&t=327s
*/ 


/*

<!DOCTYPE html>
<html>

<head>
  <script src="https://cdnjs.cloudflare.com/ajax/libs/p5.js/1.1.9/p5.js"></script>
  <script src="https://unpkg.com/ml5@0.5.0/dist/ml5.min.js"></script>
  <link rel="stylesheet" type="text/css" href="style.css">
  <meta charset="utf-8" />

</head>

<body>
  <script src="sketch.js"></script>
</body>

</html>

*/






let video;
let poseNet;
let pose;
let skeleton;

function setup() {
  createCanvas(640,480);
  video = createCapture(VIDEO);
  video.hide();
  poseNet = ml5.poseNet(video, modelLoaded);
  poseNet.on('pose', gotPoses);
}

function gotPoses(poses) {
  //console.log(poses); 
  if (poses.length > 0) {
    pose = poses[0].pose;
    skeleton = poses[0].skeleton;
  }
}


function modelLoaded() {
  console.log('poseNet ready');
}

function draw() {
  image(video, 0, 0);

  if (pose) {
    let eyeR = pose.rightEye;
    let eyeL = pose.leftEye;
    let d = dist(eyeR.x, eyeR.y, eyeL.x, eyeL.y);
    fill(255, 0, 0);
    ellipse(pose.nose.x, pose.nose.y, d);
    fill(0, 0, 255);
    ellipse(pose.rightWrist.x, pose.rightWrist.y, 32);
    ellipse(pose.leftWrist.x, pose.leftWrist.y, 32);
   
    
    
    if(pose.rightWrist.y<pose.rightShoulder.y)
      {
        console.log("Right wrist is above right shoulder")

      }
        
    if(pose.leftWrist.y<pose.leftShoulder.y)
      {
        console.log("Left wrist is above left shoulder")

      }

        if(pose.leftWrist.y<pose.rightShoulder.y)
      {
        console.log("Left wrist is above right shoulder")

      }

        if(pose.rightWrist.y<pose.leftShoulder.y)
      {
        console.log("Right wrist is above left shoulder")

      }
    
    
    
    
    
    
    if (pose.rightWrist.y<pose.nose.y)
      {
        console.log("Right wrist is above nose")
      }
    
    if (pose.leftWrist.y<pose.nose.y)
      {
        console.log("Left wrist is above nose")
      }
    
    else
      {
        console.log("-")
      }
    
    
    /*
    
    for (let i = 0; i < pose.keypoints.length; i++) {
      let x = pose.keypoints[i].position.x;
      let y = pose.keypoints[i].position.y;
      fill(0,255,0);
      ellipse(x,y,16,16);
    }
    
    */
    
    
    /* 
    for (let i = 0; i < skeleton.length; i++) {
      let a = skeleton[i][0];
      let b = skeleton[i][1];
      strokeWeight(2);
      stroke(255);
      line(a.position.x, a.position.y,b.position.x,b.position.y);      
    }*/ 
    
    
    
    
    
    
  }
}
