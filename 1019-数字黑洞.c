/*
----------------------------------------------------------------------------------------------------
                                   1019.数字黑洞（20）
    给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用
第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174,这个神
奇的数字也叫KaPREKar常数。
    例如，我们从6767开始，将得到
    7766-6677=1089
    9810-0189=9621
    9621-1269=8352
    8532-2358=6174
    7641-1467=6174
    ....
    现给定任意4位正整数，请编写程序演示到达黑洞的过程。
    输入格式：输入给出一个(0,10000)区间内的正整数N。
    输出格式：如果N的4位数字全相等，则在一行内输出“N-N=0000”；否则将计算的每一步在一行内输出，直到6174
作为差出现，输出格式见样例。注意每个数字按4位数格式输出。
    输入样例1：
    6767
    输出样例1：
    7766-6677=1089
    9810-0189=9621
    9621-1269=8352
    8532-2358=6174
    输入样例2：
    2222
    输出样例2：
    2222-2222=0000
----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<string.h>

void SortNum(char *a,int n,int flag);     //将字符串中字符排序，flag=0则从小到大排，否则从大到小排
int StrToInt(char *a,int n);              //将n个字符的字符串转化为整数
void IntToStr(char *a,int n,int num);     //将整数转化为n位字符串，整数不足N位，前面用0补齐

int main()
{
    int first,second,num;
    char a[5],b[5];
    scanf("%d",&num);
    IntToStr(a,4,num);

    if(num==6174)
        printf("7641 - 1467 = 6174\n");
    else
    {
        while(StrToInt(a,4)!=6174)
        {
            strcpy(b,a);
            SortNum(a,4,1);
            SortNum(b,4,0);
            printf("%s - %s = ",a,b);

            first=StrToInt(a,4);
            second=StrToInt(b,4);
            if(first-second==0)
            {
                printf("0000\n");
                break;
            }
            else
            {
                IntToStr(a,4,first-second);
                printf("%s\n",a);
            }
         }
    }  
    return 0;
    
}
void SwapNum(char *a,char *b)
{
    int tem;
    tem=*a;
    *a=*b;
    *b=tem;
}

void SortNum(char *a,int n,int flag)
{
    int i,j;
    for(i=n-1;i>0;i--)
        for(j=0;j<i;j++)
        {
           if(flag==0)
           {
              if(a[j]>a[j+1])
                  SwapNum(&a[j],&a[j+1]);
           }
           else
           {
               if(a[j]<a[j+1])
                   SwapNum(&a[j],&a[j+1]);
           }
        }
}

int StrToInt(char *a,int n)
{
    int sum=0,tem=1,i;
    for(i=n-1;i>=0;i--)
    {
        sum=sum+tem*(a[i]-'0');
        tem=tem*10;
    }
    return sum;
}

void IntToStr(char *a,int n,int num)
{
    int i,temp;
    for(i=n-1;i>=0;i--)
    {
        a[i]=num%10+'0';
        num=num/10;
    }
}       
