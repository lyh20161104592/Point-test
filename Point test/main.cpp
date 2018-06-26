//
//  main.cpp
//  Point test
//
//  Created by LYH on 2018/6/25.
//  Copyright © 2018年 LYH. All rights reserved.
//

#include <iostream>
struct student
{
    int num;
    char name[10];
    char sex[10];
    char class_name[10];
    char program_type[10];
    int phone_number[10];
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}
void menu_select()
{
    char s [100];
    int c;
    gets(s);
    while(1)
    {
        c=atoi(s);//利用atoi()函数将所接收的字符串转换成数值，提供给if语句判断
        if(c<1||c>7)
        {
            printf("您的输入有误，请重新输入:");
            get(s);
        }
        elsebreak;
    }
    switch(c)
    {
        case 1:
            system("cls")//清屏
            browse ();//选手信息浏览
            break;
          
        case 2:
            system("cls")//清屏
            creat ();//选手信息录入
            break;
      
        case 3:
            system("cls")//清屏
            save ();//选手信息保存
            break;
            
        case 4:
            system("cls")//清屏
            search ();//选手成绩查询
            break;



    }
}
