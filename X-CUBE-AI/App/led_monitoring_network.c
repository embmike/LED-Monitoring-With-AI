/**
  ******************************************************************************
  * @file    led_monitoring_network.c
  * @author  AST Embedded Analytics Research Platform
  * @date    Mon Jan 18 14:38:18 2021
  * @brief   AI Tool Automatic Code Generator for Embedded NN computing
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2018 STMicroelectronics.
  * All rights reserved.
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */


#include "led_monitoring_network.h"

#include "ai_platform_interface.h"
#include "ai_math_helpers.h"

#include "core_common.h"
#include "layers.h"

#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#define AI_TOOLS_VERSION_MAJOR 5
#define AI_TOOLS_VERSION_MINOR 0
#define AI_TOOLS_VERSION_MICRO 0


#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#define AI_TOOLS_API_VERSION_MAJOR 1
#define AI_TOOLS_API_VERSION_MINOR 3
#define AI_TOOLS_API_VERSION_MICRO 0

#undef AI_NET_OBJ_INSTANCE
#define AI_NET_OBJ_INSTANCE g_led_monitoring_network
 
#undef AI_LED_MONITORING_NETWORK_MODEL_SIGNATURE
#define AI_LED_MONITORING_NETWORK_MODEL_SIGNATURE     "91438f89cc546d8cde808ace7c337963"

#ifndef AI_TOOLS_REVISION_ID
#define AI_TOOLS_REVISION_ID     "(rev-5.0.0)"
#endif

#undef AI_TOOLS_DATE_TIME
#define AI_TOOLS_DATE_TIME   "Mon Jan 18 14:38:18 2021"

#undef AI_TOOLS_COMPILE_TIME
#define AI_TOOLS_COMPILE_TIME    __DATE__ " " __TIME__

#undef AI_LED_MONITORING_NETWORK_N_BATCHES
#define AI_LED_MONITORING_NETWORK_N_BATCHES         (1)

/**  Forward network declaration section  *************************************/
AI_STATIC ai_network AI_NET_OBJ_INSTANCE;


/**  Forward network array declarations  **************************************/
AI_STATIC ai_array dense_58_bias_array;   /* Array #0 */
AI_STATIC ai_array dense_58_weights_array;   /* Array #1 */
AI_STATIC ai_array dense_57_bias_array;   /* Array #2 */
AI_STATIC ai_array dense_57_weights_array;   /* Array #3 */
AI_STATIC ai_array input_0_output_array;   /* Array #4 */
AI_STATIC ai_array dense_57_output_array;   /* Array #5 */
AI_STATIC ai_array activation_57_output_array;   /* Array #6 */
AI_STATIC ai_array dense_58_output_array;   /* Array #7 */
AI_STATIC ai_array activation_58_output_array;   /* Array #8 */


/**  Forward network tensor declarations  *************************************/
AI_STATIC ai_tensor dense_58_bias;   /* Tensor #0 */
AI_STATIC ai_tensor dense_58_weights;   /* Tensor #1 */
AI_STATIC ai_tensor dense_57_bias;   /* Tensor #2 */
AI_STATIC ai_tensor dense_57_weights;   /* Tensor #3 */
AI_STATIC ai_tensor input_0_output;   /* Tensor #4 */
AI_STATIC ai_tensor dense_57_output;   /* Tensor #5 */
AI_STATIC ai_tensor activation_57_output;   /* Tensor #6 */
AI_STATIC ai_tensor dense_58_output;   /* Tensor #7 */
AI_STATIC ai_tensor activation_58_output;   /* Tensor #8 */


/**  Forward network tensor chain declarations  *******************************/
AI_STATIC_CONST ai_tensor_chain dense_57_chain;   /* Chain #0 */
AI_STATIC_CONST ai_tensor_chain activation_57_chain;   /* Chain #1 */
AI_STATIC_CONST ai_tensor_chain dense_58_chain;   /* Chain #2 */
AI_STATIC_CONST ai_tensor_chain activation_58_chain;   /* Chain #3 */


/**  Forward network layer declarations  **************************************/
AI_STATIC ai_layer_dense dense_57_layer; /* Layer #0 */
AI_STATIC ai_layer_nl activation_57_layer; /* Layer #1 */
AI_STATIC ai_layer_dense dense_58_layer; /* Layer #2 */
AI_STATIC ai_layer_nl activation_58_layer; /* Layer #3 */


/**  Array declarations section  **********************************************/
AI_ARRAY_OBJ_DECLARE(
    dense_58_bias_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 3,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_58_weights_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 144,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_57_bias_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 48,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_57_weights_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 96,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    input_0_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
    NULL, NULL, 2,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_57_output_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 48,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    activation_57_output_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 48,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    dense_58_output_array, AI_ARRAY_FORMAT_FLOAT,
    NULL, NULL, 3,
     AI_STATIC)
AI_ARRAY_OBJ_DECLARE(
    activation_58_output_array, AI_ARRAY_FORMAT_FLOAT|AI_FMT_FLAG_IS_IO,
    NULL, NULL, 3,
     AI_STATIC)




