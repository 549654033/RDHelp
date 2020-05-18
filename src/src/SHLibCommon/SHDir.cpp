#include <iostream>
#include "SHDir.h"
using namespace std;

#ifdef WIN32

#include <windows.h>

/** ����һ����Ŀ¼�Ľӿ� */
bool CSHDir::CreateDir(string path,const string directoryName)
{
    /** ȥ��·���������е�"\" */
    if (path.at(path.length()-1)=='\\')
    {
       path.erase(path.length()-1,1); 
    }
    
    /** �ַ���������ƴ��Ҫ������Ŀ¼��ȫ�� */
    string directoryFullName=path+"\\"+directoryName;
    
    /** ����windows API: BOOL CreateDirectory(LPCTSTR lpPathName, LPSECURITY_ATTRIBUTES lpSecurityAttributes );
        ����һ���µ�Ŀ¼����������ֵ */
    return (CreateDirectory(directoryFullName.c_str(),NULL)!=0);  

}
/** ɾ��һ��Ŀ¼�Ľӿ� */
bool CSHDir::DelDir(string path,const string directoryName)
{
    vector<string> dirResult,fileResult;
    vector<string>::iterator result_itr;
    
    /** ȥ��·���������е�"\" */
    if (path.at(path.length()-1)=='\\')
    {
       path.erase(path.length()-1,1); 
    }
    
    /** �ַ���������ƴ��Ҫɾ����Ŀ¼��ȫ�� */
    string directoryFullName=path+"\\"+directoryName;
    
    /** Ҫɾ����Ŀ¼�е�������Ŀ¼���Ʒ���dirResult�У�Ҫɾ����Ŀ¼�е������ļ����Ʒ���fileResult�� */
    SearchDir(directoryFullName,dirResult);
    SearchFile(directoryFullName,"*.*",fileResult);
    
    /** �ݹ����DeleteDirɾ����Ŀ¼�е����е�Ƕ����Ŀ¼ */
    for (result_itr=dirResult.begin(); result_itr!=dirResult.end();result_itr++)
        if((*result_itr!=".")&&(*result_itr!=".."))
            DelDir(directoryFullName,*result_itr);
        
    /** ��ɾ����Ŀ¼�е������ļ� */
    for (result_itr=fileResult.begin(); result_itr!=fileResult.end();result_itr++)
        DelFile(directoryFullName,*result_itr);
        
    /** ����windows API: BOOL RemoveDirectory(LPCTSTR lpPathName); 
        ɾ��һ��Ŀ¼����������ֵ */
    return (RemoveDirectory(directoryFullName.c_str())!=0);
}

/** ɾ��һ���ļ��Ľӿ� */
bool CSHDir::DelFile(string path,const string fileName)
{
       
    /** ȥ��·���������е�"\" */
    if (path.at(path.length()-1)=='\\')
    {
       path.erase(path.length()-1,1); 
    }
    
    /** �ַ���������ƴ��Ҫɾ�����ļ���ȫ�� */
    string fileFullName="\\\\?\\"+path+"\\"+fileName;
    
    /** ����windows API: BOOL DeleteFile(LPCTSTR lpFileName ); 
        ɾ��һ���ļ�����������ֵ */
    return (DeleteFile(fileFullName.c_str())!=0);
}

/** ����һ��Ŀ¼�Ľӿ� */
void CSHDir::SearchDir(string path,vector<string> &result)
{
    /** ȥ��·���������е�"\" */
    if (path.at(path.length()-1)=='\\')
    {
       path.erase(path.length()-1,1); 
    }
    
    /** ���ҵ�һ���ļ���Ŀ¼ */
    string searchPath=path+"\\"+"*.*";
    WIN32_FIND_DATA wfd;                                  
    HANDLE hFind=FindFirstFile(searchPath.c_str(),&wfd);
    
    /** �����ǰ·���·ǿ� */
    if (hFind!=INVALID_HANDLE_VALUE)
    {
        /** ���ȳ�ʼ��result������֮��� */
        result.clear();
        
        /** �����Ŀ¼���������Ƽ���result�� */
        if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
        {
            result.push_back(wfd.cFileName);
            //cout<<wfd.cFileName<<endl;
        }/** end of if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) */
        
        /** ����FindNextFile����������ǰ·���µ������ļ���Ŀ¼ */
        while (FindNextFile(hFind,&wfd))
		{
		   /** �����Ŀ¼���������Ƽ���result�� */
		   if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
		   {
		        result.push_back(wfd.cFileName);
		        //cout<<wfd.cFileName<<endl;
		   }/** end of if (wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) */
		   
		}/** end of while (FindNextFile(hFind,&wfd)) */
		
    }/** end of if (hFind!=INVALID_HANDLE_VALUE) */ 
    
    /** �������� */                                                                          
    FindClose(hFind);
    
    /** ��"."��".."��result��ȥ�� */
    vector<string>::iterator resultItr;
    for (resultItr=result.begin();resultItr!=result.end();resultItr++)
    {
        if (*resultItr==".")
            result.erase(resultItr);
    }
    
    if ( (result.size()==1) && (*result.begin()=="..") )
    /** result��ֻʣһ��".."Ԫ�صĴ����� */
    {
        result.erase(result.begin());
    }
    else
    {
        for (resultItr=result.begin();resultItr!=result.end();resultItr++)
        {
            if (*resultItr=="..")
                result.erase(resultItr);
        }
    }
}

