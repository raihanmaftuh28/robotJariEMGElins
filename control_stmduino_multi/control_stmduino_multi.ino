//Servo ASME 04A 260kg Pulse Width 500-2500 dengan degree 0-270

// posisi ngambil = 2150
// posisi lepas panah 750

/*
 * servo untuk robot jari 1 dof itu range 1700-2500max 1700buka 2500 tutup
 * CCW untuk naik
 * CW untuk turun
 * Jempol dari tutup ke buka 1600 - 2400 posisi defalt 1700
 * Telunjuk dari tutup ke buka 800 - 2200 posisi default di 1700
 * Tengah dari tutup ke buka 600 - 2200 posisi default di 1700
 * Manis dari tutup ke buka 550 - 1900 posisi default di 1700
 * Kelingking dari tutup ke buka 600 - 1800 posisi default di 1700
 */

#include<Servo.h>

Servo gripperServo;
Servo gripperServo2;
Servo gripperServo3;
Servo gripperServo4;
Servo gripperServo5;

int currentPos=1600,servoTargetPos=1600;
int currentPos2=2200,servoTargetPos2=2200;
int currentPos3=2200,servoTargetPos3=2200;
int currentPos4=1900,servoTargetPos4=1900;
int currentPos5=1800,servoTargetPos5=1800;

unsigned long lastTime;
uint32_t sample_time;
#define servoTimeInterval 15000

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
//  Serial.setTimeout(1000000);
  gripperServo.attach(PA0); //jempol
  gripperServo2.attach(PA1);
  gripperServo3.attach(PA2);
  gripperServo4.attach(PA3);
  gripperServo5.attach(PA5);

  gripperServo.writeMicroseconds(currentPos);
  gripperServo2.writeMicroseconds(currentPos2);
  gripperServo3.writeMicroseconds(currentPos3);
  gripperServo4.writeMicroseconds(currentPos4);
  gripperServo5.writeMicroseconds(currentPos5);

  //Serial.println("Posisi awal di 1250");
}
//coba pulse
int coba=1700;
int coba2=1700;
int coba3=1700;
int coba4=1700;
int coba5=1700;
void loop() {
//  // put your main code here, to run repeatedly:
////  servoTargetPos = 670;
// 
////
  if (Serial.available()) {
    coba = Serial.parseInt();
    coba2 = Serial.parseInt();
    coba3 = Serial.parseInt();
    coba4 = Serial.parseInt();
    coba5 = Serial.parseInt();
  }
  if(coba!=0){
    servoTargetPos=coba;
  }
//////  }
  if(coba2!=0){
    servoTargetPos2=coba2;
  }
  if(coba3!=0){
    servoTargetPos3=coba3;
  }
  if(coba4!=0){
    servoTargetPos4=coba4;
  }
  if(coba5!=0){
    servoTargetPos5=coba5;
  }

//if (currentPos <= 1600) servoTargetPos = 2500;
//else if (currentPos >=2500) servoTargetPos = 1600;
//if (currentPos2 <= 1700) servoTargetPos2 = 2500;
//else if (currentPos2 >=2500) servoTargetPos2 = 1700;
//if (currentPos3 <= 1700) servoTargetPos3 = 2500;
//else if (currentPos3 >=2500) servoTargetPos3 = 1700;
//if (currentPos4 <= 1700) servoTargetPos4 = 2500;
//else if (currentPos4 >=2500) servoTargetPos4 = 1700;
//if (currentPos5 <= 1700) servoTargetPos5 = 2500;
//else if (currentPos5 >=2500) servoTargetPos5 = 1700;
gripperServoControl();

//  b = map(currentPos, 0, 270, 500, 2500);
//  gripperServo.writeMicroseconds(b);
  

  
 
//  sudut=gripperServo.readMicroseconds();
//  Serial.print(currentPos);
//  Serial.print(" ");
//  Serial.print(sudut);
//  Serial.print(" ");
//  Serial.println(b);
//  
}


