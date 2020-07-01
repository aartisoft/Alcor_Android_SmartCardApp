/* Copyright Statement:
 *
 * This software/firmware and related documentation ("MediaTek Software") are
 * protected under relevant copyright laws. The information contained herein
 * is confidential and proprietary to MediaTek Inc. and/or its licensors.
 * Without the prior written permission of MediaTek inc. and/or its licensors,
 * any reproduction, modification, use or disclosure of MediaTek Software,
 * and information contained herein, in whole or in part, shall be strictly prohibited.
 */
/* MediaTek Inc. (C) 2010. All rights reserved.
 *
 * BY OPENING THIS FILE, RECEIVER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO RECEIVER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND RECEIVER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. RECEIVER EXPRESSLY ACKNOWLEDGES
 * THAT IT IS RECEIVER'S SOLE RESPONSIBILITY TO OBTAIN FROM ANY THIRD PARTY ALL PROPER LICENSES
 * CONTAINED IN MEDIATEK SOFTWARE. MEDIATEK SHALL ALSO NOT BE RESPONSIBLE FOR ANY MEDIATEK
 * SOFTWARE RELEASES MADE TO RECEIVER'S SPECIFICATION OR TO CONFORM TO A PARTICULAR
 * STANDARD OR OPEN FORUM. RECEIVER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND
 * CUMULATIVE LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY RECEIVER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
 *
 * The following software/firmware and/or related documentation ("MediaTek Software")
 * have been modified by MediaTek Inc. All revisions are subject to any receiver's
 * applicable license agreements with MediaTek Inc.
 */

/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

#ifdef BUILD_LK
#include <debug.h>
#include "lcm_drv.h"
#include <platform/upmu_common.h>
#include <platform/upmu_hw.h>
#include <platform/mt_gpio.h>
#include <platform/mt_i2c.h> 
#include <platform/mt_pmic.h>
#include <string.h>
#include <cust_gpio_usage.h>
#else
#include <linux/string.h>
#include <linux/kernel.h>
#include "lcm_drv.h"
#include <upmu_common.h>
#include <mt_gpio.h>
#include <linux/gpio.h>
#endif

// ---------------------------------------------------------------------------
//  Local Constants
// ---------------------------------------------------------------------------

#define FRAME_WIDTH  										(480)
#define FRAME_HEIGHT 										(800)

#define REGFLAG_DELAY             							0XFE
#define REGFLAG_END_OF_TABLE      							0xF1  // END OF REGISTERS MARKER

#define LCM_DSI_CMD_MODE									0

// ---------------------------------------------------------------------------
//  Local Variables
// ---------------------------------------------------------------------------
//static unsigned int lcm_esd_test = FALSE; ///only for ESD test
//static unsigned int lcm_check_status(void);
static LCM_UTIL_FUNCS lcm_util = {0};

#define SET_RESET_PIN(v)    (lcm_util.set_reset_pin((v)))


#define UDELAY(n) (lcm_util.udelay(n))
#define MDELAY(n) (lcm_util.mdelay(n))


// ---------------------------------------------------------------------------
//  Local Functions
// ---------------------------------------------------------------------------

#define dsi_set_cmdq_V2(cmd, count, ppara, force_update)	lcm_util.dsi_set_cmdq_V2(cmd, count, ppara, force_update)
#define dsi_set_cmdq(pdata, queue_size, force_update)		lcm_util.dsi_set_cmdq(pdata, queue_size, force_update)
#define wrtie_cmd(cmd)									lcm_util.dsi_write_cmd(cmd)
#define write_regs(addr, pdata, byte_nums)				lcm_util.dsi_write_regs(addr, pdata, byte_nums)
//#define read_reg(cmd)											lcm_util.DSI_dcs_read_lcm_reg(cmd)
#define read_reg_v2(cmd, buffer, buffer_size)   				lcm_util.dsi_dcs_read_lcm_reg_v2(cmd, buffer, buffer_size)    

