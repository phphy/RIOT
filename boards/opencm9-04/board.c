/*
 * Copyright (C) 2017 INRIA
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_opencm9-04
 * @{
 *
 * @file
 * @brief       Board specific implementations for the OpenCM9.04 board
 *
 * @author      Loïc Dauphin <loic.dauphin@inria.fr>
 *
 * @}
 */

#include "board.h"
#include "periph/gpio.h"
#include "log.h"

void board_init(void)
{
    /* initialize the CPU */
    cpu_init();

    /* initialize the board's LED */
    gpio_init(LED0_PIN, GPIO_OUT);
    LED0_OFF;

    /* disable bootloader's USB */
    RCC->APB1ENR &= ~RCC_APB1ENR_USBEN;

    /* configure the RIOT vector table location to internal flash + bootloader offset */
    SCB->VTOR = LOCATION_VTABLE;
}
