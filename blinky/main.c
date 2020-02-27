#define USE_STDPERIPH_DRIVER
#include "stm32f4xx.h"

#define RED	(1U << 14)
#define GREEN	(1U << 12)
#define BLUE	(1U << 15)
#define ORANGE	(1U << 13)

#define RED_BIT		(1U << 28)
#define GREEN_BIT	(1U << 24)
#define BLUE_BIT	(1U << 30)
#define ORANGE_BIT	(1U << 26)

void ms_delay(int ms)
{
	while (ms-- > 0) {
		volatile int x=5971;
		while (x-- > 0)
			__asm("nop");
	}
}


int main(void)
{
	int i = 0;

	/* enable the clock to GPIOD */
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	__asm("dsb");

	GPIOD->MODER = RED_BIT | GREEN_BIT | BLUE_BIT | ORANGE_BIT;

	for (;;) {

		ms_delay(500);
		GPIOD->ODR ^= (1 << (12 + i));           // Toggle the pin
		i++;
		if (i > 3)
			i = 0;
	}
}
