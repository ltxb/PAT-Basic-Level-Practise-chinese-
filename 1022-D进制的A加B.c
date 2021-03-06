/*
----------------------------------------------------------------------------------------------------
                                1022.D进制的A+B（20）
    输入两个非负的10进制整数A和B(<2的30次方-1)，输出A+B的D(1<D<=10)进制数。
    输入格式：
    输入在一行中依次给出3个整数A、B和D。
    输出格式：输出A+B的D进制数。
    输入样例：
    123 456 8
    输出样例：
    1103
----------------------------------------------------------------------------------------------------
    作业者：愣头小兵    E-mail:ltxb@qq.com    作业时间：2017年5月3日    地点：上海
----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<string.h>

int main()
{
    int a,b,d,result,i,length;
    char digit[33];
    
    scanf("%d %d %d",&a,&b,&d);
   
    digit[0]='\0';
    result=a+b;
    i=0;
    while(result!=0)
    {
        digit[i]=result%d+'0';
        result=result/d;
        i++;
    }
    digit[i]='\0';

    length=strlen(digit);

    if(length==0)
        printf("0");
    else
    {
        for(i=length-1;i>=0;i--)
            printf("%c",digit[i]);
    }

    return 0;
}
    
