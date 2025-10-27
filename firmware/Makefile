MCU = atmega328p
F_CPU = 16000000UL
CC = avr-g++
OBJCOPY = avr-objcopy

CFLAGS = -mmcu=$(MCU) -DF_CPU=$(F_CPU) -Os -std=gnu++17 -Wall
LDFLAGS = -mmcu=$(MCU)

TARGET = detector
SRC = src/main.cpp

all: $(TARGET).hex

$(TARGET).elf: $(SRC)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

$(TARGET).hex: $(TARGET).elf
	$(OBJCOPY) -O ihex -R .eeprom $< $@

upload: $(TARGET).hex
	avrdude -v -p $(MCU) -c arduino -P /dev/ttyACM0 -b 115200 -D -U flash:w:$(TARGET).hex:i

clean:
	rm -f $(TARGET).elf $(TARGET).hex

.PHONY: all upload clean

