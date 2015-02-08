
#ifndef __STK31xx_H__
#define __STK31xx_H__

#include <linux/ioctl.h>

/*ALSPS REGS*/
#define ALS_CMD          0x01
#define ALS_DT1          0x02
#define ALS_DT2          0x03
#define ALS_THDH1        0x04
#define ALS_THDH2        0x05
#define ALS_THDL1        0x06
#define ALS_THDL2        0x07
#define ALSPS_STATUS     0x08
#define PS_CMD           0x09
#define PS_DT            0x0A
#define PS_THDH          0x0B
#define PS_THDL          0x0C
#define PS_GAIN          0x82
#define SW_RESET	0x80

/*ALS Command*/
#define SD_ALS      (1      << 0)
#define INT_ALS     (1      << 1)
#define IT_ALS      (0x03   << 2)
#define THD_ALS     (0x03   << 4)
#define GAIN_ALS    (0x03   << 6)

/*Proximity sensor command*/
#define SD_PS       (1      << 0)
#define INT_PS      (1      << 1)
#define IT_PS       (0x03   << 2)
#define DR_PS       (1      << 4)
#define SLP_PS      (0x03   << 5)
#define INTM_PS     (1      << 7)

#define CONFIG_STK_ALS_CHANGE_THRESHOLD	5
/* STK calibration */
//#define STK_MANUAL_CT_CALI
//#define STK_MANUAL_GREYCARD_CALI
#define STK_AUTO_CT_CALI_SATU
//#define STK_AUTO_CT_CALI_NO_SATU

#if (defined(STK_MANUAL_CT_CALI) || defined(STK_MANUAL_GREYCARD_CALI) || defined(STK_AUTO_CT_CALI_SATU) || defined(STK_AUTO_CT_CALI_NO_SATU))
#define STK_CALI_SAMPLE_NO		5	
#define STK_THD_MAX				255	
#define STK_MAX_PS_DIFF_AUTO		20

#define STK_HIGH_THD				0
#define STK_LOW_THD				1

#define STK_DATA_MAX			0
#define STK_DATA_AVE				1
#define STK_DATA_MIN				2

const static uint16_t cali_sample_time_table[4] = {20, 40, 100, 300};
#define STK_CALI_VER0			0x48
#define STK_CALI_VER1			0x02
#define STK_CALI_FILE "/data/stk_ps_cali.conf"
#define STK_CALI_FILE_SIZE 5
#endif	/*	#if (defined(STK_MANUAL_CT_CALI) || defined(STK_MANUAL_GREYCARD_CALI) || defined(STK_AUTO_CT_CALI_SATU) || defined(STK_AUTO_CT_CALI_NO_SATU))	*/

#if (defined(STK_MANUAL_CT_CALI) || defined(STK_AUTO_CT_CALI_NO_SATU) || defined(STK_AUTO_CT_CALI_SATU))
#define STK_MAX_PS_CROSSTALK	200
#define STK_THD_H_ABOVE_CT		45
#define STK_THD_L_ABOVE_CT		30
#endif

#if defined(STK_AUTO_CT_CALI_SATU)
#define STK_THD_H_BELOW_MAX_CT		15
#define STK_THD_L_BELOW_MAX_CT		30
#define STK_REDETECT_CT			50
#endif

#ifdef STK_MANUAL_GREYCARD_CALI
#define STK_MIN_GREY_PS_DATA			50
#define STK_DIFF_GREY_N_THD_H		15
#define STK_DIFF_GREY_N_THD_L		30
#endif	/*	#ifdef STK_MANUAL_GREYCARD_CALI	*/

#if (defined(STK_MANUAL_CT_CALI) || defined(STK_MANUAL_GREYCARD_CALI))
#define SITRONIX_PERMISSION_THREAD
#endif

#endif

