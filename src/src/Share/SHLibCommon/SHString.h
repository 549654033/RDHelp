#pragma once
#include "Common.h"
////////////////////////////////////////////////////////////////////////////////
/// Class Name  : CSHString
/// Description : �ַ���������
/// See Also    : @see 
///************CSHString��ʼ******************

class SH_EXPORT CSHString
{
public:

  /**
    * <P>��strReplace�滻str�е�һ��sFind<P>
    * @param str:[in]ԭʼstring
    * @param sFind:[in]
    * @param sReplease:[in]
    * @param sReturn:[out]�õ�����string
    * @return void
    * @exception
    */
    static void strReplace(string str,string strFind,string strReplace,string &sReturn);
    /**
    * <P>��strRemoveSpaceȥ���ַ����пո�<P>
    * @param str:[in]ԭʼstring
    * @param sReturn:[out]�õ�����string
    * @return void
    * @exception
    */
	static void strRemoveSpace(string str,string &sReturn);
    /**
    * <P>�õ�str��sKey��ֵ(sKey=sReturn;)<P>
    * @param str:[in]ԭʼstring
    * @param sKey:[in]
    * @param s1:[in]
    * @param s2:[in]
    * @param sReturn:[out]�õ�����string
    * @return void
    * @exception
    */
    static bool GetStrValue(string str,string sKey,string &sReturn,string s1=";",string s2="=");
    static bool SetStrValue(string str,string sKey,string newData,string &sReturn,string s1,string s2="=");
    /**
    * <P>str��ʽ��<P>
    * @param str:[in]ԭʼstring
    * @param sReturn:[out]�õ�����string
    * @return void
    * @exception
    */   
    static void strFormat(string &sReturn,string str,...);
	
    /**
    * <P>str��ʽ��<P>
    * @param str:[in]ԭʼstring
    * @param arglist:[in]va_list
    * @param sReturn:[out]�õ�����string
    * @return void
    * @exception
    */   
    static void strFormatEx(string &sReturn,string str,va_list arglist);
    
    /**
    * <P>�õ�sStart��sEnd֮�����string ����߲���<P>
    * @param str:[in]ԭʼstring
    * @param sStart:[in]��ʼstring
    * @param sEnd:[in]����string
    * @param sReturn:[out]�õ�����string
    * @return bool: �ɹ�/ʧ��
    * @exception
    */
    static bool GetLeftSubStr(string str,string sStart,string sEnd,string &sReturn);

    /**
    * <P>�õ�sStart��sEnd֮�����string ���ұ߲���<P>
    * @param str:[in]ԭʼstring
    * @param sStart:[in]��ʼstring
    * @param sEnd:[in]����string
    * @param sReturn:[out]�õ�����string
    * @return bool: �ɹ�/ʧ��
    * @exception
    */
    static bool GetRightSubStr(string str,string sStart,string sEnd,string &sReturn);

    /**
    * <P>�õ�sStart��sEnd֮�����string ��ʼ���󣬽�������<P>
    * @param str:[in]ԭʼstring
    * @param sStart:[in]��ʼstring
    * @param sEnd:[in]����string
    * @param sReturn:[out]�õ�����string
    * @return bool: �ɹ�/ʧ��
    * @exception
    */
    static bool GetLeftRightSubStr(string str,string sStart,string sEnd,string &sReturn);

    /**
    * <P>����sFind�ָ��str�洢��VEC_str��<P>
    * @param vecStr: [in,out]�洢�ָ�����vector
    * @param str: [in]��ch�ָ��string
    * @param sFind: [in]�ָ��
    * @return     
    * @exception
    */
    static void ConvertString2Vector(vector<string>  &vecStr,string str,string sFind=",");

    /**
    * <P>�Ƚ�2��string<P>
    * @param str1: [in]��һ��string
    * @param str2: [in]�ڶ���string
    * @param bCase: [in]�Ƿ����ִ�Сд
    * @return �ȽϽ��
    <0��str1<str2
    =0��str1=str2
    >0��str1>str2
    * @exception
    */
    static int CmpStr(string str1,string str2,bool bCase=false);
    
    /**
    * <P>ȥ��string��ߵ��ַ�<P>
    * @param str: [in,out]Ҫת����string
    * @param c: [in]Ҫȥ�����ַ�
    * @return void
    * @exception
    */
    static void TrimCharLeft(string &str,char c);
    
    /**
    * <P>ȥ��string�ұߵ��ַ�<P>
    * @param str: [in,out]Ҫת����string
    * @param c: [in]Ҫȥ�����ַ�
    * @return void
    * @exception
    */
    static void TrimCharRight(string &str,char c);
    
    /**
    * <P>ȥ��string���ߵ��ַ�<P>
    * @param str: [in,out]Ҫת����string
    * @param c: [in]Ҫȥ�����ַ�
    * @return void
    * @exception
    */
    static void TrimChar(string &str,char c);

    /** 
      * ȥ���ַ����еĿո��ַ�
      * @param s[in]:�����ַ���
      * @return ���ú���ַ���
      * @exception ��
      * @see  
      */
    static string Trim(const string& s); 
	
