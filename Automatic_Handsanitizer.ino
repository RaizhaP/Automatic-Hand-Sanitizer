#include <Servo.h>
#define trigPin 3
#define echoPin 2
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
Servo servo1;
Servo servo2;
LiquidCrystal_I2C lcd(0x27, 16, 2);

int sound = 250;
void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo1.attach(4);
  servo1.write(0);
  servo2.attach(5);
  servo2.write(0);

  lcd.begin();
  lcd.backlight();
}

void loop() {
long duration, distance;
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
distance = (duration/2) / 29.1;

lcd.clear();
lcd.print("Taruh tangan di");
lcd.setCursor(0,1);
lcd.print("bawah sensor!");

  if (distance < 6) {
    Serial.print(distance);
    Serial.println(" ");
    
    lcd.clear();
    lcd.print("Tunggu beberapa");
    lcd.setCursor(0,1);  
    lcd.print("saat...");
    
    servo1.write(180);
    servo2.write(180);
    delay(2000);
 
    servo1.write(0);
    servo2.write(0);

    lcd.clear();
    lcd.print("Terima Kasih!");
    lcd.setCursor(0,1);
    delay(1500);
  }

   else {
    Serial.print(distance);
    Serial.println(" ");
  }
  delay(500);
}
