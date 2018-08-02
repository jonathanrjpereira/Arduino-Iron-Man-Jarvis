#include <SD.h> //Used to Read Audio files from SD Card
//#define SD_ChipSelectPin 53 //Example uses hardware SS pin 53 on Mega2560
#define SD_ChipSelectPin 4  //Using digital pin 4 on arduino nano 328, can use other pins

#include <TMRpcm.h> //Used to Convert digital Audio files into analog signal
#include <SPI.h>

int led0=10, led1 = 2, led2 = 5, led3 = 6, led4 = 7;  //LED's connected for synchronised light effects
int i=0;

TMRpcm tmrpcm;  //Create an object for use in this sketch


void setup(){
  pinMode(led0,OUTPUT); //Connect LED's here
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  
  tmrpcm.speakerPin = 9; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc. Connect the Audio Amplifier(Speaker) to this pin.

  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {  //See if the card is present and can be initialized:
    Serial.println("SD fail");  
    return; //Don't do anything more if not
  }
  
  tmrpcm.quality(1);
  tmrpcm.setVolume(3);
  tmrpcm.play("access.wav"); //The sound file "access" will play each time the arduino powers up, or is reset
}


void loop(){  
led(0,0,0,0,0); //All LED's OFF
delay(500);

tmrpcm.play("calc.wav");  //Play 'calc' for desired duration. In this case 3500ms.
led(1,0,0,0,0); //led0 = ON; All other LED's = OFF;
delay(3500);

tmrpcm.play("1.wav");
led(0,1,0,0,0);
delay(1010);

tmrpcm.play("2.wav");
led(0,1,1,0,0);
delay(500);

tmrpcm.play("3.wav");
led(0,1,1,1,0);
delay(300);

tmrpcm.play("4.wav");
led(0,1,1,1,1);
delay(1010);
}


void led(int r,int g1,int g2,int g3,int g4) //Function used to easily toggle multiple LED's simultaneously
{
  digitalWrite(led0,r);
  digitalWrite(led1,g1);
  digitalWrite(led2,g2);
  digitalWrite(led3,g3);
  digitalWrite(led4,g4); 
}
