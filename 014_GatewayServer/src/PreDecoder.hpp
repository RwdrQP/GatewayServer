#ifndef __PREDECODER_HPP__
#define __PREDECODER_HPP__



const unsigned short AUTH_FAILED_MSG_ID = 0xFFFE;
const unsigned short AUTH_ERROR_ERROR_SKEY = 1001;
const int AUTH_ERROR_STR_NUMBER = 256;



class CAuthFailedMsg
{
public:
	int Encode(char *pszOutBuffer, short& rshOutLength);

public:
	unsigned short m_ushMsgID;  // �̶���ϢID
	unsigned short m_ushResultID; // ������
	unsigned short m_ushErrStrNumber; // �����ַ�������
	char m_szErrStr[AUTH_ERROR_STR_NUMBER]; // ������ʾ

};

#endif