/** ����һ���ļ��Ľӿ� */
void CSHDir::SearchFile(string path,string type,vector<string> &result)
{
    /** ȥ��·���������е�"\" */
    if (path.at(path.length()-1)=='\\')
    {
       path.erase(path.length()-1,1); 
    }
    
    /** �ַ���������ƴ��Ҫ���ҵ��ļ�·�������� */
    string fileFullName=path+"\\"+type;
    
    /** ���ҵ�һ���ļ� */
    WIN32_FIND_DATA wfd;                                  
    HANDLE hFind=FindFirstFile(fileFullName.c_str(),&wfd);
    
    /** ����ҵ���һ�������������ļ�����֮���Ʒ���result�� */
    if (hFind!=INVALID_HANDLE_VALUE)
    {
        /** ���ȳ�ʼ��result������֮��� */
        result.clear();
        
        /** �������Ŀ¼����һ�����ļ�,�������Ƽ���result�� */
        if (!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
        {
            result.push_back(wfd.cFileName);
            //cout<<wfd.cFileName<<endl;
        }/** end of if (!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) */ 
        
        /** ����FindNextFile����������ǰ·���µ����з��ϲ����������ļ���Ŀ¼ */   
        while(FindNextFile(hFind,&wfd))
		{
		   /** �������Ŀ¼����һ�����ļ�,�������Ƽ���result�� */
		   if(!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY))
		   {
		        result.push_back(wfd.cFileName);
                //cout<<wfd.cFileName<<endl;
		   }/** end of if(!(wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) */
		   
		}/** end of while(FindNextFile(hFind,&wfd)) */

    }/** end of if (hFind!=INVALID_HANDLE_VALUE) */ 
    
    /** �������� */                                                                          
    FindClose(hFind);
}

/** ����·��path���Ƿ���Ŀ¼dirName�Ľӿ� */
bool CSHDir::FindADir(string path,const string dirName)
{
    vector<string> result;
    vector<string>::iterator resultItr;
    
    /** ����·��path�µ�����Ŀ¼����������Ŀ¼������result�� */
    SearchDir(path,result);
    
    /** �ڽ���в���������ͬ��Ŀ¼�� */
    for(resultItr=result.begin();resultItr!=result.end();resultItr++)
    {
        /** �и�Ŀ¼���򷵻�true */
        if (*resultItr==dirName) return true;
    }
    
    /** �޸�Ŀ¼������false */
    /** modify by wangwei at 20080124 */
    /// ����÷�֧Ӧ��ֱ�ӷ���false
    ///if (resultItr==result.end())
    ///    return false;
    return false;
    /** modify by wangwei at 20080124  end */
}

#else 

#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <dirent.h>
#include <fnmatch.h>

/** ����һ����Ŀ¼�Ľӿ� */
bool CSHDir::CreateDir(string path,const string directoryName)
{
	mode_t u_mode=0;
	mode_t new_mode=0777;
	
	/** ������Ŀ¼�ķ���Ȩ�� **/
	umask(u_mode);
	
	/** ȥ��·���������е�"\" */
	
  if (path.at(path.length()-1)=='/')
	{
	   path.erase(path.length()-1,1); 
	}
	
	/** �ַ���������ƴ��Ҫ������Ŀ¼��ȫ�� */
	string directoryFullName=path+"/"+directoryName;
	
	return (mkdir((const char*)directoryFullName.c_str(),new_mode));
}

