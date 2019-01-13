#ifndef CMU_H_INCLUDED
#define CMU_H_INCLUDED

//***********************************************************************************
// Include files
//***********************************************************************************
#include "main.h"
#include "em_cmu.h"
#include "em_rtcc.h"

#include "letimer.h"

//***********************************************************************************
// defined files
//***********************************************************************************



//***********************************************************************************
// global variables
//***********************************************************************************

RTCC_Init_TypeDef rtcInit;

//***********************************************************************************
// function prototypes
//***********************************************************************************
void cmu_init(void);
void CalculatePrescalar(CMU_Select_TypeDef clkType);
//void CalculateHFPrescalar(CMU_Select_TypeDef clkType);
void CalculateComps(CMU_Select_TypeDef clkType);

void rtc_init(void);

#endif /*CMU_H_INCLUDED*/
