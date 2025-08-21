// Pines de conexión
const int pinPIR = 2;  // Pin de salida del sensor PIR
const int pinRele = 3; // Pin de control del relé

void setup()
{
    pinMode(pinPIR, INPUT);     // PIR como entrada
    pinMode(pinRele, OUTPUT);   // Relé como salida
    digitalWrite(pinRele, LOW); // Relé apagado al inicio
    Serial.begin(9600);
}

void loop()
{
    int estadoPIR = digitalRead(pinPIR); // Leer estado del PIR

    if (estadoPIR == HIGH)
    {
        digitalWrite(pinRele, HIGH); // Activa el relé
        Serial.println("Movimiento detectado -> Relé encendido");
    }
    else
    {
        digitalWrite(pinRele, LOW); // Apaga el relé
        Serial.println("Sin movimiento -> Relé apagado");
    }

    delay(200); // Pequeño retardo para evitar lecturas inestables
}