/** ɾ��һ��Ŀ¼�Ľӿ� */
bool CSHDir::DelDir(string path,const string directoryName)
{
	vector<string> fileResult;		///������в��ҵ�����Ŀ¼
	vector<string> dirResult;		///������в��ҵ������ļ�
	vector<string>::iterator itr;
		
	///���path�Ľ�βû��'/',����
	if(path.at(path.length()-1)!='/')
	{
		path+="/";
	}

	path+=directoryName;

		
	///�ҳ���Ŀ¼�µ������ļ���ɾ��
	string filename;
	SearchFile(path,"*",fileResult);
	for(itr=fileResult.begin();itr!=fileResult.end();itr++)
	{
		filename = path + "/";
        filename += *itr;
        if(remove(filename.c_str())!=0)
		{
			return false;
		}
	}
	
	///�ݹ����Ŀ¼�����е���Ŀ¼
	SearchDir(path,dirResult);
	for(itr=dirResult.begin();itr!=dirResult.end();itr++)
	{
		if(!DelDir(path,*itr))
		    return false;
	}
	
		
	if(remove(path.c_str())!=0)
    {
        return false;
    }
	return true;	
}

/** ɾ��һ���ļ��Ľӿ� */
bool CSHDir::DelFile(string path,const string fileName)
{
	string m_FileName;
	
	///�鿴·�����Ƿ���'/',��û������������
	if(path.at(path.length()-1)=='/')
	{
		m_FileName=path+fileName;
	}
	else
	{
		m_FileName=path+"/"+fileName;
	}
	
	return (remove((const char *)m_FileName.c_str())==0);
	
}
/** ����һ���ļ��Ľӿ� */
void CSHDir::SearchFile(string path,string type,vector<string> &result)
{
	DIR * dp;					///Ŀ¼ָ��
	struct dirent * dir;		///Ŀ¼����ָ��
	string m_FileName;			///�ļ�����
	struct stat statbuf;		///�ļ�״̬�ṹ
	
	result.clear();
	///�򿪸�Ŀ¼
	if((dp=opendir((const char *)path.c_str()))==NULL)
	{
		return;
	}
	
	///��·������'/',���������
	if(path.at(path.length()-1)!='/')
	{
		path+="/";
	}
	///����ÿһ��Ŀ¼
	while((dir=readdir(dp))!=NULL)
	{
		m_FileName=path+dir->d_name;
		string dname=dir->d_name;
		
		///��ȡ�ļ�����
		if(stat((const char *)m_FileName.c_str(),&statbuf)<0)
		{
			continue;
		}
		
		///ֻ��ȡ��ͨ�ļ����͵��ļ�
		if(S_ISREG(statbuf.st_mode))
		{
			if(fnmatch((const char *)type.c_str(),(const char *)m_FileName.c_str(),0)==0)
			{
				result.push_back(dname);
			}			
		}///endif S_IFREG(statbuf.st_mode)
				
	}///end while
	
	///�ر�Ŀ¼
	closedir(dp);
}

/** ����һ��Ŀ¼�Ľӿ� */
void CSHDir::SearchDir(string path,vector<string> &result)
{
	DIR * dp;					///Ŀ¼ָ��
	struct dirent * dir;		///Ŀ¼����ָ��
	string m_DirName;			///Ŀ¼����
	struct stat statbuf;		///�ļ�״̬�ṹ
	
	result.clear();
	///�򿪸�Ŀ¼
	if((dp=opendir((const char *)path.c_str()))==NULL)
	{
		return;
	}
	
	///��·������'/',���������
	if(path.at(path.length()-1)!='/')
	{
		path+="/";
	}
	///����ÿһ��Ŀ¼
	while((dir=readdir(dp))!=NULL)
	{
		m_DirName=path+dir->d_name;
		string dname=dir->d_name;
		
		///��ȡ�ļ�����
		if(stat((const char *)m_DirName.c_str(),&statbuf)<0)
		{
			continue;
		}
		
		if(S_ISDIR(statbuf.st_mode))
		{
			if((dname!=".") && (dname!=".."))
			{
				result.push_back(dname);
			}
		}
	}///end while
	
	closedir(dp);
}

/** ����·��path���Ƿ���Ŀ¼dirName�Ľӿ� */
bool CSHDir::FindADir(string path,const string dirName)
{
    vector<string> result;
    vector<string>::iterator resultItr;
    
    /** ����·��path�µ�����Ŀ¼����������Ŀ¼������result�� */
    SearchDir(path,result);
    
    /** �ڽ���в���������ͬ��Ŀ¼�� */
    for(resultItr=result.begin();resultItr!=result.end();resultItr++)
    {
        /** �и�Ŀ¼���򷵻�true */
        if (*resultItr==dirName) return true;
    }
    
    /** �޸�Ŀ¼������false */
    
    /** modify by wangwei at 20080123 */
    /// ����÷�֧Ӧ��ֱ�ӷ���false
    ///if (resultItr==result.end())
    ///    return false;
    return false;
    /** modify by wangwei at 20080123  end */
}

#endif 





///#############################################################################
/// END
