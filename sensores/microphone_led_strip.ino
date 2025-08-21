#include <Adafruit_NeoPixel.h>

#define PIN_LED 6   // Pin de datos de la tira
#define NUM_LEDS 16 // Número total de LEDs
#define MIC_PIN A0  // Pin de entrada del micrófono

Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN_LED, NEO_GRB + NEO_KHZ800);

int nivelSuavizado = 0; // Para suavizar el movimiento
int caida = 0;          // Nivel de caída visual

void setup()
{
  strip.begin();
  strip.setBrightness(10);
  strip.show();
}

void loop()
{
  int lectura = analogRead(MIC_PIN);              // Lee el micrófono
  int nivel = map(lectura, 0, 1023, 0, NUM_LEDS); // Mapea a número de LEDs

  // Hacer que se iluminen más LEDs para que se vea más
  nivel = nivel * 2;
  if (nivel > NUM_LEDS)
    nivel = NUM_LEDS;

  // Suavizado (hace que no parpadee tan brusco)
  if (nivel > nivelSuavizado)
  {
    nivelSuavizado = nivel;
  }
  else
  {
    nivelSuavizado--;
    if (nivelSuavizado < 0)
      nivelSuavizado = 0;
  }

  mostrarNivel(nivelSuavizado);
  delay(25); // Ajusta la suavidad (más bajo = más rápido)
}

void mostrarNivel(int nivel)
{
  for (int i = 0; i < NUM_LEDS; i++)
  {
    if (i < nivel)
    {
      if (i < NUM_LEDS / 3)
      {
        strip.setPixelColor(i, strip.Color(0, 255, 0)); // Verde
      }
      else if (i < (2 * NUM_LEDS) / 3)
      {
        strip.setPixelColor(i, strip.Color(255, 100, 0)); // Naranja
      }
      else
      {
        strip.setPixelColor(i, strip.Color(255, 0, 0)); // Rojo
      }
    }
    else
    {
      strip.setPixelColor(i, 0); // Apagado
    }
  }
  strip.show();
}
