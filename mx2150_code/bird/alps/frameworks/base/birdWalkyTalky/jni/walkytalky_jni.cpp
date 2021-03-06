/*
 * Copyright Statement:
 * --------------------
 * This software is protected by Copyright and the information contained
 * herein is confidential. The software may not be copied and the information
 * contained herein may not be used or disclosed except with the written
 * permission of MediaTek Inc. (C) 2009
 *
 * BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
 * THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
 * RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
 * AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
 * NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
 * SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
 * SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
 * THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
 * NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
 * SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
 *
 * BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
 * LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
 * AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
 * OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
 * MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
 *
 * THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
 * WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
 * LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
 * RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
 * THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
 *
 */

/*
 *
 * Filename:
 * ---------
 *  libbirdbprotectpsd_jni
 *
 * Project:
 * --------
 *   Husijia
 *
 * Description:
 * ------------
 *   Bird B PROTECTPSD JNI Interface
 *
 * Author:
 * -------
 *  
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <termios.h>
#include <pthread.h>
#include <string.h> 
#include <sys/system_properties.h>
#include <errno.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <jni.h>
#include <utils/Log.h>
#include <linux/serial.h>
#include<android/log.h>
#include <utils/misc.h>
#include "jni.h"
#include "JNIHelp.h"
#include <linux/ioctl.h>
#ifdef _cplusplus
extern "C" {
#endif


#define TAG "BirdUartJni"
#define LOG_TAG "BirdUartJni"

#define	DEV_UART_0 "/dev/ttyMT0"   /*MTK默认LOG输出*/
#define	DEV_UART_1 "/dev/ttyMT1"   /**/
#define	DEV_UART_2 "/dev/ttyMT2"   /*外设对讲机口*/
#define	DEV_UART_3 "/dev/ttyMT3"   /**/

/*******************************************************UART begin***************************************************************/
#define BUF_SIZE 200

#define MAX_UART_DEVICE 4
typedef struct __baudrate_mpping{
	unsigned int		ul_baud_rate;
	speed_t			linux_baud_rate;
}BAUD_RATE_SETTING;
pthread_mutex_t uart_mutex = PTHREAD_MUTEX_INITIALIZER;
#define devpath  "/dev/am2120u_wt"
static int fd = -1;
char buf_cmd[BUF_SIZE];
char buf_cmd_read[BUF_SIZE];

static BAUD_RATE_SETTING speeds_mapping[] = {
    {0		,B0		},
    {50		,B50		},
    {75		,B75		},
    {110	,B110		},
    {134	,B134,		},
    {150	,B150		},
    {200	,B200		},
    {300	,B300		},
    {600	,B600		},
    {1200	,B1200		},
    {1800	,B1800		},
    {2400	,B2400		},
    {4800	,B4800		},
    {9600	,B9600		},
    {19200	,B19200		},
    {38400	,B38400		},
    {57600	,B57600		},
    {115200	,B115200	},
    {230400	,B230400	},
    {460800	,B460800	},
    {500000	,B500000	},
    {576000	,B576000	},
    {921600	,B921600	},
    {1000000	,B1000000	}, 
    {1152000	,B1152000	}, 
    {1500000	,B1500000	}, 
    {2000000	,B2000000	}, 
    {2500000	,B2500000	}, 
    {3000000	,B3000000	}, 
    {3500000	,B3500000	}, 
    {4000000	,B4000000	},
};


static speed_t get_speed(unsigned int baudrate) 
{
	unsigned int idx;
	for (idx = 0; idx < sizeof(speeds_mapping)/sizeof(speeds_mapping[0]); idx++){
		if (baudrate == (unsigned int)speeds_mapping[idx].ul_baud_rate){
			return speeds_mapping[idx].linux_baud_rate;
		}
	}
	return CBAUDEX;        
}

