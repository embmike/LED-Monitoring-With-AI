# LED-Monitoring-With-AI

With the expansion package STM32Cube.AI, STMicroelectronics enables a neural network to be implemented on a microcontroller. In this example software, a DNN (Deep Neuronal Network) is created with Keras/Tensorflow, then imported into the C project using STM32Cube.AI and then executed on the Nucleo-F767ZI test board.
   
The example illustrates the feasibility and procedure.   
For mor information read blog post http://mike-netz.biz/?p=188. You can translate the German blog post to English using Google Super Translater.


## Installation and usage

Install the integrated development environment for STM32 microcontrollers.    
[STM32CubeIDE](https://www.st.com/en/development-tools/stm32cubeide.html)

Create a new folder for your STM32 projects, for example 'stm32_workspace' and clone repository
```sh
$ cd <your stm32-workspace folder>
$ git clone https://github.com/embmike/LED-Monitoring-With-AI.git
```

Then import the software:   
Click File > Import > General > Existing Projects into Workspace > Next > Browse to folder 'LED-Monitoring-With-AI > Finish

Install data science tool   
[Anaconda](https://www.anaconda.com/)

Then create a new anaconda environment and activate
```sh
$ conda env create -f env_tf_keras.yml
$ conda activate tf_keras
```
Open keras model and execute    
Start Anaconda Navigator > Enviroments > choose 'tf_keras' > Home > Start Spyder IDE > Open file 'env_tf_keras.yml' > Klick on 'Run File'


## Important files
- keras_dnn_led_monitoring.py : Keras dnn file
- LED_Monitoring.ioc : STM32CubeMX file for initialization and configuration using a graphical view
- Core/main.c : Main file of the program
- X-CUBE-AI/App/app_x-cube-ai.c : dnn in C
- Core/pil_printer.c : Debug outputs via UART-via-USB


## Licence
This project is licensed under the terms of the [![License: MIT](https://img.shields.io/badge/License-MIT-yellow.svg)](https://opensource.org/licenses/MIT)
