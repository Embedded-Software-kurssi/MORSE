#include "MORSE.h"

#include <string.h>
#include <stdio.h>


char characters[] = {
	37, //A
	56, //B
	58, //C
	22, //D
	34, //E
	50, //F
	46, //G
	63, //H
	36, //I
	55, //J
	45, //K
	52, //L
	39, //M
	38, //N
	47, //O
	54, //P
	61, //Q
	42, //R
	40, //S
	35, //T
	49  //U
};

#define BIT5 16
#define BIT4 8
#define BIT3 4
#define BIT2 2
#define BIT1 1

void MORSE::bitAction(char b)
{
#ifdef WIN32
	if (b) {
		printf("1");
	}
	else {
		printf("0");
	}

#endif // WIN32
}

MORSE::MORSE()
{
}


MORSE::~MORSE()
{
}

void MORSE::showText(const char * text)
{
	int len;
	len = strlen(text);

	for (int i = 0; i < len; i++) {
		char merkki = characters[text[i] - 65];
		if (merkki & BIT5) {
			bitAction(merkki & BIT4);
			bitAction(merkki & BIT3);
			bitAction(merkki & BIT2);
			bitAction(merkki & BIT1);
		}
		else if (merkki & BIT4) {
			bitAction(merkki & BIT3);
			bitAction(merkki & BIT2);
			bitAction(merkki & BIT1);
		}
		else if (merkki & BIT3) {
			bitAction(merkki & BIT2);
			bitAction(merkki & BIT1);
		}
		else if (merkki & BIT2) {
			bitAction(merkki & BIT1);
		}
	}

}