static void lcd_power_en(unsigned char enabled)
{
	if (enabled)
	{

		//pmic_set_register_value(PMIC_RG_VGP1_EN,1);
		//pmic_set_register_value(PMIC_RG_VGP1_VOSEL,0x03);
		pmic_set_register_value(PMIC_RG_VCAMA_EN,1);
		pmic_set_register_value(PMIC_RG_VCAMA_VOSEL,0x01);
	}	
	else
	{
		//pmic_set_register_value(PMIC_RG_VGP1_EN,0);
		pmic_set_register_value(PMIC_RG_VCAMA_EN,0);
	}
	MDELAY(20);

}
struct LCM_setting_table {
    unsigned char cmd;
    unsigned char count;
    unsigned char para_list[64];
};

/*
static struct LCM_setting_table lcm_set_window[] = {
	{0x2A,	4,	{0x00, 0x00, (FRAME_WIDTH>>8), (FRAME_WIDTH&0xFF)}},
	{0x2B,	4,	{0x00, 0x00, (FRAME_HEIGHT>>8), (FRAME_HEIGHT&0xFF)}},
	{REGFLAG_END_OF_TABLE, 0x00, {}}
};


static struct LCM_setting_table lcm_sleep_out_setting[] = {
    	// Sleep Out
	{0x11, 1, {0x00}},
    	{REGFLAG_DELAY, 120, {}},
    
    	// Display ON
	{0x29, 1, {0x00}},
	{REGFLAG_DELAY, 10, {}},
	
	{REGFLAG_END_OF_TABLE, 0x00, {}}
};
*/

static struct LCM_setting_table lcm_sleep_in_setting[] = {
	// Display off sequence
	{0x28, 1, {0x00}},
	{REGFLAG_DELAY, 10, {}},
    	// Sleep Mode On
	{0x10, 1, {0x00}},
	{REGFLAG_DELAY, 120, {}},

	{REGFLAG_END_OF_TABLE, 0x00, {}}
};



static struct LCM_setting_table lcm_initialization_setting[] = {

        {0x10,1,{0x00}},   
        {REGFLAG_DELAY,200,{}},

	{0xFF,5,{0x77,0x01,0x00,0x00,0x10}},
	{0xD1,1,{0x11}},

	{0x11,1,{0x00}},                 // Sleep-Out

	{REGFLAG_DELAY,200,{}},
		
	{0xFF,5,{0x77,0x01,0x00,0x00,0x10}},
	{0xC0,2,{0x63,0x00}},
	{0xC1,2,{0x0C,0x07}},
	{0xC2,2,{0x31,0x08}},
	{0xB0,16,{0x40,0x02,0x87,0x0E,0x15,0x0A,0x03,0x0A,0x0A,0x18,0x08,0x16,0x13,0x07,0x09,0x19}},
	{0xB1,16,{0x40,0x01,0x86,0x0D,0x13,0x09,0x03,0x0A,0x09,0x1C,0x09,0x15,0x13,0x91,0x16,0x19}},
	//-------------------------------- Power Control Registers Initial --------------------------------------//
	{0xFF,5,{0x77,0x01,0x00,0x00,0x11}},
	{0xb0,1,{0x4d}},//4d//5f
	//-------------------------------------------Vcom Setting---------------------------------------------------//
	{0xb1,1,{0x64}},//5a//3A
	//-----------------------------------------End Vcom Setting-----------------------------------------------//
	{0xb2,1,{0x07}},//07
	{0xb3,1,{0x80}},
	{0xb5,1,{0x47}},//43
	{0xb7,1,{0x8a}},
	{0xb8,1,{0x21}},
	{0xC1,1,{0x78}},
	{0xC2,1,{0x78}},
	{0xD0,1,{0x88}},
	//---------------------------------End Power Control Registers Initial -------------------------------//
	{REGFLAG_DELAY,100,{}},
	//---------------------------------------------GIP Setting----------------------------------------------------//
	{0xe0,3,{0x00,0x00,0x02}},
	{0xe1,11,{0x06,0x00,0x00,0x00,0x05,0x00,0x0E,0x00,0x00,0x20,0x20}},
	{0xe2,13,{0x00,0x00,0x01,0x00,0x00,0x00,0x03,0x00,0x00,0x00,0x00,0x00,0x00}},
	{0xe3,4,{0x00,0x00,0x33,0x33}},
	{0xe4,2,{0x44,0x44}},
	{0xe5,16,{0x09,0x31,0xbe,0xA0,0x0b,0x31,0xbe,0xA0,0x05,0x31,0xbe,0xA0,0x07,0x31,0xbe,0xA0}},
	{0xe6,4,{0x00,0x00,0x33,0x33}},
	{0xe7,2,{0x44,0x44}},
	{0xe8,16,{0x08,0x31,0xbe,0xA0,0x0a,0x31,0xbe,0xA0,0x04,0x31,0xbe,0xA0,0x06,0x31,0xbe,0xA0}},
	{0xeb,7,{0x02,0x02,0x00,0x00,0x00,0x00,0x00}},
	{0xeC,2,{0x02,0x02}},
	{0xed,16,{0xF5,0x47,0x6f,0x0b,0x8f,0x9F,0xff,0xff,0xff,0xff,0xF9,0xf8,0xb0,0xf6,0x74,0x5f}},
	//---------------------------------------------End GIPSetting-----------------------------------------------//
	//------------------------------ Power Control Registers Initial End-----------------------------------//
	//------------------------------------------Bank1 Setting----------------------------------------------------//
	{0xFF,5,{0x77,0x01,0x00,0x00,0x00}},

