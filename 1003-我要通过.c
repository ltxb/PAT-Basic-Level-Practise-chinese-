/*
----------------------------------------------------------------------------------------------------
                                 1003.我要通过！（20）                         
     "答案正确"是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送--只要读入的字符串
满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。                      
    得到“答案正确”的条件是：                                                             
    1.字符串中必须仅有P、A、T这三种字符，不可以包含其它字符;                        
    2.任意形如xPATx的字符串都可以获得“答案正确”，其中x或者是空字符串，或者是仅由字母A组成的字符串;
    3.如果aPbTc是正确的，那么aPbATca也是正确的，其中a,b,c或是空字符串，或仅由字母A组成的字符串。
    现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”。                 
    输入格式：每个测试输入包含1个测试用例。第1行给出一个自然数n(<10)，是需要检测的字符串个数。接下来 
来每个字符串占一行，字符串长度不超过100,且不包含空格。                               
    输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。  
    输入样例：                                                                                     
    8                                                                                              
    PAT                                                                                            
    PAAT                                                                                           
    AAPATAA                                                                                        
    AAPAATAAAA                                                                                     
    xPATx                                                                                          
    PT                                                                                             
    Whatever                                                                                       
    APAAATAA                                                                                       
                                                                                                
    输出样例：                                                                                   
    YES                                                                                         
    YES                                                                                         
    YES                                                                                        
    YES                                                                                       
    NO                                                                                        
    NO                                                                                        
    NO                                                                                        
    NO                                                                                        
----------------------------------------------------------------------------------------------------
    作业者：愣头小兵   E-MAIL：ltxb@qq.com    日期：2017年4月10日   地点：上海                   
----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>

int IsRightAnswer(char*);                 //判断一个字符串是否符合"答案正确"条件

int main()
{
    int n,i;
    scanf("%d",&n);
    char str[n][101];
    for(i=0;i<n;i++)
        scanf("%s",*(str+i));
    for(i=0;i<n;i++)
    {
        if(IsRightAnswer(*(str+i))==0)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
    
int IsRightAnswer(char* str)
{
    int i=0,j=0;
    int countP=0,countA=0,countT=0;
    int count_a[3]={0,0,0};
            
    while(str[i]!='\0')
    {
        if(str[i]!='P'&&str[i]!='A'&&str[i]!='T')   //对是否符合条件1进行判断
            return 0;
        if(str[i]=='P')
        {   
            countP++;
            j=1;
            if(str[i+1]=='T')                      //符合条件2，p后至少有一个A，不能直接跟T
                return 0;
        }
        if(str[i]=='T')
        {
            countT++;
            j=2;
        }
        if(str[i]=='A')
        {
            countA++;
            count_a[j]++;
        }
        if(countT>countP)                          //符合条件2,T应在P后出现
            return 0;
        i++;
    }
    if(countP!=1||countA==0||countT!=1)            //符合条件2,"P,T"只应出现1次，A应大于等于1次
        return 0;
    if((count_a[0]*count_a[1])!=count_a[2])        //判断是否符合条件3
        return 0;
    return 1;
}