#ifndef MTK_BASIC_PACKAGE
int set_baudrate_length_parity_stopbits(int fd, unsigned int new_baudrate, int length, char parity_c, int stopbits)
{
    struct termios uart_cfg_opt;
	speed_t speed;
	//struct serial_struct ss;
	char  using_custom_speed = 0;
	
	if(-1==fd)
		return -1;

	/* Get current uart configure option */
	if(-1 == tcgetattr(fd, &uart_cfg_opt))
		return -1;

	tcflush(fd, TCIOFLUSH);

	/* Baud rate setting section */
	speed = get_speed(new_baudrate);
	if(CBAUDEX != speed){
		/*set standard buadrate setting*/
		cfsetospeed(&uart_cfg_opt, speed);
		cfsetispeed(&uart_cfg_opt, speed);
		printf("Standard baud\r\n");
	}else{
		printf("Custom baud\r\n");
		using_custom_speed = 1;
	}
	/* Apply baudrate settings */
	if(-1==tcsetattr(fd, TCSANOW, &uart_cfg_opt))
		return -1;
    
	/* Set time out */
	uart_cfg_opt.c_cc[VTIME] = 1;
	uart_cfg_opt.c_cc[VMIN] = 0;

	/*if((ioctl(fd,TIOCGSERIAL,&ss)) < 0)
		return -1;

	if(using_custom_speed){
		ss.flags |= ASYNC_SPD_CUST;  
        	ss.custom_divisor = 1<<31|new_baudrate;
        }else
        	ss.flags &= ~ASYNC_SPD_CUST;    

	if((ioctl(fd, TIOCSSERIAL, &ss)) < 0)
		return -1;//*/

	/* Data length setting section */
	uart_cfg_opt.c_cflag &= ~CSIZE;
	switch(length)
	{
	default:
	case 8:
		uart_cfg_opt.c_cflag |= CS8;
		break;
	case 5:
		uart_cfg_opt.c_cflag |= CS5;
		break;
	case 6:
		uart_cfg_opt.c_cflag |= CS6;
		break;
	case 7:
		uart_cfg_opt.c_cflag |= CS7;
		break;
	}

	/* Parity setting section */
	uart_cfg_opt.c_cflag &= ~(PARENB|PARODD);
	switch(parity_c)
	{
	default:
	case 'N':
	case 'n':
		uart_cfg_opt.c_iflag &= ~INPCK;
		break;
	case 'O':
	case 'o':
		uart_cfg_opt.c_cflag |= (PARENB|PARODD);
		uart_cfg_opt.c_iflag |= INPCK;
		break;
	case 'E':
	case 'e':
		uart_cfg_opt.c_cflag |= PARENB;
		uart_cfg_opt.c_iflag |= INPCK;
		break;
	}

	/* Stop bits setting section */
	if(2==stopbits)
		uart_cfg_opt.c_cflag |= CSTOPB;
	else
		uart_cfg_opt.c_cflag &= ~CSTOPB;

	/* Using raw data mode */
	uart_cfg_opt.c_lflag &= ~(ICANON | ECHO | ECHOE | ISIG);
	uart_cfg_opt.c_iflag &= ~(INLCR | IGNCR | ICRNL | IXON | IXOFF);
	uart_cfg_opt.c_oflag &=~(INLCR|IGNCR|ICRNL);
	uart_cfg_opt.c_oflag &=~(ONLCR|OCRNL);

	/* Apply new settings */
	if(-1==tcsetattr(fd, TCSANOW, &uart_cfg_opt))
		return -1;

	tcflush(fd,TCIOFLUSH);

	/* All setting applied successful */
	printf("setting apply done\r\n");
	return 0;
}
#endif


int open_uart_port(char *dev, int baudrate, int length, char parity_c, int stopbits)
{
	int fd=-1;
	/* Open device now */
	fd = open(dev, O_RDWR|O_NOCTTY|O_NONBLOCK);

	/* Check if the device handle is valid */
	if(-1 == fd)
		{printf("MY GOD!");return fd;}///ZHOU
	/* Apply settings */
#ifndef MTK_BASIC_PACKAGE
	if(-1 == set_baudrate_length_parity_stopbits(fd, baudrate, length, parity_c, stopbits))
		return -1;
#endif
	/* Open success */
	return fd;
}


