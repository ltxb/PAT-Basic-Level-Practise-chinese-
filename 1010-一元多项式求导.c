/*
----------------------------------------------------------------------------------------------------
                                1001.一元多项式求导(25)                        
    设计函数一元多项式的导数。(注：X的n次方(n为整数)的一阶导数为n*x的n-1次方)      
    输入格式：以指数递降方式输入多项式非零项系数和指数(绝对值均为不超过1000的整数)。数字间以空格分隔。
    输出格式：以与输入相同的格式输出导数多项式非零项的系数和指数。数字间以空格分隔，但结尾不能有多余
空格。注意"零多项式"的指数和系数都是0,但是表示为"0 0"。              
    输入样例：                                   
    3 4 -5 2 6 1 -2 0                        
    输出样例：                      
    12 3 -10 1 6 0                          
----------------------------------------------------------------------------------------------------
    作业者：愣头小兵  E-mail:ltxb@qq.com    日期：2007年4月19日       地点：上海    
----------------------------------------------------------------------------------------------------
*/

#include <stdio.h>
#include <string.h>

int main()
{
    int n,e;

    scanf("%d %d",&n,&e);
    if(n*e==0)
        printf("0 0");
    else
        printf("%d %d",n*e,e-1);
    
    while(scanf("%d %d",&n,&e)==2)
    {
        if(n*e!=0)
            printf(" %d %d",n*e,e-1);
    }
    
    return 0;
}
