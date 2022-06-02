#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DDR DDRB
#define BLINK_DDB_PIN DDB0
#define BLINK_PORT PORTB
#define BLINK_PIN PB0

int main(void) {
  BLINK_DDR |= (1 << BLINK_DDB_PIN);

  while (1) {
    BLINK_PORT |= (1 << BLINK_PIN);
    _delay_ms(100);

    BLINK_PORT &= ~(1 << BLINK_PIN);
    _delay_ms(200);

    BLINK_PORT |= (1 << BLINK_PIN);
    _delay_ms(200);

    BLINK_PORT &= ~(1 << BLINK_PIN);
    _delay_ms(1000);

  }
}