/*
----------------------------------------------------------------------------------------------------
                             1008.数组元素循环右移问题(20)                     
    一个数组A中存有N(N>0)个整数，在不允许使用另外数组的前提下，将每个整组循环向右移M(M>=0)个位置，即
将A中的数组由(A0 A1....An-1)变换为(An-m...An-1 A0....An-m+1)。如果需要考虑程序移动数据的次数尽量少，
要如何设计移动的方法？              
    输入格式：每个输入包含一个测试用例，第1行输入N(1<=N<=100),M(M>=0);第2行输入N个整数，之间用空格分
隔。      
    输出格式：在一行中输出循环右移M位后的整数序列，之间用空格分隔，序列结尾不能有多余格。 
    输入样例：                                     
    6 2                                                    
    1 2 3 4 5 6                                    
    输出样例：                                     
    5 6 1 2 3 4                               
----------------------------------------------------------------------------------------------------
    作业者：愣头小兵    E-mail:ltxb@qq.com     日期：2017年4月17日       地点：上海        
----------------------------------------------------------------------------------------------------
*/

#include <stdio.h>

void ArrayLoopRight(int* a,int n,int m);    //将数组a[n]循环右移m位

int main()
{
    int m,n,i;
    scanf("%d %d",&n,&m);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    ArrayLoopRight(a,n,m);
    
    printf("%d",a[0]);
    for(i=1;i<n;i++)
        printf(" %d",a[i]);
    
    return 0;
}

/*--以下实现代码简单易理解，但算法的时复杂度为M*n--*/
/*
void ArrayLoopRight(int *a,int n,int m) //每轮移1位，共移M轮
{
    int i,j,tem;
    for(i=0;i<m;i++)
    {
        tem=a[n-1];
        for(j=n-1;j>0;j--)
            a[j]=a[j-1];
        a[0]=tem;
    }
}
*/

/*---以下实现方式不易理解，但算法时间复杂度是n---*/

int GreatComDivisor(int m,int n)
{
    int tem;
    while(m%n!=0)
    {
        tem=m%n;
        m=n;
        n=tem;
    }
    return n;
}

void ArrayLoopRight(int *a,int n,int m)
{
    int i,j,k,tem;
    k=GreatComDivisor(m,n);
    for(i=1;i<=k;i++)
    {
        tem=a[n-i];
        for(j=0;j<(n/k)-1;j++)
            a[(m*n-i-j*m)%n]=a[(m*n-i-(j+1)*m)%n];
        a[m-i]=tem;   //a[m-i]由a[(m*n-i-(n/k-2+1)*m)%n]简化而来
    }
}

            
