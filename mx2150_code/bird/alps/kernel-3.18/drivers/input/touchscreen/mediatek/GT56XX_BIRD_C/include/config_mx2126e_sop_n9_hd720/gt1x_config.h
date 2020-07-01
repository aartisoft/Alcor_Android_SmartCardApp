/* drivers/input/touchscreen/gt1x_generic.h
 *
 * 2010 - 2014 Goodix Technology.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be a reference
 * to you, when you are integrating the GOODiX's CTP IC into your system,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * Version: 1.0
 * Revision Record:
 *      V1.0:  first release. 2014/09/28.
 *
 */

#ifndef _GT1X_CONFIG_H_
#define _GT1X_CONFIG_H_


//#define TPD_HAVE_BUTTON	0
//#define GTP_HAVE_TOUCH_KEY	0

#ifdef TPD_HAVE_BUTTON
#define TPD_KEY_COUNT   3
#define key_1           60,1438
#define key_2           180,1438
#define key_3           300,1438
#define key_4           420,1438
#define TPD_KEY_MAP_ARRAY {{key_1},{key_2},{key_3}}
#define TPD_KEYS        {KEY_MENU, KEY_HOMEPAGE, KEY_BACK}
#define TPD_KEYS_DIM    {{60,1438,50,30},{180,1438,50,30},{300,1438,50,30}}
#endif

#ifdef GTP_HAVE_TOUCH_KEY
#define GTP_MAX_KEY_NUM  4
#define GTP_KEY_TAB	 {KEY_MENU, KEY_HOMEPAGE, KEY_BACK}
extern const u16 gt1x_touch_key_array[];
#endif


/***************************PART2:TODO define**********************************/
/*TODO: puts the config info corresponded to your TP here, the following is just
		a sample config, send this config should cause the chip can not work normally*/
// Sensor_ID Map:
/* sensor_opt1 sensor_opt2 Sensor_ID 
    GND         GND         0 
    VDDIO       GND         1 
    NC          GND         2 
    GND         NC/300K     3 
    VDDIO       NC/300K     4 
    NC          NC/300K     5 
*/
//xianghuajianqiang GND GND
/* TODO define your config for Sensor_ID == 0 here, if needed */
//MX2109E SOP P2 HONGFAZHAN  GND GND
#define GTP_CFG_GROUP0 {\
0x47,0xD0,0x02,0x00,0x05,0x05,0x35,0x41,0x01,0x41,\
0x00,0x05,0x50,0x3C,0x53,0x11,0x00,0x00,0x00,0x00,\
0x14,0x17,0x1A,0x1D,0xC8,0x04,0x00,0x00,0x00,0x00,\
0x3C,0x00,0x53,0x00,0x1E,0x20,0x00,0x84,0x00,0x00,\
0x00,0x00,0x00,0x64,0x1E,0x28,0x8A,0x2B,0x0C,0x32,\
0x34,0x0F,0x0A,0x00,0x00,0x60,0x12,0x03,0x2B,0x00,\
0x00,0x1E,0x50,0x80,0x14,0x02,0x1E,0x00,0x00,0xC6,\
0x26,0xA6,0x2E,0x90,0x36,0x80,0x3F,0x75,0x47,0x6C,\
0x00,0x00,0x00,0x10,0x30,0x58,0x00,0xF0,0x40,0x30,\
0xCC,0xCC,0x27,0x00,0x00,0x00,0x02,0x0F,0x32,0x03,\
0x00,0x10,0x32,0x64,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x01,0x08,0x02,0x09,0x03,0x0A,0x04,0x0B,0x05,0x0C,\
0x06,0x0D,0xFF,0xFF,0x15,0x06,0x0C,0x07,0x0D,0x08,\
0x0E,0x09,0x0A,0x0F,0x01,0x14,0x13,0x02,0x12,0x03,\
0x11,0x04,0x10,0x05,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,\
0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,\
0x00,0x00,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x0F,0x40,0x84,\
0x22,0x03,0x00,0x00,0x53,0x00,0x0F,0x00,0x00,0x00,\
0x4B,0x37,0x50,0x00,0x00,0x00,0xFA,0xF2,0x01\
}

