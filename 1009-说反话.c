/*
----------------------------------------------------------------------------------------------------
                                     1009.说反话(20)            
    给定一句英语，要求你编写程序，将句中反有单词的顺序颠倒输出。             
    输入格式：测试输入包含一个测试用例，在一行内给出总长度不超过80的字符串。字符串由若干单词和若干空
格组成，其中单词是由英文字母(大不写有区分)组成的字符串，单词之间用1个空格分开，输入保证句子末尾没有多
余的空格。                           
    输出格式：每个测试用例的输出占一行，输出倒序后的句子。               
    输入样例：                                                     
    Hello World Here I come                       
    输出样例：                      
    Come I here World Hello            
----------------------------------------------------------------------------------------------------
    作业者：愣头小兵     E-mail:ltxb@qq.com    日期：2017年4月18日     地点：上海     
----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>

int main()
{
    int i=0,tem=0;
    char str[81];
    int space[41];      //用space[]数组来记录空格和回车等间隔符的位置
    
    fgets(str,81,stdin);
    
    space[0]=-1;
    while(str[i]!='\0')
    {
        if(str[i]==' '||str[i]=='\n')
        {
            tem++;
            space[tem]=i;
        }
        i++;
    }

    for(i=space[tem-1]+1;i<space[tem];i++)  //输出最后一个单词 
        printf("%c",str[i]);
    tem--;

    while(tem>0)                            //若还有单词，继续输出
    {
        printf(" ");
        for(i=space[tem-1]+1;i<space[tem];i++)
            printf("%c",str[i]);
        tem--;
    }
    
    return 0;
}
    
