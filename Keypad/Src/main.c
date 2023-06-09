/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

void delay(void){
	for(uint32_t i = 0; i < 300000; i++);
}

int main(void)
{
	// Peripheral register addresses
	uint32_t volatile *const pGPIODModeReg	= (uint32_t*)(0x40020C00);
	uint32_t volatile *const pInPutDataReg	= (uint32_t*)(0x40020C00 + 0x10);
	uint32_t volatile *const pOutPutDataReg	= (uint32_t*)(0x40020C00 + 0x14);
	uint32_t volatile *const pClockCtrlReg	= (uint32_t*)(0x40023800 + 0x30);
	uint32_t volatile *const pPullupDownReg	= (uint32_t*)(0x40020C00 + 0x0C);

	// Enable the peripheral clock of GPIOD peripheral
	*pClockCtrlReg |= (1 << 3);

	// Configure the rows as output
	*pGPIODModeReg &= ~(0xFF);	// clear
	*pGPIODModeReg |= 0x55;		// set

	// Configure the columns as input
	*pGPIODModeReg &= ~(0xFF << 16);

	// Enable internal pull up resistors for the columns
	*pPullupDownReg &= ~(0xFF << 16);	// clear
	*pPullupDownReg |= (0x55 << 16);	// set

    /* Loop forever */
	for(;;){
		// Make all rows high
		*pOutPutDataReg |= 0x0F;

		// Make R1 low
		*pOutPutDataReg &= ~(1 << 0);

		// Scan the columns
		// Check C1 (PD8) low or high
		if(!(*pInPutDataReg & (1 << 8))) {
			delay();
			printf("1\n");
		}

		// Check C2 (PD9) low or high
		if(!(*pInPutDataReg & (1 << 9))) {
			delay();
			printf("2\n");
		}

		// Check C3 (PD10) low or high
		if(!(*pInPutDataReg & (1 << 10))) {
			delay();
			printf("3\n");
		}

		// Check C4 (PD11) low or high
		if(!(*pInPutDataReg & (1 << 11))) {
			delay();
			printf("A\n");
		}

		// Make R2 low
		*pOutPutDataReg |= 0x0F;
		*pOutPutDataReg &= ~(1 << 1);

		// Scan the columns
		// Check C1 (PD8) low or high
		if(!(*pInPutDataReg & (1 << 8))) {
			delay();
			printf("4\n");
		}

		// Check C2 (PD9) low or high
		if(!(*pInPutDataReg & (1 << 9))) {
			delay();
			printf("5\n");
		}

		// Check C3 (PD10) low or high
		if(!(*pInPutDataReg & (1 << 10))) {
			delay();
			printf("6\n");
		}

		// Check C4 (PD11) low or high
		if(!(*pInPutDataReg & (1 << 11))) {
			delay();
			printf("B\n");
		}

		// Make R3 low
		*pOutPutDataReg |= 0x0F;
		*pOutPutDataReg &= ~(1 << 2);

		// Scan the columns
		// Check C1 (PD8) low or high
		if(!(*pInPutDataReg & (1 << 8))) {
			delay();
			printf("7\n");
		}

		// Check C2 (PD9) low or high
		if(!(*pInPutDataReg & (1 << 9))) {
			delay();
			printf("8\n");
		}

		// Check C3 (PD10) low or high
		if(!(*pInPutDataReg & (1 << 10))) {
			delay();
			printf("9\n");
		}

		// Check C4 (PD11) low or high
		if(!(*pInPutDataReg & (1 << 11))) {
			delay();
			printf("C\n");
		}

		// Make R4 low
		*pOutPutDataReg |= 0x0F;
		*pOutPutDataReg &= ~(1 << 3);

		// Scan the columns
		// Check C1 (PD8) low or high
		if(!(*pInPutDataReg & (1 << 8))) {
			delay();
			printf("*\n");
		}

		// Check C2 (PD9) low or high
		if(!(*pInPutDataReg & (1 << 9))) {
			delay();
			printf("0\n");
		}

		// Check C3 (PD10) low or high
		if(!(*pInPutDataReg & (1 << 10))) {
			delay();
			printf("#\n");
		}

		// Check C4 (PD11) low or high
		if(!(*pInPutDataReg & (1 << 11))) {
			delay();
			printf("D\n");
		}
	}
}
