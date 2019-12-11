#include <Wire.h>

#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2); // si no te sale con esta direccion  puedes usar (0x3f,16,2) || (0x27,16,2)  ||(0x20,16,2) 
//*************************************************** declarando como constante a distanceCm hace que salga en el display solo que solo pone cero, no anota la distancia que mide el sensor
const int EchoPin = 5;
const int TriggerPin = 6;
float distanceCm,duration;
//******************************************
void setup() {
//*******************************************
 Serial.begin(9600);
   pinMode(TriggerPin, OUTPUT);
   pinMode(EchoPin, INPUT);
   pinMode(2,OUTPUT);
   lcd.begin(0x27,16,2);
    
//********************************************
}

void loop() { 
 
  int distanceCm = ping(TriggerPin, EchoPin);
   Serial.print("Distancia: ");
   Serial.println(distanceCm);
   }
   int ping(int TriggerPin, int EchoPin) {
   long duration, distanceCm;
   
   
   digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
   delayMicroseconds(4);
   digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
   delayMicroseconds(10);
   digitalWrite(TriggerPin, LOW);
   duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos
   distanceCm =  int(0.017*duration);   //convertimos a distancia, en cm
   lcd.init();
   lcd.backlight();
   lcd.clear();
   lcd.setCursor(0,0);
   lcd.print("Distancia:");
   lcd.setCursor(0,1);
   lcd.print(distanceCm);
 

   
 
   
   
   
   //*********************************************

}
