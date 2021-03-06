/*
----------------------------------------------------------------------------------------------------
                             1004.成绩排名（20）                                            
    读入N名学生的姓名、学号、成绩，分别输出成绩最高和成绩最低学生的姓名和学号。                
    输入格式：每个测试输入包含1个测试用例，格式为：                                            
      第1行：正整数n                                                                         
      第2行：第1个学生的姓名  学号  成绩                                                     
      第3行：第2个学生的姓名  学号  成绩                                                     
      ... ... ...                                                                            
      第n+1行：第n个学生的姓名 学号 成绩                                                     
    其中姓名和学号均为不超过10个字符的字符串，成绩为0到100之间的一个整数，这里保证在一组测试用例中没
有两个学生的成绩是相同的。                                                                  
    输出格式：对每个测试用例输出2行，第1行是成绩最高学生的姓名和学号，每2行是成绩最低学生的姓名和学号，
字符串间有1个空格。                                                                     
    输入样例：                                                                                  
    3                                                                                          
    Joe Math990112 89                                                                          
    Mike CS991301 100                                                                          
    Mary EE990830 95                                                                           
                                                                                                
    输出样例：                                                                                 
    Mike CS991301                                                                              
    Joe Math990112                                                                            
----------------------------------------------------------------------------------------------------
    作业者：愣头小兵   E-mail:ltxb@qq.com    作业时间：2017年4月11日    地点：上海               
----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>
#include<string.h>

typedef struct student
{
    char name[11];
    char id[11];
    int score;
}Student;

int main()
{
    int n,i;
    int min=0,max=0;
    scanf("%d",&n);
    Student stu[n];

    for(i=0;i<n;i++)
    {
        scanf("%s %s %d",stu[i].name,stu[i].id,&(stu[i].score));
        if(stu[i].score>stu[max].score)
            max=i;
        if(stu[i].score<stu[min].score)
            min=i;
    }

    printf("%s %s\n",stu[max].name,stu[max].id);
    printf("%s %s\n",stu[min].name,stu[min].id);
    return 0;
}
    
