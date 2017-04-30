/*
----------------------------------------------------------------------------------------------------
                                        1017.A除以B(20)
    本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A=B×Q+R
成立。
    输入格式：输入在1行中依次给出A和B，中间以1空格分隔。
    输出格式：在1行中依次输出Q和R，中间以一空格分隔。
    输出样例：
    123456789050987654321 7
    输出样例：
    17636684150141093474 3
----------------------------------------------------------------------------------------------------
    作业者：愣头小兵    e-mail:ltxb@qq.com    日期：2017年4月28日      地点：上海
----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<string.h>
int main()
{
    char a[1001],q[1001];
    int b,r=0,length,temp,i;
    
    scanf("%s %d",a,&b);

    length=strlen(a);
    for(i=0;i<length;i++)
    {
        r=r*10+a[i]-'0';
        q[i]=r/b+'0';
        r=r%b;
    }
    q[length]='\0';
    
    if(length==1)
        temp=0;
    else
    {
        if(q[0]=='0')
           temp=1;
        else
           temp=0;
    }
    
    for(i=temp;i<length;i++)
        printf("%c",q[i]);
    printf(" %d",r);

    return 0;
}
        
