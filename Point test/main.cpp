
#include <iostream>
#include <cstring>
#include<stdio.h>

using namespace std;
int c = 0;
struct student {
    int id;
    string name;
    string sex;
    string proname;
    string type;
    string number;
    string cclass;
    double score[10];
    double sum=0;
    double average=0;
    double max;
    double min;
};
struct referee {
    string name;
    string sex;
    string tel;
};
int menu_select()
{
    int MenuItem;
    cout << "**********比赛打分系统**********" << endl;
    cout << "    -----1. 输入参赛人员及裁判信息-----      " << endl;
    cout << "    -----2. 输出参赛人员及裁判信息-----      " << endl;
    cout << "    -----3. 裁判评分-----          " << endl;
    cout << "    -----4. 计算平均分-----       " << endl;
    cout << "    -----5. 显示参赛者分数具体信息 ˝-----       " << endl;
    cout << "    -----6. 降序排序参赛者的平均分-----      " << endl;
    cout << "    -----0. 退出并保存到文件-----       " << endl;
    do
    {
        cout << "请输入选项(0-6:)" << endl;
        cin >> MenuItem;
    } while (MenuItem<0 || MenuItem>7);
    return MenuItem;
}
int inputs(student *s)
{
    int i, n;
    cout << "输入参赛者人数信息:" << endl;
    cin >> n;
    for (i = 0; i<n; i++)
    {
        cout << "输入学生编号:" << endl;
        cin >> s[i].id;
        cout << "输入学生名字:" << endl;
        cin >> s[i].name;
        cout << "性别：" << endl;
        cin >> s[i].sex;
        cout << "节目名称：" << endl;
        cin >> s[i].proname;
        cout << "节目类别:" << endl;
        cin >> s[i].type;
        cout << "学生电话" << endl;
        cin >> s[i].number;
        cout << "学生班级:" << endl;
        cin >> s[i].cclass;
        c++;
    }
    cout << "学生信息输入完成!" << endl;
    return 0;
}
int Inputr(referee *r)
{
    int i;
    cout << "请输入裁判信息:" << endl;
    for (i = 0; i<5; i++)
    {
        cout << "裁判姓名:" << endl;
        cin >> r[i].name;
        cout << "裁判性别:" << endl;
        cin >> r[i].sex;
        cout << "裁判电话:" << endl;
        cin >> r[i].tel;
        
    }
    cout << "裁判信息输入完成!" << endl;
    return 0;
}
int input(student *s, referee *r)
{
    int MenuItem;
    cout << "      ****** 输入选项******       " << endl;
    cout << "    -----1. 输入参赛者信息-----       " << endl;
    cout << "    -----2. 输入裁判信息-----       " << endl;
    do
    {
        cout << "请输入选项(1-2:)" << endl;
        cin >> MenuItem;
    } while (MenuItem<0 || MenuItem>2);
    switch (MenuItem)
    {
        case 1:
            inputs(s);
            break;
        case 2:
            Inputr(r);
            break;
    }
    return MenuItem;
}
int outputs(student *s)
{
    int i;
    for (i = 0; i<c; i++)
    {
        cout<<"参赛者编号:";
        cout<<s[i].id<<endl;
        cout<<"参赛者姓名:";
        cout<<s[i].name<<endl;
        cout<<"性别:";
        cout<<s[i].sex<<endl;
        cout<<"节目名称:";
        cout<<s[i].proname<<endl;
        cout<<"节目类别:";
        cout<<s[i].type<<endl;
        cout<<"电话号:";
        cout<<s[i].number<<endl;
        cout<<"班级号:";
        cout<<s[i].cclass<<endl;
    }
    cout<<"参赛者信息输出成功!"<<endl;
    return 0;
}
int Outputr(referee *r)
{
    int i;
    for (i = 0; i<5; i++)
    {
        cout<<"裁判姓名:";
        cout<<r[i].name<<endl;
        cout<<"性别:";
        cout<<r[i].sex<<endl;
        cout<<"电话号:";
        cout<<r[i].tel<<endl;	}
    cout << "裁判信息输出成功!" << endl;
    return 0;
}
int output(student *s, referee *r)
{
    int MenuItem;
    cout<<"      ******输出菜单******       "<<endl;
    cout<<"    -----1.输出参赛者信息-----       "<<endl;
    cout<<"    -----2.输出裁判信息-----       "<<endl;
    do
    {
        cout << "请输入选项(1-2:)" << endl;
        cin >> MenuItem;
    } while (MenuItem<0 || MenuItem>2);
    switch (MenuItem)
    {
        case 1:
            outputs(s);
            break;
        case 2:
            Outputr(r);
            break;
    }
    return MenuItem;
}

