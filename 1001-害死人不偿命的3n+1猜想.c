/*
---------------------------------------------------------------------------------------------------
                           1001.害死人不偿命的（3N+1）猜想（15）                                    
    卡拉兹（Callatz)猜想：                                                                        
    对于任何一个自然数N，如果它是偶数，那么把它砍掉一半；如果它是奇数，那么把(3N+1)砍掉一半。这样一 
直反复砍下去，最后一定在某一步得到N=1.卡拉兹在1950年的世界数学家大会上公布了这个猜想，传说当时耶鲁大
大学师生齐动员，拼命想证明这个貌似很傻很天真的命题，结果闹得学生们无心学业，一心只证(3n+1),以至于有
有人说这是一个阴谋，卡拉兹是在蓄意延缓美国数学界教学与科研的进展...            
    我们今天的题目不是证明卡拉兹猜想，而是对给定的任一不超过1000的正整数N，简单地数一下，需要多少步
才能得到N=1？                                                                                 
    输入格式：每个测试输入包含1个测试用例，即给出自然数N的值。                                    
    输出格式：输出从N计算到1需要的步数。                                                          
    输入样例：                                                                                   
    3              
    输出样例：
    5                                                                                           
---------------------------------------------------------------------------------------------------
     作业者：愣头小兵    E-mail:ltxb@qq.com    作业日期：2007年4月12日      地点：上海            
---------------------------------------------------------------------------------------------------
*/

#include <stdio.h>

int CalcuSteps(int);          //Calculate how many steps can get "n=1".

int main()
{
    int steps,n;
    scanf("%d",&n);
    steps=CalcuSteps(n);
    printf("%d",steps);
    return 0;
}

int CalcuSteps(int n)
{
    int count=0;
    while(n!=1)
    {
        if(n%2==0)
            n=n/2;
        else
            n=(3*n+1)/2;
        count++;
    }
    return count;
}

