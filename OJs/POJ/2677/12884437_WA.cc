//Other's Code for Astar 2014
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
#define MAX 123456789
struct point
{
    double x,y;
};
point vert[101];
double res[101][101];
double dis(int i,int j)
{
    return sqrt((vert[i].x-vert[j].x)*(vert[i].x-vert[j].x)+(vert[i].y-vert[j].y)*(vert[i].y-vert[j].y));
}
double min(double a,double b)
{
    return a < b ? a : b;
}
double work(int n)
{
    int i,j;
    double s,Min=MAX;
    res[2][1]=dis(2,1);
    for(i=2;i<=n;i++)
    {
        for(j=1;j<i;j++)
        {
            res[i][j]=min(res[i][j],res[i-1][j]+dis(i-1,i));
            res[i][i-1]=min(res[i][i-1],res[i-1][j]+dis(j,i));
        }
    }
    for(i=1;i<n;i++)
    {
        s=dis(i,n);
        if(Min > res[n][i] + s) Min = res[n][i] + s;
        //printf("%.2lf\n",res[n][i] + s);
    }
    return Min;
}
int main()
{
    int i,j,n;
    while(scanf("%d",&n)!=EOF)
    {
        for(i=1;i<=n;i++)
            scanf("%lf %lf",&vert[i].x,&vert[i].y);
        for(i=1;i<=n;i++)
            for(j=1;j<=n;j++) res[i][j]=MAX;
   
        printf("%.2lf\n",work(n));
    }
    return 0;
}