/*This Code is Submitted by Timer for Problem 1714 at 2012-07-27 09:36:01*/
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

struct cyr
{
    int x;
    int y;
};

int m;
cyr a[56];
int d[56][56];

int mmax(int u1,int u2)
{
    if (u1>u2) return u1;
    return u2;
}

int cal(int q,int w,int e)
{
    int temp;
    int x1,x2,y1,y2;
    x1=a[w].x-a[q].x;
    y1=a[w].y-a[q].y;
    x2=a[e].x-a[q].x;
    y2=a[e].y-a[q].y;
    temp=x1*y2-x2*y1;
    if (temp<0) return (-temp);
    return temp;
}

bool inside(int i,int j,int k)
{
  int r,s,t,p;
  s=cal(i,j,k);
  for (p=1;p<=m;p++)
  {
    if ((p==i)||(p==j)||(p==k)) continue;
    t=cal(i,j,p)+cal(i,k,p)+cal(j,k,p);
    if (s==t) return false;
  }
  return true;
}

int main()
{
 int T,i,j,min,r,k;
 int s,temp;
 scanf("%d",&T);
 while (T--)
 {
   memset(a,0,sizeof(a));
   memset(d,0,sizeof(d));
   scanf("%d",&m);
   for (i=1;i<=m;i++)
   scanf("%d%d",&a[i].x,&a[i].y);
   for (i=1;i<=(m-2);i++)
     d[i][i+2]=cal(i,i+1,i+2);
   for (r=3;r<m;r++)
   {
     for (i=1;(i+r)<=m;i++)
     {
       j=i+r;
       min=99999999;
       for (k=i+2;k<=(j-2);k++)
       if (inside(i,k,j))
       {
         s=cal(i,k,j);
         temp=d[i][k];
         if (temp>s) s=temp;
         temp=d[k][j];
         if (temp>s) s=temp;
         if (s<min) min=s;
       }
     if (inside(i,j-1,j))
     {
       s=mmax(cal(i,j-1,j),d[i][j-1]);
       if (s<min) min=s;
     }
     if (inside(i,i+1,j))
     {
       s=mmax(cal(i,i+1,j),d[i+1][j]);
       if (s<min) min=s;
     }
     d[i][j]=min;
    }
   }
   printf("%d",d[1][m]>>1);
   if (d[1][m]&1) printf(".5");
     else printf(".0");
   printf("\n");
 }
  return 0;
}
 