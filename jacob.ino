#include <Servo.h>

Servo ax1;
Servo ax2;
Servo ax3;
Servo ax4;
Servo ax5;
Servo ax6;

const int J1Y = A0; // analog pin connected to Y output
const int J1X = A1; // analog pin connected to X output
int J1X_pos = 160;
int J1Y_pos = 90;
int J1X_val;
int J1Y_val;

const int J2Y = A2; // analog pin connected to Y output
const int J2X = A3; // analog pin connected to X output
int J2X_pos = 95;
int J2Y_pos = 90;
int J2X_val;
int J2Y_val;

const int J3Y = A4; // analog pin connected to Y output
const int J3X = A5; // analog pin connected to X output
int J3X_pos = 90; // #2 from bottom
int J3Y_pos = 90; // #1 from bottom
int J3X_val;
int J3Y_val;

int ez_wake = 1;

// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  ax1.attach(1);
  ax2.attach(2);
  ax3.attach(3);
  ax4.attach(4);
  ax5.attach(5);
  ax6.attach(6);
}

void loop() {

/////////////////////////////////////JOYSTICK 1///////////////////////
J1X_val = analogRead(J1X);  
J1Y_val = analogRead(J1Y); 
ax1.write(J1X_pos);
ax2.write(J1Y_pos);


// For X-Axis Servo
  if (J1X_val < 300)
  {
    if (J1X_pos <= 45) 
    {
      // Do Nothing 
    } 
    else
    {
      J1X_pos = J1X_pos - 5;
      ax1.write(J1X_pos);
      delay(100); 
    } 
  } 
  
  if (J1X_val > 700)
  {
    if (J1X_pos >= 160)
    {
      // Do Nothing  
    }
    else
    {
      J1X_pos = J1X_pos + 5;
      ax1.write(J1X_pos);
      delay(100);
    }
  }
// For X-Axis Servo
  if (J1Y_val < 300)
  {
    if (J1Y_pos <= 0) 
    {
      // Do Nothing 
    } 
    else
    {
      J1Y_pos = J1Y_pos - 5;
      ax2.write(J1Y_pos);
      delay(100); 
    } 
  } 
  
  if (J1Y_val > 700)
  {
    if (J1Y_pos >= 180)
    {
      // Do Nothing  
    }
    else
    {
      J1Y_pos = J1Y_pos + 5;
      ax2.write(J1Y_pos);
      delay(100);
    }
  }
///////////////////////////////////////////////////////////////////////


/////////////////////////////////////JOYSTICK 2///////////////////////
J2X_val = analogRead(J2X);  
J2Y_val = analogRead(J2Y); 
ax3.write(J2X_pos);
ax4.write(J2Y_pos);

// For X-Axis Servo
  if (J2X_val < 300)
  {
    if (J2X_pos <= 0) 
    {
      // Do Nothing 
    } 
    else
    {
      J2X_pos = J2X_pos - 5;
      ax3.write(J2X_pos);
      delay(100); 
    } 
  } 
  
  if (J2X_val > 700)
  {
    if (J2X_pos >= 180)
    {
      // Do Nothing  
    }
    else
    {
      J2X_pos = J2X_pos + 5;
      ax3.write(J2X_pos);
      delay(100);
    }
  }
// For X-Axis Servo
  if (J2Y_val < 300)
  {
    if (J2Y_pos <= 0) 
    {
      // Do Nothing 
    } 
    else
    {
      J2Y_pos = J2Y_pos - 5;
      ax4.write(J2Y_pos);
      delay(100); 
    } 
  } 
  
  if (J2Y_val > 700)
  {
    if (J2Y_pos >= 180)
    {
      // Do Nothing  
    }
    else
    {
      J2Y_pos = J2Y_pos + 5;
      ax4.write(J2Y_pos);
      delay(100);
    }
  }
///////////////////////////////////////////////////////////////////////

/////////////////////////////////////JOYSTICK 3///////////////////////
J3X_val = analogRead(J3X);  
J3Y_val = analogRead(J3Y); 
ax5.write(J3X_pos);
ax6.write(J3Y_pos);

// For X-Axis Servo
  if (J3X_val < 300)
  {
    if (J3X_pos <= 0) 
    {
      // Do Nothing 
    } 
    else
    {
      J3X_pos = J3X_pos - 5;
      ax5.write(J3X_pos);
      delay(100); 
    } 
  } 
  
  if (J3X_val > 700)
  {
    if (J3X_pos >= 180)
    {
      // Do Nothing  
    }
    else
    {
      J3X_pos = J3X_pos + 5;
      ax5.write(J3X_pos);
      delay(100);
    }
  }
// For X-Axis Servo
  if (J3Y_val < 300)
  {
    if (J3Y_pos <= 0) 
    {
      // Do Nothing 
    } 
    else
    {
      J3Y_pos = J3Y_pos - 5;
      ax6.write(J3Y_pos);
      delay(100); 
    } 
  } 
  
  if (J3Y_val > 700)
  {
    if (J3Y_pos >= 180)
    {
      // Do Nothing  
    }
    else
    {
      J3Y_pos = J3Y_pos + 5;
      ax6.write(J3Y_pos);
      delay(100);
    }
  }
///////////////////////////////////////////////////////////////////////
}