int  read_a_line(int fd, char rbuff[], unsigned int length) {
	unsigned int has_read=0;
	ssize_t      ret_val;

	if(-1 == fd)
		return -1;
	
	printf(TAG "Enter read_a_line(): uart = %d\n", fd);
	memset (rbuff, 0, length);
	
	while(has_read<length){
		
loop:
	    usleep(20000);
		//LOGD("read_a_line uart_mutex try lock\n");
		if (pthread_mutex_lock (&uart_mutex))
		{
			//LOGE( "read_a_line pthread_mutex_lock ERROR!\n"); 
		}
		//LOGD("read_a_line uart_mutex lock done\n");
		
		ret_val = read(fd, &rbuff[has_read], 1);

		//LOGD("read_a_line uart_mutex try unlock\n");
		if (pthread_mutex_unlock (&uart_mutex))
		{
			//LOGE( "read_a_line pthread_mutex_unlock ERROR!\n"); 
		}
		printf("read: %c, %ld, %d", rbuff[has_read], ret_val, has_read);
		//LOGD("read_a_line uart_mutex unlock done\n");
		if(-1 == ret_val){
			if (errno == EAGAIN){
                printf("UART1 can't read a byte!\n"); 
			}else
				printf("uart read fail! Error code = 0x%x\n", errno); 
			//continue;  
			goto loop;
		}
		
		if((rbuff[has_read]=='\r') || (rbuff[has_read]=='\n'))
            break;
		else
			has_read += (unsigned int)ret_val;

	}
	return has_read+1;
}

int write_chars(int fd, char wbuff[], unsigned int length) {

    unsigned int has_write = 0;
    unsigned int refer_time,curr_time;
    ssize_t ret_val;
    
    if (-1 == fd) {
    	return -1;
    }
    printf(TAG "Enter write_chars()\n");
	
    /* Get refer time */
    refer_time = time(NULL);
    
    while (has_write < length) {

#if 1
		//LOGD("write_chars uart_mutex try lock\n");
		if (pthread_mutex_lock (&uart_mutex)) {
			printf(TAG "write_chars pthread_mutex_lock ERROR!\n"); 
		}
		//LOGD("write_chars uart_mutex lock done\n");
#endif 
    	ret_val = write(fd, &wbuff[has_write], length-has_write);
#if 1
		//LOGD("write_chars uart_mutex try unlock\n");

		if (pthread_mutex_unlock (&uart_mutex)) {
			printf(TAG "write_chars pthread_mutex_unlock ERROR!\n"); 
		}
		//LOGD("write_chars uart_mutex unlock done\n");
#endif 

		if (-1 == ret_val) {
			printf(TAG "write_chars write ERROR! Error code = 0x%x\n", errno); 
    		return -1;
    	}
    	
    	has_write += (unsigned int)ret_val;
    	curr_time = (unsigned int)time(NULL);
    	if(curr_time - refer_time > 1)
    		break;
    }
    return has_write;
}


/*
 * Method: writeDataToUart
 */
