#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "semphr.h"
#include "init_uart.h"


SemaphoreHandle_t xSemaphore;


void vTransmit();
static uint32_t g_ui32DataRx;


// The interrupt handler for the for I2C0 data slave interrupt.
void I2C0SlaveIntHandler(void)
{		
		
		portBASE_TYPE xHigherPriorityTaskwoken = pdFALSE;
    // Clear the I2C0 interrupt flag.
    I2CSlaveIntClear(I2C0_BASE);
    // Read the data from the slave.
		g_ui32DataRx =I2CSlaveDataGet(I2C0_BASE);
    I2CSlaveStatus(I2C0_BASE);
		xSemaphoreGiveFromISR(xSemaphore,&xHigherPriorityTaskwoken);
		portEND_SWITCHING_ISR(&xHigherPriorityTaskwoken);

}


	 
int main(void){

		xSemaphore = xSemaphoreCreateBinary();

		MAP_SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ);
		uart0_init();
		InitI2C0();
		IntEnable(INT_I2C0);
    I2CSlaveIntEnableEx(I2C0_BASE, I2C_SLAVE_INT_DATA);
    I2CSlaveEnable(I2C0_BASE);
    I2CSlaveInit(I2C0_BASE, SLAVE_ADDRESS);
		I2CIntRegister(I2C0_BASE,I2C0SlaveIntHandler);
		IntPrioritySet(INT_I2C0,configMAX_SYSCALL_INTERRUPT_PRIORITY);
    IntMasterEnable();
		xTaskCreate( vTransmit, (const portCHAR *)"Transmitter", configMINIMAL_STACK_SIZE, NULL, 1, NULL );
		vTaskStartScheduler();

}


void vTransmit(){
	volatile float t=0;
	volatile float value=0;
	for(;;){
	if( xSemaphoreTake( xSemaphore, ( TickType_t ) 0 ) == pdTRUE ){
			char buffer[60];
			char z[20];
			
			ftoa(t,z,3);
			UARTSend(UART0_BASE, (uint8_t*)z,strlen(z));
			UARTSend(UART0_BASE, (uint8_t *)"\t", strlen("\t"));
			t+=0.237;
			
			value=(float)g_ui32DataRx/10.0;
			ftoa(value,buffer,2);
			UARTSend(UART0_BASE, (uint8_t*)buffer,strlen(buffer));
			UARTSend(UART0_BASE, (uint8_t *)"\n\r", strlen("\n\r"));
		}
	}
}



