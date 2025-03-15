# clay-bot


while (zDist_mm < 20.0){
    move(zDir,zStep,POS);
    zDist_mm += stepDistance;
  } 

// mark the floor 
  while (zDist_mm > 0.0){
    move(zDir,zStep,NEG);
    zDist_mm -= stepDistance;
  } 

   // move to top x left
  while (xDist_mm > xDesired){
    move(xDir,xStep,NEG);
    xDist_mm -= stepDistance;
  }

  // move up 
  while (yDist_mm < yDesired){
    move(yDir,yStep,POS);
    yDist_mm += stepDistance;
  }


   // move to right
  xDesired += 40.0;
  while (xDist_mm < xDesired){
    move(xDir,xStep,POS);
    xDist_mm += stepDistance;
  }

  // move down
  yDesired -= 40.0;
  while (yDist_mm > yDesired){
    move(yDir,yStep,NEG);
    yDist_mm -= stepDistance;
  }
