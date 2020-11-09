/**
 * Copyright 2018 - 2020 HITSIC
 * All rights reserved.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef D_RT1052_SYS_EXTINT_PORT_HPP_
#define D_RT1052_SYS_EXTINT_PORT_HPP_

#include "hitsic_common.h"

#if defined(HITSIC_USE_EXTINT) && (HITSIC_USE_EXTINT > 0)

typedef GPIO_Type INTC_Type;
typedef gpio_interrupt_mode_t extInt_interruptMode_t;

#define EXTINT_InterruptOrDMADisabled   kGPIO_InterruptOrDMADisabled
#define EXTINT_DMARisingEdge            kGPIO_DMARisingEdge
#define EXTINT_DMAFallingEdge           kGPIO_DMAFallingEdge
#define EXTINT_DMAEitherEdge            kGPIO_DMAEitherEdge
#define EXTINT_InterruptLogicZero       kGPIO_InterruptLogicZero
#define EXTINT_InterruptRisingEdge      kGPIO_InterruptRisingEdge
#define EXTINT_InterruptFallingEdge     kGPIO_InterruptFallingEdge
#define EXTINT_InterruptEitherEdge      kGPIO_InterruptEitherEdge
#define EXTINT_InterruptLogicOne        kGPIO_InterruptLogicOne

#define EXTINT_SetInterruptConfig(_intc, _pin, _cfg)    GPIO_SetPinInterruptConfig(_intc, _pin, _cfg)
#define EXTINT_GetInterruptFlags(_intc)                 GPIO_GetPinsInterruptFlags(_intc)
#define EXTINT_ClearInterruptFlags(_intc, _mask)                GPIO_ClearPinsInterruptFlags(_intc, _mask)



#ifndef HITSIC_EXTMGR_INITLIZE
#define HITSIC_EXTMGR_INITLIZE      (1U)
#endif // ! HITSIC_EXTMGR_INITLIZE

#if defined(HITSIC_EXTMGR_INITLIZE) && (HITSIC_EXTMGR_INITLIZE > 0)
inline void EXTINT_PlatformInit(void)
{
    NVIC_SetPriority(GPIO1_Combined_0_15_IRQn, 6);
    NVIC_SetPriority(GPIO1_Combined_16_31_IRQn, 6);
    NVIC_SetPriority(GPIO2_Combined_0_15_IRQn, 6);
    NVIC_SetPriority(GPIO2_Combined_16_31_IRQn, 6);
    NVIC_SetPriority(GPIO3_Combined_0_15_IRQn, 6);
    NVIC_SetPriority(GPIO3_Combined_16_31_IRQn, 6);

    EnableIRQ(GPIO1_Combined_0_15_IRQn);
    EnableIRQ(GPIO1_Combined_16_31_IRQn);
    EnableIRQ(GPIO2_Combined_0_15_IRQn);
    EnableIRQ(GPIO2_Combined_16_31_IRQn);
    EnableIRQ(GPIO3_Combined_0_15_IRQn);
    EnableIRQ(GPIO3_Combined_16_31_IRQn);
}
#endif // ! HITSIC_EXTMGR_INITLIZE

#define HTISIC_EXTINT_DEFAULT_IRQ 	(1U)

inline INTC_Type* EXTINT_GetPortInst(GPIO_Type *gpio)
{
    return gpio;
}

#endif // ! HITSIC_USE_EXTINT

#endif // ! D_RT1052_SYS_EXTINT_PORT_HPP_
