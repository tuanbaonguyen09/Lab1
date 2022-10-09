/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
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
void display7SEG(int num){
	//reset port
	HAL_GPIO_WritePin (GPIOA,a_Pin|b_Pin|c_Pin|d_Pin|e_Pin|f_Pin|g_Pin, GPIO_PIN_SET ) ;
	switch(num){
	case 0:
		HAL_GPIO_TogglePin (GPIOA,a_Pin|b_Pin|c_Pin|d_Pin|e_Pin|f_Pin) ;
		break;
	case 1:
		HAL_GPIO_TogglePin (GPIOA ,b_Pin|c_Pin ) ;
		break;
	case 2:
		HAL_GPIO_TogglePin (GPIOA,a_Pin|b_Pin|g_Pin|d_Pin|e_Pin) ;
		break;
	case 3:
		HAL_GPIO_TogglePin (GPIOA,a_Pin|b_Pin|g_Pin|c_Pin|d_Pin) ;
		break;
	case 4:
		HAL_GPIO_TogglePin (GPIOA,f_Pin|g_Pin|b_Pin|c_Pin) ;
		break;
	case 5:
		HAL_GPIO_TogglePin (GPIOA,a_Pin|f_Pin|g_Pin|c_Pin|d_Pin) ;
		break;
	case 6 :
		HAL_GPIO_TogglePin (GPIOA,a_Pin|f_Pin|g_Pin|e_Pin|c_Pin|d_Pin) ;
		break;
	case 7 :
		HAL_GPIO_TogglePin (GPIOA ,a_Pin|b_Pin|c_Pin ) ;
		break;
	case 8:
		HAL_GPIO_TogglePin (GPIOA,a_Pin|b_Pin|c_Pin|d_Pin|e_Pin|f_Pin|g_Pin) ;
		break;
	case 9:
		HAL_GPIO_TogglePin (GPIOA,a_Pin|b_Pin|c_Pin|d_Pin|f_Pin|g_Pin) ;
		break;
	}
	return;
}
void display7SEG_0(int num){
	//reset port
	HAL_GPIO_WritePin (GPIOB,a0_Pin|b0_Pin|c0_Pin|d0_Pin|e0_Pin|f0_Pin|g0_Pin, GPIO_PIN_SET ) ;
	switch(num){
	case 0:
		HAL_GPIO_TogglePin (GPIOB,a0_Pin|b0_Pin|c0_Pin|d0_Pin|e0_Pin|f0_Pin) ;
		break;
	case 1:
		HAL_GPIO_TogglePin (GPIOB ,b0_Pin|c0_Pin ) ;
		break;
	case 2:
		HAL_GPIO_TogglePin (GPIOB,a0_Pin|b0_Pin|g0_Pin|d0_Pin|e0_Pin) ;
		break;
	case 3:
		HAL_GPIO_TogglePin (GPIOB,a0_Pin|b0_Pin|g0_Pin|c0_Pin|d0_Pin) ;
		break;
	case 4:
		HAL_GPIO_TogglePin (GPIOB,f0_Pin|g0_Pin|b0_Pin|c0_Pin) ;
		break;
	case 5:
		HAL_GPIO_TogglePin (GPIOB,a0_Pin|f0_Pin|g0_Pin|c0_Pin|d0_Pin) ;
		break;
	case 6 :
		HAL_GPIO_TogglePin (GPIOB,a0_Pin|f0_Pin|g0_Pin|e0_Pin|c0_Pin|d0_Pin) ;
		break;
	case 7 :
		HAL_GPIO_TogglePin (GPIOB ,a0_Pin|b0_Pin|c0_Pin ) ;
		break;
	case 8:
		HAL_GPIO_TogglePin (GPIOB,a0_Pin|b0_Pin|c0_Pin|d0_Pin|e0_Pin|f0_Pin|g0_Pin) ;
		break;
	case 9:
		HAL_GPIO_TogglePin (GPIOB,a0_Pin|b0_Pin|c0_Pin|d0_Pin|f0_Pin|g0_Pin) ;
		break;
	}
	return;
}
int state = 1;
int second = -1; int second_tmp;
int red = 5;
int yellow = 2;
int green = 3;

void two_lightcontrol (){
	  if(second == -1){
	    switch (state){
	    	case 1: // RED 1 time 5s
	    		state = 3;
	    		second += red;
	    		HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_RESET);
	    		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, GPIO_PIN_SET);
	    		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_SET);

			  	second_tmp = green -1;
	    		HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, GPIO_PIN_RESET); // GREEN 2 Light
	    		HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, GPIO_PIN_SET);
	    		HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_SET);
	    		break;
	    	case 2:// YELLOW 1 time 2s
	    		state = 1;
	    		second += yellow;
	    		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_SET);
	    		HAL_GPIO_WritePin(YELLOW_1_GPIO_Port, YELLOW_1_Pin, GPIO_PIN_RESET);
	    		break;
	    	case 3: // GREEN 1 time 3s
	    		state = 2;
	    		second += green;
	    		HAL_GPIO_WritePin(RED_1_GPIO_Port, RED_1_Pin, GPIO_PIN_SET);
	    		HAL_GPIO_WritePin(GREEN_1_GPIO_Port, GREEN_1_Pin, GPIO_PIN_RESET);

			  	second_tmp = red -1;
	    		HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, GPIO_PIN_SET);// YELLOW 2 Off
	    		HAL_GPIO_WritePin(RED_2_GPIO_Port, RED_2_Pin, GPIO_PIN_RESET); // RED 2 Light
	    		break;
	    }
	  }
	  else if (second == yellow -1 && state == 3){
		  	second_tmp = yellow -1;
			HAL_GPIO_WritePin(GREEN_2_GPIO_Port, GREEN_2_Pin, GPIO_PIN_SET); // GREEN 2 Off
			HAL_GPIO_WritePin(YELLOW_2_GPIO_Port, YELLOW_2_Pin, GPIO_PIN_RESET);// YELLOW 2 Light
		}
}
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */

int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  while (1)
  {
    /* USER CODE END WHILE */

	    /* USER CODE BEGIN 3 */
	two_lightcontrol();

	display7SEG(second--) ;
	display7SEG_0(second_tmp--);
	HAL_Delay(1000);
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, a_Pin|b_Pin|c_Pin|d_Pin
                          |e_Pin|f_Pin|g_Pin|RED_1_Pin
                          |YELLOW_1_Pin|GREEN_1_Pin|RED_2_Pin|YELLOW_2_Pin
                          |GREEN_2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, a0_Pin|b0_Pin|c0_Pin|d0_Pin
                          |e0_Pin|f0_Pin|g0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : a_Pin b_Pin c_Pin d_Pin
                           e_Pin f_Pin g_Pin RED_1_Pin
                           YELLOW_1_Pin GREEN_1_Pin RED_2_Pin YELLOW_2_Pin
                           GREEN_2_Pin */
  GPIO_InitStruct.Pin = a_Pin|b_Pin|c_Pin|d_Pin
                          |e_Pin|f_Pin|g_Pin|RED_1_Pin
                          |YELLOW_1_Pin|GREEN_1_Pin|RED_2_Pin|YELLOW_2_Pin
                          |GREEN_2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : a0_Pin b0_Pin c0_Pin d0_Pin
                           e0_Pin f0_Pin g0_Pin */
  GPIO_InitStruct.Pin = a0_Pin|b0_Pin|c0_Pin|d0_Pin
                          |e0_Pin|f0_Pin|g0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

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
  __disable_irq();
  while (1)
  {
  }
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
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
