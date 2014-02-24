/*This Code is Submitted by Timer for Problem 1931 at 2012-08-11 17:47:34*/
#include <cstdio>
#include <cmath>

#define EPS 0.1

using namespace std;

struct cyr
{
  double x;
  double y;
};

const double way[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int n;
cyr in[110];

double cal(double x,double y)
{
  int i;
  double sum;
  sum=0;
  for (i=0;i<n;i++)
    sum+=sqrt((x-in[i].x)*(x-in[i].x)+(y-in[i].y)*(y-in[i].y));
  return sum;
}

int main()
{
  double ans,step,temp,a,b,ta,tb;
  int i;
  bool flag;
  while (scanf("%d",&n)==1)
  {
    for (i=0;i<n;i++)
      scanf("%lf%lf",&in[i].x,&in[i].y);
    a=in[0].x;
    b=in[0].y;
    ans=cal(a,b);
    step=10;
    while (step>EPS)
    {
      flag=true;
      while (flag)
      {
        flag=false;
        for (i=0;i<4;i++)
        {
          temp=cal(a+step*way[i][0],b+step*way[i][1]);
          if (temp<ans)
          {
            flag=true;
            ans=temp;
            ta=a+step*way[i][0];
            tb=b+step*way[i][1];
          }
        }
        a=ta;
        b=tb;
      }
      step=step/2.0;
    }
    printf("%.0lf\n",ans);
  }
  return 0;
}