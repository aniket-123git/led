#include"stm32f4xx_hal.h"
void LED_INIT(void);
int main()
{
	HAL_Init();
	LED_INIT();
	while(1)
	{
		GPIOC->ODR^=1<<10;
		HAL_Delay(2000);
		GPIOC->ODR^=1<<10;
		HAL_Delay(2000);
	}
	return 0;
}
void LED_INIT(void)
{
	GPIO_InitTypeDef GPIO_InitStruct={0};
	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_InitStruct.Pin = GPIO_PIN_10;
	GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull = GPIO_NOPULL;
	GPIO_InitStruct.Speed = GPIO_SPEED_LOW;
	HAL_GPIO_Init(GPIOC,&GPIO_InitStruct);
	return;
}
/*#include <stm32f4xx.h>
void PLL_SET(void);
void GPIO_SET(void);
int main()
{
	unsigned int i;
	//PLL_SET();
	__HAL_RCC_GPIOC_CLK_ENABLE();
	GPIO_SET();
	while(1)
	{
		GPIOC->BSRR|=1<<10;
		//HAL_Delay(1000);
	   // for(i=0;i<100;i++);
		GPIOC->BSRR|=1<<26;
		//HAL_Delay(1000);

		//for(i=0;i<100;i++);
	}
	return 0;
}
void PLL_SET(void)
{
	RCC->PLLCFGR&=~(0x3f<<0);
	RCC->PLLCFGR|=0x04;//dividing factor M=4 VCO in 2 Mhz M=4

	RCC->PLLCFGR&=~(0x1ff<<6);
	RCC->PLLCFGR|=0x32<<6;//Multiplication factor n=50

	RCC->PLLCFGR&=~(0x03)<<16;//PLL output frequency will be 50 Mhz P=2

	RCC->PLLCFGR|=1<<22;//Source of PLL is HSE


	RCC->CR|=1<<16;//HSE clock source enabled
	while((RCC->CR&1<<17)==0);//waiting to HSE clock become stable


	RCC->CR|=1<<24;//PLL Turned on
	while((RCC->CR&1<<25)==0);//waiting to PLL clock become stable

	RCC->CFGR&=~(0x03<<0);
	RCC->CFGR|=1<<1;//pll clock selected as main system clock

	RCC->CR&=~(1<<0);//HSI disabled

	RCC->AHB1ENR|=1<<2;//clock for PORTC enabled

	return;
}
void GPIO_SET(void)
{
	GPIOC->MODER|=1<<20;//pin 11 of port c as general output pin
	GPIOC->OTYPER|=0x00;//push-pull mode
	GPIOC->OSPEEDR=0x00;//low speed pins
	GPIOC->PUPDR=0x00;//pull ups not activated
	RCC->AHB1ENR|=1<<2;//clock for PORTC enabled

	return ;
}*/
