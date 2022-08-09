/*
 * UART_m328p.c
 *
 * Created: 4 ago. 2022 12:13:13
 * Author : marti
 */ 

#define  F_CPU 16000000UL
#define BAUD 9600
#define set_bit(sfr,bit) (_SFR_BYTE(sfr) |= _BV(bit))
#define clear_bit(sfr,bit) (_SFR_BYTE(sfr) &=~ _BV(bit))

#include <avr/sfr_defs.h>
#include <util/delay.h>
#include <util/setbaud.h>

#include <avr/io.h>
#include <stdio.h>

void uart_config();
//void uart_tx(char character);
//void uart_printf(char *string);
//char uart_rx();


static int uart_putchar(char c, FILE *stream)
{
	if (c == '\n')
		uart_putchar('\r',stream);
	loop_until_bit_is_set(UCSR0A, UDRE0);
    UDR0 = c;
    return 0;
}
static int uart_getchar(FILE *stream)
{
	loop_until_bit_is_set(UCSR0A, RXC0);
	return UDR0;
}

static FILE mystdout = FDEV_SETUP_STREAM(uart_putchar, NULL, _FDEV_SETUP_WRITE);
static FILE mystdin = FDEV_SETUP_STREAM(NULL,uart_getchar,_FDEV_SETUP_READ);

int main(void)
{
	uart_config();
	float radio,area;
	while(1)
	{
		//uart_printf(array);
		printf("Obtención de datos de Potenciometro\n");
		printf("ponga el valor del radio\n");
		scanf("%f",&radio);
		area = 3.1415*radio*radio;
		printf("el area es %0.8f\n",area);
		_delay_ms(200);
	}
}
void uart_config()
{
	clear_bit(UCSR0A,U2X0);             //1. Desactivate double speed transmission. (optional)
	UCSR0B |= _BV(RXEN0)|_BV(TXEN0);    //2. enable Receiver and transmitter.
	UCSR0C |= (0<<UMSEL01)|(0<<UMSEL01);//3. Activate Asynchronous UART
	UCSR0C |= (0<<UPM01)|(0<<UPM00);    //4. Parity: Disabled
	clear_bit(UCSR0C,USBS0);            //5. Stop bit: 1-bit
	clear_bit(UCSR0B,UCSZ02);
	UCSR0C |= _BV(UCSZ01)|_BV(UCSZ00);  //6. Character size: 8-bits
	UBRR0H = UBRRH_VALUE;                        //7. Baud Rate: 9600
	UBRR0L = UBRRL_VALUE;                        //7. Baud Rate: 9600
	stdout = &mystdout;
	stdin = &mystdin;

}
//void uart_tx(char character)
//{
	////while(!bit_is_set(ucsr0a,udre0));
	//loop_until_bit_is_set(ucsr0a,udre0);
	//udr0 = character;
//}
//
//char uart_rx()
//{
	//while(!bit_is_set(ucsr0a,rxc0));
	//return udr0;
//}
//
//void uart_printf(char *string)
//{
	//while (*string != 0x00)
	//{
		//uart_tx(*string);
		//string++;
	//}
//}
