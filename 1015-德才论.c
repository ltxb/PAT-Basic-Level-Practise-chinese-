/*
----------------------------------------------------------------------------------------------------
                              1015.德才论（25）
    宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德
胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”
    现给出一批考生的德才分数，请根据司马光的理论给出录取排名。
    输入格式：输入第1行给出3个正整数，分别为：N(<=100000),即考生总数；L(>=60),为录取最低分数，即德分
和才分均不低于L的考生才有资格被考虑录取；H(<100),为优先录取线--德分和才分均不低于此线的被定义为“才德
全尽”，此类考生按德才总分从高到低排序：才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在
第一类考生之后；德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但
排在第二类考生之后；其它达到最低线的L的考生也按总分排序，但排在第三类考生之后。
    随后N行，每行给出一位考生和信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间
[0,100]内整。数字间以空格分隔。
    输入格式：输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，
考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则
按准考证号的升序输出。
    输入样例：
    14 60 80
    10000001 64 90
    10000002 90 60
    10000011 85 80
    10000003 85 80
    10000004 80 85
    10000005 82 77
    10000006 83 76
    10000007 90 78
    10000008 75 79
    10000009 59 90
    10000010 88 45
    10000012 80 100
    10000013 90 99
    10000014 66 60
    输出样例：
    12
    10000013 90 99
    10000012 80 100
    10000003 85 80
    10000011 85 80
    10000004 80 85
    10000007 90 78
    10000006 83 76
    10000005 82 77
    10000002 90 60
    10000014 66 60
    10000008 75 79
    10000001 64 90
----------------------------------------------------------------------------------------------------
    作业者：愣头小兵    E-mail:ltxb@qq.com    日期：2017年4月25日    地点：上海
----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>

typedef struct student          //用于存储学生准考证号、德分和才分的结构体
{
    int id;
    int morality;
    int talent;
}Student;


void HeapSortStu(Student a[],int n,int l,int h);  //没办法，使用简单而经典的冒泡排序会超时，所以用堆排序算法

int main()
{
    int n,l,h,i,j,k;
    scanf("%d %d %d",&n,&l,&h);
    
    Student stu[n];
    
    for(i=0;i<n;i++)
        scanf("%d %d %d",&stu[i].id,&stu[i].morality,&stu[i].talent);

    HeapSortStu(stu,n,l,h);           //用堆排序算法，按题目给出的规则将学生从大到小排序；    

    j=n;
    for(i=0;i<n;i++)        //沿排序后的学生结构体数组，找到第一个不能录取的学生位置，那前面都是应该录取的
    {
        if(stu[i].morality<l||stu[i].talent<l)
        {
            j=i;
            break;
        }
    }
   
    printf("%d\n",j);    //将前面能录取的人员按输出格式输出
    for(i=0;i<j;i++)
        printf("%d %d %d\n",stu[i].id,stu[i].morality,stu[i].talent);

    return 0;
}

/*------下面是实现两个学生的比较,核心函数是:int CompareStu(Student *,student *,int,int)------*/
 
int StuLevel(Student *a,int l,int h)   //按规则返回a学生在什么层次，德才兼备返回1,德胜才返回2....
{
    if(a->morality>=h&&a->talent>=h)
        return 1;
    else if(a->morality<l||a->talent<l)
        return 5;
    else if(a->morality>=h&&a->talent<h)
        return 2;
    else if(a->morality<h&&a->talent<h&&a->morality>=a->talent)
        return 3;
    else
        return 4;
}

int CompareStu(Student *a,Student *b,int l,int h) //学生a应排在学生b的前面也就是a大，就返回1,否则返回0
{
    if(StuLevel(a,l,h)>StuLevel(b,l,h))
        return 0;
    else if(StuLevel(a,l,h)<StuLevel(b,l,h))
        return 1;
    else
    {
        if((a->morality+a->talent)>(b->morality+b->talent))
            return 1;
        else if((a->morality+a->talent)<(b->morality+b->talent))
            return 0;
        else
        {
           if(a->morality>b->morality)
               return 1;
           else if(a->morality<b->morality)
               return 0;
           else
           {
               if(a->id<b->id)
                   return 1;
               else
                   return 0;
           }
        }
    }
}

/*---下面是实现学生数组的排序，算法是堆排序，核心函数是:void HeapSortStu(Student a[],int)-----*/
void SwapStu(Student *a,Student *b)    //实现两个学生结构体之间的数值交换
{
    int i,m,t;
    i=a->id;
    m=a->morality;
    t=a->talent;
    a->id=b->id;
    a->morality=b->morality;
    a->talent=b->talent;
    b->id=i;
    b->morality=m;
    b->talent=t;
} 

void MinHeapify(Student a[],int i,int n,int l,int h)  //维护堆，确保i结点以下的是最小堆。
{
    int left=i*2+1;
    int right=i*2+2;
    int min;
    if(left<n&&CompareStu(&a[i],&a[left],l,h)==1)
        min=left;
    else
        min=i;
    if(right<n&&CompareStu(&a[min],&a[right],l,h)==1)
        min=right;
    if(min!=i)
    {
        SwapStu(&a[min],&a[i]);
        MinHeapify(a,min,n,l,h);
    }
}

void BuildMinHeap(Student a[],int n,int l,int h)    //将一个随机数组建成最小堆
{
    int i;
    for(i=n/2-1;i>=0;i--)
        MinHeapify(a,i,n,l,h);
}

void HeapSortStu(Student a[],int n,int l,int h)    //堆排序算法
{
    int i;
    BuildMinHeap(a,n,l,h);
    for(i=n-1;i>=1;i--)
    {
        SwapStu(&a[0],&a[i]);
        MinHeapify(a,0,i,l,h);
    }
}    
