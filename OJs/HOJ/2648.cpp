/*This Code is Submitted by Timer for Problem 2648 at 2012-08-11 11:26:57*/
#include <cstdio>
#include <algorithm>

#define eps 1e-8

using namespace std;

struct cyr
{
  int x;
  int y;
};

cyr a[5010];
int n,s,top;
cyr stack[5010];

bool equ(double x)
{
  if (x<-eps) return false;
  if (x>eps) return false;
  return true;
}

bool operator < (cyr q,cyr w)
{
  if (q.y<w.y) return true;
  if (q.y==w.y)
    if (q.x<w.x) return true;
  return false;
}

inline int chaji(cyr q,cyr w,cyr e)
{
  int x1,x2,y1,y2;
  x1=w.x-q.x;
  y1=w.y-q.y;
  x2=e.x-q.x;
  y2=e.y-q.y;
  return (x1*y2-x2*y1);
}

void graham()
{
  int i;
  int limit;
  sort(a+1,a+n+1);
  stack[1]=a[1];
  stack[2]=a[2];
  top=2;
  for (i=3;i<=n;i++)
  {
    while ((top>1) && (chaji(stack[top-1],a[i],stack[top])>=0))
      top--;
    top++;
    stack[top]=a[i];
  }
  limit=top;
  top++;
  stack[top]=a[n-1];
  for (i=n-2;i>=1;i--)
  {
    while ((top>limit) && (chaji(stack[top-1],a[i],stack[top])>=0))
      top--;
    top++;
    stack[top]=a[i];
  }
}

inline double inside(cyr q,cyr w,int r)
{
  double t1,t2;
  t1=(r-q.x)*(w.y-q.y);
  t2=w.x-q.x;
  t1=t1/t2;
  t2=q.y;
  t1=t1+t2;
  return t1;
}

int main()
{
  int i,flag;
  int t;
  double temp,max,min;
  while (scanf("%d%d",&n,&s)==2)
  {
    for (i=1;i<=n;i++)
      scanf("%d",&a[i].x);
    for (i=1;i<=n;i++)
      scanf("%d",&a[i].y);
    graham();
    flag=0;
    max=0.0;
    min=99999999.0;
    for (i=1;i<top;i++)
    {
      t=i+1;
      if (((s>=stack[i].x) && (s<=stack[t].x)) || ((s<=stack[i].x) && (s>=stack[t].x)))
      {
        flag++;
        if (equ(stack[i].x-stack[t].x))
        {
          if (stack[i].y>max) max=stack[i].y;
          if (stack[t].y>max) max=stack[t].y;
          if (stack[i].y<min) min=stack[i].y;
          if (stack[t].y<min) min=stack[t].y;
        }
        else
        {
          temp=inside(stack[i],stack[t],s);
          if (temp>max) max=temp;
          if (temp<min) min=temp;
        }
      }
      if (flag>=10) break;
    }
    if (equ(min-99999999.0)) min=0.000;
    printf("%.3lf %.3lf\n",min,max);
  }
  return 0;
}