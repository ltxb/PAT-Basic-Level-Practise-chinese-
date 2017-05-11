/*
----------------------------------------------------------------------------------------------------
                                 1025.反转链表（25）
    给定一个常数K以及一个单链表L，请编写程序将L中每K个结点反转。例如：给定L为1->2->3->4->5->6,K为3,
则输出应该为3->2->1->6->5->4;如果K为4,则输出应该为4->3->2->1->5->6,即最后不到K个元素不反转。
    输入格式：每个输入包含1个测试用例。每个测试用例第1行给出第1个结点的地址、结点总个数正整数N（N<
100000）、以及正整数K（K<N），即要求反转的子链结点的个数。结点的地址是5位非负整数，NULL地址用-1表示。
    接下来有N行，每行格式为：
    Address Data Next
    其中Address是结点地址，Data是该结点保存的整数数据，Next是下一结点的地址。
    输出格式：对每个测试用例，顺序输出反转后的链表，其上每个结点占一行，格式与输入相同。
    输入样例：
    00100 6 4
    00000 4 99999
    00100 1 12309
    68237 6 -1
    33218 3 00000
    99999 5 68237
    12309 2 33218
    输出样例：
    00000 4 33218
    33218 3 12309
    12309 2 00100
    00100 1 99999
    99999 5 68237
    68237 6 -1
----------------------------------------------------------------------------------------------------
    作业者：愣头小兵    E-mail:ltxb@qq.com     日期：2017年5月10日     地点：上海
----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>

typedef struct node
{
    int address;
    int data;
    int next;
}Node;

void CopyNode(Node *a,Node *b);

int main()
{
    int p,q,n,k,i,j,dat,nex;
    scanf("%d %d %d",&p,&n,&k);
    Node a[100000];
    Node b[n];
    q=p;
    for(i=0;i<n;i++)
    {
        scanf("%d %d %d",&j,&dat,&nex);
        a[j].address=j;
        a[j].data=dat;
        a[j].next=nex;
    }
   
    for(i=0;i<n&&p!=-1;i++)
    {
        CopyNode(&b[i],&a[p]);
        p=a[p].next;
    }
    
    n=i;

    for(i=0;(i+1)*k-1<n;i++)
        for(j=0;j<k;j++)
          CopyNode(&a[i*k+j],&b[(i+1)*k-j-1]);

    for(j=i*k;j<n;j++)
        CopyNode(&a[j],&b[j]);

    for(i=0;i<n-1;i++)
        a[i].next=a[i+1].address;
    a[n-1].next=-1;

    if(q==-1)
        printf("-1\n");
    else
    {
        if(n!=1)
        {
            for(i=0;i<n-1;i++)
                printf("%05d %d %05d\n",a[i].address,a[i].data,a[i].next);
        }
        printf("%05d %d %d",a[n-1].address,a[n-1].data,a[n-1].next);
    }
    
    return 0;
}

void CopyNode(Node *a,Node *b)
{
    a->address=b->address;
    a->data=b->data;
    a->next=b->next;
}

