/*-----------------------------------------------------------------------------------------------*/
/*                         1005.继续(3n+1)猜想(25)                                               */
/* 卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。                   */
/* 当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每个数。例如对N=3进行 */
/* 验证的时候，我们需要计算3,5,8,4,2,1，则当我们对n=5,8,4,2进行验证的时候，就可以直接判定卡拉兹猜*/
/* 想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，我们称5,8,4,2是被3“覆盖”的数*/
/* 。我们称一个数列中的某个数N为“关键数”，如果N不能被数列中的其他数字所覆盖。                    */
/* 现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必重复验证余下的数字。你的*/
/* 任务就是找出这些关键数字，并按从大到小顺序输出它们。                                          */
/* 输入格式：每个测试输入包含1个测试用例，第1行给出一个正整数K(<100)，第2行给出K个互不相同的待验 */
/* 证的正整数N(1<n<100)的值，数字间用空格隔开。                                                  */
/* 输出格式：每个测试用例的输出占一行，按从大到小的顺序输出关键字数字。数字间用我个空格隔开，但一*/
/* 行中最后一个数字后没有空格。                                                                  */
/* 输入样例：                                                                                    */
/* 6                                                                                             */
/* 3 5 6 7 8 11                                                                                  */
/* 输出样例：                                                                                    */
/* 7 6                                                                                           */
/*-----------------------------------------------------------------------------------------------*/
/* 作业者：愣头小兵    E-mail:ltxb@qq.com    时间：2007年4月14日    地点：上海                   */
/*-----------------------------------------------------------------------------------------------*/

#include <stdio.h>

void CoverNumber(int *a,int n);      //将不是关键数的数字全部清零
void SortNumber(int *a,int n);      //将整个数组按从大到小排序

int main()
{
    int n,i;
    scanf("%d",&n);
    int a[n];
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);

    CoverNumber(a,n);
    SortNumber(a,n);
    
    printf("%d",a[0]);
    i=1;
    while(a[i]!=0)
    {
        printf(" %d",a[i]);
        i++;
    }

    return 0;
}

void CoverNumber(int *a,int n)
{
    int i,j,tmp;
    for(i=0;i<n;i++)
    {
        if(a[i]==0)
           continue;
        
        tmp=a[i];
        while(tmp!=1)
        {
          if(tmp%2==0)
              tmp=tmp/2;
          else
              tmp=(3*tmp+1)/2;
          
          for(j=0;j<n;j++)
          {
              if(a[j]==tmp)
                a[j]=0;
          }
        }
    }
}

void SortNumber(int *a,int n)
{   
    int i,j,tmp; 
    for(i=n-1;i>0;i--)
    {
        for(j=0;j<i;j++)
        {
            if(a[j]<a[j+1])
            {
                tmp=a[j];
                a[j]=a[j+1];
                a[j+1]=tmp;
            }
        }
    }
}
