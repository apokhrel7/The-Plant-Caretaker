#include <dht.h>
#include <LiquidCrystal.h>
#include <Stepper.h>

#define DHT11_PIN 7
#define STEPPER_PIN_1 8
#define STEPPER_PIN_2 9
#define STEPPER_PIN_3 10
#define STEPPER_PIN_4 11

dht DHT;

LiquidCrystal lcd(13, 12, 5, 4, 3, 2);
Stepper myStepper(2048, 8,10,9,11);
int step_number = 0;


void setup(){
  lcd.begin(16, 2);
  Serial.begin(9600);
  myStepper.setSpeed(10);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  lcd.setCursor(0,0); 
  lcd.print("Temp: ");
  lcd.print(DHT.temperature);
  lcd.print((char)223);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Moisture: ");
  lcd.print(DHT.humidity);
  lcd.print("%");

  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
  Serial.print("Moisture = ");
  Serial.println(DHT.humidity);

  myStepper.step(2048);
  delay(1000);
  myStepper.step(-2048);
  delay(1000);
}
