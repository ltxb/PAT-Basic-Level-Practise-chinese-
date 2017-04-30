/*
----------------------------------------------------------------------------------------------------
                                1018.锤子剪刀布(20)
    大应该都会玩“锤子剪刀布”的游戏，两人同时给出手势，胜负规则如图所示：
    现给出两人的冷锋记录，请统计双方的胜、平、负次数，并且组出双方分别出什么手势的胜算最大。
    输入格式：输入第1行给出正整数N（<=100000），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即
甲、乙双方同时给出的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间
有1个空格。
    输出格式：输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以一个空格分隔。第3行纷出两个字母，分
代表甲、乙获胜次数最多的手势，中间有1个空格。如果不唯一，则输出按字母序最小的解。
    输入样例：
    10
    C J
    J B
    C B
    B B
    B C
    C C
    C B
    J B
    B C
    J J
    输出样例：
    5 3 2
    2 3 5
    B B
----------------------------------------------------------------------------------------------------
    作业者：愣头小兵    E-mail:ltxb@qq.com   日期：2017年4月28日    地点：上海
----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>

int FingerGuess(char a,char b);   //a,b取值'B','C','J',a赢就返回1,平返回0,a输返回-1
int Finger(char a);               
char WinFinger(int *a); //a数组中分别存了用'B','C','J'赢得次数，该函数返回最大的那个。

int main()
{
    int n,i,temp;
    scanf("%d",&n);
    int win=0,flat=0,lose=0;
    int fingerJ[3]={0};
    int fingerY[3]={0};
    
    
    char finger[n][2];
    

    for(i=0;i<n;i++)
    {
        getchar();
        scanf("%c %c",&finger[i][0],&finger[i][1]);
    }
    
    for(i=0;i<n;i++)
    {
        if(FingerGuess(finger[i][0],finger[i][1])==1)
        {
            win++;
            temp=Finger(finger[i][0]);
            fingerJ[temp]++;
        }
            
        else if(FingerGuess(finger[i][0],finger[i][1])==0)
            flat++;
        else
        {
            lose++;
            temp=Finger(finger[i][1]);
            fingerY[temp]++;
       }
    }
    
    printf("%d %d %d\n%d %d %d\n",win,flat,lose,lose,flat,win);
    printf("%c %c",WinFinger(fingerJ),WinFinger(fingerY));   
    return 0;
}

char WinFinger(int *a)
{
    if(a[0]>=a[1]&&a[0]>=a[2])
        return 'B';
    else if(a[0]<a[1]&&a[1]>=a[2])
        return 'C';
    else
        return 'J';
}

int Finger(char c)
{
    if(c=='B')
        return 0;
    else if(c=='C')
        return 1;
    else
        return 2;
}

int FingerGuess(char a,char b)
{
    if(a==b)
        return 0;
    else if((a=='C'&&b=='J')||(a=='J'&&b=='B')||(a=='B'&&b=='C'))
        return 1;
    else
        return -1;
}


