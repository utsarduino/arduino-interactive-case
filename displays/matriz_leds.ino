#include <MD_MAX72xx.h>
#include <SPI.h>

#define HARDWARE_TYPE MD_MAX72XX::FC16_HW // Prueba con FC16_HW o PAROLA_HW
#define MAX_DEVICES 4                     // Número de módulos 8x8
#define CS_PIN 53                         // Pin de CS (Chip Select) en Mega

MD_MAX72XX matrix = MD_MAX72XX(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup()
{
  matrix.begin();
  matrix.control(MD_MAX72XX::INTENSITY, 5);
  matrix.clear();
}

void loop()
{
  scrollText("HOLA MUNDO!");
  delay(1000);
}

// Función para desplazar texto de izquierda a derecha
void scrollText(const char *mensaje)
{
  uint8_t cBuf[8]; // buffer para un caracter
  uint8_t charWidth;

  while (*mensaje != '\0')
  {
    charWidth = matrix.getChar(*mensaje++, sizeof(cBuf) / sizeof(cBuf[0]), cBuf);
    matrix.transform(MD_MAX72XX::TSR);
    for (uint8_t i = 0; i < charWidth + 1; i++)
    {
      matrix.transform(MD_MAX72XX::TSL); // Shift Left
      if (i < charWidth)
      {
        matrix.setColumn(MAX_DEVICES - 1, cBuf[i]);
      }
      else
      {
        matrix.setColumn(MAX_DEVICES - 1, 0);
      }
      delay(80);
    }
  }
}
