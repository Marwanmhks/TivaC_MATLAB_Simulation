#include "uart.h"

void InitI2C0(void)
{
	//enable I2C module 0
	MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_I2C0);

	//reset module
	MAP_SysCtlPeripheralReset(SYSCTL_PERIPH_I2C0);

	//enable GPIO peripheral that contains I2C 0
	MAP_SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
	MAP_GPIOPadConfigSet(GPIO_PORTB_BASE,GPIO_PIN_3|GPIO_PIN_4,GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD);
	
	// Configure the pin muxing for I2C0 functions on port B2 and B3.
	MAP_GPIOPinConfigure(GPIO_PB2_I2C0SCL);
	MAP_GPIOPinConfigure(GPIO_PB3_I2C0SDA);

	// Select the I2C function for these pins.
	MAP_GPIOPinTypeI2CSCL(GPIO_PORTB_BASE, GPIO_PIN_2);
	MAP_GPIOPinTypeI2C(GPIO_PORTB_BASE, GPIO_PIN_3);

	// Enable and initialize the I2C0 master module.  Use the system clock for
	// the I2C0 module.  The last parameter sets the I2C data transfer rate.
	// If false the data rate is set to 100kbps and if true the data rate will
	// be set to 400kbps.
	MAP_I2CMasterInitExpClk(I2C0_BASE, MAP_SysCtlClockGet(), false);

	//clear I2C FIFOs
	HWREG(I2C0_BASE + I2C_O_FIFOCTL) = 80008000;
}



void I2CSend(uint8_t slave_addr, uint8_t num_of_args, ...)
{
	// Tell the master module what address it will place on the bus when
	// communicating with the slave.
	MAP_I2CMasterSlaveAddrSet(I2C0_BASE, slave_addr, false);

	//stores list of variable number of arguments
	va_list vargs;

	//specifies the va_list to "open" and the last fixed argument
	//so vargs knows where to start looking
	va_start(vargs, num_of_args);

	//put data to be sent into FIFO
	MAP_I2CMasterDataPut(I2C0_BASE, va_arg(vargs, uint32_t));

	//if there is only one argument, we only need to use the
	//single send I2C function
	if (num_of_args == 1)
	{
		//Initiate send of data from the MCU
		MAP_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_SINGLE_SEND);

		// Wait until MCU is done transferring.
		while (MAP_I2CMasterBusy(I2C0_BASE));

		//"close" variable argument list
		va_end(vargs);
	}

	//otherwise, we start transmission of multiple bytes on the
	//I2C bus
	else
	{
		//Initiate send of data from the MCU
		MAP_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_START);

		// Wait until MCU is done transferring.
		while (MAP_I2CMasterBusy(I2C0_BASE));

		//send num_of_args-2 pieces of data, using the
		//BURST_SEND_CONT command of the I2C module
		for (uint8_t i = 1; i < (num_of_args - 1); i++)
		{
			//put next piece of data into I2C FIFO
			MAP_I2CMasterDataPut(I2C0_BASE, va_arg(vargs, uint32_t));
			//send next data that was just placed into FIFO
			MAP_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_CONT);

			// Wait until MCU is done transferring.
			while (MAP_I2CMasterBusy(I2C0_BASE));
		}

		//put last piece of data into I2C FIFO
		MAP_I2CMasterDataPut(I2C0_BASE, va_arg(vargs, uint32_t));
		//send next data that was just placed into FIFO
		MAP_I2CMasterControl(I2C0_BASE, I2C_MASTER_CMD_BURST_SEND_FINISH);
		// Wait until MCU is done transferring.
		while (MAP_I2CMasterBusy(I2C0_BASE));

		//"close" variable args list
		va_end(vargs);
	}
}





