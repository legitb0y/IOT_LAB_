/*
* Copyright (c) 2020 - 2024 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "hal_data.h"

void R_BSP_WarmStart(bsp_warm_start_event_t event);

extern bsp_leds_t g_bsp_leds;

/*******************************************************************************************************************//**
 * @brief  Blinky example application
 *
 * Blinks all leds at a rate of 1 second using the software delay function provided by the BSP.
 *
 **********************************************************************************************************************/
void hal_entry (void)
{
#if BSP_TZ_SECURE_BUILD

    /* Enter non-secure code */
    R_BSP_NonSecureEnter();
#endif

    /* Define the units to be used with the software delay function */
    const bsp_delay_units_t bsp_delay_units = BSP_DELAY_UNITS_MILLISECONDS;

    /* Set the blink frequency (must be <= bsp_delay_units */
    const uint32_t freq_in_hz = 2;

    /* Calculate the delay in terms of bsp_delay_units */
    const uint32_t delay = bsp_delay_units / freq_in_hz;

    /* LED type structure */
    bsp_leds_t leds = g_bsp_leds;

    /* If this board has no LEDs then trap here */
    if (0 == leds.led_count)
    {
        while (1)
        {
            ;                          // There are no LEDs on this board
        }
    }

    R_BSP_PinAccessEnable();
           /* turn off RGB led*/
           uint32_t three_color_pin = leds.p_leds[3];
           uint32_t four_color_pin = leds.p_leds[4];
           uint32_t five_color_pin = leds.p_leds[5];
            /* Set all LEDs to off initially */
            R_BSP_PinWrite((bsp_io_port_pin_t) three_color_pin, BSP_IO_LEVEL_HIGH);
            R_BSP_PinWrite((bsp_io_port_pin_t) four_color_pin, BSP_IO_LEVEL_HIGH);
            R_BSP_PinWrite((bsp_io_port_pin_t) five_color_pin, BSP_IO_LEVEL_HIGH);

       R_BSP_PinAccessDisable();
     while (1)
    {
        /* Enable access to the PFS registers. If using r_ioport module then register protection is automatically
         * handled. This code uses BSP IO functions to show how it is used.
         */
        R_BSP_PinAccessEnable();

        /* Update board LED sequentially */
        for (uint32_t i = 0; i < leds.led_count && i!=3; i++)
        {
            /* Get pin to toggle */
            uint32_t pin = leds.p_leds[i];

            /* Write to this pin */
            R_BSP_PinWrite((bsp_io_port_pin_t)pin, BSP_IO_LEVEL_HIGH);  // Turn on the current LED

            /* Delay for the current LED to be on */
            R_BSP_SoftwareDelay(delay, bsp_delay_units);

            /* Turn off the current LED */
            R_BSP_PinWrite((bsp_io_port_pin_t)pin, BSP_IO_LEVEL_LOW);
        }

        /* Protect PFS registers */
        R_BSP_PinAccessDisable();
    }
}

/*******************************************************************************************************************//**
 * This function is called at various points during the startup process.  This implementation uses the event that is
 * called right before main() to set up the pins.
 *
 * @param[in]  event    Where at in the start up process the code is currently at
 **********************************************************************************************************************/
void R_BSP_WarmStart (bsp_warm_start_event_t event)
{
    if (BSP_WARM_START_RESET == event)
    {
#if BSP_FEATURE_FLASH_LP_VERSION != 0

        /* Enable reading from data flash. */
        R_FACI_LP->DFLCTL = 1U;

        /* Would normally have to wait tDSTOP(6us) for data flash recovery. Placing the enable here, before clock and
         * C runtime initialization, should negate the need for a delay since the initialization will typically take more than 6us. */
#endif
    }

    if (BSP_WARM_START_POST_C == event)
    {
        /* C runtime environment and system clocks are setup. */

        /* Configure pins. */
        R_IOPORT_Open(&IOPORT_CFG_CTRL, &IOPORT_CFG_NAME);
    }
}