int mark(student *s)
{
    int i, n;
    int flag = 1;
    while (flag)
    {
        cout << "请输入要评分的参赛者编号:" << endl;
        cin >> n;
        for (i = 0; i<c;)
        {
            if (s[i].id != n)
            {
                i++;
            }
            else
            {
                break;
            }
        }
        if (i >= c || n <= 0)
        {
            cout << "输入编码错误，请重新输入!" << endl;
            
        }
        else
        {
            cout<<"第一个裁判打的分数为:";
            cin>>s[n-1].score[0];
            cout<<"第二个裁判打的分数为:";
            cin>>s[n-1].score[1];
            cout<<"第三个裁判打的分数为:";
            cin>>s[n-1].score[2];
            cout<<"第四个裁判打的分数为:";
            cin>>s[n-1].score[3];
            cout<<"第五个裁判打的分数为:";
            cin >> s[n - 1].score[4];
            flag = 0;
        }
    }
    cout << " 评分完成!" << endl;
    return 0;
}
int average(student *s)
{
    int i;
    int j;
    for (i = 0; i<c; i++)
    {
        s[i].max = s[i].score[0];
        s[i].min = s[i].score[0];
        for (j = 0; j<5; j++)
        {
            if (s[i].score[j]>s[i].max)
            {
                s[i].max = s[i].score[j];
            }
            if (s[i].score[j]<s[i].min)
            {
                s[i].min = s[i].score[j];
            }
            s[i].sum += s[i].score[j];
        }
        s[i].sum = s[i].sum - s[i].max - s[i].min;
        s[i].average = s[i].sum / 3;
        cout << s[i].average << endl;
        
    }
    cout << "计算平均分成功!" << endl;
    return 0;
}

int show(student *s, referee *r)
{
    int i;
    for (i = 0; i<c; i++)
    {
        cout<<"|参赛者姓名|编号|性别|节目名称|节目类别|电话|班级|"<<endl;
        cout<<s[i].name<<"        |"<<s[i].id<<"   |"<<s[i].sex<<"   |"<<s[i].proname<<"    |"<<s[i].type<<"     |"<<s[i].number<<"  |"<<s[i].cclass<<"  |"<<endl;
        cout<<"第一个评委|第二个评委|第三个评委|第四个评委|第五个评委|"<<endl;
        cout<<s[i].score[0]<<"       |"<<s[i].score[1]<<"       |"<<s[i].score[2]<<"       |"<<s[i].score[3]<<"         |"<<s[i].score[4]<<endl;
        cout<<"|最低分|";
        cout<<"  "<<s[i].min<<endl;
        cout<<"|最高分|";
        cout<<"  "<<s[i].max<<endl;
        cout<<"|平均成绩是|";
        cout<<"  "<<s[i].average << endl;
    }
    return 0;
}

void sort(student *s)
{
    int i, j;
    struct student temp;
    for (j = 0; j < c; j++)
    {
        for (i = 0; i < c - j; i++)
        {
            if (s[i].average < s[i + 1].average)
            {
                temp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = temp;
            }
        }
    }
    for (i = 0; i < c; i++)
    {
        cout << s[i].name<<"    "<< s[i].average << endl;
        
        
    }
    
}

/*void open(student *s)
{
    FILE *fp1;//定义文件流指针，用于打开读取的文件
    char text[1024];//定义一个字符串数组，用于存储读取的字符
    fp1 = fopen("//Users//lyh//Desktop//Point test//lyh.csv","r");//只读方式打开文件a.txt
    while(fgets(text,1024,fp1)!=NULL)//逐行读取fp1所指向文件中的内容到text中
    {
        puts(text);//输出到屏幕
    }
    fclose(fp1);//关闭文件a.txt，有打开就要有关闭
}*/
void save(student *s)
 {
	int i;
	FILE* fp;
	fp = fopen("//Users//lyh//Desktop//Point test//lyh.csv", "w");
	if (fp == NULL)
	{
 cout << ("该文件无法打开!\n") << endl;
	}
	else
	{
 fprintf(fp, "学生编号,学生姓名,性别,节目名称,节目类别,电话,班级,第一位评委分数,第二位评委分数,第三位评委分数,第四位评委分数,第五位评委分数,总分,最高分,最低分,平均分\n");
	}
	for (i = 0; i < c; i++)
	{
      fprintf(fp, "%d,%s,%s,%s,%s,%s,%s,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf\n",
              s[i].id, s[i].name.c_str(), s[i].sex.c_str(), s[i].proname.c_str(),
              s[i].type.c_str(), s[i].number.c_str(),s[i].cclass.c_str(),s[i].score[0],
              s[i].score[1], s[i].score[2], s[i].score[3], s[i].score[4], s[i].sum, s[i].max,
              s[i].min, s[i].average);
	}
	cout << ("文件保存成功！\n") << endl;
	fclose(fp);
 }
int main()
{
    struct student s[100];
    struct referee r[100];
    while (1)
    {
        switch (menu_select())
        {
            case 1:
                input(s, r);
                break;
            case 2:
                output(s, r);
                break;
            case 3:
                mark(s);
                break;
            case 4:
                average(s);
                break;
            case 5:
                show(s, r);
                break;
            case 6:
                sort(s);
                break;
            /*case 7:
                open(s);
                break;*/
            case 0:
                 save(s);
                 cout << "谢谢使用!" << endl;
                 return 0;
        }
    }
    return 0;
}
