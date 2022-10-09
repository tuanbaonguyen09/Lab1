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
  int state = 1;
  while (1)
  {
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
	  HAL_GPIO_WritePin (GPIOA,l1_Pin|l2_Pin|l3_Pin|l4_Pin|l5_Pin|l6_Pin|l7_Pin|l8_Pin|l9_Pin|l10_Pin|l11_Pin|l12_Pin, GPIO_PIN_SET );
	  switch(state){
	  case 1:
		  HAL_GPIO_TogglePin (l1_GPIO_Port,l1_Pin) ;
		  state = 2;
		  break;
	  case 2:
		  HAL_GPIO_TogglePin (l2_GPIO_Port,l2_Pin) ;
		  state = 3;
		  break;
	  case 3:
		  HAL_GPIO_TogglePin (l3_GPIO_Port,l3_Pin) ;
		  state = 4;
		  break;
	  case 4:
		  HAL_GPIO_TogglePin (l4_GPIO_Port,l4_Pin) ;
		  state = 5;
		  break;
	  case 5:
		  HAL_GPIO_TogglePin (l5_GPIO_Port,l5_Pin) ;
		  state = 6;
		  break;
	  case 6:
		  HAL_GPIO_TogglePin (l6_GPIO_Port,l6_Pin) ;
		  state = 7;
		  break;
	  case 7:
		  HAL_GPIO_TogglePin (l7_GPIO_Port,l7_Pin) ;
		  state = 8;
		  break;
	  case 8:
		  HAL_GPIO_TogglePin (l8_GPIO_Port,l8_Pin) ;
		  state = 9;
		  break;
	  case 9:
		  HAL_GPIO_TogglePin (l9_GPIO_Port,l9_Pin) ;
		  state = 10;
		  break;
	  case 10:
		  HAL_GPIO_TogglePin (l10_GPIO_Port,l10_Pin) ;
		  state = 11;
		  break;
	  case 11:
		  HAL_GPIO_TogglePin (l11_GPIO_Port,l11_Pin) ;
		  state = 12;
		  break;
	  case 12:
		  HAL_GPIO_TogglePin (l12_GPIO_Port,l12_Pin) ;
		  state = 1;
		  break;
	  }
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

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, l1_Pin|l2_Pin|l3_Pin|l4_Pin
                          |l5_Pin|l6_Pin|l7_Pin|l8_Pin
                          |l9_Pin|l10_Pin|l11_Pin|l12_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : l1_Pin l2_Pin l3_Pin l4_Pin
                           l5_Pin l6_Pin l7_Pin l8_Pin
                           l9_Pin l10_Pin l11_Pin l12_Pin */
  GPIO_InitStruct.Pin = l1_Pin|l2_Pin|l3_Pin|l4_Pin
                          |l5_Pin|l6_Pin|l7_Pin|l8_Pin
                          |l9_Pin|l10_Pin|l11_Pin|l12_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

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
