#include <Servo.h>

Servo myServo;
int potPin = A0; // Pin del potenciómetro (opcional)
int val = 0;

void setup()
{
    myServo.attach(9); // Pin de señal del servo
}

void loop()
{
    val = analogRead(potPin);        // Lee el potenciómetro
    val = map(val, 0, 1023, 0, 180); // Mapea a grados
    myServo.write(val);              // Mueve el servo
    delay(15);
}