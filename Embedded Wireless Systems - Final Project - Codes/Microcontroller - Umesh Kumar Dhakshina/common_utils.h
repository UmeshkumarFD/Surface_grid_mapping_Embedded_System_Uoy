/***********************************************************************************************************************
 * File Name    : common_utils.h
 * Description  : Contains macros, data structures, and functions commonly used in the example project (EP).
 ***********************************************************************************************************************/
/***********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
 * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
 * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
 * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
 * SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
 ***********************************************************************************************************************/

#ifndef COMMON_UTILS_H_
#define COMMON_UTILS_H_

/* Generic headers */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hal_data.h"

/* SEGGER RTT and error-related headers */
#include "SEGGER_RTT/SEGGER_RTT.h"

/* Macro Definitions */
#define BIT_SHIFT_8             (8u)       ///< Bit shift value for 8-bit operations
#define SIZE_64                 (64u)      ///< Size constant for 64 bytes

#define LVL_ERR                 (1u)       ///< Error level flag

#define RESET_VALUE             (0x00)     ///< Reset value for initialization

#define EP_VERSION              ("1.0")    ///< Example Project Version
#define MODULE_NAME             "r_icu"    ///< Module name for the project

/* Banner Information displayed on project start */
#define BANNER_INFO             "\r\n******************************************************************"\
                                "\r\n*   Renesas FSP Example Project for "MODULE_NAME" Module                 *"\
                                "\r\n*   Example Project Version %s                                  *"\
                                "\r\n*   Flex Software Pack Version  %d.%d.%d                            *"\
                                "\r\n******************************************************************"\
                                "\r\nRefer to readme.txt file for more details on Example Project and" \
                                "\r\nFSP User's Manual for more information about "MODULE_NAME" driver\r\n"

#define SEGGER_INDEX            (0)        ///< SEGGER RTT buffer index

/* Printing Macros */
#define APP_PRINT(fn_, ...)      SEGGER_RTT_printf(SEGGER_INDEX, (fn_), ##__VA_ARGS__) ///< General printing macro
#define APP_ERR_PRINT(fn_, ...)  if(LVL_ERR) \
                                 SEGGER_RTT_printf(SEGGER_INDEX, "[ERR] In Function: %s(), %s", __FUNCTION__, (fn_), ##__VA_ARGS__); ///< Error printing macro

#define APP_ERR_TRAP(err)        if(err) { \
                                 SEGGER_RTT_printf(SEGGER_INDEX, "\r\nReturned Error Code: 0x%x  \r\n", err); \
                                 __asm("BKPT #0\n");} ///< Error trapping macro, triggers a breakpoint on error

#define APP_READ(read_data)      SEGGER_RTT_Read(SEGGER_INDEX, read_data, sizeof(read_data)); ///< Macro to read data using SEGGER RTT
#define APP_CHECK_DATA           SEGGER_RTT_HasKey() ///< Macro to check if any key is pressed in SEGGER RTT

#endif /* COMMON_UTILS_H_ */
