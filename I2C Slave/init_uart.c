#include "init_uart.h"


void uart0_init(){

    MAP_SysCtlClockSet(SYSCTL_SYSDIV_1 | SYSCTL_USE_OSC | SYSCTL_OSC_MAIN |SYSCTL_XTAL_16MHZ);
 
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);

    // Set GPIO A0 and A1 as UART pins.
    MAP_GPIOPinConfigure(GPIO_PA0_U0RX);
    MAP_GPIOPinConfigure(GPIO_PA1_U0TX);
    MAP_GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
	
    // Configure the UART for 115,200, 8-N-1 operation.
    MAP_UARTConfigSetExpClk(UART0_BASE, MAP_SysCtlClockGet(), 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

}


void InitI2C0(void)
{
	MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);

	MAP_SysCtlPeripheralReset(SYSCTL_PERIPH_I2C0);

	//enable GPIO peripheral that contains I2C 0
	MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

	// Configure the pin muxing for I2C0 functions on port B2 and B3.
	MAP_GPIOPinConfigure(GPIO_PB2_I2C0SCL);
	MAP_GPIOPinConfigure(GPIO_PB3_I2C0SDA);

	// Select the I2C function for these pins.
	MAP_GPIOPinTypeI2CSCL(GPIO_PORTB_BASE, GPIO_PIN_2);
	MAP_GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_3);
	
	//clear I2C FIFOs
	HWREG(I2C0_BASE + I2C_O_FIFOCTL) = 80008000;
}


void UARTSend(uint32_t ui32UARTBase, const uint8_t *pui8Buffer, uint32_t ui32Count){
    
    while(ui32Count--)  {  // Loop while there are more characters to send.
 
        MAP_UARTCharPut(ui32UARTBase, *pui8Buffer++);
    }
}
 


// Reverses a string 'str' of length 'len' 
void reverse(char* str, int len) 
{ 
	int i = 0, j = len - 1, temp; 
	while (i < j) { 
		temp = str[i]; 
		str[i] = str[j]; 
		str[j] = temp; 
		i++; 
		j--; 
	} 
} 

// Converts a given integer x to string str[]. 
// d is the number of digits required in the output. 
// If d is more than the number of digits in x, 
// then 0s are added at the beginning. 
int intToStr(int x, char str[], int d) 
{ 
	
	int i = 0; 
	do { 
		str[i++] = (x % 10) + '0'; 
		x = x / 10; 
	} while (x);

	// If number of digits required is more, then 
	// add 0s at the beginning 
	while (i < d) 
		str[i++] = '0'; 

	reverse(str, i); 
	str[i] = '\0'; 
	return i; 
} 

// Converts a floating-point/double number to a string. 
void ftoa(float n, char* res, int afterpoint) 
{ 
	
	
	// Extract integer part 
	int ipart = (int)n; 

	// Extract floating part 
	float fpart = n - (float)ipart; 

	// convert integer part to string 
	int i = intToStr(ipart, res, 0); 

	// check for display option after point 
	if (afterpoint != 0) { 
		res[i] = '.'; // add dot 

		// Get the value of fraction part upto given no. 
		// of points after dot. The third parameter 
		// is needed to handle cases like 233.007 
		fpart = fpart * pow(10, afterpoint); 

		intToStr((int)fpart, res + i + 1, afterpoint); 
	} 
} 





