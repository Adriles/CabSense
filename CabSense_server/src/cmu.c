//***********************************************************************************
// Include files
//***********************************************************************************
#include "cmu.h"

//***********************************************************************************
// defined files
//***********************************************************************************


//***********************************************************************************
// global variables
//***********************************************************************************


//***********************************************************************************
// function prototypes
//***********************************************************************************



/*
 * Before programming a peripheral, its clock tree must be configured and enabled
 *
 * Set the oscillator frequency
 * Enable its oscillator
 * Configure the oscillator to the clock tree
 * Program the peripheral prescalar
 * Enable the peripheral clock
 */
void cmu_init(void){
	// Peripheral clocks enabled
	CMU_ClockEnable(cmuClock_GPIO, true);

	if(min_sleep_mode < 3)
	{
		CMU_OscillatorEnable(cmuOsc_LFXO, true, true);
		CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_LFXO);
		CalculatePrescalar(cmuSelect_LFXO);

		// sets the prescalar for a clock that'll be driving LETIMER
		//CMU_ClockPrescSet(cmuClock_LFA, LFXO_Prescalar);

		while ((CMU->SYNCBUSY & CMU_SYNCBUSY_LFAPRESC0) != 0UL)

		CMU->LFAPRESC0 = CMU->LFAPRESC0 & 0;

		CMU->LFAPRESC0 = (CMU->LFAPRESC0 | LFXO_Prescalar);


	}
	else if(min_sleep_mode == 3)
	{
		CMU_OscillatorEnable(cmuOsc_ULFRCO, true, true);
		CMU_ClockSelectSet(cmuClock_LFA, cmuSelect_ULFRCO);
		CalculatePrescalar(cmuSelect_ULFRCO);
		CMU_ClockPrescSet(cmuClock_LFA, ULFRCO_Prescalar);
	}

	//CMU_ClockEnable(cmuClock_LFA, true);
	CMU_ClockEnable(cmuClock_CORELE, true);

	CMU_ClockEnable(cmuClock_LETIMER0, true);

	// clocks required for the I2C peripheral
	// need the high-frequency clock
	//CMU_OscillatorEnable(cmuOsc_HFRCO, true, true);
	//sCMU_ClockSelectSet(cmuClock_HF, cmuSelect_HFXO);

	CMU_ClockEnable(cmuClock_HFPER, true);
	//CMU_ClockEnable(cmuClock_TIMER0, true);
	CMU_ClockEnable(cmuClock_I2C0, true);

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void rtc_init(void)
{
	rtcInit.enable = false;
	rtcInit.debugRun = true;
	rtcInit.disLeapYearCorr = false;
	rtcInit.enaOSCFailDetect = false;
	rtcInit.precntWrapOnCCV0 = false;
	rtcInit.cntWrapOnCCV1 = false;
	rtcInit.presc = rtccCntPresc_32;
	rtcInit.prescMode = rtccCntTickPresc;
	rtcInit.cntMode = rtccCntModeNormal;
	rtcInit.disLeapYearCorr = false;


	//configure the System Reset Mode to be LIMITED instead of EXTENDED in the RMU (Reset Management Unit)
	RMU->CTRL = (RMU->CTRL & (~_RMU_CTRL_SYSRMODE_MASK)) | RMU_CTRL_SYSRMODE_LIMITED;

	RTCC_Init(&rtcInit);

	RTCC_Enable(true);

	return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CalculatePrescalar(CMU_Select_TypeDef clkType)
{
	float temp;

	float a = LFXO_period;		//casting to enable float division
	float b = ULFRCO_period;
	float c = LETIMER_OVERFLOW;

	if(clkType == cmuSelect_LFXO)
	{
		temp = (float)((LETIMER_period)*(a/c));
		if(temp < 1)		//if period is less than 2 seconds
		{
			LFXO_Prescalar = 0;	//cmuClkDiv_1;
		}
		else if(temp < 2)	//if period is less than 4 seconds
		{
			LFXO_Prescalar = 1;	//cmuClkDiv_2;
		}
		else if(temp < 4)	//if period is less than 8 seconds
		{
			LFXO_Prescalar = 2;	//cmuClkDiv_4;
		}
		else if(temp < 8)	//if period is less than 16 seconds
		{
			LFXO_Prescalar = 3;	//cmuClkDiv_8;
		}
	}
	else if(clkType == cmuSelect_ULFRCO)
	{
		temp = (float)((LETIMER_period)*(b/c));
		if(temp < 1)		//if period is less than 66 seconds
		{
			ULFRCO_Prescalar = cmuClkDiv_1;
		}
		else if(temp < 2)	//if period is less than 123 seconds
		{
			ULFRCO_Prescalar = cmuClkDiv_2;
		}
	}
	return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void CalculateComps(CMU_Select_TypeDef clkType)
{
	//only need to set comp0 and comp1 for one clock
	// the lowest possible EM-mode determines whether I'll be using LFXO || ULFRCO

	float le_clk_period, le_clk_scalar;

	if(clkType == cmuSelect_LFXO)
	{
		le_clk_period = (float)LFXO_period;
		le_clk_scalar = (float)(1 << LFXO_Prescalar);
		comp0_LFXO = (LETIMER_period)*(le_clk_period/le_clk_scalar);
		comp1_LFXO = (LETIMER_sensor_on)*(le_clk_period/le_clk_scalar);
	}
	else if(clkType == cmuSelect_ULFRCO)
	{
		le_clk_period = (float)ULFRCO_period;
		le_clk_scalar = (float)(1 << ULFRCO_Prescalar);
		comp0_ULFRCO = (LETIMER_period)*(le_clk_period/le_clk_scalar);
		comp1_ULFRCO = (LETIMER_sensor_on)*(le_clk_period/le_clk_scalar);
	}

	return;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*void CalculateHFPrescalar(CMU_Select_TypeDef clkType)
{
	float temp;

	float a = HFRCO_period;		//casting to enable float division
	float b = HFXO_period;
	float c = TIMER_OVERFLOW;

	if(clkType == cmuSelect_HFRCO)
	{
		temp = (float)((TIMER_period)*(a/c));
		if(temp < 1)		//if period is less than 2 seconds
		{
			HFRCO_Prescalar = 0;	//cmuClkDiv_1;
		}
		else if(temp < 2)	//if period is less than 4 seconds
		{
			HFRCO_Prescalar = 1;	//cmuClkDiv_2;
		}
		else if(temp < 4)	//if period is less than 8 seconds
		{
			HFRCO_Prescalar = 2;	//cmuClkDiv_4;
		}
		else if(temp < 8)	//if period is less than 16 seconds
		{
			HFRCO_Prescalar = 3;	//cmuClkDiv_8;
		}
		else if(temp < 16)
		{
			HFRCO_Prescalar = 4;
		}
		else if(temp < 32)
		{
			HFRCO_Prescalar = 5;
		}
		else if(temp < 64)
		{
			HFRCO_Prescalar = 6;
		}
	}
	else if(clkType == cmuSelect_HFXO)
		{
			temp = (float)((TIMER_period)*(b/c));
			if(temp < 1)		//if period is less than 2 seconds
			{
				HFXO_Prescalar = 0;	//cmuClkDiv_1;
			}
			else if(temp < 2)	//if period is less than 4 seconds
			{
				HFXO_Prescalar = 1;	//cmuClkDiv_2;
			}
			else if(temp < 4)	//if period is less than 8 seconds
			{
				HFXO_Prescalar = 2;	//cmuClkDiv_4;
			}
			else if(temp < 8)	//if period is less than 16 seconds
			{
				HFXO_Prescalar = 3;	//cmuClkDiv_8;
			}
			else if(temp < 16)
			{
				HFXO_Prescalar = 4;
			}
			else if(temp < 32)
			{
				HFXO_Prescalar = 5;
			}
			else if(temp < 64)
			{
				HFXO_Prescalar = 6;
			}
		}
	return;
}*/



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