	{REGFLAG_DELAY,10,{}},	

	{0x29,1,{0x00}},                 // Display On
	{REGFLAG_DELAY,100,{}},	

    	{REGFLAG_END_OF_TABLE, 0x00, {}}
};


static void push_table(struct LCM_setting_table *table, unsigned int count, unsigned char force_update)
{
    unsigned int i;

    for(i = 0; i < count; i++)
    {

        unsigned cmd;
        cmd = table[i].cmd;

        switch (cmd)
        {

            case REGFLAG_DELAY :
                MDELAY(table[i].count);
                break;

            case REGFLAG_END_OF_TABLE :
                break;

            default:				
		dsi_set_cmdq_V2(cmd, table[i].count, table[i].para_list, force_update);
        }
    }
	
}



// ---------------------------------------------------------------------------
//  LCM Driver Implementations
// ---------------------------------------------------------------------------

static void lcm_set_util_funcs(const LCM_UTIL_FUNCS *util)
{
    memcpy(&lcm_util, util, sizeof(LCM_UTIL_FUNCS));
}


static void lcm_get_params(LCM_PARAMS *params)
{

	memset(params, 0, sizeof(LCM_PARAMS));

	params->type = LCM_TYPE_DSI;

	params->width = FRAME_WIDTH;
	params->height = FRAME_HEIGHT;

	// enable tearing-free
	params->dbi.te_mode 				= LCM_DBI_TE_MODE_DISABLED;  //LCM_DBI_TE_MODE_VSYNC_ONLY;
	//params->dbi.te_edge_polarity		= LCM_POLARITY_RISING;

	params->dsi.mode   = SYNC_PULSE_VDO_MODE;


	// DSI
	/* Command mode setting */
	params->dsi.LANE_NUM				= LCM_TWO_LANE;
	//The following defined the fomat for data coming from LCD engine.
	params->dsi.data_format.color_order = LCM_COLOR_ORDER_RGB;
	params->dsi.data_format.trans_seq   = LCM_DSI_TRANS_SEQ_MSB_FIRST;
	params->dsi.data_format.padding     = LCM_DSI_PADDING_ON_LSB;
	params->dsi.data_format.format      = LCM_DSI_FORMAT_RGB888;

	// Highly depends on LCD driver capability.
	// Not support in MT6573
	params->dsi.packet_size=256;

		// Video mode setting		
		params->dsi.intermediat_buffer_num = 2;

		params->dsi.PS=LCM_PACKED_PS_24BIT_RGB888;

		params->dsi.vertical_sync_active				= 4;
		params->dsi.vertical_backporch					= 16;
		params->dsi.vertical_frontporch					= 20;
		params->dsi.vertical_active_line				= FRAME_HEIGHT; 

		//params->dsi.horizontal_sync_active				= 10+10;
		//params->dsi.horizontal_backporch				= 64+20;
		//params->dsi.horizontal_frontporch				= 64+20;
		params->dsi.horizontal_sync_active				= 10;
		params->dsi.horizontal_backporch				= 80;
		params->dsi.horizontal_frontporch				= 80;
		params->dsi.horizontal_active_pixel				= FRAME_WIDTH;

		// Bit rate calculation

	params->dsi.PLL_CLOCK = 215;//216;//217;//215;//213;//192;//208 241 280 208  //  /******* 215  850  1900 OK*******2016-5-5***/
   	
	// params->dsi.cont_clock=1;
		params->dsi.ssc_disable	= 1;
		//params->dsi.ssc_range	= 2;
	//params->dsi.clk_lp_per_line_enable = 0;

	params->dsi.esd_check_enable = 1;
	params->dsi.customization_esd_check_enable = 1;
	
	params->dsi.lcm_esd_check_table[0].cmd          = 0x0a;//0a
	params->dsi.lcm_esd_check_table[0].count        = 1;
	params->dsi.lcm_esd_check_table[0].para_list[0] = 0x9c;//9c
	
	params->dsi.noncont_clock=1;
	params->dsi.noncont_clock_period=2;
}


