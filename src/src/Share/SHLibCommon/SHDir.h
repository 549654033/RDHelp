#pragma once
#include "Common.h"

class SH_EXPORT CSHDir
{
public:
	/**
    *��ָ��·�����½�һ��Ŀ¼��
    *@param path��[in]ָ������Ŀ¼���ڵ�·����
    *@param directoryName��[in]ָ������Ŀ¼�����ƣ�
    *@return bool���Ƿ񴴽��ɹ���
    */
    static bool CreateDir(string path,const string directoryName);
    
    /**
    *��ָ��·����ɾ��һ��Ŀ¼��
    *@param path��[in]ָ��ɾ��Ŀ¼���ڵ�·����
    *@param directoryName��[in]ָ��ɾ��Ŀ¼�����ƣ�
    *@return bool���Ƿ�ɾ���ɹ���
    */
    static bool DelDir(string path,const string directoryName);
    
    /**
    *����ָ��·��path�µ�����Ŀ¼����������Ŀ¼������result�У�
    *@param path��[in]ָ��������·����
    *@param result��[out]�����������Ŀ¼���Ƶ�vector<string>��
    *@return��
    */
    static void SearchDir(string path,vector<string> &result);
    
    /**
    *����ָ��·��path�µ�����ָ������type���ļ����������и������ļ�������result�У�
    *@param path��ָ��������·����
    *@param type��ָ���������ļ����ͣ�
    *@param result��������������ļ����Ƶ�vector<string>��
    *@return��
    */
    static void SearchFile(string path,const string type,vector<string> &result);
    
    /**
    *����·��path���Ƿ���Ŀ¼dirName�Ľӿڣ�
    *@param path��ָ��������·����
    *@param dirName�������ҵ�Ŀ¼���ƣ�
    *@return bool���ҵ��˷���true���Ҳ�������false��
    */
    static bool FindADir(string path,const string dirName);

    /**
    *��ָ��·����ɾ��һ���ļ���
    *@param path��[in]ָ��ɾ���ļ����ڵ�·����
    *@param fileName��[in]ָ��ɾ���ļ������ƣ�
    *@return bool���Ƿ�ɾ���ɹ���
    */
    static bool DelFile(string path,const string fileName);                
};