int writeDataToUart(int port, char* data) {

    int fd = -1;
    char * temp = "\r";
    char buff[256] = {0};
    
	switch ((int) port) {
	    case 0:
                fd = open_uart_port(DEV_UART_0, 921600, 8, 'N', 1); // O_NONBLOCK Open Uart1
	        break;
	    case 1:
                fd = open_uart_port(DEV_UART_1, 115200, 8, 'N', 1); // O_NONBLOCK Open Uart1
	        break;
	    case 2:
	        fd = open_uart_port(DEV_UART_2, 9600, 8, 'N', 1); // O_NONBLOCK Open Uart2 //外挂对讲机
	        break;
	    case 3:
	        fd = open_uart_port(DEV_UART_3, 9600, 8, 'N', 1); // O_NONBLOCK Open Uart3
	        break;
	    default:
	        break;
	}
	
	ALOGD("writeDataToUart fd = %d,  port = %d, data = %s, strlen(data) = %d\n", fd, port, data, strlen(data));

	ALOGD("writeDataToUart data= %s+1111", data); 
    if (fd < 0) {	
        ALOGD("writeDataToUart Open uart port fail!\n");
        return -1;
    }
    ALOGD("writeDataToUart Open uart port succeed!\n");
	
    //char * strOut = "AT+B GVER\r" ;///zhou

	snprintf(buff, 256, "%s", data);
	data = buff;
	
    // if (port == 1) {
    // data = strcat(data,temp);
	//	snprintf(buff, 256, "%s%s", data, temp);
	//	data = buff;
    //}
	ALOGD("writeDataToUart data= %s, strlen(data) = %d\n", data, strlen(data)); 
	//printf("writeDataToUart strlen(strOut) = %d", strlen(strOut));   
    write_chars(fd, data, strlen(data) + 1);
    //write_chars(fd, strOut, strlen(strOut) + 1);
    ALOGD("writeDataToUart uart driver write chars end\n");
	if (fd != -1) {
		//close(fd) ;
		//fd = -1;
	}
    return 0;	
}

/*
 * Method: readDataFromUart
 */
int readDataFromUart(int port, char buf_cmd[], int lenth) {

    int fd = -1;
    int i;
    int len;
    char buffer[BUF_SIZE];
    
    memset(buffer,0,sizeof(buffer));
    
	switch ((int) port) {
	case 0:
            fd = open(DEV_UART_0, O_RDWR|O_NOCTTY|O_NONBLOCK); // O_NONBLOCK Open Uart0// MTK_LOG
	        break;
        case 1:
            fd = open(DEV_UART_1, O_RDWR|O_NOCTTY|O_NONBLOCK); // O_NONBLOCK Open Uart1
	        break;
        case 2:
            fd = open(DEV_UART_2, O_RDWR|O_NOCTTY|O_NONBLOCK); // O_NONBLOCK Open Uart2 //外挂对讲机
            break;
        case 3:
            fd = open(DEV_UART_3, O_RDWR|O_NOCTTY|O_NONBLOCK); // O_NONBLOCK Open Uart3
            break;
        default:
            break;
	}
	
	ALOGD("readDataFromUart fd = %d,  port = %d\n", fd, port);
	
    if (fd < 0) {	
        ALOGD("readDataFromUart Open uart port fail\n");
        return -1;
    }
    ALOGD("readDataFromUart Open uart port succeed!\n");
    	
    len = read(fd, buffer, BUF_SIZE);
    
    for (i = 0; i < BUF_SIZE; i++) {
        buf_cmd[i] = buffer[i];
    }
    ALOGD("readDataFromUart readbuffer =%s ,buf_cmdr =%s", buffer, buf_cmd);	
  	 
	if (fd != -1) {
		close(fd) ;
		fd = -1;
	}
    return 0;	
}
/*******************************************************UART end***************************************************************/

static jint openWt(JNIEnv *env, jobject clazz)
{
  ALOGD("%s\n", __FUNCTION__);
  char open_am2120u_wt[1];
  open_am2120u_wt[0]=0x43;//打开对讲机
  char *s_connect = "AT+DMOCONNECT\r\n";

  fd = open(devpath, O_RDWR);
  if (fd < 0) 
  {	
    ALOGE("wt open faild\n");
    return -1;
  }
  write(fd,open_am2120u_wt,1);//打开对讲机

  writeDataToUart(2,s_connect);//握手
  usleep(100000);

  int status = readDataFromUart(2,buf_cmd_read,BUF_SIZE);

  ALOGD("status = %d,buf_cmd_read = %s\n",status,buf_cmd_read);
  //printf("cccccccccccccccc====%s\n",buf_cmd_read);
  return status;
}

static jint closeWt(JNIEnv *env, jobject clazz)
{
  ALOGD("%s\n", __FUNCTION__);
  char close_am2120u_wt[1];
  close_am2120u_wt[0]=0x44;//关闭对讲机
  if(fd < 0)
    return -1;
  write(fd,close_am2120u_wt,1);//关闭对讲机
  close(fd);
  return 0;
}

