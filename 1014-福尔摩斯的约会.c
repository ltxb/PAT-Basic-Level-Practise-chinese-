/*
----------------------------------------------------------------------------------------------------
                              1014.福尔摩斯的约会(20)
    大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！348djDkh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscv
nm”。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对
相同的大写英文字母(大小写有区分)是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，
代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同
的英文字母'S'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到
约会的时间。
    输入格式：输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。
    输出格式：在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期
一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输
入保证每个测试存在唯一解。
    输入样例：
    3485djDkxh4hhGE
    2984akDfkkkkggEdsb
    s&hgsfdk
    d&Hyscvnm
    输出样例：
    THU 14:04
----------------------------------------------------------------------------------------------------
    作业者：愣头小兵   E-mail:ltxb@qq.com    日期：2017年4月24日     地点：上海
----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<string.h>

int main()
{
    char str1[61],str2[61],str3[61],str4[61];
    char week[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    int i,tem,strSize1,strSize2;

    scanf("%s%s%s%s",str1,str2,str3,str4);
    
    strSize1=strlen(str1);
    strSize2=strlen(str2);

    for(i=0;i<strSize1&&i<strSize2;i++)
    {
        if(str1[i]==str2[i]&&str1[i]>='A'&&str1[i]<='G')
        {
            tem=str1[i]-'A';
            printf("%s ",week[tem]);
            tem=i+1;
            break;
        }
    }
    
    for(i=tem;i<strSize1&&i<strSize2;i++)
    {
        if(str1[i]==str2[i]&&str1[i]>='0'&&str1[i]<='9')
        {
            tem=str1[i]-'0';
            printf("%02d:",tem);
            break;
        }
        if(str1[i]==str2[i]&&str1[i]>='A'&&str1[i]<='N')
        {
            tem=str1[i]-'A'+10;
            printf("%02d:",tem);
            break;
        }
    }
    
    strSize1=strlen(str3);
    strSize2=strlen(str4);
    for(i=0;i<strSize1&&i<strSize2;i++)
    {
        if(str3[i]==str4[i]&&((str3[i]>='A'&&str3[i]<='Z')||(str3[i]>='a'&&str3[i]<='z')))
        {
            tem=i;
            printf("%02d",tem);
            break;
        }
    }
    
    return 0;
}
    
    
    
