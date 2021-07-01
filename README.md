# TivaC_MATLAB_Simulation
## Objective
Developing a closed-loop control embedded system real time operation.
## Project Description
Generating a MATLAB Simulink physical model and generating its MATLAB code. Then implementing it on Tive C Evaluation board. Furthermore, communicating between two Tiva boards and serially transmitting data into the PC Excel file to be graphed and then validated and verified with the MATLAB output scope.
## Project Flowchart

## Connections Diagram


## MATLAB Model

## Sampling Time
The time 𝜏 required to reach 63% of the maximum output is 2.369s. According to Nyquist “Sampling Theory” the sampling rate is at least half the time constant, but for more accurate and practical representation we assumed the sampling time to be 110 𝜏.
We attached rt_OneStep to a periodic task with a period of 237ms (the model's base sample time).


## Project operation
Task vController gets created which initializes the water tank level simulator, rt_OneStep is called to get the simulation values to be sent and give semaphore to vTransmit to gets unblocked then sends the data then the task blocks itself for the sampling time duration using vTaskDelayUntil.
The Slave waits for the input which fires the ISR then the interrupt service routine saves the data into a global variable and calls xSemaphoreGiveFromISR which unblocks the continuous task vTransmit which displays the data on the terminal.
And then the whole process gets repeated.

## Functions Description

## Results
