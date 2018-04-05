#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

typedef struct point
{
    double xs;
    int zs;
} point;//���������

typedef struct list
{
    int len;
    point * date;
} LIST;//��
bool cmp(point a,point b)
{
    return a.zs<b.zs;
}//sortӦ�õıȽϺ���
void creat_list(LIST & list)
{
    int n;
    scanf("%d",&n);
    list.len = 0;
    list.date = (point *)malloc(n * sizeof(point));
    while (n--)
    {
        point dt;
        scanf("%lf %d",&dt.xs,&dt.zs);
        list.date[list.len++] = dt;
    }
}//�����ظ� ���д���������ٴ�����
void sum_list(LIST & list1, LIST & list2)
{
    bool b = true;
    LIST list3;
    list3.date = (point *)malloc((list1.len + list2.len) * sizeof(point));
    list3.len = 0;
    for (int i = 0; i < list1.len; i++)
    {
        for (int j = 0; j < list2.len; j++)
//��1���е�����2���б��� ���
        {
            if(list1.date[i].zs == list2.date[j].zs)
            {
                point dt;
                dt.zs = list2.date[j].zs;
                dt.xs = list2.date[j].xs + list1.date[i].xs;
                list3.date[list3.len] = dt;
                list3.len++;
                list1.date[i].xs = 0;
                list2.date[j].xs = 0;
                b = false;
                break;
            }
        }
        if (b)//�Ҳ��� ֱ�ӷŽ���3
        {
            point dta;
            dta.xs = list1.date[i].xs;
            dta.zs = list1.date[i].zs;
            list3.date[list3.len] = dta;
            list3.len++;
        }
        else
            b = true;
    }
    for (int k = 0; k < list2.len; k++)//�ѱ�2û�õļӽ�ȥ��3
    {
        point dat;
        dat.xs = list2.date[k].xs;
        dat.zs = list2.date[k].zs;
        list3.date[list3.len] = dat;
        list3.len++;
    }
    sort(list3.date,list3.date+list3.len,cmp);//����
    for (int x = 0; x < list3.len; x++)
    {
        if (list3.date[x].xs != 0)
        {
            printf("%.2lf %d\n", list3.date[x].xs, list3.date[x].zs);
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        LIST lst1, lst2;
        creat_list(lst1);
        creat_list(lst2);
        sum_list(lst1, lst2);
        if(n)
            printf("\n");//��ĿҪ�ĸ�ʽ
    }
    return 0;
}
