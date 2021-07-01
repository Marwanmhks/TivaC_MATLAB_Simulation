#include "tm4c123gh6pm.h"
#include <stdint.h>
#include <stdbool.h>
#include <stdarg.h>
#include "math.h"
#include "inc/hw_i2c.h"
#include "inc/hw_ints.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/i2c.h"
#include "driverlib/interrupt.h"
#include "driverlib/pin_map.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
#include "driverlib/rom_map.h"

#define SLAVE_ADDRESS          0x3C




void InitI2C0(void);
void I2CSend(uint8_t slave_addr, uint8_t num_of_args, ...);