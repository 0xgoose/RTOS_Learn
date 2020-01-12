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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

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
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

//static volatile uint32_t TimingDelay = uwTick;

int ll = 0;

uint32_t test = 0;
volatile _inc_sched;

volatile int ii;
volatile int v=1000000;

void task1();
void task2();
void task10();


void task10(void) {
	asm volatile ("pop {r5, r6}");
	asm volatile ("mov r9, r5");
	asm volatile ("mov r10, r6");
	/*
	asm volatile ("cpsie i");
	task = &t;
	task->current_task = 9;
	task->ptr =  &task10;
	tasks[task->current_task] = task->ptr;
*/


	while(1) {
		  if (ll > 500000 ) { // 500000

			  task->sp = 1;
			  	  //GPIOB->ODR = ~GPIOB->ODR;
			  	  GPIOB->ODR = 0;
			  	  //delay(1000000);
			  	  for(v;v > 0; v--);
			  	  ll = 0;
			  	//task1();
			  	//  task2();


		  } else {
			  ll++;
			 	  task->sp = 0;
		  }
		  }


}

void save_context(void) {
	/*
	asm volatile ("push {r0}");
	asm volatile ("push {r1}");
	asm volatile ("push {r2}");
	asm volatile ("push {r3}");
	asm volatile ("push {r4}");
	asm volatile ("push {r5}");
	asm volatile ("push {r6}");
	asm volatile ("push {r7}");
	//asm volatile ("push {r13}");
	asm volatile ("push {lr}");
	//asm volatile ("push {r15}");
	 *
	 */
	//asm volatile ("mov r6, pc");
}

void schedule(void) {
	sys = &system;
	sys->acs = 1;
	//task10();
	// do sth
	//sys->acs = 0;
	// get current task

}


// scheduler
void update() {
	asm ("push {r0}");
	task = &t;
	int tmp;
	//asm ("mov r7, #tmp");

	//asm volatile (".set XX, &t");
	//asm volatile ("ldr r0, #task->sp");
	test++;
}

void TimingDelay_Decrement(void)
{
 // if ( TimingDelay != 0x00)
  //{//
	//  TimingDelay--;
  //}
}

void Delay(__IO uint32_t nTime)
{
	 //TimingDelay = nTime;
	// TimingDelay_Decrement();
  //while( TimingDelay != 0);
}

void delay(uint32_t v) {
	asm volatile ("pop {r5, r6}");
	asm volatile ("mov r9, r5");
	asm volatile ("mov r10, r6");
	for(;v > 0; v--);
}

static int i ,a, u;

/**
  * @brief  The application entry point.
  * @retval int
  */


//long unsigned int xxSize = sizeof(os_task2);

volatile int settings_done = 0;
volatile int update_list = 0;

