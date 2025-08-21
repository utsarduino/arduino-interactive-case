# :bulb: Sensor PIR y Relé

Este documento detalla las librerías a usar, conexiones y ejecución de proyectos en los que se usa un **sensor PIR** y un **módulo relé** con Arduino.

Proyectos:

1. Activación de un relé a partir de la detección de movimiento.

Esta carpeta contiene ejemplos prácticos para la conexión y modificación de Script y ejecución del proyecto.

---

## :open_file_folder: Archivos incluidos

| Archivo             | Descripción                                             |
| ------------------- | ------------------------------------------------------- |
| sensor_pir_rele.ino | Proyecto de control de relé con detección de movimiento |

---

## :wrench: Requisitos de Hardware

- Arduino MEGA (también puede usarse UNO o Nano).
- Sensor PIR Keyestudio.
- Módulo relé Keyestudio (1 canal).
- Cables Dupont.
- Protoboard (opcional).
- Fuente de alimentación (5V del Arduino).

---

## 1. :inbox_tray: Instalar Arduino IDE

Como primer paso tener instalado el IDE de Arduino para poder compilar el código al Arduino MEGA.  
Si no cuenta con este software podrá descargarlo siguiendo los pasos aquí mencionados:

1. Ve al sitio oficial: [https://www.arduino.cc/en/software](https://www.arduino.cc/en/software)
2. Descarga la versión para tu sistema operativo (Windows, macOS o Linux).
3. Instala Arduino IDE siguiendo las instrucciones del instalador.

## ![Arduino IDE](assets/arduinoIDE.png)

---

## 2. :ballot_box_with_check: Instalar las librerías requeridas

Este proyecto **no requiere librerías externas**, se utiliza únicamente la librería estándar incluida en Arduino IDE (`Arduino.h`).

---

## 3. Conectar la placa Arduino

1. Conecta tu placa Arduino al computador usando un cable USB.
2. Espera a que el sistema reconozca el dispositivo.

---

## 4. Configurar Arduino IDE

1. Ve a **Herramientas > Placa** y selecciona el modelo de tu placa (Arduino Mega o la que uses).
2. Ve a **Herramientas > Puerto** y selecciona el puerto COM correspondiente.

---

# :checkered_flag: Proyecto

## 1. Proyecto de control de relé con sensor PIR

Este proyecto permite activar un **relé** al detectar movimiento mediante el **sensor PIR**.  
Cuando el PIR detecta movimiento, el relé se activa (encendiendo la carga conectada).  
Si no hay movimiento, el relé se apaga.

- Sensor PIR
  | Pin PIR | Pin Arduino MEGA |
  |---------|------------------|
  | VCC | 5V |
  | GND | GND |
  | OUT | 2 |

- Relé
  | Pin Relé | Pin Arduino MEGA |
  |----------|------------------|
  | VCC | 5V |
  | GND | GND |
  | IN | 3 |

---

## 2. Abrir y cargar el código

1. Ve a **Archivo > Abrir** y selecciona `sensor_pir_rele.ino`.
2. Haz clic en **Verificar** (✓) para compilar el código.
3. Haz clic en **Subir** (→) para cargar el código a la placa.

---

## 3. Probar el sistema

- Observa el monitor serial para verificar los mensajes de estado.
- Acércate o mueve una mano frente al **sensor PIR**.
- Verifica que el **relé se active** cuando hay movimiento.
- Comprueba que el **relé se apaga** cuando no hay movimiento.

---
