/*
 * UART_m328p.c
 *
 * Created: 4 ago. 2022 12:13:13
 * Author : marti
 */ 

#define  F_CPU 16000000UL
#define set_bit(sfr,bit) (_SFR_BYTE(sfr) |= _BV(bit))
#define clear_bit(sfr,bit) (_SFR_BYTE(sfr) &=~ _BV(bit))

#include <avr/sfr_defs.h>
#include <util/delay.h>
#include <avr/io.h>

int main(void)
{
	uart_config();
	float radio,area;
	while(1)
	{
		//uart_printf(array);
		printf("--Calculo del Area del circulo---\n");
		printf("introdusca el valor del radio en cm: \n");
		scanf("%f",&radio);
		area = 3.1415*radio*radio;
		printf("el area es %0.4f cm2\n",area);
		_delay_ms(200);
	}
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
