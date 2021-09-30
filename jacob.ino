
#include <SoftwareSerial.h>
#include <VoiceRecognitionV3.h>
#include <Servo.h>

/**
  Connection
  Arduino    VoiceRecognitionModule
   2   ------->     TX
   3   ------->     RX
*/
VR myVR(12, 13);   // 12:RX 13:TX, you can choose your favourite pins.

// servos
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



uint8_t records[7]; // save record
uint8_t buf[64];

#define onRecord    (0)
#define offRecord   (1)

/**
  @brief   Print signature, if the character is invisible,
           print hexible value instead.
  @param   buf     --> command length
           len     --> number of parameters
*/
void printSignature(uint8_t *buf, int len)
{
  int i;
  for (i = 0; i < len; i++) {
    if (buf[i] > 0x19 && buf[i] < 0x7F) {
      Serial.write(buf[i]);
    }
    else {
      Serial.print("[");
      Serial.print(buf[i], HEX);
      Serial.print("]");
    }
  }
}

/**
  @brief   Print signature, if the character is invisible,
           print hexible value instead.
  @param   buf  -->  VR module return value when voice is recognized.
             buf[0]  -->  Group mode(FF: None Group, 0x8n: User, 0x0n:System
             buf[1]  -->  number of record which is recognized.
             buf[2]  -->  Recognizer index(position) value of the recognized record.
             buf[3]  -->  Signature length
             buf[4]~buf[n] --> Signature
*/
void printVR(uint8_t *buf)
{
  Serial.println("VR Index\tGroup\tRecordNum\tSignature");

  Serial.print(buf[2], DEC);
  Serial.print("\t\t");

  if (buf[0] == 0xFF) {
    Serial.print("NONE");
  }
  else if (buf[0] & 0x80) {
    Serial.print("UG ");
    Serial.print(buf[0] & (~0x80), DEC);
  }
  else {
    Serial.print("SG ");
    Serial.print(buf[0], DEC);
  }
  Serial.print("\t");

  Serial.print(buf[1], DEC);
  Serial.print("\t\t");
  if (buf[3] > 0) {
    printSignature(buf + 4, buf[3]);
  }
  else {
    Serial.print("NONE");
  }
  Serial.println("\r\n");
}

void setup()
{
  ax1.attach(2);
  ax2.attach(3);
  ax3.attach(4);
  ax4.attach(5); // central pivot
  ax5.attach(6);
  ax6.attach(7);



  /** initialize */
  myVR.begin(9600);

  Serial.begin(115200);
  Serial.println("Elechouse Voice Recognition V3 Module\r\nControl LED sample");

  if (myVR.clear() == 0) {
    Serial.println("Recognizer cleared.");
  } else {
    Serial.println("Not find VoiceRecognitionModule.");
    Serial.println("Please check connection and restart Arduino.");
    while (1);
  }

  if (myVR.load((uint8_t)onRecord) >= 0) {
    Serial.println("onRecord loaded");
  }

  if (myVR.load((uint8_t)offRecord) >= 0) {
    Serial.println("offRecord loaded");
  }
}

void loop()
{
  int ret;
  ret = myVR.recognize(buf, 50);
  if (ret > 0) {
    switch (buf[1]) {
      case onRecord:
        /** turn on LED */
        // digitalWrite(led, HIGH);
        for (int i = 0; i <= 10; i++) {
          ax3.write(90);
          delay(1000);
          ax3.write(60);
          delay(1000);
        }
      case offRecord:
        /** turn off LED*/
        // digitalWrite(led, LOW);
        break;
      default:
        Serial.println("Record function undefined");
        break;
    }
    /** voice recognized */
    printVR(buf);
  }

/////////////////////////////////////JOYSTICK 1///////////////////////
J1X_val = analogRead(J1X);  
J1Y_val = analogRead(J1Y); 
ax1.write(J1X_pos);
ax2.write(J1Y_pos);


// For X-Axis Servo
  if (J1X_val < 300)
  {
    if (J1X_pos <= 55) 
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
