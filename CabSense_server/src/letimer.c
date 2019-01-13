#include "letimer.h"
#include "gpio.h"
#include <em_letimer.h>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


// initialize the LETIMER peripheral
void letimer0_init(CMU_Select_TypeDef clkType, SLEEP_EnergyMode_t EMx)
{
	blockSleepMode(EMx);

	// clear the LETIMER registers and preset with desired values
	LETIMER_Init_TypeDef init0 = {
		false,
		false,
		true,
		false,
		0,
		0,
		letimerUFOANone,
		letimerUFOANone,
		letimerRepeatFree
	};

	CalculateComps(clkType);

	// set the values at which LETIMER interrupts will trigger in comp0 and comp1
	if(clkType == cmuSelect_LFXO)
	{
		LETIMER_CompareSet(LETIMER0, 0, comp0_LFXO);
		LETIMER_CompareSet(LETIMER0, 1, comp1_LFXO);
	}
	else if(clkType == cmuSelect_ULFRCO)
	{
		LETIMER_CompareSet(LETIMER0, 0, comp0_ULFRCO);
		LETIMER_CompareSet(LETIMER0, 1, comp1_ULFRCO);
	}
	LETIMER_Init(LETIMER0, &init0);

	//wait for syncbusy to clear, ensures synchronization with the low-freq domain
	while (LETIMER0->SYNCBUSY);

	//enable the COMP0 LETIMER interrupt
	LETIMER_IntEnable(LETIMER0, LETIMER_IEN_COMP0 | LETIMER_IEN_COMP1);

	//clear interrupt flags
	LETIMER_IntClear(LETIMER0, LETIMER0->IEN);


	//NVIC handler needs to be enabled, otherwise the CPU doesn't know when the interrupt has occurred
	NVIC_EnableIRQ(LETIMER0_IRQn);

	LETIMER_Enable(LETIMER0, true);

	return;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// LETIMER IRQ handler
// override the generic handler to implement intended functionality
void LETIMER0_IRQHandler(void)
{
	//CORE_ATOMIC_IRQ_DISABLE();
	uint32_t IRQ_flags;
	IRQ_flags = LETIMER0->IF;
	LETIMER0->IFC = IRQ_flags;

	// depending on which LETIMER interrupt has thrown, queue up a different external_signal event to process
	if((IRQ_flags & LETIMER_IF_COMP0) == LETIMER_IF_COMP0)
	{
		// COMP0 is the top of my LETIMER count. turn on my LED
		gecko_external_signal(0x01);
	}
	if((IRQ_flags & LETIMER_IF_COMP1) == LETIMER_IF_COMP1)
	{
		// COMP1 is 1 [s] after the top of LETIMER count. Using to turn off my LED
		// Was: Sensor power-on time has transpired, take a reading
		gecko_external_signal(0x10);
	}

	//CORE_ATOMIC_IRQ_ENABLE();
	return;
}


