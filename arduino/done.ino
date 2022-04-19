
int digitalPin = 13;
int analogPin = A0;  // KY-026 analog interface
int digitalVal;      // digital readings
int analogVal;       //analog readings
char data;

void setup() {
  pinMode(digitalPin, OUTPUT);
  digitalWrite(digitalPin, LOW);
  Serial.begin(9600);
}

void loop() {

  // Read the analog interface
  analogVal = analogRead(analogPin);
  
 if(analogVal <= 20) {   // le capteur KY-026 détecte un feu
    digitalWrite(digitalPin, HIGH); 
     Serial.write('5');}



  if (Serial.available()){     
    //Si un message a été reçu  faire ceci
     data=Serial.read();  

  if (data == '0')  //si le caractère lu est égale à 1
    {
      digitalWrite(digitalPin, LOW);  // LED s'éteint et le buzzer s'arrête de sonner
       
  }
  } 
  }