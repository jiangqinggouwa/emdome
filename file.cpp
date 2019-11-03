
#include<iostream> //输入输出流
#include<fstream> //文件流头文件
using namespace std;
int main()
{
    ifstream in("/home/liuyq/cwork/find/helloworld.c"); //源文件读
    ofstream out( "/home/liuyq/cwork/find/list.h" ); //目标文件写
    if (!in){
        cout <<"open source file error!"<<endl;
        return -1;
    }
    while( !in.eof() ) //文件未结束，循环
    {
        char str[1024];
        in.getline(str,sizeof(str),'\n'); //读一行
        cout << str << endl; //输出到屏幕
        out<< str <<endl; //输出到文件
    }
    in.close();
    out.close();
    return 0;
}