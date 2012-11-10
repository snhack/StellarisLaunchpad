/*
 * StellarisPort.cpp
 *
 *  Created on: 9 Nov 2012
 *      Author: tony
 */
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/rom.h"
#include "StellarisPort.h"

StellarisPort::StellarisPort(long sysctlPort) {
	ROM_SysCtlPeripheralEnable(sysctlPort);
}

StellarisPort::~StellarisPort() {
}

