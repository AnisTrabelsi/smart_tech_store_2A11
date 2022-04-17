
#include <LiquidCrystal.h>
#include <Keypad.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>


const byte rows = 4; // number of the keypad's rows and columns
const byte cols = 4;
int etat = 0;
char keyMap[rows][cols] = { // define the cymbols on the buttons of the keypad

    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}};

byte rowPins[rows] = {11, 10, 9, 8}; // pins of the keypad²²²
byte colPins[cols] = {7, 6, 5, 4};
int k = 0;
char arr[6];
char data,nom;
String tab;
int buzz = 13; // buzzer
Keypad keypad = Keypad(makeKeymap(keyMap), rowPins, colPins, rows, cols);

LiquidCrystal_I2C lcd(0x27, 16, 2);
void setup()
{
  lcd.init();
  lcd.backlight();
  pinMode(buzz, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  char whichKey = keypad.getKey();
  if (etat == 0)
  {
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("***welcome***");
    lcd.setCursor(1, 1);
    lcd.print("**write code**");
  }
  if (Serial.available())
  {
    etat = 1;
    k = 0;
    data = Serial.read();
    tab=data;
    tab+=Serial.readString();
    lcd.clear();
    lcd.setCursor(0, 0);
    //lcd.print(data);
    if (data == '0')
    {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("code invalide");
      tone(buzz, 261);
      delay(1000);
      noTone(buzz);
      lcd.clear();
      etat = 0;
      k = 0;
    }
    if(data != '0')
    {
      //tab=Serial.readString();
      int j=0;
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("****bonjour****");
       lcd.setCursor(0, 1);
       lcd.print(tab);
      tone(buzz, 3000, 500);
      delay(1000);
      noTone(buzz);
     for(int j=0;j<5;j++)
    arr[j] = "";
      delay(3000);
      lcd.clear();
      etat = 0;
    
      k = 0;
    }
  }

  if (whichKey == '*' || whichKey == '#' || whichKey == 'A' || // define invalid keys
      whichKey == 'B' || whichKey == 'C' || whichKey == 'D')
  {
    etat = 0;
    for(int j=0;j<5;j++)
    arr[j] = "";
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("  Invalid Key!");
    delay(1000);
    lcd.clear();
    k = 0;
  }
  else if (whichKey == '0' || whichKey == '1' || whichKey == '2' || whichKey == '3' || whichKey == '4' || whichKey == '5' || whichKey == '6' || whichKey == '7' || whichKey == '8' || whichKey == '9')
  {
    etat = 1;
    tone(buzz, 1000);
    delay(200);
    noTone(buzz);
    arr[k] = whichKey;
    k++;
  }
  if(k==5){
    Serial.write(arr);
  k=0;
  for(int j=0;j<5;j++)
    {
    arr[j]= "";
    }
}
}
