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

int currentPos=2400,servoTargetPos=2400;
int currentPos2=2400,servoTargetPos2=2400;
int currentPos3=2400,servoTargetPos3=2400;
int currentPos4=2400,servoTargetPos4=2400;
int currentPos5=2400,servoTargetPos5=2400;

unsigned long lastTime;
unsigned long waktu;
unsigned long waktuTemp;
uint32_t sample_time;
#define servoTimeInterval 15000

void setup() {
  Serial.begin(9600);
//  Serial.setTimeout(1000000);

  gripperServo.attach(9); //jempol
  gripperServo2.attach(3);
  gripperServo3.attach(5);
  gripperServo4.attach(6);
  gripperServo5.attach(10);

  //setting awal posisi servo
  gripperServo.writeMicroseconds(currentPos);
  gripperServo2.writeMicroseconds(currentPos2);
  gripperServo3.writeMicroseconds(currentPos3);
  gripperServo4.writeMicroseconds(currentPos4);
  gripperServo5.writeMicroseconds(currentPos5);

}
//coba pulse
String rea;
bool trigger = false;

int coba=2400;
int coba2=2400;
int coba3=1700;
int coba4=1700;
int coba_last=1700;
void loop() {
  if (Serial.available()>0) {
    coba = Serial.parseInt();
    coba2 = Serial.parseInt();
    coba3 = Serial.parseInt();
    coba4 = Serial.parseInt();
    coba_last = Serial.parseInt();
//  rea = Serial.readString();
  }
// untuk menerima data dari program python dari laptop  
//  terimaDanKasih(rea);
  
// if coba ini untuk aktifkan 
  //servo melalui serial monitor
  if(coba!=0){
    servoTargetPos=coba;
  }
  if(coba2!=0){
    servoTargetPos2=coba2;
  }
  if(coba3!=0){
    servoTargetPos3=coba3;
  }
  if(coba4!=0){
    servoTargetPos4=coba4;
  }
  if(coba_last!=0){
    servoTargetPos5=coba_last;
  }
  
//checking waktu
  if (abs(servoTargetPos2 - currentPos2) >= 1200){
    waktuTemp = micros();
    trigger = true;
  }
  
//fungsi untuk menjalankan servo
gripperServoControl();
  
  //Serial.println(waktu);
  if (currentPos2 == servoTargetPos2 && trigger){
    waktu = micros();
    trigger = false;
    Serial.println(waktu-waktuTemp);
  }
//aktifkan bila perlu check data 
//checkingParsing();

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
        if(currentPos < servoTargetPos){
          if(abs(currentPos - servoTargetPos) >= 20) currentPos += 1;//perubahan pada posisi tertentu
          else if(abs(currentPos - servoTargetPos) > 4 && abs(currentPos - servoTargetPos) < 20 ) currentPos += 1;
          else {
              currentPos++;
          }
        }
    
        if(currentPos2 < servoTargetPos2){
          if(abs(currentPos2 - servoTargetPos2) >= 20) currentPos2+= 1;//perubahan pada posisi tertentu
          else if(abs(currentPos2 - servoTargetPos2) > 4 && abs(currentPos2 - servoTargetPos2) < 20 ) currentPos2 += 1;
          else {
              currentPos2++;
          }
        }
                
        if(currentPos3 < servoTargetPos3){
          if(abs(currentPos3 - servoTargetPos3) >= 20) currentPos3 += 1;//perubahan pada posisi tertentu
          else if(abs(currentPos3 - servoTargetPos3) > 4 && abs(currentPos3 - servoTargetPos3) < 20 ) currentPos3 += 1;
          else {
              currentPos3++;
          }
        }
           
        if(currentPos4 < servoTargetPos4){
          if(abs(currentPos4 - servoTargetPos4) >= 20) currentPos4 += 1;//perubahan pada posisi tertentu
          else if(abs(currentPos4 - servoTargetPos4) > 4 && abs(currentPos4 - servoTargetPos4) < 20 ) currentPos4 += 1;
          else {
              currentPos4++;
          }
        }
        
        if(currentPos5 < servoTargetPos5){
          if(abs(currentPos5 - servoTargetPos5) >= 20) currentPos5 += 1;//perubahan pada posisi tertentu
          else if(abs(currentPos5 - servoTargetPos5) > 4 && abs(currentPos5 - servoTargetPos5) < 20 ) currentPos5 += 1;
          else {
              currentPos5++;
          }
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
        if(currentPos > servoTargetPos){
          if(abs(currentPos - servoTargetPos) >= 20) currentPos -= 1;
          else if(abs(currentPos - servoTargetPos) > 4 && abs(currentPos - servoTargetPos) < 20 ) currentPos -= 1;
          else {
              currentPos--;  
          }
        }
        
        if(currentPos2 > servoTargetPos2){
          if(abs(currentPos2 - servoTargetPos2) >= 20) currentPos2 -= 1;
          else if(abs(currentPos2 - servoTargetPos2) > 4 && abs(currentPos2 - servoTargetPos2) < 20 ) currentPos2 -= 1;
          else {
              currentPos2--;  
          }
        }
        
        if(currentPos3 > servoTargetPos3){
          if(abs(currentPos3 - servoTargetPos3) >= 20) currentPos3 -= 1;
          else if(abs(currentPos3 - servoTargetPos3) > 4 && abs(currentPos3 - servoTargetPos3) < 20 ) currentPos3 -= 1;
          else {
              currentPos3--;  
          }
        }
        
        if(currentPos4 > servoTargetPos4){
          if(abs(currentPos4 - servoTargetPos4) >= 20) currentPos4 -= 1;
          else if(abs(currentPos4 - servoTargetPos4) > 4 && abs(currentPos4 - servoTargetPos4) < 20 ) currentPos4 -= 1;
          else {
              currentPos4--;  
          }
        }
       
        if(currentPos5 > servoTargetPos5){
          if(abs(currentPos5 - servoTargetPos5) >= 20) currentPos5 -= 1;
          else if(abs(currentPos5 - servoTargetPos5) > 4 && abs(currentPos5 - servoTargetPos5) < 20 ) currentPos5 -= 1;
          else {
              currentPos5--;  
          }
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

void terimaDanKasih (String dataSer){
  int a = 0;
  for (int i = 0; i < 5 ; i++){
    switch(i){
      case 0 :
      coba = dataSer.substring(a,a+4).toInt();
      break;
      case 1 : 
      coba2 = dataSer.substring(a,a+4).toInt();
      break;
      case 2:
      coba3 = dataSer.substring(a,a+4).toInt();
      break;
      case 3:
      coba4 = dataSer.substring(a,a+4).toInt();
      break;
      case 4:
      coba_last = dataSer.substring(a,a+4).toInt();
      break;
    }
    a += 4;
  }
  }

void checkingParsing(){
  Serial.print(currentPos);
  Serial.print(" nilai coba5 ");
  Serial.print(coba);
  Serial.print(" ");
  Serial.print(servoTargetPos);
  Serial.print(" ");
  Serial.print(servoTargetPos2);
  Serial.print(" ");
  Serial.print(servoTargetPos3);
  Serial.print(" ");
  Serial.print(servoTargetPos4);
  Serial.print(" ");
  Serial.println(servoTargetPos5);
}
