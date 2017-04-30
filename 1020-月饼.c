/*
----------------------------------------------------------------------------------------------------
                                   1020.月饼（25）
    月饼是中国人在中秋佳节时吃的一种传统食品，不同地区有许多不同风味的月饼。现给定所有种类月饼的库存
量、总售价、以及市场的最大需求量，请你计算可以获得的最大收益是多少。
    注意：销售时允许取出一部分库存。样例给出的情形是这样的：假如我们有3种月饼，其库存量分别为18、15、
10万吨，总售价分别为75、72、45亿元。如果市场的最大需求量只有20万吨，那么我们最大收益策略应该是卖出全部
15万吨第2种月饼，以及5万吨第3种月饼，获得72+45/2=94.5亿元。
    输入格式：每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N表示月饼的种类数、以及
不超过500（以万吨为单位）的正整数D表示市场最大需求量。随后一行给出N个正数表示每种月饼的库存量（以万吨
为单位）；最后一行给出N个正数表示每种月饼的总售价（以亿元为单位）。数字间以空格分隔。
    输出格式：对每组测试用例，在一行中输出最大由收益，以亿元为单位并精确到小数点后2位。
    输入样例：
    3 20
    18 15 10
    75 72 45
    输出样例：
    94.50
----------------------------------------------------------------------------------------------------
    作业者：愣头小兵    E-mail:ltxb@qq.com    日期：2017年4月30日    地点：上海
----------------------------------------------------------------------------------------------------
*/

#include<stdio.h>


typedef struct moonCake
{
    double inventory;
    double totalPrice;
    double unitPrice;
}MoonCake;


void SwapMC(MoonCake *m,MoonCake *n);
void SortMC(MoonCake *m,int n);

int main()
{
    double maxGains=0;
    int kind,demand,i;
    scanf("%d %d",&kind,&demand);
    MoonCake mc[kind];

    for(i=0;i<kind;i++)
        scanf("%lf",&mc[i].inventory);

    for(i=0;i<kind;i++)
    {
        scanf("%lf",&mc[i].totalPrice);
        if(mc[i].inventory!=0)
            mc[i].unitPrice=mc[i].totalPrice/mc[i].inventory;
        else
            mc[i].unitPrice=0;
    }

    SortMC(mc,kind);
    
    for(i=0;i<kind&&demand>0;i++)
    {
        if(mc[i].inventory>=demand)
        {
            maxGains=maxGains+demand*mc[i].unitPrice;
            demand=0;
        }
        else
        {
            maxGains=maxGains+mc[i].totalPrice;
            demand=demand-mc[i].inventory;
        }
    }

    printf("%.2lf",maxGains);
    
    return 0;
}    
    
void SwapMC(MoonCake *m,MoonCake *n)
{
    double temp;
    temp=m->inventory;
    m->inventory=n->inventory;
    n->inventory=temp;
    temp=m->totalPrice;
    m->totalPrice=n->totalPrice;
    n->totalPrice=temp;
    temp=m->unitPrice;
    m->unitPrice=n->unitPrice;
    n->unitPrice=temp;
}

void SortMC(MoonCake *m,int n)
{
    int i,j,k;
    for(i=n-1;i>0;i++)
    {
        k=0;
        for(j=0;j<i;j++)
        {
            if(m[j].unitPrice<m[j+1].unitPrice)
            {
                SwapMC(&m[j],&m[j+1]);
                k++;
            }
        }
        
        if(k==0)
            break;
    }
}
