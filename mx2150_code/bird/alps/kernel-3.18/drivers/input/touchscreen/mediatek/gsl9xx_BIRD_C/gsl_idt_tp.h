static const struct fw_data GSL_IDT_FW[]={
{0xf0,0x3},
{0x00,0x5a5a5a5a},
{0x04,0x000a000a},//dacg
{0x08,0x00000003},//driver voltage
{0x0c,0x0000016b},//driver frequency
{0x10,0x00000000},//bit set default = 0
#if defined(MX1091E_ARES_A5509_HD)
{0x14,0x00000bb8},//threshold
{0x18,0x00000004},//bias,
#elif defined(MX1091E_ARES_A5509_QHD)
{0x14,0x00000bb8},//threshold
{0x18,0x00000004},//bias,
#else
{0x14,0x000007fc},//threshold
{0x18,0x00000000},//bias,
#endif

{0x1c,0x00000000},
{0x20,0x00000000},
{0x24,0x00000000},
{0x28,0x00000000},
{0x2c,0x00000000},
{0x30,0x00000000},
{0x34,0x00000000},
{0x38,0x00000000},
{0x3c,0x00000000},
{0x40,0x00000000},
{0x44,0x00000000},
{0x48,0x00000000},
{0x4c,0x00000000},
{0x50,0x00000000},
{0x54,0x00000000},
{0x58,0x00000000},
{0x5c,0x00000000},
{0x60,0x00000000},
{0x64,0x00000000},
{0x68,0x00000000},
{0x6c,0x00000000},
{0x70,0x00000000},
{0x74,0x00000000},
{0x78,0x12345678},
{0x7c,0x00000000},//freq_check = 0
{0xf0,0x0},
{0x00,0x01000000},
{0x04,0x01000000},
{0x08,0x01000000},
{0x0c,0x233fc0c0},
{0x10,0xa2146004},
{0x14,0xa4102000},
{0x18,0xe4244000},
{0x1c,0x233fc0c0},
{0x20,0xa2146010},
{0x24,0x2500003f},
{0x28,0xa414a3ff},
{0x2c,0xe4244000},
{0x30,0x01000000},
{0x34,0x821020e0},
{0x38,0x81880001},
{0x3c,0x01000000},
{0x40,0x01000000},
{0x44,0x01000000},
{0x48,0x270010c0},
{0x4c,0xa614e00f},
{0x50,0xe6a00040},
{0x54,0x01000000},
{0x58,0xa410200f},
{0x5c,0xe4a00040},
{0x60,0x01000000},
{0x64,0xa0100000},
{0x68,0xa2100000},
{0x6c,0xa4100000},
{0x70,0xa6100000},
{0x74,0xa8100000},
{0x78,0xaa100000},
{0x7c,0xac100000},
{0xf0,0x1},
{0x00,0xae100000},
{0x04,0x90100000},
{0x08,0x92100000},
{0x0c,0x94100000},
{0x10,0x96100000},
{0x14,0x98100000},
{0x18,0x9a100000},
{0x1c,0x9c100000},
{0x20,0x9e100000},
{0x24,0x84100000},
{0x28,0x86100000},
{0x2c,0x88100000},
{0x30,0x8a100000},
{0x34,0x8c100000},
{0x38,0x8e100000},
{0x3c,0x01000000},
{0x40,0x01000000},
{0x44,0x01000000},
{0x48,0x82100000},
{0x4c,0x81900001},
{0x50,0x82100000},
{0x54,0x81980001},
{0x58,0x81800000},
{0x5c,0x01000000},
{0x60,0x01000000},
{0x64,0x01000000},
{0x68,0xbc1025f8},
{0x6c,0x9c102578},
{0x70,0x01000000},
{0x74,0x01000000},
{0x78,0x01000000},
{0x7c,0x01000000},
{0xf0,0x2},
{0x00,0x270010c0},
{0x04,0xa614e00f},
{0x08,0xe6a00040},
{0x0c,0x01000000},
{0x10,0x40000451},
{0x14,0x01000000},
{0x18,0x01000000},
{0x1c,0x10bfffff},
{0x20,0x01000000},
{0x24,0x00000000},
{0x28,0x00000000},
{0x2c,0x00000000},
{0x30,0x00000000},
{0x34,0x00000000},
{0x38,0x00000000},
{0x3c,0x00000000},
{0x40,0x00000000},
{0x44,0x00000000},
{0x48,0x00000000},
{0x4c,0x00000000},
{0x50,0x00000000},
{0x54,0x00000000},
{0x58,0x00000000},
{0x5c,0x00000000},
{0x60,0x00000000},
{0x64,0x00000000},
{0x68,0x00000000},
{0x6c,0x00000000},
{0x70,0x00000000},
{0x74,0x00000000},
{0x78,0x00000000},
{0x7c,0x00000000},

{0xf0,0x20},
{0x00,0x83580000},
{0x04,0x82086ff0},
{0x08,0x83306004},
{0x0c,0x80a06005},
{0x10,0x02800024},
{0x14,0x01000000},
{0x18,0x80a06006},
{0x1c,0x02800039},
{0x20,0x01000000},
{0x24,0x80a06015},
{0x28,0x02800051},
{0x2c,0x01000000},
{0x30,0x80a0602a},
{0x34,0x02800085},
{0x38,0x01000000},
{0x3c,0x073fc180},
{0x40,0x8610e03c},
{0x44,0x05169680},
{0x48,0x84004002},
{0x4c,0xc420c000},
{0x50,0x073fc000},
{0x54,0x8610e020},
{0x58,0x84102001},
{0x5c,0xc420c000},
{0x60,0x0500000c},
{0x64,0x01000000},
{0x68,0x01000000},
{0x6c,0x8480bfff},
{0x70,0x12bffffe},
{0x74,0x01000000},
{0x78,0x01000000},
{0x7c,0x073fc000},
{0xf0,0x21},
{0x00,0x8610e020},
{0x04,0x84102000},
{0x08,0xc420c000},
{0x0c,0x01000000},
{0x10,0x01000000},
{0x14,0x81c44000},
{0x18,0x81cc8000},
{0x1c,0x01000000},
{0x20,0xa7500000},
{0x24,0xa92ce002},
{0x28,0xa734e001},
{0x2c,0xa614c014},
{0x30,0xa60ce007},
{0x34,0x81900000},
{0x38,0x01000000},
{0x3c,0x01000000},
{0x40,0x81e00000},
{0x44,0xe03ba000},
{0x48,0xe43ba008},
{0x4c,0xe83ba010},
{0x50,0xec3ba018},
{0x54,0xf03ba020},
{0x58,0xf43ba028},
{0x5c,0xf83ba030},
{0x60,0xfc3ba038},
{0x64,0x81e80000},
{0x68,0x8194c000},
{0x6c,0x01000000},
{0x70,0x01000000},
{0x74,0x81c44000},
{0x78,0x81cc8000},
{0x7c,0x01000000},
{0xf0,0x22},
{0x00,0xa7500000},
{0x04,0xa934e002},
{0x08,0xa72ce001},
{0x0c,0xa614c014},
{0x10,0xa60ce007},
{0x14,0x81900000},
{0x18,0x01000000},
{0x1c,0x01000000},
{0x20,0x81e80000},
{0x24,0x81e80000},
{0x28,0xe01ba000},
{0x2c,0xe41ba008},
{0x30,0xe81ba010},
{0x34,0xec1ba018},
{0x38,0xf01ba020},
{0x3c,0xf41ba028},
{0x40,0xf81ba030},
{0x44,0xfc1ba038},
{0x48,0x81e00000},
{0x4c,0x81e00000},
{0x50,0x8194c000},
{0x54,0x01000000},
{0x58,0x01000000},
{0x5c,0x81c44000},
{0x60,0x81cc8000},
{0x64,0x01000000},
{0x68,0x01000000},
{0x6c,0x82102010},
{0x70,0x273fc0c0},
{0x74,0xa614e010},
{0x78,0xc224c000},
{0x7c,0x01000000},
{0xf0,0x23},
{0x00,0x033fc0c0},
{0x04,0x82106004},
{0x08,0xa6102000},
{0x0c,0xe6204000},
{0x10,0x01000000},
{0x14,0x01000000},
{0x18,0x01000000},
{0x1c,0xa6102020},
{0x20,0x83480000},
{0x24,0x82104013},
{0x28,0x81884000},
{0x2c,0x01000000},
{0x30,0x4000025f},
{0x34,0x01000000},
{0x38,0x01000000},
{0x3c,0x01000000},
{0x40,0xa7500000},
{0x44,0xa934e002},
{0x48,0xa72ce001},
{0x4c,0xa614c014},
{0x50,0xa60ce007},
{0x54,0x81900000},
{0x58,0x01000000},
{0x5c,0x81e80000},
{0x60,0xe01ba000},
{0x64,0xe41ba008},
{0x68,0xe81ba010},
{0x6c,0xec1ba018},
{0x70,0xf01ba020},
{0x74,0xf41ba028},
{0x78,0xf81ba030},
{0x7c,0xfc1ba038},
{0xf0,0x24},
{0x00,0x81e00000},
{0x04,0x8194c000},
{0x08,0x01000000},
{0x0c,0xa6102020},
{0x10,0x83480000},
{0x14,0x82284013},
{0x18,0x81884000},
{0x1c,0x01000000},
{0x20,0x033fc0c0},
{0x24,0x82106004},
{0x28,0xa6103fff},
{0x2c,0xe6204000},
{0x30,0x01000000},
{0x34,0x01000000},
{0x38,0x01000000},
{0x3c,0x81c44000},
{0x40,0x81cc8000},
{0x44,0x01000000},
{0x48,0x81c48000},
{0x4c,0x81cca004},
{0x50,0x01000000},
{0x54,0x9de3bf98},
{0x58,0x40000099},
{0x5c,0x01000000},
{0x60,0x40000090},
{0x64,0x01000000},
{0x68,0xc20021fc},
{0x6c,0x80a06000},
{0x70,0x0280002f},
{0x74,0x213fc200},
{0x78,0x1b3fc040},
{0x7c,0x98136004},
{0xf0,0x25},
{0x00,0x82103fff},
{0x04,0xc2230000},
{0x08,0x96136008},
{0x0c,0x8210202b},
{0x10,0xc222c000},
{0x14,0x9a13600c},
{0x18,0x11000066},
{0x1c,0xc0234000},
{0x20,0x40000077},
{0x24,0x90122228},
{0x28,0xc20021fc},
{0x2c,0x80a06000},
{0x30,0x0280001e},
{0x34,0x033fc040},
{0x38,0x8210600c},
{0x3c,0xc0204000},
{0x40,0x213fc000},
{0x44,0xa0142020},
{0x48,0x82102001},
{0x4c,0x110000cd},
{0x50,0xc2240000},
{0x54,0x4000006a},
{0x58,0x90122050},
{0x5c,0xc0240000},
{0x60,0x40000082},
{0x64,0x01000000},
{0x68,0x1b000035},
{0x6c,0xd80021fc},
{0x70,0x9a1362d8},
{0x74,0x03222222},
{0x78,0x82106089},
{0x7c,0x9a5b000d},
{0xf0,0x26},
{0x00,0x80534001},
{0x04,0x9b400000},
{0x08,0x9b336005},
{0x0c,0x033fc040},
{0x10,0x9a38000d},
{0x14,0xc2004000},
{0x18,0x80a0400d},
{0x1c,0x1abffff1},
{0x20,0x80a32000},
{0x24,0x30bfffe3},
{0x28,0x213fc200},
{0x2c,0xa014201c},
{0x30,0x82102035},
{0x34,0xc2240000},
{0x38,0x0300001f},
{0x3c,0x821063fc},
{0x40,0x27000020},
{0x44,0xe204c000},
{0x48,0xe4004000},
{0x4c,0x4000004c},
{0x50,0x9010200a},
{0x54,0x80a46000},
{0x58,0x0280000d},
{0x5c,0xe0040000},
{0x60,0x1b000016},
{0x64,0x03000028},
{0x68,0x98136108},
{0x6c,0x82106088},
{0x70,0xc2230000},
{0x74,0x96136114},
{0x78,0x82102014},
{0x7c,0x9a136110},
{0xf0,0x27},
{0x00,0xc2234000},
{0x04,0x10800024},
{0x08,0x8210201f},
{0x0c,0x80a4a000},
{0x10,0x0280000c},
{0x14,0x80a42000},
{0x18,0x1b000016},
{0x1c,0x82136108},
{0x20,0x9814e036},
{0x24,0xd8204000},
{0x28,0x96136114},
{0x2c,0x82102018},
{0x30,0x9a136110},
{0x34,0xc2234000},
{0x38,0x10800017},
{0x3c,0x82102020},
{0x40,0x0280000c},
{0x44,0x1b000016},
{0x48,0x03000014},
{0x4c,0x98136108},
{0x50,0x82106091},
{0x54,0xc2230000},
{0x58,0x96136114},
{0x5c,0x8210200e},
{0x60,0x9a136110},
{0x64,0xc2234000},
{0x68,0x1080000b},
{0x6c,0x8210201a},
{0x70,0x03000028},
{0x74,0x98136108},
{0x78,0x82106082},
{0x7c,0xc2230000},
{0xf0,0x28},
{0x00,0x96136114},
{0x04,0x8210200c},
{0x08,0x9a136110},
{0x0c,0xc2234000},
{0x10,0x82102017},
{0x14,0xc222c000},
{0x18,0x19000016},
{0x1c,0x82132108},
{0x20,0xd6004000},
{0x24,0x033fc180},
{0x28,0x1b3fc200},
{0x2c,0x82106034},
{0x30,0xd6204000},
{0x34,0x94136010},
{0x38,0xc0228000},
{0x3c,0x92136014},
{0x40,0xc0224000},
{0x44,0x90136018},
{0x48,0xc0220000},
{0x4c,0xa0136024},
{0x50,0x9e13601c},
{0x54,0xc023c000},
{0x58,0x9a136020},
{0x5c,0xc0234000},
{0x60,0x98132100},
{0x64,0xc0240000},
{0x68,0x400000ca},
{0x6c,0xc0230000},
{0x70,0x40000025},
{0x74,0x01000000},
{0x78,0x30bffffe},
{0x7c,0x80a22000},
{0xf0,0x29},
{0x00,0x02800006},
{0x04,0x01000000},
{0x08,0x01000000},
{0x0c,0x90823fff},
{0x10,0x12bffffe},
{0x14,0x01000000},
{0x18,0x81c3e008},
{0x1c,0x01000000},
{0x20,0x82102001},
{0x24,0x81904000},
{0x28,0x01000000},
{0x2c,0x01000000},
{0x30,0x01000000},
{0x34,0x81c3e008},
{0x38,0x01000000},
{0x3c,0x03000008},
{0x40,0x82106342},
{0x44,0xa3804000},
{0x48,0x03000004},
{0x4c,0x82106000},
{0x50,0x81984000},
{0x54,0x01000000},
{0x58,0x01000000},
{0x5c,0x01000000},
{0x60,0x81c3e008},
{0x64,0x01000000},
{0x68,0x01000000},
{0x6c,0x27001040},
{0x70,0xa614e00f},
{0x74,0xe6a00040},
{0x78,0x01000000},
{0x7c,0x81c3e008},
{0xf0,0x2a},
{0x00,0x01000000},
{0x04,0x01000000},
{0x08,0x01000000},
{0x0c,0x01000000},
{0x10,0xa7800000},
{0x14,0x01000000},
{0x18,0x01000000},
{0x1c,0x01000000},
{0x20,0x81c3e008},
{0x24,0x01000000},
{0x28,0x9c03bf10},
{0x2c,0x8203a060},
{0x30,0x98102020},
{0x34,0xc0204000},
{0x38,0x98833fff},
{0x3c,0x1cbffffe},
{0x40,0x82006004},
{0x44,0x03000016},
{0x48,0x82106108},
{0x4c,0xda004000},
{0x50,0x19000028},
{0x54,0x82132088},
{0x58,0x80a34001},
{0x5c,0x32800022},
{0x60,0x03000020},
{0x64,0x98102000},
{0x68,0x9003a0e8},
{0x6c,0x832b2005},
{0x70,0x9200620f},
{0x74,0x9b2b2002},
{0x78,0x80a3200f},
{0x7c,0x940321e0},
{0xf0,0x2b},
{0x00,0x96034008},
{0x04,0x14800004},
{0x08,0x82032001},
{0x0c,0x10800003},
{0x10,0xd222ff78},
{0x14,0xd422ff78},
{0x18,0x80a0601e},
{0x1c,0x04bffff4},
{0x20,0x98100001},
{0x24,0xc203a0d8},
{0x28,0x1b000004},
{0x2c,0x8210400d},
{0x30,0xc223a0d8},
{0x34,0x033fc200},
{0x38,0x941060a0},
{0x3c,0x98102000},
{0x40,0x9603a0e8},
{0x44,0x832b2002},
{0x48,0x9a00400b},
{0x4c,0xda037f78},
{0x50,0x98032001},
{0x54,0x80a3201e},
{0x58,0x04bffffb},
{0x5c,0xda20400a},
{0x60,0x3080006a},
{0x64,0x82106036},
{0x68,0x80a34001},
{0x6c,0x32800022},
{0x70,0x82132082},
{0x74,0x98102000},
{0x78,0x9003a0e8},
{0x7c,0x832b2005},
{0xf0,0x2c},
{0x00,0x9200620f},
{0x04,0x9b2b2002},
{0x08,0x80a3200f},
{0x0c,0x940321e0},
{0x10,0x96034008},
{0x14,0x14800004},
{0x18,0x82032001},
{0x1c,0x10800003},
{0x20,0xd222ff78},
{0x24,0xd422ff78},
{0x28,0x80a0601f},
{0x2c,0x04bffff4},
{0x30,0x98100001},
{0x34,0xc203a0dc},
{0x38,0x1b000004},
{0x3c,0x8210400d},
{0x40,0xc223a0dc},
{0x44,0x033fc200},
{0x48,0x941060a0},
{0x4c,0x98102000},
{0x50,0x9603a0e8},
{0x54,0x832b2002},
{0x58,0x9a00400b},
{0x5c,0xda037f78},
{0x60,0x98032001},
{0x64,0x80a3201e},
{0x68,0x04bffffb},
{0x6c,0xda20400a},
{0x70,0x30800046},
{0x74,0x80a34001},
{0x78,0x32800022},
{0x7c,0x03000014},
{0xf0,0x2d},
{0x00,0x98102000},
{0x04,0x9003a0e8},
{0x08,0x832b2005},
{0x0c,0x9200620f},
{0x10,0x9b2b2002},
{0x14,0x80a3200b},
{0x18,0x940321e4},
{0x1c,0x96034008},
{0x20,0x14800004},
{0x24,0x82032001},
{0x28,0x10800003},
{0x2c,0xd222ff78},
{0x30,0xd422ff78},
{0x34,0x80a06016},
{0x38,0x04bffff4},
{0x3c,0x98100001},
{0x40,0xc203a0b8},
{0x44,0x1b000004},
{0x48,0x8210400d},
{0x4c,0xc223a0b8},
{0x50,0x033fc200},
{0x54,0x941060a0},
{0x58,0x98102000},
{0x5c,0x9603a0e8},
{0x60,0x832b2002},
{0x64,0x9a00400b},
{0x68,0xda037f78},
{0x6c,0x98032001},
{0x70,0x80a32016},
{0x74,0x04bffffb},
{0x78,0xda20400a},
{0x7c,0x30800023},
{0xf0,0x2e},
{0x00,0x82106091},
{0x04,0x80a34001},
{0x08,0x12800020},
{0x0c,0x98102000},
{0x10,0x9003a0e8},
{0x14,0x832b2005},
{0x18,0x9200620f},
{0x1c,0x9b2b2002},
{0x20,0x80a3200c},
{0x24,0x940321e3},
{0x28,0x96034008},
{0x2c,0x14800004},
{0x30,0x82032001},
{0x34,0x10800003},
{0x38,0xd222ff78},
{0x3c,0xd422ff78},
{0x40,0x80a06019},
{0x44,0x04bffff4},
{0x48,0x98100001},
{0x4c,0xc203a0c4},
{0x50,0x1b000004},
{0x54,0x8210400d},
{0x58,0xc223a0c4},
{0x5c,0x033fc200},
{0x60,0x941060a0},
{0x64,0x98102000},
{0x68,0x9603a0e8},
{0x6c,0x832b2002},
{0x70,0x9a00400b},
{0x74,0xda037f78},
{0x78,0x98032001},
{0x7c,0x80a32019},
{0xf0,0x2f},
{0x00,0x04bffffb},
{0x04,0xda20400a},
{0x08,0x81c3e008},
{0x0c,0x9c23bf10},
{0x10,0x9de3bf98},
{0x14,0x17000016},
{0x18,0x8212e110},
{0x1c,0xd8004000},
{0x20,0x233fc140},
{0x24,0x9a146040},
{0x28,0x8212e114},
{0x2c,0xd2004000},
{0x30,0xfa034000},
{0x34,0x95332001},
{0x38,0x825a8009},
{0x3c,0xba0f7800},
{0x40,0xba174001},
{0x44,0xfa234000},
{0x48,0x82146004},
{0x4c,0xfa004000},
{0x50,0xba0f7fe0},
{0x54,0x213fc200},
{0x58,0xba17400a},
{0x5c,0xfa204000},
{0x60,0xac142080},
{0x64,0xfa058000},
{0x68,0x9a142070},
{0x6c,0x82102fff},
{0x70,0xc2234000},
{0x74,0x033fc000},
{0x78,0xda002188},
{0x7c,0x82106030},
{0xf0,0x30},
{0x00,0xda204000},
{0x04,0x033e0040},
{0x08,0x90142074},
{0x0c,0x8210600f},
{0x10,0xc2220000},
{0x14,0xba0f7fe0},
{0x18,0x0300003f},
{0x1c,0x9e146058},
{0x20,0xba17400a},
{0x24,0x821063ff},
{0x28,0x985b0009},
{0x2c,0xc223c000},
{0x30,0x9612e1d0},
{0x34,0x94146088},
{0x38,0x9803000c},
{0x3c,0xd6228000},
{0x40,0x9803000b},
{0x44,0x9214608c},
{0x48,0xd8224000},
{0x4c,0x31200040},
{0x50,0xfa258000},
{0x54,0xae162101},
{0x58,0xee240000},
{0x5c,0xa614605c},
{0x60,0xc024c000},
{0x64,0xa8146080},
{0x68,0xd6250000},
{0x6c,0xaa146084},
{0x70,0x253fc0c0},
{0x74,0xd8254000},
{0x78,0xa414a004},
{0x7c,0x7fffff2b},
{0xf0,0x31},
{0x00,0xc0248000},
{0x04,0x033fc1c0},
{0x08,0xda00218c},
{0x0c,0x82106064},
{0x10,0x17200000},
{0x14,0xd6204000},
{0x18,0x98036001},
{0x1c,0x992b2010},
{0x20,0x0300007f},
{0x24,0x952b6010},
{0x28,0x9803000d},
{0x2c,0x92146010},
{0x30,0x821063ff},
{0x34,0xc2224000},
{0x38,0xae146030},
{0x3c,0x3507ffc0},
{0x40,0x9b2b6004},
{0x44,0xf425c000},
{0x48,0x9a02800d},
{0x4c,0x90142084},
{0x50,0xda220000},
{0x54,0x9e142088},
{0x58,0xd423c000},
{0x5c,0x98032002},
{0x60,0xa614208c},
{0x64,0xd824c000},
{0x68,0xc2002184},
{0x6c,0xa8142030},
{0x70,0xc2250000},
{0x74,0x030001c0},
{0x78,0x82106011},
{0x7c,0xaa142094},
{0xf0,0x32},
{0x00,0xc2254000},
{0x04,0x03000100},
{0x08,0xac142090},
{0x0c,0xc2258000},
{0x10,0x030000c0},
{0x14,0xba142068},
{0x18,0xc2274000},
{0x1c,0x03004009},
{0x20,0x82106182},
{0x24,0xb8142064},
{0x28,0xc2270000},
{0x2c,0x0300065f},
{0x30,0x821063ff},
{0x34,0xb614204c},
{0x38,0xc226c000},
{0x3c,0x82103fff},
{0x40,0xc2248000},
{0x44,0xf0240000},
{0x48,0xa2146014},
{0x4c,0xb2142060},
{0x50,0xf4244000},
{0x54,0xc0264000},
{0x58,0x81c7e008},
{0x5c,0x81e80000},
{0x60,0x9de3bf98},
{0x64,0x39000016},
{0x68,0x82172114},
{0x6c,0xfa004000},
{0x70,0x82172104},
{0x74,0x9e102000},
{0x78,0xc0204000},
{0x7c,0x80a3c01d},
{0xf0,0x33},
{0x00,0x1a800043},
{0x04,0x92100018},
{0x08,0x94172110},
{0x0c,0xb0102000},
{0x10,0xc026001c},
{0x14,0xc2028000},
{0x18,0x83306001},
{0x1c,0xb6102000},
{0x20,0x80a6c001},
{0x24,0x1a800023},
{0x28,0x35000016},
{0x2c,0x0300003f},
{0x30,0x961063ff},
{0x34,0x9a10001a},
{0x38,0xb216a110},
{0x3c,0x193fffc0},
{0x40,0xc2064000},
{0x44,0x83306001},
{0x48,0x8258400f},
{0x4c,0x8206c001},
{0x50,0x83286002},
{0x54,0xc2024001},
{0x58,0xb808400c},
{0x5c,0x8208400b},
{0x60,0xfa002194},
{0x64,0xb606e001},
{0x68,0x80a0401d},
{0x6c,0x08800005},
{0x70,0xb9372010},
{0x74,0xc206001a},
{0x78,0x82006001},
{0x7c,0xc226001a},
{0xf0,0x34},
{0x00,0xc2002194},
{0x04,0x80a70001},
{0x08,0x08800005},
{0x0c,0x35000016},
{0x10,0xc206000d},
{0x14,0x82006001},
{0x18,0xc226000d},
{0x1c,0xc2064000},
{0x20,0x83306001},
{0x24,0x80a6c001},
{0x28,0x2abfffe7},
{0x2c,0xc2064000},
{0x30,0x33000016},
{0x34,0x82102001},
{0x38,0xb6166104},
{0x3c,0xb528400f},
{0x40,0xc206c000},
{0x44,0xb828401a},
{0x48,0xf826c000},
{0x4c,0xfa002198},
{0x50,0xc2028000},
{0x54,0x8220401d},
{0x58,0xfa060019},
{0x5c,0x80a74001},
{0x60,0x0a800005},
{0x64,0x82166114},
{0x68,0x8217001a},
{0x6c,0xc226c000},
{0x70,0x82166114},
{0x74,0x9e03e001},
{0x78,0xc2004000},
{0x7c,0xb8100019},
{0xf0,0x35},
{0x00,0x80a3c001},
{0x04,0x0abfffc3},
{0x08,0xb0062004},
{0x0c,0xc2002190},
{0x10,0x80a06000},
{0x14,0x1280001f},
{0x18,0x03000016},
{0x1c,0x39000016},
{0x20,0x82172108},
{0x24,0xfa004000},
{0x28,0x37000028},
{0x2c,0x8216e088},
{0x30,0x80a74001},
{0x34,0x32800006},
{0x38,0x03000014},
{0x3c,0x82172104},
{0x40,0xfa004000},
{0x44,0x10800010},
{0x48,0x39200000},
{0x4c,0x82106091},
{0x50,0x80a74001},
{0x54,0x32800006},
{0x58,0x8216e082},
{0x5c,0x82172104},
{0x60,0xfa004000},
{0x64,0x10800008},
{0x68,0x393f0000},
{0x6c,0x80a74001},
{0x70,0x12800008},
{0x74,0x03000016},
{0x78,0x82172104},
{0x7c,0xfa004000},
{0xf0,0x36},
{0x00,0x393fe000},
{0x04,0xba17401c},
{0x08,0xfa204000},
{0x0c,0x03000016},
{0x10,0x82106104},
{0x14,0xfa004000},
{0x18,0x033fc180},
{0x1c,0x82106038},
{0x20,0xfa204000},
{0x24,0x81c7e008},
{0x28,0x81e80000},
{0x2c,0x9de3bf98},
{0x30,0x7ffffe6e},
{0x34,0x01000000},
{0x38,0x1b3e0040},
{0x3c,0x033fc200},
{0x40,0x9a13600f},
{0x44,0x82106074},
{0x48,0xda204000},
{0x4c,0x033fc040},
{0x50,0x8210600c},
{0x54,0xc0204000},
{0x58,0x7ffffe49},
{0x5c,0x90102014},
{0x60,0x1b000016},
{0x64,0x98136100},
{0x68,0xc2030000},
{0x6c,0x82006001},
{0x70,0x94136108},
{0x74,0xb01361d0},
{0x78,0x9613610c},
{0x7c,0x80a06ffe},
{0xf0,0x37},
{0x00,0x08800004},
{0x04,0xc2230000},
{0x08,0x82102001},
{0x0c,0xc2230000},
{0x10,0xda030000},
{0x14,0xc2028000},
{0x18,0x9b2b6010},
{0x1c,0x9a134001},
{0x20,0x033fc140},
{0x24,0x82106048},
{0x28,0xd8004000},
{0x2c,0x033fc180},
{0x30,0x82106034},
{0x34,0xda204000},
{0x38,0x03000040},
{0x3c,0x808b0001},
{0x40,0x02800004},
{0x44,0xd822c000},
{0x48,0x7fffff66},
{0x4c,0x81e80000},
{0x50,0x01000000},
{0x54,0x81c7e008},
{0x58,0x81e80000},
{0x5c,0x00000000},
{0x60,0x00000000},
{0x64,0x00000000},
{0x68,0x00000000},
{0x6c,0x00000000},
{0x70,0x00000000},
{0x74,0x00000000},
{0x78,0x00000000},
{0x7c,0x00000000},
{0xf0,0x38},
{0x00,0xa5020102},
{0x04,0xa5000000},
{0x08,0x57414e43},
{0x0c,0x00000000},
{0x10,0x53657020},
{0x14,0x20342032},
{0x18,0x30313400},
{0x1c,0x00000000},
{0x20,0x31333a34},
{0x24,0x353a3437},
{0x28,0x00000000},
{0x2c,0x00000000},
{0x30,0x00000000},
{0x34,0x00000000},
{0x38,0x00000000},
{0x3c,0x00000000},
{0x40,0x00000000},
{0x44,0x00000000},
{0x48,0x00000000},
{0x4c,0x00000000},
{0x50,0x00000000},
{0x54,0x00000000},
{0x58,0x00000000},
{0x5c,0x00000000},
{0x60,0x00000000},
{0x64,0x00000000},
{0x68,0x00000000},
{0x6c,0x00000000},
{0x70,0x00000000},
{0x74,0x00000000},
{0x78,0x00000000},
{0x7c,0x00000000},
};

