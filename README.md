# UART-stdio_avr

If you're a programmer with knowloedge in the C lenguage or just a person who was forced to learn it, you'll remember that we had two funtions that allow us to print data on the console and get data from the keyboard, yes I'm talking about `printf()` and `scanf()`.

Well, you'll be surprised that we can use these functions for the **UART of the ATMEGA328P**, this will help us send and receive large strings of characters, or *strings*, in a very easy way.

Whit this protocol we can use bluetooth and wifi modules for *IoT* or any other function that you think needs to receive a large amount of data.

# Table of contents 

- [Demo](#demo)
- [How to use](#how-to-use)
    - [Requirements](#requirements)
- [Useful resources](#useful-resources)
- [Author](#author)

# Demo

The program only asks for a radius to show the area of circle.
## simulation (Proteus)
![simulación de proteus](https://im4.ezgif.com/tmp/ezgif-4-8b32b2752f.gif)

# How to use

## Requirements

- git

- This program needs the IDE of *Microchip studio* <img src="./assets/mchp-studio-logo.png" alt="logo de microchip studio" style="width: 70px; margin-right: 10px;"/>

> You can downloads in [microchip][IDE]

- Atmega328p
- protoboard
- 5v power supply
- quartz clock $16 MHz$
- converter RS232 to TTL
- Pickit4 or Atmel ICE

> or only a *Arduino UNO*

## Steps

1. clone this repository or download it.
```shell
git clone https://github.com/marti-gutierrez/UART-stdio_avr.git
```

2. Open microchip studio and go to task bar *file>open>project/solution* and select where the repository is located, select the file *.atsln.

3. Click on the build icon <img src="./assets/icon.png"/> and it'll start compiling.


# Useful resources

- [AVRDUDE in microchip studio][video] - this video explains how to program an arduino UNO with the microchip studio IDE by [Carlos Ql][c-youtube].

- [CADENA DE CARACTERES POR UART ][printf-uart] - In this video shows another algorith for using only the `printf()` function.

# Author

This code was carried out as part of the [AVR in C programming course][c-udemy] by Ernesto Paredes Martinez.

[IDE]: https://www.microchip.com/en-us/tools-resources/develop/microchip-studio
[video]: https://www.youtube.com/watch?v=Rdf0gnCTi5E&list=PL5a8rjiFubvetVKc8T-bHUXx6KZXm6XkA&index=21
[c-youtube]: https://www.youtube.com/c/CarlosQL
[printf-uart]: https://www.youtube.com/watch?v=TF_0XT_N_pk&list=PL5a8rjiFubvetVKc8T-bHUXx6KZXm6XkA&index=7
[c-udemy]: https://www.udemy.com/course/curso-practico-para-programacion-de-avr-en-c/

