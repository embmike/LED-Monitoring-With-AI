
#ifdef __cplusplus
 extern "C" {
#endif
/**
  ******************************************************************************
  * @file           : app_x-cube-ai.c
  * @brief          : AI program body
  ******************************************************************************
  * This notice applies to any and all portions of this file
  * that are not between comment pairs USER CODE BEGIN and
  * USER CODE END. Other portions of this file, whether
  * inserted by the user or by software development tools
  * are owned by their respective copyright owners.
  *
  * Copyright (c) 2018 STMicroelectronics International N.V.
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice,
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other
  *    contributors to this software may be used to endorse or promote products
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under
  *    this license is void and will automatically terminate your rights under
  *    this license.
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS"
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include <string.h>
#include "app_x-cube-ai.h"
#include "main.h"
//#include "constants_ai.h"
#include "ai_datatypes_defines.h"

/* USER CODE BEGIN includes */
#include <math.h>
/* USER CODE END includes */
/* USER CODE BEGIN initandrun */
#include <stdlib.h>

/* Global handle to reference the instance of the NN */
static ai_handle led_monitoring_network = AI_HANDLE_NULL;
static ai_buffer ai_input[AI_LED_MONITORING_NETWORK_IN_NUM] = AI_LED_MONITORING_NETWORK_IN ;
static ai_buffer ai_output[AI_LED_MONITORING_NETWORK_OUT_NUM] = AI_LED_MONITORING_NETWORK_OUT ;

/*
 * Init function to create and initialize a NN.
 */
int aiInit(const ai_u8* activations)
{
    ai_error err;

    /* 1 - Specific AI data structure to provide the references of the
     * activation/working memory chunk and the weights/bias parameters */
    const ai_network_params params = {
            AI_LED_MONITORING_NETWORK_DATA_WEIGHTS(ai_led_monitoring_network_data_weights_get()),
            AI_LED_MONITORING_NETWORK_DATA_ACTIVATIONS(activations)
    };

    /* 2 - Create an instance of the NN */
    err = ai_led_monitoring_network_create(&led_monitoring_network, AI_LED_MONITORING_NETWORK_DATA_CONFIG);
    if (err.type != AI_ERROR_NONE) {
	    return -1;
    }

    /* 3 - Initialize the NN - Ready to be used */
    if (!ai_led_monitoring_network_init(led_monitoring_network, &params)) {
        err = ai_led_monitoring_network_get_error(led_monitoring_network);
        ai_led_monitoring_network_destroy(led_monitoring_network);
        led_monitoring_network = AI_HANDLE_NULL;
	    return -2;
    }

    return 0;
}

/*
 * Run function to execute an inference.
 */
int aiRun(const void *in_data, void *out_data)
{
    ai_i32 nbatch;
    ai_error err;

    /* Parameters checking */
    if (!in_data || !out_data || !led_monitoring_network)
        return -1;

    /* Initialize input/output buffer handlers */
    ai_input[0].n_batches = 1;
    ai_input[0].data = AI_HANDLE_PTR(in_data);
    ai_output[0].n_batches = 1;
    ai_output[0].data = AI_HANDLE_PTR(out_data);

    /* 2 - Perform the inference */
    nbatch = ai_led_monitoring_network_run(led_monitoring_network, &ai_input[0], &ai_output[0]);
    if (nbatch != 1) {
        err = ai_led_monitoring_network_get_error(led_monitoring_network);
        // ...
        return err.code;
    }

    return 0;
}
/* USER CODE END initandrun */

/*************************************************************************
  *
  */
void MX_X_CUBE_AI_Init(void)
{
    /* USER CODE BEGIN 0 */
    /* Activation/working buffer is allocated as a static memory chunk
     * (bss section) */
    AI_ALIGNED(4)
    static ai_u8 activations[AI_LED_MONITORING_NETWORK_DATA_ACTIVATIONS_SIZE];

    aiInit(activations);
    /* USER CODE END 0 */
}

uint8_t Switch_Led(ai_float arrOut_data[])
{
	uint8_t u8Result = 0;

	if( arrOut_data[0] > arrOut_data[1] && arrOut_data[0] > arrOut_data[2])
	{
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
	}
	else if( arrOut_data[1] > arrOut_data[0] && arrOut_data[1] > arrOut_data[2])
	{
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_SET);
		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
		u8Result = 1;
	}
	else if( arrOut_data[2] > arrOut_data[0] && arrOut_data[2] > arrOut_data[1])
	{
		HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, GPIO_PIN_RESET);
		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
		u8Result = 2;
	}

	return u8Result;
}

