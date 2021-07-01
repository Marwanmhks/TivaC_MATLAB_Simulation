# TivaC_MATLAB_Simulation
## Objective
Developing a closed-loop control embedded system real time operation.
## Project Description
Generating a MATLAB Simulink physical model and generating its MATLAB code. Then implementing it on Tive C Evaluation board using FreeRTOS. Furthermore, communicating between two Tiva C boards and serially transmitting data into the PC Excel file to be graphed and then validated and verified with the MATLAB output scope.
## Project Flowchart
![flowchart](https://user-images.githubusercontent.com/66640498/124151494-e7903480-da92-11eb-9c0a-97e613622c8f.PNG)
## Connections Diagram
![connection diagram](https://user-images.githubusercontent.com/66640498/124151842-45248100-da93-11eb-8ad1-cc71532532f6.PNG)
## MATLAB Model
![Model](https://user-images.githubusercontent.com/66640498/124151873-4bb2f880-da93-11eb-9228-c83c17d4e95e.JPG)
### Water-Tank Subsystem
![Water Tank System](https://user-images.githubusercontent.com/66640498/124151883-4eade900-da93-11eb-8b3a-1a475dfc244b.JPG)
## Sampling Time
The time 𝜏 required to reach 63% of the maximum output is 2.369s. According to Nyquist “Sampling Theory” the sampling rate is at least half the time constant, but for more accurate and practical representation we assumed the sampling time to be 110 𝜏.
We attached rt_OneStep to a periodic task with a period of 237ms (the model's base sample time).
## Project operation
Task vController gets created which initializes the water tank level simulator, rt_OneStep is called to get the simulation values to be sent and give semaphore to vTransmit to gets unblocked then sends the data then the task blocks itself for the sampling time duration using vTaskDelayUntil.
The Slave waits for the input which fires the ISR then the interrupt service routine saves the data into a global variable and calls xSemaphoreGiveFromISR which unblocks the continuous task vTransmit which displays the data on the terminal.
And then the whole process gets repeated.
## Functions Description
![function description](https://user-images.githubusercontent.com/66640498/124151930-57062400-da93-11eb-8788-82973c611c75.PNG)
## Results
![Validation and Verification](https://user-images.githubusercontent.com/66640498/124152001-68e7c700-da93-11eb-8280-521e1dac0f7b.JPG)
