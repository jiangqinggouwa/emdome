#include <io.h>		//_finddata_t的头文件
#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
void findAllFile(const char * path,const char * format)
{
    char newpath[200];
    strcpy(newpath, path);
    strcat(newpath, "\\*.*");    // 在目录后面加上"\\*.*"进行第一次搜索
    int handle;
    _finddata_t findData;
    handle = _findfirst(newpath, &findData);
    if (handle == -1)        // 检查是否成功
        return;
     while (_findnext(handle, &findData) == 0){
        if (findData.attrib & _A_SUBDIR){
            if (strcmp(findData.name, ".") == 0 || strcmp(findData.name, "..") == 0)
                continue;
            strcpy(newpath, path);
            strcat(newpath, "\\");
            strcat(newpath, findData.name);
            findAllFile(newpath,format);
        }
        else{
            if(strstr( findData.name,format)){     //判断是不是txt文件
                cout << findData.name << "\t" <<path<<"\t"<< findData.size << " bytes.\n";
            }
        }
    }
    _findclose(handle);    // 关闭搜索句柄
}

int main()
{
    findAllFile("D:\\WorkSpace\\test",".txt");
    return 0;
}