/* TODO define your config for Sensor_ID == 0 here, if needed */
#define GTP_CFG_GROUP0_CHARGER {\
}
//MX2109E SOP P2 HONGZHAN  VDD GND
/* TODO define your config for Sensor_ID == 1 here, if needed */
#define GTP_CFG_GROUP1 {\
	}

/* TODO define your config for Sensor_ID == 1 here, if needed */
#define GTP_CFG_GROUP1_CHARGER {\
	}

/* TODO define your config for Sensor_ID == 2 here, if needed */
//NC GND
//hongzhan 
#define GTP_CFG_GROUP2 {\
0x48,0xD0,0x02,0x00,0x05,0x05,0x35,0x41,0x01,0x41,\
0x04,0x08,0x5A,0x3C,0x53,0x11,0x00,0x00,0x00,0x00,\
0x14,0x17,0x1A,0x1D,0xC8,0x00,0x00,0x00,0x00,0x00,\
0x3C,0x00,0x53,0x00,0x1E,0x20,0x00,0x84,0x00,0x00,\
0x00,0x00,0x00,0x64,0x1E,0x28,0x89,0x2A,0x0C,0x3C,\
0x3E,0xD3,0x07,0x00,0x00,0x61,0x13,0x02,0x44,0x00,\
0x00,0x32,0x64,0x80,0x14,0x02,0x00,0x00,0x00,0xB5,\
0x3A,0x9E,0x42,0x8D,0x4A,0x7E,0x53,0x76,0x5B,0x6D,\
0x00,0x00,0x00,0x10,0x30,0x58,0x00,0xF0,0x80,0x50,\
0x88,0x88,0x27,0x00,0x00,0x00,0x02,0x0F,0x32,0x03,\
0x00,0x10,0x32,0x64,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x01,0x08,0x02,0x09,0x03,0x0A,0x04,0x0B,0x05,0x0C,\
0x06,0x0D,0xFF,0xFF,0x12,0x11,0x10,0x0F,0x0E,0x0D,\
0x0C,0x0A,0x0B,0x06,0x05,0x07,0x08,0x09,0x04,0x03,\
0x02,0x01,0x00,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,\
0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xFF,\
0xFF,0xFF,0x00,0x00,0x3C,0x00,0x00,0x00,0x00,0x00,\
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,\
0x60,0x00,0x00,0x00,0x00,0x00,0x01,0x0F,0x40,0x86,\
0x22,0x03,0x00,0x00,0x33,0x00,0x0F,0x00,0x03,0x0F,\
0x50,0x3C,0x50,0x00,0x00,0x0F,0x40,0x2E,0x01\
	}

/* TODO define your config for Sensor_ID == 2 here, if needed */
#define GTP_CFG_GROUP2_CHARGER {\
	}

/* TODO define your config for Sensor_ID == 3 here, if needed */
#define GTP_CFG_GROUP3 {\
	}

/* TODO define your config for Sensor_ID == 3 here, if needed */
#define GTP_CFG_GROUP3_CHARGER {\
	}

/* TODO define your config for Sensor_ID == 4 here, if needed */
#define GTP_CFG_GROUP4 {\
	}

/* TODO define your config for Sensor_ID == 4 here, if needed */
#define GTP_CFG_GROUP4_CHARGER {\
	}

/* TODO define your config for Sensor_ID == 5 here, if needed */
#define GTP_CFG_GROUP5 {\
	}

/* TODO define your config for Sensor_ID == 5 here, if needed */
#define GTP_CFG_GROUP5_CHARGER {\
	}


#endif				/* _GT1X_CONFIG_H_ */
