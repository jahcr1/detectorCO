#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>

#define F_CPU 16000000UL
#define BAUD 9600
#define UBRR_VAL ((F_CPU/16/BAUD)-1)

extern "C" void uart_init() {
    UBRR0H = (uint8_t)(UBRR_VAL >> 8);
    UBRR0L = (uint8_t)UBRR_VAL;
    UCSR0B = (1 << TXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}
extern "C" void uart_putc(char c) {
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = c;
}
extern "C" void uart_puts(const char* s) {
    while (*s) uart_putc(*s++);
}

void adc_init() {
    ADMUX = (1 << REFS0);  // referencia AVcc
    ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
}
uint16_t adc_read(uint8_t ch) {
    ADMUX = (ADMUX & 0xF0) | (ch & 0x0F);
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    return ADC;
}

int main() {
    uart_init();
    adc_init();
    char buf[32];
    while (1) {
        uint16_t value = adc_read(0);  // pin A0
        sprintf(buf, "CO:%u\n", value);
        uart_puts(buf);
        _delay_ms(1000);
    }
}

