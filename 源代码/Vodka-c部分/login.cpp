//
// Created by 蓝一潇 on 2018/5/27.
//
#include "iostream"
#include "fstream"
#include "cstdio"
using namespace std;
int login(){
 //   printf("123\n");
    fstream scan;
    scan.open("user_list.txt", ios::in);
    cout<<scan.is_open()<<endl;
    string password;
    string username;
    string input_password;
    string input_username;
    cout<<"请输入用户名："<<endl;
    cin>>input_username;
    cout<<"请输入密码："<<endl;
    cin>>input_password;
    while(!scan.eof()){
        scan>>password>>username;
        if(password==input_password&&username==input_username){
            cout<<"登录成功！"<<endl;
            scan.close();
            return 200;
        }
    }
    cout<<"用户名或密码错误，请重新输入！"<<endl;
    scan.close();
    return 504;
}
//int main(){
//    login();
//    return 0;
//}
