/*
 * 
 * All the resources for this project: https://randomnerdtutorials.com/
 * Modified by Rui Santos
 * 
 * Created by FILIPEFLOP
 * 
 */


using namespace std; 
#include <SPI.h>
#include <MFRC522.h>
#include "SevSeg.h"

#define LED_G 25 //define green LED pin
#define LED_R 24 //define red LED
#define LED_B 27 //define blue LED
#define BUZZER 22 //buzzer pin
#define SS_PIN 53
#define RST_PIN 5
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
MFRC522::MIFARE_Key key; 
SevSeg myDisplay;
char message[2];
char solde[2]={'-','-'};
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
int displayType = COMMON_CATHODE;
  int digit1 = 3; 
  int digit2 = 2;
  int digit3 = 0;
  int digit4 = 0;
  int segA = 6; 
  int segB = 7; 
  int segC = 8; 
  int segD = 9; 
  int segE = 10; 
  int segF = 11; 
  int segG = 12; 
  int segDP = 13; 
  int numberOfDigits = 2;
myDisplay.Begin(displayType, numberOfDigits, digit1, digit2, digit3, digit4, segA, segB, segC, segD, segE, segF, segG, segDP);
myDisplay.SetBrightness(100); //Set the display to 100% brightness level

}






void loop() 
{
 
    myDisplay.DisplayString(solde, 3);
  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
  content=content.substring(1);
    char arr[content.length()+1]; 
 for (int x = 0; x < sizeof(arr); x++) { 
        arr[x] = content[x]; } 
   
  digitalWrite(LED_B, HIGH);
  delay(1000);
  digitalWrite(LED_B, LOW);
  Serial.write(arr);
delay(1000);
  if (Serial.available()>0) {

    while (Serial.available()>0)
    {   



  

      
       char message[2];
       unsigned int message_pos = 0;

      char inByte1 = Serial.read();
char inByte2 = Serial.read();
     
     

      solde[0]=inByte1;
      solde[1]=inByte2;
   
      
  
    }



    
  
  if ( solde[0] != '-' ) 
  {
      digitalWrite(LED_G, HIGH);
      tone(BUZZER, 500);
      delay(300);
      noTone(BUZZER);
      digitalWrite(LED_G, LOW);
 

 }
 
 else   {
  
      digitalWrite(LED_R, HIGH);
      tone(BUZZER, 300);
      delay(1000);
      digitalWrite(LED_R, LOW);
      noTone(BUZZER);
    
  
  }
  
  }
     mfrc522.PICC_HaltA();

  
 mfrc522.PCD_StopCrypto1();
} 
