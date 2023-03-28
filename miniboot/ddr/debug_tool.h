#ifndef __DEBUG_TOOL_H__
#define __DEBUG_TOOL_H__
/*****************************************************************************/
/*                                                                           */
/*                     HozironRobtics MMC MAC SOFTWARE                       */
/*                                                                           */
/*                  Horizon Robtics SYSTEMS LTD                              */
/*                           COPYRIGHT(C) 2019                               */
/*                                                                           */
/*  This program  is  proprietary to  Ittiam  Systems  Private  Limited  and */
/*  is protected under china Copyright Law as an unpublished work. Its use   */
/*  and  disclosure  is  limited by  the terms  and  conditions of a license */
/*  agreement. It may not be copied or otherwise  reproduced or disclosed to */
/*  persons outside the licensee's organization except in accordance with the*/
/*  terms  and  conditions   of  such  an  agreement.  All  copies  and      */
/*  reproductions shall be the property of HorizonRobtics Systems Private    */
/*    Limited and must bear this notice in its entirety.                     */
/*                                                                           */
/*****************************************************************************/

/*****************************************************************************/
/*                                                                           */
/*  File Name         : debug_tool.h                                         */
/*                                                                           */
/*  Description       : This file contains all the declarations related to   */
/*                      DDR debug tool.                                      */
/*                                                                           */
/*  Issues / Problems : None                                                 */
/*                                                                           */
/*  Revision History  :                                                      */
/*                                                                           */
/*         DD MM YYYY   Author(s)       Changes                              */
/*         05 12 2019   shaochuanzhang@hobot.cc  Draft                       */
/*                                                                           */
/*****************************************************************************/


/* Function declaration. */

void debug_tool_init(void);
void debug_tool_input_odt(unsigned long addr);
void debug_tool_input_phy_ds(unsigned long addr);
void debug_tool_input_x_delay(unsigned long addr);
void debug_tool_input_y_vref(unsigned long addr);
void debug_tool_output(void);
void debug_tool_output_all(void);
#endif /* __DEBUG_TOOL_H__ */