void gripperServoControl()
{
  if((currentPos != servoTargetPos) || (currentPos2 != servoTargetPos2) || (currentPos3 != servoTargetPos3) || (currentPos4 != servoTargetPos4) || (currentPos5 != servoTargetPos5) )
  {
    
    if(currentPos < servoTargetPos || currentPos2 < servoTargetPos2 || currentPos3 < servoTargetPos3 || currentPos4 < servoTargetPos4 
    || currentPos5 < servoTargetPos5)
    {
      
      if((micros() - lastTime) > servoTimeInterval)
      {
        if(abs(currentPos - servoTargetPos) >= 20) currentPos += 24;//perubahan pada posisi tertentu
        else if(abs(currentPos - servoTargetPos) > 4 && abs(currentPos - servoTargetPos) < 20 ) currentPos += 3;
        else {
          currentPos++;
        }
        if(abs(currentPos2 - servoTargetPos2) >= 20) currentPos2+= 24;//perubahan pada posisi tertentu
        else if(abs(currentPos2 - servoTargetPos2) > 4 && abs(currentPos2 - servoTargetPos2) < 20 ) currentPos2 += 3;
        else {
          currentPos2++;
        }
        if(abs(currentPos3 - servoTargetPos3) >= 20) currentPos3 += 24;//perubahan pada posisi tertentu
        else if(abs(currentPos3 - servoTargetPos3) > 4 && abs(currentPos3 - servoTargetPos3) < 20 ) currentPos3 += 3;
        else {
          currentPos3++;
        }
        if(abs(currentPos4 - servoTargetPos4) >= 20) currentPos4 += 24;//perubahan pada posisi tertentu
        else if(abs(currentPos4 - servoTargetPos4) > 4 && abs(currentPos4 - servoTargetPos4) < 20 ) currentPos4 += 3;
        else {
          currentPos4++;
        }
        if(abs(currentPos5 - servoTargetPos5) >= 20) currentPos5 += 24;//perubahan pada posisi tertentu
        else if(abs(currentPos5 - servoTargetPos5) > 4 && abs(currentPos5 - servoTargetPos5) < 20 ) currentPos5 += 3;
        else {
          currentPos5++;
        }
//
      lastTime = micros();
      }
    }
    else if(currentPos > servoTargetPos || currentPos2 > servoTargetPos2 || currentPos3 > servoTargetPos3 || currentPos4 > servoTargetPos4 
    || currentPos5 > servoTargetPos5)
    {
      if((micros()-lastTime) > servoTimeInterval)
      {
        if(abs(currentPos - servoTargetPos) >= 20) currentPos -= 24;
        else if(abs(currentPos - servoTargetPos) > 4 && abs(currentPos - servoTargetPos) < 20 ) currentPos -= 3;
        else {
          currentPos--;  
        }
        if(abs(currentPos2 - servoTargetPos2) >= 20) currentPos2 -= 24;
        else if(abs(currentPos2 - servoTargetPos2) > 4 && abs(currentPos2 - servoTargetPos2) < 20 ) currentPos2 -= 3;
        else {
          currentPos2--;  
        }
        if(abs(currentPos3 - servoTargetPos3) >= 20) currentPos3 -= 24;
        else if(abs(currentPos3 - servoTargetPos3) > 4 && abs(currentPos3 - servoTargetPos3) < 20 ) currentPos3 -= 3;
        else {
          currentPos3--;  
        }
        if(abs(currentPos4 - servoTargetPos4) >= 20) currentPos4 -= 24;
        else if(abs(currentPos4 - servoTargetPos4) > 4 && abs(currentPos4 - servoTargetPos4) < 20 ) currentPos4 -= 3;
        else {
          currentPos4--;  
        }
        if(abs(currentPos5 - servoTargetPos5) >= 20) currentPos5 -= 24;
        else if(abs(currentPos5 - servoTargetPos5) > 4 && abs(currentPos5 - servoTargetPos5) < 20 ) currentPos5 -= 3;
        else {
          currentPos5--;  
        }
        
        lastTime = micros();
      }
    }
  }
  gripperServo.writeMicroseconds(currentPos);
  gripperServo2.writeMicroseconds(currentPos2);
  gripperServo3.writeMicroseconds(currentPos3);
  gripperServo4.writeMicroseconds(currentPos4);
  gripperServo5.writeMicroseconds(currentPos5);
}
