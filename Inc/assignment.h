/*
 * assignment.h
 *
 *  Created on: 27. 9. 2020
 *      Author: Stancoj
 */

#ifndef ASSIGNMENT_H_
#define ASSIGNMENT_H_

/**
 * 		This header file provides macros to the MCU's registers required for this assignment.
 * 		Your task is to provide their actual implementation so you can use them in application in "main.c"
 * 		and make your "LED blink" application code readable and great again!
 */

/* General purpose input output port A macros */
//GPIOA peripheral base address

#define led_pin 4
#define push_button_bit 3
#define clock_enable_pA 17

//#define	GPIOA_BASE_ADDR			(uint32_t) 0x48000000/* Add GPIO A peripheral base address here. */
//MODER register
//#define	GPIOA_MODER_REG			(uint32_t)0x00/* Add moder register address here. */
//OTYPER register
//#define	GPIOA_OTYPER_REG		(uint32_t)0x04/* Add otyper register address here. */
//OSPEEDER register
//#define GPIOA_OSPEEDER_REG		(uint32_t)0x08/* Add ospeeder register address here. */
//PUPDR register
//#define GPIOA_PUPDR_REG			(uint32_t)0x0C/* Add pupdr register address here. */
//IDR register
//#define GPIOA_IDR_REG			(uint32_t)0x10/* Add idr register address here. */
//ODR register
//#define GPIOA_ODR_REG			(uint32_t)0x14/* Add odr register address here. */
//BSRR register
//#define GPIOA_BSRR_REG			(uint32_t)0x18/* Add bsrr register address here. */
//BRR register
//#define GPIOA_BRR_REG			(uint32_t)0x28/* Add brr register address here. */

#define	GPIOA_BASE_ADDR			(uint32_t) 0x48000000/* Add GPIO A peripheral base address here. */
//MODER register
#define	GPIOA_MODER_REG			*((volatile uint32_t *)(GPIOA_BASE_ADDR+(uint32_t)0x00))/* Add moder register address here. */
//OTYPER register
#define	GPIOA_OTYPER_REG		*((volatile uint32_t *)(GPIOA_BASE_ADDR+(uint32_t)0x04))/* Add otyper register address here. */
//OSPEEDER register
#define GPIOA_OSPEEDER_REG		*((volatile uint32_t *)(GPIOA_BASE_ADDR+(uint32_t)0x08))/* Add ospeeder register address here. */
//PUPDR register
#define GPIOA_PUPDR_REG			*((volatile uint32_t *)(GPIOA_BASE_ADDR+(uint32_t)0x0C))/* Add pupdr register address here. */
//IDR register
#define GPIOA_IDR_REG			*((volatile uint32_t *)(GPIOA_BASE_ADDR+(uint32_t)0x10))/* Add idr register address here. */
//ODR register
#define GPIOA_ODR_REG			*((volatile uint32_t *)(GPIOA_BASE_ADDR+(uint32_t)0x14))/* Add odr register address here. */
//BSRR register
#define GPIOA_BSRR_REG			*((volatile uint32_t *)(GPIOA_BASE_ADDR+(uint32_t)0x18))/* Add bsrr register address here. */
//BRR register
#define GPIOA_BRR_REG			*((volatile uint32_t *)(GPIOA_BASE_ADDR+(uint32_t)0x28))/* Add brr register address here. */

/*Reset clock control register macros */
//RCC base address
#define	RCC_BASE_ADDR			(uint32_t)0x40021000/* Add rcc register address here. */
//AHBEN register
#define	RCC_AHBENR_REG			*((volatile uint32_t *)(RCC_BASE_ADDR+(uint32_t)0x14))/* Add ahben register address here. */

/* LED and button macros */
//#define LED_ON					*((volatile uint32_t *)((uint32_t)(GPIOA_BASE_ADDR + GPIOA_BSRR_REG))) |= (1 << led_pin )
//#define LED_OFF					*((volatile uint32_t *)((uint32_t)(GPIOA_BASE_ADDR+ GPIOA_BRR_REG))) |= (1 << led_pin)/* Add LED_OFF implementation here. */

#define LED_ON					GPIOA_BSRR_REG |= (1 << led_pin )
#define LED_OFF					GPIOA_BRR_REG |= (1 << led_pin)/* Add LED_OFF implementation here. */

//#define BUTTON_GET_STATE		!(*((volatile uint32_t *)((uint32_t)(GPIOA_BASE_ADDR + GPIOA_IDR_REG))) & (1 << push_button_bit))/* Add BUTTON_GET_STATE implementation here. */
#define BUTTON_GET_STATE		!(GPIOA_IDR_REG & (1 << push_button_bit))/* Add BUTTON_GET_STATE implementation here. */


#endif /* ASSIGNMENT_H_ */
