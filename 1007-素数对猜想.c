/*-----------------------------------------------------------------------------------------------*/
/*                             1007.素数对猜想（20）                                             */
/* 让我们定义dn为dn=Pn+1-Pn,其中Pi是第i个素数。显然有d1=1且对于n>1有dn是偶数。“素数对猜想”认为存 */
/* 在无穷多对想邻且差为2的素数“。                                                                */
/* 现给定任意正整数N(<100000），请计算不超过N的满足猜想的素数对的个数。                          */
/* 输入格式：每个测试输入包含1个测试用例，给出正整数N。                                          */
/* 输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。                         */
/* 输入样例：                                                                                    */
/* 20                                                                                            */
/* 输出样例：                                                                                    */
/* 4                                                                                             */
/*-----------------------------------------------------------------------------------------------*/
/*作业者：愣头小兵    E-mail:ltxb@qq.com    日期：2007年4月16日    地点：上海                    */
/*-----------------------------------------------------------------------------------------------*/

#include<stdio.h>

int IsPrime(int);               //To determine whether a number is prime
int CalcuPrimePair(int);        //Calculate the number of prime pairs

int main()
{
    int n,count;
    scanf("%d",&n);
    count=CalcuPrimePair(n);
    printf("%d",count);
    return 0;
}
    
int IsPrime(int n)
{
    int isPri=1;
    int i;
    int k=n/2;
    for(i=2;i<=k;i++)
    {
        if(n%i==0)
        {
            isPri=0;
            break;
        }
    }
    return isPri;
}

int CalcuPrimePair(int n)
{
    int i;
    int prePrime=2,prime=3,primePairs=0;
    for(i=5;i<=n;i=i+2)
    {
	if(IsPrime(i)==1)
        {
            prePrime=prime;
            prime=i;
            if((prime-prePrime)==2)
                primePairs++;
        }
    }
    return primePairs;
}
        
