#ifndef DESBASE64_H
#define DESBASE64_H

/**
  * 
  * @param pKey[in]:
  * @param source[in]:
  * @param dest[in]:
  * @param desDest[in]:
  * @return ���� 0 �ɹ� ����ֵʧ��
  * @exception ��
  * @see 
  */
extern int DesEncrypt(const char *pKey,  const char* source, char*dest, char *desDest);

/**
  * 
  * @param pKey[in]:
  * @param source[in]:
  * @param dest[in]:
  * @param desDest[in]:
  * @return ���� 0 �ɹ� ����ֵʧ��
  * @exception ��
  * @see 
  */

extern int DesDecrypt(const char *pKey, const char* source, char*dest, char *desDest);

/**
  * 
  * @param source[in]:
  * @param dest[in]:
  * @param desDest[in]:
  * @return ���� 0 �ɹ� ����ֵʧ��
  * @exception ��
  * @see 
  */

extern int DesEncryptFixKey(const char* source, char*dest);

/**
  * �̶���Ҫ�����㷨 
  * @param  source[in]:
  * @param  dest[in]:
  * @param  desDest[in]:
  * @return ���� 0 �ɹ� ����ֵʧ��
  * @exception ��
  * @see 
  */

extern int DesDecryptFixKey(const char* source, char*dest);

#endif  /// desBase64.h end 