int main(void)
{

	if (!settings_done) {
  //__NVIC_EnableIRQ((1UL << __NVIC_PRIO_BITS) - 1UL);
  HAL_Init();
  SystemClock_Config();
  MX_GPIO_Init();


  settings_done = 1;
	}

  uint32_t k;
  int y;

  //asm volatile ("ldr r0, =test"); // wskaźnik test wrzucony na r0
  //asm volatile ("ldr r1, =t");
  task = &t;
  task->sp = 0x10;
  task->size = sizeof(os_task);

  // main is default ( start ) task
  // means value is 0
  task->current_task = 0;

  // add task to list of tasks
  // musiałem zrobić to ręcznie
  // czyli dodać zadania do listy przy starcie systemu
  // przed główną pętlą i przrwaniami
  if (!update_list) {
	  // 0
	  task->ptr =  &main;
	  tasks[0] = &main;
	  // 1
	  task->ptr =  &task1;
	  tasks[1] = &task1;
	  // 2
	  task->ptr =  &task2;
	  tasks[2] = &task2;
	  // 10
	  task->ptr =  &task10;
	  tasks[9] = &task10;
	  update_list = 1;
  }

  //if (uwTick > 0) {
  //__asm volatile
  //	(
  			//"pop {r0} \n"
  			//"pop {pc} \n"
  			//"mov r0,  \n"
  			//"pop {r14} \n"
  //	);
  //}


  while(1) {

	  // jednak główna pętla programu musi być
	  // i z tego miejsca trzeba wskakiwać do zadań
	  // przy przełączaniu kotekstu. Ta, trzeba
	  // jeszcze nie wiem czy trzeba ale tak mi sie wydaje

	  //if ()
	 // asm volatile ("ldr r0, =tasks");
	 // asm volatile ("ldr r1, [r0, #36]");
	 // asm volatile ("blx r1");
	  //task1();
	  //task2();
	  //task10();

  }

  /*
  asm volatile ("mov r5, sp");
  asm volatile ("ldr r6, [r5, #0]");
  asm volatile ("ldr r6, [r5, #4]");
  asm volatile ("movs r0, #10");
  asm volatile ("str r0, [r5, #0]");
  */

  /*
  asm volatile ("mov r0, sp");
  asm volatile ("ldr r5, =t");
  //asm volatile ("ldr r6, [r5, #0]");
  //asm volatile ("ldr r6, [r5, #0]");
  asm volatile ("ldr r6, [r5, #4]");

  asm volatile ("str r0, [r5, #4]"); // ?

  asm volatile ("ldr r6, [r5, #4]");
  */

  /*
  //asm volatile ("ldr r2, =test");
  //asm volatile ("ldr r3, =t");
  asm volatile ("ldr r0, =task");
  //asm volatile ("ldr r2, =u");
  asm volatile ("mov r1, sp");
  //asm volatile ("push =task");
  asm volatile ("ldr r5, [r0, #0]"); // load task->size
  asm volatile ("ldr r6, [r5]");
  //asm volatile ("ldr r5, [r0, #0]");
  asm volatile ("ldr r6, [r5, #4]"); // load task->sp
  //asm volatile ("ldr r6, [r0, #4]");
  //asm volatile ("str r1, [r0, #0]");
  asm ("nop");
  asm volatile ("push {lr}");
  //asm volatile ("ldr r1, [sp, #0]");
  //asm volatile ("push sp");
   * */


  //int a, b, c;
  //register int r;

  //for (a=0; a< 10000000; a++);
  //for (r=0; r < 10000000; r++);
  /*
  while(1) {
  if (ll > 500000) {

	  task->sp = 1;
	  	  //GPIOB->ODR = ~GPIOB->ODR;
	  	  GPIOB->ODR = 1 << 3;
	  	  delay(3000000);
	  	  ll = 0;
	  	//task1();
	  	//  task2();
	  	if (task->current_task == 0) {
	  	 		  asm volatile ("bl task1");
	  	 	  } else {
	  	 		  asm volatile ("bl task2");
	  	 	  }
  } else {
	  ll++;
	 	  task->sp = 0;
  }
  }
  */

  //for (b=0; b< 10000000; b++);


  /*
  while (1)
  {
	  if (test > 1000) {
		  k++;
		  GPIOB->ODR = ~GPIOB->ODR;
		  test = 0;
	  }

	  i++;

	 // delay(100000);
  }
	*/


  // trap
  // albo inaczej to jest idle task właśnie
  while(1);
}

void task1()
{
	task = &t;
	task->current_task = 1;
	task->ptr =  &task10;
	tasks[task->current_task] = task->ptr;

	for (ii=0;ii<10000000;ii++);

}

void task2()
{

	task = &t;
	task->current_task = 2;
	task->ptr =  &task10;
	tasks[task->current_task] = task->ptr;
	//while(1);
	//for (ii;ii>0;ii--);
	while(1);
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB busses clocks 
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  // led 3
  RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
  GPIOB->MODER = 1 << 6;
  GPIOB->ODR = 1 << 3;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }

  if (SysTick_Config(SystemCoreClock / 1000)) // 1000 default
  {
  		//while (1); //W przypadku błędu program zawiesi się w pętli nieskończonej
	  Error_Handler();
  }

  //asm volatile ("CPSIE i");

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOF_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();


}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
	while(1);
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