/**  Tensor declarations section  *********************************************/
AI_TENSOR_OBJ_DECLARE(
  dense_58_bias, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &dense_58_bias_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_58_weights, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 48, 3, 1, 1), AI_STRIDE_INIT(4, 4, 192, 576, 576),
  1, &dense_58_weights_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_57_bias, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &dense_57_bias_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_57_weights, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 2, 48, 1, 1), AI_STRIDE_INIT(4, 4, 8, 384, 384),
  1, &dense_57_weights_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  input_0_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 2, 1, 1), AI_STRIDE_INIT(4, 4, 4, 8, 8),
  1, &input_0_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_57_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &dense_57_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  activation_57_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 48, 1, 1), AI_STRIDE_INIT(4, 4, 4, 192, 192),
  1, &activation_57_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  dense_58_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &dense_58_output_array, NULL)
AI_TENSOR_OBJ_DECLARE(
  activation_58_output, AI_STATIC,
  0x0, 0x0, AI_SHAPE_INIT(4, 1, 3, 1, 1), AI_STRIDE_INIT(4, 4, 4, 12, 12),
  1, &activation_58_output_array, NULL)


/**  Layer declarations section  **********************************************/


AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_57_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&input_0_output),
  AI_TENSOR_LIST_ENTRY(&dense_57_output),
  AI_TENSOR_LIST_ENTRY(&dense_57_weights, &dense_57_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_57_layer, 0,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &activation_57_layer, AI_STATIC,
  .tensors = &dense_57_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  activation_57_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&dense_57_output),
  AI_TENSOR_LIST_ENTRY(&activation_57_output),
  AI_TENSOR_LIST_EMPTY,
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  activation_57_layer, 1,
  NL_TYPE,
  nl, forward_relu,
  &AI_NET_OBJ_INSTANCE, &dense_58_layer, AI_STATIC,
  .tensors = &activation_57_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  dense_58_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&activation_57_output),
  AI_TENSOR_LIST_ENTRY(&dense_58_output),
  AI_TENSOR_LIST_ENTRY(&dense_58_weights, &dense_58_bias),
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  dense_58_layer, 2,
  DENSE_TYPE,
  dense, forward_dense,
  &AI_NET_OBJ_INSTANCE, &activation_58_layer, AI_STATIC,
  .tensors = &dense_58_chain, 
)

AI_TENSOR_CHAIN_OBJ_DECLARE(
  activation_58_chain, AI_STATIC_CONST, 4,
  AI_TENSOR_LIST_ENTRY(&dense_58_output),
  AI_TENSOR_LIST_ENTRY(&activation_58_output),
  AI_TENSOR_LIST_EMPTY,
  AI_TENSOR_LIST_EMPTY
)

AI_LAYER_OBJ_DECLARE(
  activation_58_layer, 3,
  NL_TYPE,
  nl, forward_sm,
  &AI_NET_OBJ_INSTANCE, &activation_58_layer, AI_STATIC,
  .tensors = &activation_58_chain, 
)


AI_NETWORK_OBJ_DECLARE(
  AI_NET_OBJ_INSTANCE, AI_STATIC,
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 1164, 1,
                     NULL),
  AI_BUFFER_OBJ_INIT(AI_BUFFER_FORMAT_U8,
                     1, 1, 204, 1,
                     NULL),
  AI_TENSOR_LIST_IO_ENTRY(AI_FLAG_NONE, AI_LED_MONITORING_NETWORK_IN_NUM, &input_0_output),
  AI_TENSOR_LIST_IO_ENTRY(AI_FLAG_NONE, AI_LED_MONITORING_NETWORK_OUT_NUM, &activation_58_output),
  &dense_57_layer, 0, NULL)



AI_DECLARE_STATIC
ai_bool led_monitoring_network_configure_activations(
  ai_network* net_ctx, const ai_buffer* activation_buffer)
{
  AI_ASSERT(net_ctx &&  activation_buffer && activation_buffer->data)

  ai_ptr activations = AI_PTR(AI_PTR_ALIGN(activation_buffer->data, 4));
  AI_ASSERT(activations)
  AI_UNUSED(net_ctx)

  {
    /* Updating activations (byte) offsets */
    input_0_output_array.data = AI_PTR(NULL);
    input_0_output_array.data_start = AI_PTR(NULL);
    dense_57_output_array.data = AI_PTR(activations + 0);
    dense_57_output_array.data_start = AI_PTR(activations + 0);
    activation_57_output_array.data = AI_PTR(activations + 0);
    activation_57_output_array.data_start = AI_PTR(activations + 0);
    dense_58_output_array.data = AI_PTR(activations + 192);
    dense_58_output_array.data_start = AI_PTR(activations + 192);
    activation_58_output_array.data = AI_PTR(NULL);
    activation_58_output_array.data_start = AI_PTR(NULL);
    
  }
  return true;
}



