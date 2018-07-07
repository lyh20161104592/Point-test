
#include <iostream>
#include <String>
using namespace std;
int c=0;
struct student{
    int id;
    string name;
    string sex;
    string proname;
    string type;
    string number;
    string cclass;
    double score[10];
    double sum;
    double average;
    double max;
    double min;
};
struct referee{
    string name;
    string sex;
    string tel;
};
int inputs(student *s)
{
    int i,n;
    cout<<"请输入参赛者人数:"<<endl;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cout<<"请输入参赛者编号:"<<endl;
        cin>>s[i].id;
        cout<<"请输入参赛者姓名:"<<endl;
        cin>>s[i].name;
        cout<<"请输入参赛者性别:"<<endl;
        cin>>s[i].sex;
        cout<<"请输入参赛者节目名称:"<<endl;
        cin>>s[i].proname;
        cout<<"请输入参赛者节目类别:"<<endl;
        cin>>s[i].type;
        cout<<"请输入参赛者电话号:"<<endl;
        cin>>s[i].number;
        cout<<"请输入参赛者班级号:"<<endl;
        cin>>s[i].cclass;
        c++;
    }
    cout<<"参赛者信息录入成功!"<<endl;
    return 0;
}
int outputs(student *s)
{
    int i;
    for(i=0;i<c;i++)
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
int Inputr(referee *r)
{
    int i;
    cout<<"请分别输入五位裁判的个人信息:"<<endl;
    for(i=0;i<5;i++)
    {
        cout<<"请输入裁判姓名:"<<endl;
        cin>>r[i].name;
        cout<<"请输入裁判性别:"<<endl;
        cin>>r[i].sex;
        cout<<"请输入裁判电话:"<<endl;
        cin>>r[i].tel;
        
    }
    cout<<"裁判信息录入成功!"<<endl;
    return 0;
}
int Outputr(referee *r)
{
    int i;
    for(i=0;i<5;i++)
    {
        cout<<"裁判姓名:";
        cout<<r[i].name<<endl;
        cout<<"性别:";
        cout<<r[i].sex<<endl;
        cout<<"电话号:";
        cout<<r[i].tel<<endl;
    }
    cout<<"裁判信息输出成功!"<<endl;
    return 0;
}
int mark(student *s)
{
    int i,n;
    int flag=1;
    while (flag)
    {
        cout<<"请输入要评分的参赛者编号:"<<endl;
        cin>>n;
        for (i=0; i<c;)
        {
            if (s[i].id!=n)
            {
                i++;
            }
            else
            {
                break;
            }
        }
        if(i>=c||n<=0)
        {
            cout<<"输入编码错误，请重新输入!"<<endl;
            
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
            cin>>s[n-1].score[4];
            flag=0;
        }
    }
    cout<<"裁判评分成功!"<<endl;
    return 0;
}
int average(student *s)
{
    int i,j;
    s[i].sum=0;
    s[i].average=0;
    for(i=0;i<c;i++)
    {
        s[i].max=s[i].score[0];
        s[i].min=s[i].score[0];
        for(j=0;j<5;j++)
        {
            if(s[i].score[j]>s[i].max)
            {
                s[i].max=s[i].score[j];
            }
            if(s[i].score[j]<s[i].min)
            {
                s[i].min=s[i].score[j];
            }
            s[i].sum+=s[i].score[j];
        }
        s[i].sum=s[i].sum - s[i].max - s[i].min;
        s[i].average = s[i].sum / 3;
    }
    cout<<"计算平均分成功!"<<endl;
    return 0;
}

int show(student *s,referee *r)
{
    int i;
    for(i=0;i<c;i++)
    {
        cout<<"参赛者姓名为:"<<s[i].name<<endl;
        cout<<"编号:"<<s[i].id<<endl;
        cout<<"性别:"<<s[i].sex<<endl;
        cout<<"节目名称:"<<s[i].proname<<endl;
        cout<<"节目类别:"<<s[i].type<<endl;
        cout<<"电话:"<<s[i].number<<endl;
        cout<<"班级:"<<s[i].cclass<<endl;
        cout<<"第一个评委"<<r[0].name<<"分数是:";
        cout<<s[i].score[0]<<endl;
        cout<<"第二个评委"<<r[1].name<<"分数是:";
        cout<<s[i].score[1]<<endl;
        cout<<"第三个评委"<<r[2].name<<"分数是:";
        cout<<s[i].score[2]<<endl;
        cout<<"第四个评委"<<r[3].name<<"分数是:";
        cout<<s[i].score[3]<<endl;
        cout<<"第五个评委"<<r[4].name<<"分数是:";
        cout<<s[i].score[4]<<endl;
        cout<<"去掉一个最低分为:";
        cout<<s[i].min<<endl;
        cout<<"去掉一个最高分为:";
        cout<<s[i].max<<endl;
        cout<<"所得的平均成绩是:";
        cout<<s[i].average<<endl;
    }
    return 0;
}
int updatemark(student *s)
{
    int i,n;
    int flag=1;
    while (flag)
    {
        cout<<"请输入要修改评分的参赛者编号:"<<endl;
        cin>>n;
        for (i=0; i<c;)
        {
            if (s[i].id!=n)
            {
                i++;
            }
            else
            {
                break;
            }
        }
        if(i>=c||n<=0)
        {
            cout<<"输入编号错误，请重新输入!"<<endl;
            
        }
        else
        {
            cout<<"请重新输入第一个裁判修改后的分数:";
            cin>>s[n-1].score[0];
            cout<<"请重新输入第二个裁判修改后的分数:";
            cin>>s[n-1].score[1];
            cout<<"请重新输入第三个裁判修改后的分数:";
            cin>>s[n-1].score[2];
            cout<<"请重新输入第四个裁判修改后的分数:";
            cin>>s[n-1].score[3];
            cout<<"请重新输入第五个裁判修改后的分数:";
            cin>>s[n-1].score[4];
            flag=0;
        }
    }
    return 0;
}
int deletebyno(student *s)
{
    int i,j,n;
    int flag=1;
    while (flag)
    {
        cout<<"请输入要删除的参赛者编号:"<<endl;
        cin>>n;
        for (i=0; i<c;)
        {
            if (s[i].id!=n)
            {
                i++;
            }
            else
            {
                break;
            }
        }
        if(i>=c||n<=0)
        {
            cout<<"输入编号错误，请重新输入!"<<endl;
        }
        else
        {
            for(j=i;j<c;j++)
            {
                s[j]=s[j+1];
            }
            c--;
            flag=0;
        }
    }
    cout<<"参赛者信息删除成功!"<<endl;
    return 0;
}
int deletebyname(student *s)
{
    int i,j;
    string n;
    int flag=1;
    while (flag)
    {
        cout<<"请输入要删除的参赛者姓名:"<<endl;
        cin>>n;
        for (i=0; i<c;)
        {
            if (s[i].name!=n)
            {
                i++;
            }
            else
            {
                break;
            }
        }
        if(i>=c)
        {
            cout<<"输入姓名错误，请重新输入!"<<endl;
        }
        else
        {
            for(j=i;j<c;j++)
            {
                s[j]=s[j+1];
            }
            c--;
            flag=0;
        }
    }
    cout<<"参赛者信息删除成功!"<<endl;
    return 0;
}
int delet(student *s)
{
    int MenuItem;
    cout<<"         ******删除菜单******       "<<endl;
    cout<<"    -----1.按照编号删除参赛者信息-----       "<<endl;
    cout<<"    -----2.按照姓名删除参赛者信息-----       "<<endl;
    do
    {
        cout<<"请输入选项(1-2:)"<<endl;
        cin>>MenuItem;
    }while(MenuItem<0||MenuItem>2);
    switch(MenuItem)
    {
        case 1:
            deletebyno(s);
            break;
        case 2:
            deletebyname(s);
            break;
    }
    return MenuItem;
}
int input(student *s,referee *r)
{
    int MenuItem;
    cout<<"      ******输入菜单******       "<<endl;
    cout<<"    -----1.输入参赛人员信息-----       "<<endl;
    cout<<"    -----2.输入裁判信息-----       "<<endl;
    do
    {
        cout<<"请输入选项(1-2:)"<<endl;
        cin>>MenuItem;
    }while(MenuItem<0||MenuItem>2);
    switch(MenuItem)
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
int output(student *s,referee *r)
{
    int MenuItem;
    cout<<"      ******输出菜单******       "<<endl;
    cout<<"    -----1.输出参赛者信息-----       "<<endl;
    cout<<"    -----2.输出裁判信息-----       "<<endl;
    do
    {
        cout<<"请输入选项(1-2:)"<<endl;
        cin>>MenuItem;
    }while(MenuItem<0||MenuItem>2);
    switch(MenuItem)
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
int menu_select()
{
    int MenuItem;
    cout<<"**********比赛打分系统**********"<<endl;
    cout<<"    -----1.输入参赛人员信息-----      "<<endl;
    cout<<"    -----2.输出参赛人员信息-----      "<<endl;
    cout<<"    -----3.裁判评分-----          "<<endl;
    cout<<"    -----4.计算裁判评分-----          "<<endl;
    cout<<"    -----5.显示裁判评分-----       "<<endl;
    cout<<"    -----6.修改裁判评分-----       "<<endl;
    cout<<"    -----7.删除参赛人员信息-----       "<<endl;
    cout<<"    -----0.退出系统-----       "<<endl;
    do
    {
        cout<<"请输入选项(0-7:)"<<endl;
        cin>>MenuItem;
    }while(MenuItem<0||MenuItem>7);
    return MenuItem;
}
int main()
{
    struct student s[100];
    struct referee r[100];
    while(1)
    {
        switch(menu_select())
        {
            case 1:
                input(s,r);
                break;
            case 2:
                output(s,r);
                break;
            case 3:
                mark(s);
                break;
            case 4:
                average(s);
                break;
            case 5:
                show(s,r);
                break;
            case 6:
                updatemark(s);
                break;
            case 7:
                delet(s);
                break;
            case 8:
                cout<<"谢谢使用!"<<endl;
                return 0;
        }
    }
    return 0;
}
