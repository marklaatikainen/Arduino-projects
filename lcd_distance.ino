#include <LiquidCrystal.h>         
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Digital pins to which you connect the LCD

const int trigPin = 9;
const int echoPin = 10;

long duration;
int distance;

void setup()
{
  lcd.begin(16,2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 /2;

  Serial.print("\nDistance: ");
  Serial.print(distance);
  Serial.print(" cm");

    
  lcd.setCursor(0,1);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance: ");
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print(" cm");
  delay(800);
}
