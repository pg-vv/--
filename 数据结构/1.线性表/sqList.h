//
// Created by ww on 2021/6/15.
//

#include<stdio.h>
#define MaxSize 10//定义静态线性表最大长度
typedef int Elemtype;

typedef struct
{
    Elemtype data[MaxSize];
    int length;
}sqList;//静态线性表数据结构

void InitsqList(sqList &L);//初始化线性表
int LocateElem(sqList L,Elemtype e);//按值查找找到第一个与e相等的元素返回位序
bool GetElem(sqList L,int i,Elemtype &e);//按位查找获取L中第i个数据元素的值用e返回
bool ListInser(sqList &L,int i,Elemtype e);//插入操作在表L的第i个位置插入指定元素e
bool ListDelete(sqList &L,int i,Elemtype &e);//删除操作删除L中第i个位置的元素用e返回
bool PrintfList(sqList L);//打印操作输出线性表中所有元素的值
bool Empty(sqList L);//判空操作若为空表返回true否则返回false


void InitsqList(sqList &L){
    int i;
    for(i=0;i<MaxSize;i++)
        L.data[i]=0;
    L.length=0;
};
int LocateElem(sqList L,Elemtype e){
    int i;
    for(i=0;i<L.length;i++)
    {
        if(L.data[i]==e)
         return i;
    }
}
bool GetElem(sqList L,int i,Elemtype &e)
{
    if(i<0||i>L.length)
        return false;
    e=L.data[i-1];
}

bool ListInser(sqList &L,int i,Elemtype e)
{
    if(i<1||i>L.length+1)
        return false;
    if(L.length>=MaxSize)
        return false;
    for (int j = L.length-1; j>=i;j--)
        L.data[j+1]=L.data[j];
    L.data[i]=e;
    L.length++;
    return true;
}
bool ListDelete(sqList &L,int i,Elemtype &e)
{
    if(i<1||i>L.length)
        return false;
    e=L.data[i-1];
    for (int j = i; j<=L.length ; j++)
        L.data[j-1]=L.data[j];
    L.length--;
    return true;
}

bool PrintfList(sqList L)
{
    if(L.length==0)
        return false;
    for (int i = 0; i <L.length ; i++)
    {
        printf("第%d元素为%d\n",i,L.data[i]);
    }
    return true;
}
bool Empty(sqList L)
{
    if(L.length==0)
        return false;
    else
        return true;
}

