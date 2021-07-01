#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"
#include "Water.h" /* Model's header file */
#include "uart.h"
#include "Sampling.h"




void rt_OneStep(void);
void vController();
void vTransmit();

	SemaphoreHandle_t xSemaphore;
	float x=0;
	
	 

int main(void){


	xSemaphore = xSemaphoreCreateBinary();
	
	MAP_SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);


	InitI2C0();
	
	xTaskCreate( vController, (const portCHAR *)"Controller", configMINIMAL_STACK_SIZE, NULL, 1, NULL );
xTaskCreate( vTransmit, (const portCHAR *)"Transmission" , configMINIMAL_STACK_SIZE, NULL, 2, NULL );
	vTaskStartScheduler();

}
void vController(){
		TickType_t xLastWakeTime;
		xLastWakeTime = xTaskGetTickCount();
		Water_initialize();

	for( ;; ){

    rt_OneStep();
		xSemaphoreGive(xSemaphore);
		vTaskDelayUntil( &xLastWakeTime, SamplingTime / portTICK_PERIOD_MS);
	}
}

void vTransmit(){
	
	for(;;){
		if( xSemaphoreTake( xSemaphore, ( TickType_t ) 10 ) == pdTRUE ){
			
			uint32_t ui32DataTx=x*10;
			I2CSend(SLAVE_ADDRESS, 1,ui32DataTx );
		
		}
	}
}

void rt_OneStep(void)
{
  static boolean_T OverrunFlag = false;

  /* Disable interrupts here */
	taskENTER_CRITICAL();
  /* Check for overrun */
  if (OverrunFlag) {
    return;
  }

  OverrunFlag = true;

  /* Save FPU context here (if necessary) */
  /* Re-enable timer or interrupt here */
	taskEXIT_CRITICAL();											//added
  /* Set model inputs here */
	rtU.In1=10;																//added
  /* Step the model */
  Water_step();

  /* Get model outputs here */
	x = rtY.Out1;															//added
  /* Indicate task complete */
  OverrunFlag = false;

  /* Disable interrupts here */
  /* Restore FPU context here (if necessary) */
  /* Enable interrupts here */
}



