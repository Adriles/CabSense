#include "cmu.h"
#include "em_timer.h"
#include "native_gecko.h"


#define LETIMER_period		2.000		//2000 milliseconds period
#define LETIMER_sensor_on	(LETIMER_period - SENSOR_pwr_on_period)	//80 ms after LETIMER triggers, take a reading

//#define si720_por_period	(LETIMER_period - TIMER_pwr_on_period)		//80 milliseconds after LETIMER triggers
#define led_off_period		1.00		// 1 second period for LED testing
#define SENSOR_pwr_on_period		0.08		//80 milliseconds period

#define LETIMER_OVERFLOW	65536		//16-bit counter overflow value
#define TIMER_OVERFLOW		65536		// want to use in 16-bit overflow mode



uint8_t letimer_flag;

// somewhat misleadingly named, init's the letimer
void letimer0_init(CMU_Select_TypeDef clkType, SLEEP_EnergyMode_t EMx);
