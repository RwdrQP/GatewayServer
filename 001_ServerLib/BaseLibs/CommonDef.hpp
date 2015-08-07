/**
*@file  CommonDef.hpp
*@author jasonxiong
*@date 2009-07-02
*@version 1.0
*@brief ���ļ�����һЩ�����ĺ궨��
*
*
*/

#ifndef __COMMON_DEF_HPP__
#define __COMMON_DEF_HPP__

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <sys/timeb.h>
//#include <time.h>
//#include <errno.h>
//#include <stdint.h>
//#include <assert.h>
//
//#ifdef WIN32
//#include <winsock2.h>
//#include <sys/types.h>
//#include <sys/timeb.h>
//#else
//#include <signal.h>
//#include <netinet/in.h>
//#include <unistd.h>
//#include <sys/time.h>
//#include <sys/file.h>
//#include <sys/types.h>
//#include <sys/stat.h>
//#include <sys/socket.h>
//#include <arpa/inet.h>
//#include <sys/ioctl.h>
//#include <linux/sockios.h>
//#include <net/if.h>
//#include <dirent.h>
//#include <dlfcn.h>
//#include <stdarg.h>
//#endif

#include "stddef.h"

namespace ServerLib
{
const unsigned int MAX_FILENAME_LENGTH = 256; //!<�ļ�����󳤶�
const unsigned int MAX_DATETIME_LENGTH = 32; //!<YYYY-mm-dd HH:MM:SS��ʽ��ʱ�䴮��󳤶�
const unsigned int MAX_DATE_LENGTH = 16; //!<YYYY-mm-dd��ʽ��ʱ�䴮��󳤶�
const unsigned int MAX_IPV4_LENGTH = 16; //!<IPv4���ַ�������
const unsigned int MAX_DEPRATED_CODEQUEUE_LENGTH = 20; //!<���֧�ֵ�CodeQueue����
const unsigned int MAX_TCP_CODE_LENGTH = 32 * 1024 - 1; //!<���֧�ֵ�TCP��Ϣ�ĳ���
const int MIN_TIME_STRING_LENGTH = 19; //!<����ת��ʱ���tmʱ���ַ���
const int MAX_LINE_BUF_LENGTH = 1024; //!<һ���ַ�������󳤶�

const char MtGAME_STX = 0x82; //!<��MtGame��Э���б�־��Ϣ��ʼ
const char MtGAME_ETX = 0x83; //!<��MtGame��Э���б�־��Ϣ����
const int MIN_MtGAME_NEW_MSG_LENGTH = 6; //!<STX(1)+Len(4)+ETX(1)
const int MAX_UIN_STRING_LENGTH = 12; //!<Mt�ű�ʾ�������ַ�����󳤶�
const int MICROSECOND_PER_SECOND = 1000000; //!<ÿ���ж���΢��

#ifndef ref //���ڱ�־����
#define ref
#endif

//typedef unsigned short USHORT;

typedef unsigned char TKey[16];
typedef char TName[32];
typedef char TFName[256];
typedef char StrLine[1024];

//!����|a-b|
#define ABS(a,b)  (((unsigned int) (a) > (unsigned int)(b)) ? ((a) - (b)) : ((b) - (a)))

//!��ȡa��b�Ľϴ���
#ifndef MAX
#define MAX(a,b)  (((a) > (b)) ? (a) : (b))
#endif

//!��ȡa��b�Ľ�С��
#ifndef MIN
#define MIN(a,b)  (((a) < (b)) ? (a) : (b))
#endif

//!��ȫ�ͷ�ָ��
#define DELETEOBJ(a)  {	if(a) { delete a; } a = NULL; }

//!�ж�AWORD�Ƿ�����ĳһ��BIT
#define BIT_ENABLED(AWORD, BIT) (((AWORD) & (BIT)) != 0)

//!�ж�AWORD�Ƿ�û����ĳһ��BIT
#define BIT_DISABLED(AWORD, BIT) (((AWORD) & (BIT)) == 0)

//!��AWORD����ĳЩBITS
#define SET_BITS(AWORD, BITS) ((AWORD) |= (BITS))

//!��AWORD���ĳЩBITS
#define CLR_BITS(AWORD, BITS) ((AWORD) &= ~(BITS))

template <typename T, size_t N>
char (&ArraySizeHelper(T (&array)[N]))[N];
#define arraysize(array) (sizeof(ArraySizeHelper(array)))


//��λ����������
#define cast(t, exp)	((t)(exp))
#define resetbits(x,m)	((x) &= (~(m)) )
#define setbits(x,m)	((x) |= (m))
#define testbits(x,m)	((x) & (m))
#define bitmask(b)	(1<<(b))

//�����ֽ�x�ĵ�bλΪ1
#define setbitsbypos(x, b)		setbits(x, bitmask(b))
#define resetbitsbypos(x, b)	resetbits(x, bitmask(b));


}

#endif //__COMMON_DEF_HPP__
///:~
