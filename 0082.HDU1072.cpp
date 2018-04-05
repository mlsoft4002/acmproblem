#include <stdio.h>  
#include <string.h>  
#include <queue>  
using namespace std;  
int T,n,m,a[10][10],i,j,t,sx,sy,ex,ey;  
int d[4][2]={{1,0},{0,1},{-1,0},{0,-1}};  
struct node  
{  
    int x,y,t,v;  
};  
queue<node> q;  
  
bool pd(int x,int y)  
{  
    if(x<0 ||x>n ||y<0 ||y>m ||a[x][y]==0)  
        return false;  
    return true;  
}  
int bfs()  
{  
    node now,next;  
    while(!q.empty())  
    {  
        now=q.front();  
        q.pop();  
      
        if(now.t==1) continue;  
        for(i=0;i<4;i++)  
        {  
            next.x=now.x+d[i][0];  
            next.y=now.y+d[i][1];  
            next.t=now.t-1;  
            next.v=now.v;  
            if(next.x==ex&&next.y==ey) return now.v;  
            if(pd(next.x,next.y))  
            {     
             // printf("%d %d\n",now.x,now.y);  
                next.v++;  
                if(a[next.x][next.y]==4)  
                {  
                    a[next.x][next.y]=0;  
                    next.t=6;  
                }  
                q.push(next);  
            }  
        }  
    }  
    return -1;  
}  
int main()  
{  
    scanf("%d",&T);  
    while(T--)  
    {  
        while(!q.empty())  
            q.pop();  
        t=0;  
        scanf("%d %d",&n,&m);  
        for(i=0;i<n;i++)  
            for(j=0;j<m;j++)  
            {  
                scanf("%d",&a[i][j]);  
                if(a[i][j]==2)  
                {  
                    sx=i;sy=j;  
                }  
                if(a[i][j]==3)  
                {  
                    ex=i;ey=j;  
                }  
            }  
        node now;  
        now.x=sx;now.y=sy;now.t=6;now.v=1;  
        //printf("%d %d",)  
        q.push(now);  
        printf("%d\n",bfs());  
    }  
    return 0;  
} 