AI_DECLARE_STATIC
ai_bool led_monitoring_network_configure_weights(
  ai_network* net_ctx, const ai_buffer* weights_buffer)
{
  AI_ASSERT(net_ctx &&  weights_buffer && weights_buffer->data)

  ai_ptr weights = AI_PTR(weights_buffer->data);
  AI_ASSERT(weights)
  AI_UNUSED(net_ctx)

  {
    /* Updating weights (byte) offsets */
    
    dense_58_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_58_bias_array.data = AI_PTR(weights + 1152);
    dense_58_bias_array.data_start = AI_PTR(weights + 1152);
    dense_58_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_58_weights_array.data = AI_PTR(weights + 576);
    dense_58_weights_array.data_start = AI_PTR(weights + 576);
    dense_57_bias_array.format |= AI_FMT_FLAG_CONST;
    dense_57_bias_array.data = AI_PTR(weights + 384);
    dense_57_bias_array.data_start = AI_PTR(weights + 384);
    dense_57_weights_array.format |= AI_FMT_FLAG_CONST;
    dense_57_weights_array.data = AI_PTR(weights + 0);
    dense_57_weights_array.data_start = AI_PTR(weights + 0);
  }

  return true;
}


/**  PUBLIC APIs SECTION  *****************************************************/

AI_API_ENTRY
ai_bool ai_led_monitoring_network_get_info(
  ai_handle network, ai_network_report* report)
{
  ai_network* net_ctx = AI_NETWORK_ACQUIRE_CTX(network);

  if ( report && net_ctx )
  {
    ai_network_report r = {
      .model_name        = AI_LED_MONITORING_NETWORK_MODEL_NAME,
      .model_signature   = AI_LED_MONITORING_NETWORK_MODEL_SIGNATURE,
      .model_datetime    = AI_TOOLS_DATE_TIME,
      
      .compile_datetime  = AI_TOOLS_COMPILE_TIME,
      
      .runtime_revision  = ai_platform_runtime_get_revision(),
      .runtime_version   = ai_platform_runtime_get_version(),

      .tool_revision     = AI_TOOLS_REVISION_ID,
      .tool_version      = {AI_TOOLS_VERSION_MAJOR, AI_TOOLS_VERSION_MINOR,
                            AI_TOOLS_VERSION_MICRO, 0x0},
      .tool_api_version  = {AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR,
                            AI_TOOLS_API_VERSION_MICRO, 0x0},

      .api_version            = ai_platform_api_get_version(),
      .interface_api_version  = ai_platform_interface_api_get_version(),
      
      .n_macc            = 333,
      .n_inputs          = 0,
      .inputs            = NULL,
      .n_outputs         = 0,
      .outputs           = NULL,
      .activations       = AI_STRUCT_INIT,
      .params            = AI_STRUCT_INIT,
      .n_nodes           = 0,
      .signature         = 0x0,
    };

    if ( !ai_platform_api_get_network_report(network, &r) ) return false;

    *report = r;
    return true;
  }

  return false;
}

AI_API_ENTRY
ai_error ai_led_monitoring_network_get_error(ai_handle network)
{
  return ai_platform_network_get_error(network);
}

AI_API_ENTRY
ai_error ai_led_monitoring_network_create(
  ai_handle* network, const ai_buffer* network_config)
{
  return ai_platform_network_create(
    network, network_config, 
    &AI_NET_OBJ_INSTANCE,
    AI_TOOLS_API_VERSION_MAJOR, AI_TOOLS_API_VERSION_MINOR, AI_TOOLS_API_VERSION_MICRO);
}

AI_API_ENTRY
ai_handle ai_led_monitoring_network_destroy(ai_handle network)
{
  return ai_platform_network_destroy(network);
}

AI_API_ENTRY
ai_bool ai_led_monitoring_network_init(
  ai_handle network, const ai_network_params* params)
{
  ai_network* net_ctx = ai_platform_network_init(network, params);
  if ( !net_ctx ) return false;

  ai_bool ok = true;
  ok &= led_monitoring_network_configure_weights(net_ctx, &params->params);
  ok &= led_monitoring_network_configure_activations(net_ctx, &params->activations);

  return ok;
}


AI_API_ENTRY
ai_i32 ai_led_monitoring_network_run(
  ai_handle network, const ai_buffer* input, ai_buffer* output)
{
  return ai_platform_network_process(network, input, output);
}

AI_API_ENTRY
ai_i32 ai_led_monitoring_network_forward(ai_handle network, const ai_buffer* input)
{
  return ai_platform_network_process(network, input, NULL);
}

#undef AI_LED_MONITORING_NETWORK_MODEL_SIGNATURE
#undef AI_NET_OBJ_INSTANCE
#undef AI_TOOLS_VERSION_MAJOR
#undef AI_TOOLS_VERSION_MINOR
#undef AI_TOOLS_VERSION_MICRO
#undef AI_TOOLS_API_VERSION_MAJOR
#undef AI_TOOLS_API_VERSION_MINOR
#undef AI_TOOLS_API_VERSION_MICRO
#undef AI_TOOLS_DATE_TIME
#undef AI_TOOLS_COMPILE_TIME

