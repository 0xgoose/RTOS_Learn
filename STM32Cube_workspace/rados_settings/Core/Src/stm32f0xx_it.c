/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f0xx_it.c
  * @brief   Interrupt Service Routines.
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
#include "stm32f0xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
 
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M0 Processor Interruption and Exception Handlers          */ 
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */
	//update();
  /* USER CODE END HardFault_IRQn 0 */

  while (1);
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVC_IRQn 0 */

  /* USER CODE END SVC_IRQn 0 */
  /* USER CODE BEGIN SVC_IRQn 1 */

  /* USER CODE END SVC_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{

	__asm volatile
	 (
	  	"ldr r5, =tasks  \n"
	  	"ldr r6, [r5, #36]  \n"
	    "str r6, [r7, #32] \n"
	 );

	/*
  task = &t;
  sys = &system;
*/
  HAL_IncTick();

  /*
  // get task

  //asm volatile ("mov ")
  //asm volatile ("mov pc, r1");
  //asm volatile ("push {pc}");
 // asm volatile ("push {lr}");

 // asm volatile ("ldr r0, =tasks");
 // asm volatile ("ldr r1, [r0, #36]");



  //asm volatile ("push {r1}");
  //asm volatile ("pop {pc}");
  //asm volatile ("blx r1");
 */
  /*
  __asm volatile
    (
  		  "ldr r0, =tasks  \n"
  		  "ldr r1, [r0, #36]  \n"
  		  "mov r10, r1 \n"
  		  //"push {r10} \n"
  		  //"pop {pc}"
  		  //"cpsie i \n"
  		 // "isb \n"
    	  "push {lr} \n"
    	  //"push {r15} \n"
  		  "blx r10 \n"
    	  //"isb \n"
    );
    */
  /*
     asm volatile("push {r3}");
	 if (sys->acs == 0) {
	  schedule();
	  save_context();
	  // end context switch
	  sys->acs = 0;
	 }
	 asm volatile("pop {r3}");
*/
  if (uwTick > 100) {
	  //if (task->sp == 0) {
	  GPIOB->ODR = ~GPIOB->ODR;
	   //delay(100000);

	 // }
	  uwTick = 0;
  }
 // asm volatile ("push {lr}");

 /*

  */
  //delay(10000);
  //update();
  //task1();
  //task2();
	//asm ("bx lr");
	//asm ("mov r0, [xPSR, #0]");

}

/******************************************************************************/
/* STM32F0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f0xx.s).                    */
/******************************************************************************/

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
