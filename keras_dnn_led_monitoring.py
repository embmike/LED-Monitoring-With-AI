#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Jan 20 14:17:15 2019

@author: Mike Netz
"""
# Import Numpy and Keras utilities
import numpy as np
import tensorflow as tf
from tensorflow import keras
from tensorflow.keras import utils
from tensorflow.keras.models import Sequential
from tensorflow.keras.layers import Dense, Activation
from keras.utils import plot_model

#from keras import utils
#from keras.models import Sequential
#from keras.layers.core import Dense, Activation
#from keras.utils import plot_model

import matplotlib.pyplot as plt


# Set random seed
np.random.seed(42)

# Our data
# LED State
#
# x1 x2 y
# 0  0  2 > RED LED ON > FAILURE
# 0  1  0 > ALL LEDs OFF > OFF
# 1  0  1 > GREEN LED ON > ON
# 1  1  0 > > RED LED ON > FAILURE
#'
X = np.array([[0,0],[0,1],[1,0],[1,1]]).astype('float32')
y = np.array([[2],[0],[1],[2]]).astype('float32')


# One-hot encoding the output
y = utils.to_categorical(y)

# Building the model
led_monitoring = Sequential()

# Add required layers
led_monitoring.add(Dense(48, input_dim=X.shape[1]))
led_monitoring.add(Activation("relu"))
led_monitoring.add(Dense(3))
led_monitoring.add(Activation("softmax"))

# Specify loss as "binary_crossentropy", optimizer as "adam",
# and add the accuracy metric0led_monitoring.compile(loss="categorical_crossentropy", optimizer="adam", metrics = ["accuracy"])
led_monitoring.compile(loss="categorical_crossentropy", optimizer="adam", metrics = ["accuracy"])

# Uncomment this line to print the model architecture
led_monitoring.summary()

# Fitting the model
history = led_monitoring.fit(X, y, epochs=100, verbose=1)
#print('\nhistory dict:', history.history)

# plot model
plot_model(led_monitoring, to_file='led_monitoring_model.png')

# Scoring the model
score = led_monitoring.evaluate(X, y)
print("\nAccuracy: ", score[-1])

# Checking the predictions
print("\nPredictions:")
print(led_monitoring.predict_proba(X))

# Plot training & validation accuracy values
def ploti():
    plt.plot(history.history['accuracy'])
    plt.plot(history.history['loss'])
    plt.title('Model accuracy')
    plt.ylabel('Accuracy')
    plt.xlabel('Epoch')
    plt.legend(['Accuracy', 'Loss'], loc='upper left')
    plt.savefig('led_monitoring_plot.png', dpi=300)
    plt.show()
    
ploti()

# Save Model for STM32Cube.AI import
led_monitoring.save('led_monitoring.h5')
