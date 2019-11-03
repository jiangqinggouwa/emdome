
#include<iostream>
#include<dirent.h>
using namespace std;
int main( void )
{
    DIR* dirp;
    struct dirent* direntp;
    dirp = opendir( "/home/liuyq/cwork/find" );
    string tmp =".cpp";
    string filename;
    if( dirp != NULL ) 
	{
        for(;;) {
            direntp = readdir( dirp );
            if( direntp == NULL ) 
		break;
            string s = direntp->d_name;
            int x = s.find(tmp,0);           
            if(x>0){
            	string last;
		last.assign(s,0,x);
		filename=last;
		//filename 就是txt文件的名称，不包含txt后缀，得到名称后添加.txt后缀就可以直接打开进行其他操作
            }
        }
        closedir( dirp );
    }
    cout<<filename<<endl;
    return 0;

}