static void lcm_init(void)
{
	lcd_power_en(1);
	MDELAY(50);
	SET_RESET_PIN(1);
	MDELAY(5);
	SET_RESET_PIN(0);
	MDELAY(20);
	SET_RESET_PIN(1);
	MDELAY(120);
	
	push_table(lcm_initialization_setting, sizeof(lcm_initialization_setting) / sizeof(struct LCM_setting_table), 1);

}



static void lcm_suspend(void)
{

        push_table(lcm_sleep_in_setting, sizeof(lcm_sleep_in_setting) / sizeof(struct LCM_setting_table), 1);
	SET_RESET_PIN(1);
	MDELAY(5);	
	SET_RESET_PIN(0);
	MDELAY(20);
	SET_RESET_PIN(1);
  	MDELAY(120);

}


static void lcm_resume(void)
{
	lcm_init();
//	push_table(lcm_sleep_out_setting, sizeof(lcm_sleep_out_setting) / sizeof(struct LCM_setting_table), 1);
}

static unsigned int lcm_compare_id(void)
{
#ifdef BUILD_LK
	unsigned int lcd_id = 0;

	lcd_power_en(1);
	MDELAY(50);
   	lcd_id = ((mt_get_gpio_in(GPIO_LCD_ID1_PIN) << 1) & 0x2) | mt_get_gpio_in(GPIO_LCD_ID2_PIN);

	printf("lcd_id anan =%x\n", lcd_id);	
	printf("lcd_id_pin1 anan =%x\n", mt_get_gpio_in(GPIO_LCD_ID1_PIN));	
	printf("lcd_id_pin2 anan =%x\n", mt_get_gpio_in(GPIO_LCD_ID2_PIN));

	return (lcd_id == 1)?1:0;
#else
	return 1;
#endif
}

LCM_DRIVER st7701_wvga_ctc_vdo_yixinda_for_mx2131fp_s45269_smt_lcm_drv = 
{
    	.name			= "st7701_wvga_ctc_vdo_yixinda_for_mx2131fp_s45269_smt",
	.set_util_funcs = lcm_set_util_funcs,
	.get_params     = lcm_get_params,
	.init           = lcm_init,
	.suspend        = lcm_suspend,
	.resume         = lcm_resume,
	.compare_id     = lcm_compare_id,
};
