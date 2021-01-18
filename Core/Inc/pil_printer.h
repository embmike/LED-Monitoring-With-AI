/*
 * pil_printer.h
 *
 *  Created on: 03.04.2018
 *      Author: Admin
 */

#ifndef INC_PIL_PRINTER_H_
#define INC_PIL_PRINTER_H_

#include <stdio.h>					//!< Include Fuer Diagnose-Testausgaben ueber Uart3 notwentig
#include "stm32f7xx_hal.h"			//!< Include HAL-Funktionen

/**
********************************************************************************
* @fn		int16_t __io_putchar(int16_t ch);
* @brief	Ruft letztendlich HAL_UART_Transmit ueber printf(...) auf
* @author 	Technagon Team
*
* @date 	2018-02-28
*
* Diagnose-Textausgaben mit der Funktion printf("Info an Rechnerbildschirm") ueber Uart senden.
*
*********************************************************************************
*/
#ifdef __GNUC__
	int16_t __io_putchar(int16_t ch);
#endif /* __GNUC__ */

void Printer_Set_Uart(UART_HandleTypeDef *puUart);

#endif /* INC_PIL_PRINTER_H_ */
