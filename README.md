# 🧠 Sistema de Detección de Monóxido de Carbono (CO)
### Proyecto Integrador de Informática 2 – 2025 / 2R2 / Grupo 0

**Autor:** Contreras Martín 'jahcr1'  
**Email:** martin.contreras.dev@gmail.com  
**Repositorio:** [https://github.com/jahcr1/detectorCO]

---

## 📖 Descripción general

El **Sistema de Detección de Monóxido de Carbono (CO)** es un proyecto de electrónica y programación orientado a la **prevención de intoxicaciones por gases tóxicos** en entornos domésticos e industriales.  
Utiliza un sensor **MQ-9** conectado a un **Arduino Uno**, el cual realiza la medición continua de la concentración de CO en el ambiente.  
Los datos se envían por puerto serie a una aplicación en **Linux**, que permite visualizar las mediciones en tiempo real y generar alertas cuando los valores superan los límites seguros.

---

## ⚙️ Características principales

- Detección continua de niveles de **Monóxido de Carbono (CO)**  
- Sensor **MQ-9** con salida analógica/digital  
- Procesamiento de señal mediante **Arduino UNO (ATmega328p)**  
- Comunicación **serial USB (9600 bps)** con una aplicación en C++  
- Posible integración futura con:
  - Pantalla **LCD/LED**
  - Alarma sonora/luminosa
  - Módulo **WiFi ESP8266** o **Bluetooth HC-05** para notificaciones
  - Alimentación Independiente mediante un transformador 220v AC / 5v DC

---

## 🧰 Componentes utilizados

| Componente | Descripción | Imagen |
|-------------|-------------|--------|
| **Arduino UNO R3** | Microcontrolador ATmega328P encargado del procesamiento y la comunicación serial | ![Arduino UNO](/docs/arduino_uno.jpg) |
| **Sensor MQ-9** | Sensor de gas para CO y gases combustibles, basado en óxido de estaño (SnO₂) | ![MQ-9](/docs/mq9_sensor.jpg) |
| **Protoboard** | Protoboard convencional para conexiones de componentes electronicos | ![Protoboard](/docs/protoboard.jpg) |
| **Zumbador (Buzzer)** | Activa una alarma sonora ante niveles peligrosos | ![Buzzer](/docs/buzzer.jpg) |
| **LED Rojo/Verde** | Indica el estado del sistema (seguro / peligro) | ![LEDs](/docs/leds.jpg) |
| **Jumpers y resistencias** | Interconexión de los componentes | ![Jumpers](/docs/jumpers.jpg) |

> 🖼️ Todas las imágenes se encuentran dentro de la carpeta `/docs/`.

---

## 🧩 Estructura del repositorio

```bash
detectorCO/
├── docs/                  # Documentación y recursos
│   └── Trabajo de Detector de CO.pdf
├── firmware/              # Código Arduino (microcontrolador)
│   ├── detector.elf
│   ├── detector.hex
│   ├── Makefile           # Archivo Makefile para compilación automatizada
│   └── src/
│       └── main.cpp
├── software/              # Código en C++ (PC / Linux)
│   ├── read_serial
│   └── src/
│       └── read_serial.cpp
└── README.md
```
---

## 🧠 Dependencias y entorno de desarrollo

### 🔹 En Ubuntu 24.04 LTS

Instalá los siguientes paquetes esenciales:

```bash
sudo apt update
sudo apt install -y build-essential git make gcc-avr g++-avr binutils-avr avr-libc g++ screen
sudo apt install -y arduino-core avrdude
```

---

##  ⚙️  Configuración basica del entorno

1. Conceder permisos de puerto serie:
```bash
sudo usermod -aG dialout $USER
```
 >	Luego cerrar sesión o reinicia para aplicar cambios
 
 2. Verificar detección del Arduino: 
```bash
lsusb | grep -i arduino
ls /dev/ttyACM*
```
 >	Esto devuelve los datos necesarios del arduino conectado y deberia mostrar el puerto /dev/ttyACM0 ó /dev/ttyUSB0
 
 3. Si usas VirtualBox:
 >	Activá el controlador USB 2.0 (EHCI)
 >	Agregá un filtro USB con el ID 2341:0043 (Arduino UNO R3)
 
 4. Instalación del proyecto desde Github
```bash
git clone git@github.com:jahcr1/detectorCO.git
cd detectorCO
```
 
---
 
##	🔧 Compilación

🔹Firmware (Arduino)
Podés compilar y cargar el firmware desde la linea de comandos:
```bash
cd firmware
make
```
 >	Si el **Makefile** está configurado, generará los archivos **.elf** y **.hex** automaticamente.
 >	También podes abrir **main.cpp** en el IDE de arduino y cargarlo manualmente.
 
 🔹Software en Linux
```bash
cd software
make
```
 >	Esto generará el ejecutable **read_serial**
 
---
 
##	🚀  Ejecución

1. Conectá el Arduino y verificá el puerto:
```bash
ls /dev/ttyACM*
```
2. Ejecutá el lector en tiempo real:
```bash
./read_serial /dev/ttyACM0 9600
```
3. También podés usar screen:
```bash
screen /dev/ttyACM0 9600
```
>	Salida de screen: apretar Ctrl + A, luego K y confirmar con Y.

---

## 📊 Ejemplo de salida
```bash
CO = 130
CO = 150
CO = 300
```
---

## 🧪 Pruebas y calibración

1. Encender el sensor MQ-9 al menos 60 segundos antes de medir (tiempo de calentamiento).

2. Acercar una fuente de gas (encendedor sin llama) y observar la respuesta. Las mediciones están dadas en ppm (mayores a 400ppm de manera constante ya es peligroso).

3. Verificar activación de alarmas y visualización de datos.

---

## 💡 Mejoras futuras

- [ ] Interfaz gráfica con Qt
- [ ] Registro histórico de datos en base de datos (MySQL / SQLite)
- [ ] Integración de LCD y alarmas físicas adicionales
- [ ] Notificaciones mediante WiFi o Bluetooth (usando otros shields)

---

## 📚 Referencias
1. World Health Organization – Carbon monoxide

2. CDC – Carbon Monoxide Poisoning

3. Kumar, S. et al. “Design and Implementation of a Low-Cost Carbon Monoxide Detector”, International Journal of Sensor Networks, 2021.

4. Prometec – Sensores MQ[https://www.prometec.net/sensores-de-gas-serie-mq/]

5. Video demostrativo del proyecto[https://www.youtube.com/watch?v=ihxuKCD-zFw&t=42s]

---

## 🧑‍💻 Autor

**Martín Contreras Roldán </jahcr1>**  
Desarrollador Web / Ingeniería Electrónica  
📧 martin.contreras.dev@gmail.com  
🌐 [Mi Portfolio](https://www.martincontrerasdev.com/)

---

## 🧾 Licencia

Este proyecto es de uso educativo y experimental.
© 2025 – Contreras Martín. Todos los derechos reservados.

---