    /**
      * ��һ���ַ�����ָ�����ַ��ָ�ɼ����ַ��������ѷָ����ַ��������set��
      * @param str[in]:�����ַ���
      * @param separator[in]:�жϷָ���ַ�
      * @return �ָ�֮���һ���ַ���������set��
      * @exception ��
      * @see  
      */
    static std::set<string> Split(string str,char separator);

      
      /** ��һ���ַ��������ض��ķָ��ַ��ָ�ɼ����ַ�������ȡ�����Ӵ����κοո񼰿��Ʒ�
      * �ָ��������Ӵ�������vector��string�����vector�Ĵ�С�̶�Ϊ
      * �����ַ�����ָ���ָ������ֵĴ�����һ
      * @param str[in]: �����ַ���
      * @param separator[in]:�жϷָ���ַ�
      * @return ����vector��vector���ŵ��·ָ����ַ���  
      * @exception ��
      * @see  
      */
    static vector<string> SplitAllInVector(string str,char separator);

    /** 
      * ��һ���ַ��������ض��ķָ��ַ��ָ�ɼ����ַ�������ȥ�����Ӵ���ǰ��ո񼰿��Ʒ�
      * �ָ��������Ӵ�������vector��string����ַ���Ҳһ������������vector�Ĵ�С�̶�Ϊ
      * �����ַ�����ָ���ָ������ֵĴ�����һ
      * @param str[in]: �����ַ���
      * @param separator[in]:�жϷָ���ַ�
      * @return ����vector��vector���ŵ��·ָ����ַ���  
      * @exception ��
      * @see  
      */
    static vector<string> SplitAllInVectorNoTrim(string str,char separator);

        /** 
      * ��һ���ַ��������ض��ķָ��ַ��ָ�ɼ����ַ������ѷָ����ַ�������vector��string��	      
      * ͬʱɾ�����п��ַ���
      * @param str[in]: �����ַ���
      * @param separator[in]:�жϷָ���ַ�
      * @return ����vector��vector���ŵ��·ָ����ַ���  
      * @exception ��
      * @see  
      */
    static vector<string> SplitInVector(string str,char separator);
	
    /** 
      * ��һ���ַ��������ض��ķָ��ַ��ָ�ɼ����ַ������ѷָ����ַ�������vector��string�
      * ��ÿ���ַ���������Trim����	      
      * @param str[in]: �����ַ���
      * @param separator[in]:�жϷָ���ַ�
      * @return ����vector��vector���ŵ��·ָ����ַ���  
      * @exception ��
      * @see  
      */
    static vector<string> SplitInVectorNoTrim(string str,char separator);
	
    /**
      * <P>csv�ļ��ַ������</P> 
      * @param str: [in]���ֵ�һ��csv��ʽ�ַ���
      * @return �Ѳ�ֺõĸ��ֶ�����
      */
    static vector<string> SplitCsvFields(string& str);
        
    /**
      * ȡ����string��ʽ��set���Ӧ��string���Ӽ�
      * @param r1[in]��������ַ���
      * @param r2[in]��������ַ��� 
      * @return ����set��ʽ��string�����������ַ����Ľ������ڷ���string��  
      * @exception ��
      * @see
      */
      static std::set<string> StringSetSubstraction(std::set<string> &r1,std::set<string> &r2);
	
      ///implements the string sets intersection
    /**
      * ȡ�����ַ����Ľ��������ѽ������ַ����ŵ�set��ʽ��string��
      * @param r1[in]��������ַ���
      * @param r2[in]��������ַ��� 
      * @return ת�����32λ�޷�������
      * @exception ��
      * @see
      */	
      static std::set<string> StringSetIntersection(std::set<string> &r1,std::set<string> &r2);

    /**
      * ��theStringת��Ϊ��д��ʽ
      * @param theString[in]��������ַ���
      * @return ת�����32λ�޷�������
      * @exception ��
      * @see
      */	    
      static string ToUpperCase(const string theString);
	
    /**
      * ��theStringת��ΪСд��ʽ
      * @param theString[in]��������ַ���
      * @return ת�����32λ�޷�������
      * @exception ��
      * @see
      */
      static string ToLowerCase(const string theString);
	
    /**
      * �ж��ַ����Ƿ���������ʽ
      * @param theString[in]��
      * @return 
      * @exception ��
      * @see
      */
      static bool IsDigit(const string theString);   	
    /**
      * 
      * @param pBuf��Ҫת���ַ������׵�ַ
      * @param nLen��Ҫת���ַ����ĳ��� 
      * @return ת�����32λ�޷�������
      * @exception logic_error
      * @see
      */
      static uint32 StringToLong(const char* pBuf, int nLen);
	
    /**
      * 
      * @param pBuf��Ҫת���ַ������׵�ַ
      * @param nLen��Ҫת���ַ����ĳ��� 
      * @return ת�����16λ�޷�������
      * @exception logic_error
      * @see
      */
      static uint16 StringToShort(const char* pBuf, int nLen) ;	    
    /**
      * ���ַ����е�ָ�� char ��ָ�� string �滻
      * @param strOrig  ��ԭ�ַ���
      * @param chKey    ����Ҫ���滻�� char
      * @param strValue �������滻 char �� string
      * @return string  ���滻����������ַ���
      * @exception ��
      * @see
      */
    static string ReplaceCharWithString(const string& strOrig, const char chKey, const string& strValue );     

    static std::string Base64Encode(string str);
	static std::string Base64Decode(string str);
};
