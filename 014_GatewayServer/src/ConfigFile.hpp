
#ifndef __CONFIGFILE_H__
#define __CONFIGFILE_H__
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include <errno.h>
#include <fstream>
#include <netinet/in.h>
#include <unistd.h>
#include <stdint.h>
#include <sys/time.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <assert.h>
#include <signal.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
//#define BYTE unsigned char



class CConfigFile
{
private:
    char    *m_pszContent;      /* 配置文件的原始内容 */
    char    *m_pszShadow;       /* 配置文件的内容全部转换成小写 */
    size_t  m_nSize;            /* 配置文件内容的长度，不包括最后的NULL */
    short   m_bIsOpen;          /* 配置文件是否打开成功的标志 */

public:
    char    *m_pszFilename;     /* 存放需要读取的配置文件名 */
    CConfigFile();
    ~CConfigFile();

    unsigned int IsOpen();
    unsigned int GetItemValue( const char *pszSectionName,
                        const char *pszKeyName,
                        char *pszReturnedString,
                        unsigned int nSize );
    unsigned int SetItemValue( const char *pszSectionName,
                        const char *pszKeyName,
                        const char *pszKeyValue );
    unsigned int GetItemValue( const char *pszSectionName,
                        const char *pszKeyName,
                        int &lReturnedValue );
    unsigned int SetItemValue( const char *pszSectionName,
                        const char *pszKeyName,
                        int lKeyValue );
    unsigned int GetItemValue( const char *pszSectionName,
                        const char *pszKeyName,
                        int &lReturnedValue,
                        int lDefaultValue );
	unsigned int /*CConfigFile::*/GetItemValue( const char *pszSectionName,
                                   const char *pszKeyName,
                                   int64_t &lReturnedValue );
	unsigned int GetItemValue( const char *pszSectionName,
                        const char *pszKeyName,
                        int64_t &lReturnedValue,
                        int64_t lDefaultValue );
    unsigned int GetItemValue( const char *pszSectionName,
                        const char *pszKeyName,
                        char *pszReturnedString,
                        unsigned int nSize,
                        const char *pszDefaultValue );

    int  OpenFile(const char *pszFilename);

    void CloseFile();

private:

    unsigned int LocateSection(const char *pszSectionName,
                        char * &pszSectionBegin,
                        char * &pszSectionEnd);
    unsigned int LocateKeyRange(const char *pszKeyName,
                        const char *pszSectionBegin,
                        const char *pszSectionEnd,
                        char * &pszKeyBegin,
                        char * &pszKeyEnd);
    unsigned int LocateKeyValue(const char *pszKeyName,
                        const char *pszSectionBegin,
                        const char *pszSectionEnd,
                        char * &pszValueBegin,
                        char * &pszValueEnd);
    char *LocateStr(    const char *pszCharSet,
                        const char *pszBegin,
                        const char *pszEnd );
    char *SearchMarchStr(const char *pszBegin, const char *pszCharSet);

    char *MapToContent(const char *p);
    char *MapToShadow(const char *p);

    void ToLower( char * pszSrc, size_t len);

};



#endif
