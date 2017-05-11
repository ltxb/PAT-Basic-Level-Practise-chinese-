/*
----------------------------------------------------------------------------------------------------
                              1024.科学计数法（20）
    科学计数法是科学家用来表示很大或很小的数字的一种方便的方法，其满足正则表达式[+-][1-9]"."[0-9]+E
[+-][0-9]+,即数字的整数部分只有1位，小数部分至少有1位，该数字及其指数部分的正负号即使对正数也必定明确
给出。
    现以科学计数法的格式给出实数A，请编写程序按普通数字表示法输出A，并保证所有有效位都被保留。
    输入格式：每个输入包含个测试用例，即一个以科学计数表示的实数A。该数字的存储长度不超过9999字节，且
其指数的绝对值不超过9999。
    输出格式：对每个测试用例，在一行中按普通数字表示法输出A，并保证所有有效位都被保留，包括末尾的0。
    输入样例1：
    +1.23400E-03
    输出样例1：
    0.00123400
    输入样例2：
    -1.2E+10
    输出样例2：
    -12000000000
----------------------------------------------------------------------------------------------------
    作业者：愣头小兵    E-mail:ltxb@qq.com    日期：2017年5月3日     地点：上海
----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<string.h>
void ScientificToNormal(char *a);

int main()
{
    char scientific[20000];
    scanf("%s",scientific);
    
    ScientificToNormal(scientific);

    printf("%s",scientific);
    return 0;
}

void ScientificToNormal(char *a)
{
    int i,j,exponent=0;
    char *pointToE;
    char symbol;
   
    pointToE=strchr(a,'E');
    symbol=*(pointToE+1);
    *pointToE='\0';
    
    i=2;
    while(*(pointToE+i)!='\0')
    {
        exponent=exponent*10+*(pointToE+i)-'0';
        i++;
    }
    
    j=strlen(a);
    if(symbol=='-')
    {
        for(i=j-1;i>=3;i--)
            a[i+exponent]=a[i];
        a[j+exponent]='\0';
        a[exponent+2]=a[1];
        for(i=1+exponent;i>=3;i--)
            a[i]='0';
        a[1]='0';
    }
    else
    {
        for(i=2;i<2+exponent&&i<j-1;i++)
            a[i]=a[i+1];
        if(j-1>2+exponent)
            a[2+exponent]='.';
        else
        {
            for(i=j-1;i<2+exponent;i++)
                a[i]='0';
            a[exponent+2]='\0';
        }
    }

    j=strlen(a);
    if(a[0]=='+')
    {
        for(i=0;i<j;i++)
            a[i]=a[i+1];
    }

}


   
