#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
/*
 * StellarisLaunchpad.cpp
 *
 *  Created on: 5 Nov 2012
 *      Author: tony
 */

#include "StellarisLaunchpad.h"

StellarisLaunchpad::StellarisLaunchpad() {
	ROM_SysCtlClockSet(
			SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ
					| SYSCTL_OSC_MAIN);
}

StellarisLaunchpad::~StellarisLaunchpad() {
}

