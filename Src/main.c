/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "assignment.h"

#define timeout_cnt_max (uint8_t)253

int main(void)
{
  /*
   *  DO NOT WRITE TO THE WHOLE REGISTER!!!
   *  Write to the bits, that are meant for change.
   */
   
  //Systick init
  LL_Init1msTick(8000000);
  LL_SYSTICK_SetClkSource(LL_SYSTICK_CLKSOURCE_HCLK);
  LL_SetSystemCoreClock(8000000);	

  /*
   * TASK - configure MCU peripherals so that button state can be read and LED will blink.
   * Button must be connected to the GPIO port A and its pin 3.
   * LED must be connected to the GPIO port A and its pin 4.
   *
   * In header file "assignment.h" define macros for MCU registers access and LED blink application.
   * Code in this file must use these macros for the peripherals setup.
   * Code of the LED blink application is already given so just the macros used in the application must be defined.
   */


  /* Enable clock for GPIO port A*/

	//type your code for GPIOA clock enable here:

  /*Enables clock for GPIO port B*/
  //*((volatile uint32_t *) (uint32_t)(RCC_BASE_ADDR + RCC_AHBENR_REG)) |= (uint32_t)(1 << clock_enable_pA);

  /* GPIOA pin 3 and 4 setup */

	//type your code for GPIOA pins setup here:
  /*GPIOA pin 3 and 4 setup*/
  /*GPIO MODER register*/
  //Set mode for pin 3
  //*((volatile uint32_t *)(GPIOA_BASE_ADDR)) &= ~(uint32_t)(0x3 << push_button_bit);
  //*((volatile uint32_t *)(GPIOA_BASE_ADDR)) |= (uint32_t)(1 << (2*led_pin));
  //Set mode for pin 4
  //*((volatile uint32_t *)(GPIOA_BASE_ADDR)) &= ~(uint32_t)(0x3 << (2*push_button_bit));

  /*GPIO OTYPER register*/
  //*((volatile uint32_t *)((uint32_t)(GPIOA_BASE_ADDR + GPIOA_OTYPER_REG))) &= ~(1 << led_pin);

  /*GPIO OSPEEDR register*/
  //Set Low speed for GPIOa pin 3
  //*((volatile uint32_t *)((uint32_t)(GPIOA_BASE_ADDR + GPIOA_OSPEEDER_REG))) &= ~(0x3 <<(2*led_pin));

  /*GPIO PUPDR register, reset*/
  //Set pull up for GPIOB pin 6 (input)
  //*((volatile uint32_t *)((uint32_t)(GPIOA_BASE_ADDR + GPIOA_PUPDR_REG))) |= (1 << (2*push_button_bit));
  //Set no pull for GPIOB pin 3
  //*((volatile uint32_t *)((uint32_t)(GPIOA_BASE_ADDR + GPIOA_PUPDR_REG))) &= ~(0x3 << (2*led_pin));
  /* GPIOA pin 3 and 4 setup */
  *((volatile uint32_t *) (uint32_t)(RCC_BASE_ADDR + RCC_AHBENR_REG)) |= (uint32_t)(1 << clock_enable_pA);

    /* GPIOA pin 3 and 4 setup */

  	//type your code for GPIOA pins setup here:
    /*GPIOA pin 3 and 4 setup*/
    /*GPIO MODER register*/
    //Set mode for pin 3
  	GPIOA_MODER_REG &= ~(uint32_t)(0x3 << push_button_bit);
  	GPIOA_MODER_REG |= (uint32_t)(1 << (2*led_pin));
    //Set mode for pin 4
  	GPIOA_MODER_REG &= ~(uint32_t)(0x3 << (2*push_button_bit));

    /*GPIO OTYPER register*/
  	GPIOA_OTYPER_REG &= ~(1 << led_pin);

    /*GPIO OSPEEDR register*/
    //Set Low speed for GPIOa pin 3
    GPIOA_OSPEEDER_REG &= ~(0x3 <<(2*led_pin));

    /*GPIO PUPDR register, reset*/
    //Set pull up for GPIOB pin 6 (input)
    GPIOA_PUPDR_REG |= (1 << (2*push_button_bit));
    //Set no pull for GPIOB pin 3
    GPIOA_PUPDR_REG &= ~(0x3 << (2*led_pin));

	//type your code for GPIOA pins setup here:

    EDGE_TYPE state;
    uint8_t samples=5,cnt_edges=0;//flag=1
    //LED_ON;
  while (1)
  {
	//flag=BUTTON_GET_STATE;
	state=edgeDetect(BUTTON_GET_STATE,samples);
	if (state==RISE){
		cnt_edges++;
		if ((GPIOA_ODR_REG & (1 << led_pin)) ==0)
			LED_ON;
		else
			LED_OFF;
			/*if(flag==1){
				LED_OFF;
				//flag=0;
			}
			else{
			 //LED_ON;
			 //flag=1;
			//}*/
		}
  }



}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

//define function

EDGE_TYPE edgeDetect(uint8_t pin_state, uint8_t samples){
uint8_t first_num=pin_state;
uint8_t counter_null,counter_one=0,time_cnt=0;
while(1){
	pin_state= BUTTON_GET_STATE ;
	if (first_num==0 ){
		if ( pin_state == 1 )
			{if (++counter_one>=samples)
				return FALL;
			}
		else
			counter_one=0;


		}
	else{
		if (pin_state == 0)
			{if (++counter_null>=samples)
				return RISE;
			}
		else
			counter_null=0;
		}

	//time_cnt++;
	if ( ++time_cnt >=timeout_cnt_max)
		return NONE;
	/*
	if(first_num==1 ){
		if(pin_state==0){
					++counter_null;
				}else{
					{++counter_one;
					counter_null=0;}
				}
				if(counter_null==samples){


			return FALL;
		//} else if(counter_one+counter_null==samples+1){
		//	return NONE;
		}

	}else{
		if(pin_state>0){
					++counter_one;
				}else{
					{++counter_null;counter_one=0;}
				}
				if(counter_one==samples){

			return  RISE;
		//} else if(counter_one+counter_null==samples+1){
		//	return NONE;
		}
	}
	*/
}
}



/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */

void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(char *file, uint32_t line)
{ 
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
