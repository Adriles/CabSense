//***********************************************************************************
// Include files
//***********************************************************************************

#include <stdint.h>
#include <stdbool.h>
//#include "sleep.h"
//#include "gpio.h"
//#include <unistd.h>

/*
 * Credit for the sleep mechanism should be given to Silicon Labs. I agree to
 * the terms of the Silabs License Agreement ("Silabs_License_Agreement.txt")
 * in order to use their IP
*/

//***********************************************************************************
// defined files
//***********************************************************************************

#define HFXO_period	 40000000		// [periods/sec]
#define HFRCO_period 38000000		// [periods/sec]
#define LFXO_period 	32768		// [periods/sec]
#define ULFRCO_period 	1000		// [periods/sec]

#define min_sleep_mode 2

//***********************************************************************************
// global variables
//***********************************************************************************
uint32_t comp0_LFXO;
uint32_t comp0_ULFRCO;
uint32_t comp1_LFXO;
uint32_t comp1_ULFRCO;

uint32_t timerCompVal;

uint32_t LFXO_Prescalar;
uint32_t ULFRCO_Prescalar;
uint32_t HFXO_Prescalar;
uint32_t HFRCO_Prescalar;


uint8_t connection_handle;
/***********************************************************************************/
// function prototypes
//***********************************************************************************

