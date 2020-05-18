#pragma once
#include "Common.h"

///************CSHString����******************
////////////////////////////////////////////////////////////////////////////////
/// Class Name  : CEncryptDecrypt
/// Description : �ӽ��ܴ�����
/// See Also    : @see 
///************CEncryptDecrypt��ʼ******************
class SH_EXPORT CSHEncrypt
{
public:
    /**
      * �÷����ṩ�˶ԳƼӽ��ܵĹ��ܡ�	 
      * @param Type[in]��ȷ�ϲ��������Ǽ��ܻ��ǽ��� 
      *  0��ʾ���ܶԳ� 1 ��ʾ�Գƽ���
      * @param pInput[in]�������ԭ�� 
      * @param lenInput[in]������ԭ�ĵĳ��� 
      * @param pOutput[in]��������ĵ�buffer,��buffer��Ҫ�������ڵ��ýӿ�ǰ���䲢��ʼ���� 
      * @param lenOutput[out]��������ݳ��� 
      * @param CryType[in]�������㷨���ͣ�Ĭ��Ϊ3des�㷨 
      *                    0��ʾ����des�㷨    1��ʾ����3des�㷨
      * @param pkeyCh[in]����Կ��Ĭ��Ϊ12345678 
      * @return 0 �ɹ� ����ֵʧ��
      * @exception ��
      * @see 
      */
      static int32 EncryptDecryptData(int32 type, const char* pInput, int32 lenInput, char *pOutput, int32 *lenOutput, int32 cryType=1, const char* pKeyCh="01234567");
    /**
      * �÷����ṩ�˹̶���Կ�ĶԳƼӽ��ܵĹ���,Ĭ�ϵ��㷨��3des�㷨��	 
      * @param pInput[in]�������ԭ�� 
      * @param pOutput[in]���������ĵ�buffer,��buffer��Ҫ�������ڵ���֮ǰ���䲢��ʼ���� 
      * @param CryType[in]�������㷨���ͣ�Ĭ��Ϊ3des�㷨 
      *                    0��ʾ����des�㷨    1��ʾ����3des�㷨
      * @return 0 �ɹ� ����ֵʧ��
      * @exception ��
      * @see 
      */
      static int32 TripleDesFixKeyEncryptDecryptData(int32 type, const char* pInput, char *pOutput, int32 cryType=1);	
    /**
      * �÷����ṩ�Ĺ��ܶ�һ�����ݽ���ժҪ,Ĭ�ϵ���MD5ժҪ.ժҪ������ݱ�base64����.
      * @param  pOriginalText[in]�������ԭ��
      * @param  lenOriginalText[in]�������ԭ�ĳ��� 
      * @param  pDigestInfo[in]������ԭ�ĵ�ժҪ��Ϣ��buffer
      * @param  lenDigest[out]�� ժҪ��Ϣ�ĳ���
      * @param  digestArithType[in]�� ժҪ���㷨����Ŀǰ�ṩMd5�㷨��Ĭ�ϵ���Ϊ0��Md5�㷨 
      * @return 0 �ɹ� ����ֵʧ��
      * @exception ��
      * @see 
      */
      static int32 DigestInfo(const char* pOriginalText, int32 lenOriginalText, char *pDigestInfo, int32 *lenDigest,int32 digestArithType=0);

	  static string Encrypt(string minwen);
	  static string Decrypt(string miwen);
};