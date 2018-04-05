#include <iostream>
#include <stdio.h>
using namespace std;
int date[50001*3];
void init(int n){
    for(int i=0; i<=3*n; i++)date[i] = i;
}
int find_root(int index){
    if(date[index]==index)return index;
    return date[index] = find_root(date[index]);
}
void union_set(int a,int b){
    int r1 = find_root(a);
    int r2 = find_root(b);
    if(r1!=r2){
        date[r1] = r2;
    }
}
//�ж��Ƿ���һ������
bool isInOneSet(int a,int b){
    return find_root(a)==find_root(b);
}
int main()
{
    int n,k;
    scanf("%d%d",&n,&k);
    //��ʼ�����鼯
    init(n);
    int sc, x, y;
    int ans = 0;

    while(k--){
        scanf("%d%d%d",&sc,&x,&y);
        //x,y���ڷ�Χ��
        if(x<1 || x>n || y<1 || y>n){
            ans++;continue;
        }

        //�Լ����Լ�
        if(sc==2 && x==y){
             ans++;continue;
        }

        if(sc==1){//ͬ���ϵ
            //x��y֮���г��뱻�ԵĹ�ϵ
            if(isInOneSet(x,n+y) || isInOneSet(x,2*n+y)){
                ans++;
            }else{
                //������ȷ��¼
                union_set(x,y);
                union_set(n+x,n+y);
                union_set(2*n+x,2*n+y);
            }
        }else if(sc==2){
            //����(��x��y)�г�ͻ��ϵ(y��x)��
//����ͬ��ͳԵ�˳��,��x,y���������е�a,b
            if(isInOneSet(x,y) || isInOneSet(x,n+y)){
                ans++;
            }else{
                  //������ȷ��¼
                union_set(x,2*n+y);
                union_set(n+x,y);
                union_set(2*n+x,n+y);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
