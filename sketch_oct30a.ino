
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// LCD configuration
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Component pin connections
const int trigPin = 9;
const int echoPin = 10;
const int redLED = 11;
const int greenLED = 12;
const int buzzer = 8;

// Tank height in centimetres
const float tankHeight = 30.0;

void setup()
{
  // Set pin modes
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(redLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Start LCD
  lcd.init();
  lcd.backlight();

  // Start Serial Monitor
  Serial.begin(9600);

  // Welcome message
  lcd.setCursor(0, 0);
  lcd.print("SMART WATER");
  lcd.setCursor(0, 1);
  lcd.print("TANK MONITOR");
  delay(2000);
  lcd.clear();
}

void loop()
{
  // Generate ultrasonic trigger pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  // Read echo time
  long duration = pulseIn(echoPin, HIGH, 30000);

  // Check sensor reading
  if (duration == 0)
  {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("SENSOR ERROR");

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzer, LOW);

    Serial.println("Sensor Error");
    delay(1000);
    return;
  }

  // Calculate distance
  float distance = duration * 0.0343 / 2;

  // Calculate water level
  float waterLevel = tankHeight - distance;

  // Limit water level
  waterLevel = constrain(waterLevel, 0, tankHeight);

  // Calculate percentage
  int percentage = (waterLevel / tankHeight) * 100;

  // Display water level on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Water Level:");

  lcd.setCursor(0, 1);
  lcd.print(percentage);
  lcd.print("% ");

  // LOW WATER CONDITION
  if (percentage < 20)
  {
    lcd.print("LOW");

    digitalWrite(redLED, HIGH);
    digitalWrite(greenLED, LOW);
    digitalWrite(buzzer, HIGH);
  }

  // FULL TANK CONDITION
  else if (percentage >= 80)
  {
    lcd.print("FULL");

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(buzzer, HIGH);
  }

  // NORMAL WATER CONDITION
  else
  {
    lcd.print("NORMAL");

    digitalWrite(redLED, LOW);
    digitalWrite(greenLED, HIGH);
    digitalWrite(buzzer, LOW);
  }

  // Display readings in Serial Monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm");

  Serial.print(" | Water Level: ");
  Serial.print(percentage);
  Serial.println("%");

  delay(1000);
}