char* Led_State_As_String(uint8_t led_status, char out_info[])
{
	if( led_status == 0)
	{
		strcpy(out_info, "0 > OFF: All leds are off");
	}
	else if( led_status == 1)
	{
		strcpy(out_info, "1 > ON: Led green is on and led red is off");
	}
	else if( led_status == 2)
	{
		strcpy(out_info, "2 > FAILURE: Led green is off and led red is on");
	}

	return out_info;
}

ai_float* Set_arrOutData(ai_i8 out_data[], ai_float arrOut_data[])
{
    arrOut_data[0] = ((ai_float *)out_data)[0];
    arrOut_data[1] = ((ai_float *)out_data)[1];
    arrOut_data[2] = ((ai_float *)out_data)[2];

	return arrOut_data;
}

void MX_X_CUBE_AI_Process(void)
{
    /* USER CODE BEGIN 1 */
	/* Example of definition of the buffers to store the tensor input/output */
	/*  type is dependent of the expected format                             */
	AI_ALIGNED(4)
	static ai_i8 in_data[AI_LED_MONITORING_NETWORK_IN_1_SIZE_BYTES];

	AI_ALIGNED(4)
	static ai_i8 out_data[AI_LED_MONITORING_NETWORK_OUT_1_SIZE_BYTES];

	ai_float arrOutData[3];
	char sOutInfo[64] = {0};

    printf("###############################################################\n");
    printf("### Neural Network based on truth table of led monitoring   ###\n");
    printf("### UC x1 x2  y                                             ###\n");
    printf("###  1  0  0  2 > FAILURE > RED LED ON                      ###\n");
    printf("###  2  0  1  0 > OFF     > ALL LEDs OFF                    ###\n");
    printf("###  3  1  0  1 > ON      > GREEN LED ON                    ###\n");
    printf("###  4  1  1  2 > FAILURE > RED LED ON                      ###\n");
    printf("###############################################################\n\n");

    // Use case 1
    ((ai_float *)in_data)[0] = (ai_float) 0.0f;
    ((ai_float *)in_data)[1] = (ai_float) 0.0f;
    aiRun(in_data, out_data);

    Set_arrOutData(out_data, arrOutData);
    printf("Use case 1:\n");
    printf("Input = x1=%d and x2=%d\n", (int)round(((ai_float *)in_data)[0]), (int)round(((ai_float *)in_data)[1]));
    printf( "Output = [%.6f %.6f %.6f] > %s\n\n", arrOutData[0], arrOutData[1], arrOutData[2], Led_State_As_String(Switch_Led(arrOutData), sOutInfo) );
    HAL_Delay(5000);

    // Use case 2
    ((ai_float *)in_data)[0] = (ai_float) 0.0f;
    ((ai_float *)in_data)[1] = (ai_float) 1.0f;
    aiRun(in_data, out_data);

    Set_arrOutData(out_data, arrOutData);
    printf("Use case 2:\n");
    printf("Input = x1=%d and x2=%d\n", (int)round(((ai_float *)in_data)[0]), (int)round(((ai_float *)in_data)[1]));
    printf( "Output = [%.6f %.6f %.6f] > %s\n\n", arrOutData[0], arrOutData[1], arrOutData[2], Led_State_As_String(Switch_Led(arrOutData), sOutInfo) );
    HAL_Delay(5000);

    // Use case 3
    ((ai_float *)in_data)[0] = (ai_float) 1.0f;
    ((ai_float *)in_data)[1] = (ai_float) 0.0f;
    aiRun(in_data, out_data);

    Set_arrOutData(out_data, arrOutData);
    printf("Use case 3:\n");
    printf("Input = x1=%d and x2=%d\n", (int)round(((ai_float *)in_data)[0]), (int)round(((ai_float *)in_data)[1]));
    printf( "Output = [%.6f %.6f %.6f] > %s\n\n", arrOutData[0], arrOutData[1], arrOutData[2], Led_State_As_String(Switch_Led(arrOutData), sOutInfo) );
    HAL_Delay(5000);

    // Use case 4
    ((ai_float *)in_data)[0] = (ai_float) 1.0f;
    ((ai_float *)in_data)[1] = (ai_float) 1.0f;
    aiRun(in_data, out_data);

    Set_arrOutData(out_data, arrOutData);
    printf("Use case 4:\n");
    printf("Input = x1=%d and x2=%d\n", (int)round(((ai_float *)in_data)[0]), (int)round(((ai_float *)in_data)[1]));
    printf( "Output = [%.6f %.6f %.6f] > %s\n\n", arrOutData[0], arrOutData[1], arrOutData[2], Led_State_As_String(Switch_Led(arrOutData), sOutInfo) );

    printf("###############################################################\n\n");

    HAL_Delay(5000);
    /* USER CODE END 1 */
}
#ifdef __cplusplus
}
#endif
