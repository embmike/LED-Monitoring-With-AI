/*
 * pil_printer.c
 *
 *  Created on: 03.04.2018
 *      Author: Admin
 */


#include "pil_printer.h"
#include "stm32f7xx_hal_uart.h"

static UART_HandleTypeDef *puUartHandle;

#ifdef __GNUC__
/* With GCC/RAISONANCE, small printf (option LD Linker->Libraries->Small printf
   set to 'Yes') calls __io_putchar() */
  #define PUTCHAR_PROTOTYPE int16_t __io_putchar(int16_t ch)
#else
  #define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
/* int32_t fputc(int32_t ch, FILE *f) */
#endif /* __GNUC__ */
PUTCHAR_PROTOTYPE;



/**
  * *******************************************************************************
  * @brief  Retargets the C library printf function to the USART.
  *
  * ********************************************************************************
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the EVAL_COM1 and Loop until the end of transmission */
  HAL_UART_Transmit(puUartHandle, (uint8_t *)&ch, 1, 0xFFFF);
//	HAL_UART_Transmit_IT(puUartHandle, (uint8_t *)&ch, 1);

  return ch;
}

#ifdef __GNUC__
/**
 **********************************************************************************
 * @brief  Retargets the C library printf function to the USART.
 *
 * ********************************************************************************
 */
int16_t _write(int16_t file, int8_t *ptr, int16_t len)
{
	HAL_UART_Transmit(puUartHandle, (uint8_t *)ptr, len, 0xFFFF);

	return len;
}
#endif /* __GNUC__ */

/**
 **********************************************************************************
 * @brief  Set UART handle.
 *
 * ********************************************************************************
 */
void Printer_Set_Uart(UART_HandleTypeDef *puUart)
{
	puUartHandle = puUart;
}
