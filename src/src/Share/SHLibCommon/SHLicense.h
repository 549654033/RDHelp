#pragma once
#include "Common.h"

////////////////////////////////////////////////////////////////////////////////
/// Class Name  : CLicenseTools
/// Description : license����
/// See Also    : @see 
///************CLicenseTools��ʼ******************
class SH_EXPORT CSHLicense
{
public:
	/**
	* ��license���ݽ��м����γ�key
	* @param content[in]: license�ļ��ľ�������
	* @param size[in]: license�����ַ����Ĵ�С
	* @param bufferKey[out]: ����licenseKey���ַ���
	* @param bufOfLen[out]: licenseKey�Ĵ�С
	* @return [int]: 0��ʾ�ɹ���-1��ʾʧ��
	*/  
	static int CreateLicenseKey( const char*content, const int size, char *bufferKey, int &bufOfLen);
	/**
	* ��֤license�Ƿ�Ϸ�
	* @param content[in]: license������
	* @param size[in]: license�ĳ���
	* @param key[in]: key������
	* @param keysize[in]: key�ĳ���
	* @return: 0��ʾ��֤�ɹ�,-1��ʾ��֤ʧ��
	*/
	static int CheckLicense( const char*content, const int size, const char*key, const int keysize);
	/** 
	* @param licenseFile[in]: license�ļ�������
	* @param keyFile[in]:key�ļ�������
	* @return : �Ϸ�����true, �Ƿ�����false
	*/
	static bool CheckLicenseByFile( char* licenseFile, char*keyFile);

};