static jint setGroup(JNIEnv *env, jobject clazz, jstring data)
{
  ALOGD("%s\n", __FUNCTION__);
  const char* s_setgroup;
  char* attention;
  if(fd < 0)
    return -1;

    int res = -1;
    s_setgroup = env->GetStringUTFChars(data, NULL);
    attention = const_cast<char*>(s_setgroup);
	ALOGD("attention = %s\n",attention);
    writeDataToUart(2,attention);//工作参数
    usleep(100000);

    int status = readDataFromUart(2,buf_cmd_read,BUF_SIZE);
    printf("ddddddddddddddddd====%s\n",buf_cmd_read);
    env->ReleaseStringUTFChars(data, s_setgroup);
    return status;
}

static jint setVolume(JNIEnv *env, jobject clazz, jstring data)
{
  ALOGD("%s\n", __FUNCTION__);
  const char* s_setgroup;
  char* attention;
  if(fd < 0)
    return -1;

    int res = -1;
    s_setgroup = env->GetStringUTFChars(data, NULL);
    attention = const_cast<char*>(s_setgroup);
	ALOGD("attention = %s\n",attention);
    writeDataToUart(2,attention);//工作参数
    usleep(100000);

    int status = readDataFromUart(2,buf_cmd_read,BUF_SIZE);
    printf("ddddddddddddddddd====%s\n",buf_cmd_read);
    env->ReleaseStringUTFChars(data, s_setgroup);
    return status;
}


static const char *classPathNameRx = "com/bird/walkytalky/walkyTalkyNative";


static JNINativeMethod gNotify[] = {
	{ "openWt", "()I", (void*)openWt},
        { "closeWt", "()I", (void*)closeWt},
        { "setGroup", "(Ljava/lang/String;)I", (void*)setGroup},
        { "setVolume", "(Ljava/lang/String;)I", (void*)setVolume},
};


/*
 * Register several native methods for one class.
 */
static jint registerNativeMethods(JNIEnv* env, const char* className,
    JNINativeMethod* gMethods, int numMethods)
{
    jclass clazz;

    clazz = env->FindClass(className);
    if (env->ExceptionCheck()) {
        env->ExceptionDescribe();
        env->ExceptionClear();
    }
    if (clazz == NULL) {
        ALOGD("Native registration unable to find class '%s'", className);
        return JNI_FALSE;
    }
    if (env->RegisterNatives(clazz, gMethods, numMethods) < 0) {
        ALOGD("RegisterNatives failed for '%s'", className);
        return JNI_FALSE;
    }

    ALOGD("%s, success\n", __func__);
    return JNI_TRUE;
}

/*
 * Register native methods for all classes we know about.
 *
 * returns JNI_TRUE on success.
 */
static jint registerNatives(JNIEnv* env)
{
    jint ret = JNI_FALSE;

    if (registerNativeMethods(env, classPathNameRx,gNotify,
        sizeof(gNotify) / sizeof(gNotify[0]))) {
        ret = JNI_TRUE;
    }

    ALOGD("%s, done\n", __func__);
    return ret;
}

// ----------------------------------------------------------------------------

/*
 * This is called by the VM when the shared library is first loaded.
 */

typedef union {
    JNIEnv* env;
    void* venv;
} UnionJNIEnvToVoid;

jint JNI_OnLoad(JavaVM* vm, void* reserved)
{
    UnionJNIEnvToVoid uenv;
    uenv.venv = NULL;
    jint result = -1;
    JNIEnv* env = NULL;

    ALOGD("JNI_OnLoad");

    if (vm->GetEnv(&uenv.venv, JNI_VERSION_1_4) != JNI_OK) {
        ALOGD("ERROR: GetEnv failed");
        goto fail;
    }
    env = uenv.env;

    if (registerNatives(env) != JNI_TRUE) {
        ALOGD("ERROR: registerNatives failed");
        goto fail;
    }
    result = JNI_VERSION_1_4;

fail:
    return result;
}



