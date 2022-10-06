#include <Arduino.h>
//#include <AFMotro.h>
#include <Servo.h>
#define MOTOR_PWM_PIN D1
#define MOTOR_DIR_PIN D3

// AF_DCMotro motor(1);
Servo servol;

int LED = 13;
// init the sesnor
int isFlamePin = 7;
int isFlame = HIGH;

void setup()
{
  pinMode(LED, OUTPUT);
  pinMode(isFlamePin, INPUT);
  Serial.begin(9600);

  pinMode(MOTOR_PWM_PIN, OUTPUT);
  pinMode(MOTOR_DIR_PIN, OUTPUT);

  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{

  // Here is The flame Sensor
  isFlame = digitalRead(isFlamePin); // Read the data givin by the flame
  if (isFlame == LOW)
  {
    Serial.println("FLAME, it is bruning")
        digitalWrite(LED, HIGH); // Led on, or pump
  }
  else
  {
    Serial.println("No Flames");
    digitalWrite(LED, LOW); // led of, pump of
  }

  //___________________________________________//
  // This is the engin
  // MOTOR_PWM_PIN er til fart
  // MOTOR_DIR_PIN er til frem eller tilbage
  // speed  går fra 0-1023
  analogWrite(MOTOR_PWM_PIN, 1000);
  // Low er frem eller tilbage og high er det modsatte af low
  digitalWrite(MOTOR_DIR_PIN, LOW);
  delay(1000);
  analogWrite(MOTOR_PWM_PIN, 0);
  digitalWrite(MOTOR_DIR_PIN, LOW);
  delay(1000);
  analogWrite(MOTOR_PWM_PIN, 500);
  digitalWrite(MOTOR_DIR_PIN, HIGH);
  delay(1000);

  // put your main code here, to run repeatedly:
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("LED is on");

  delay(500);

  digitalWrite(LED_BUILTIN, LOW);
  Serial.println("LED is off");

  delay(500);
}
