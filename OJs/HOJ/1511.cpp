/*This Code is Submitted by Timer for Problem 1511 at 2013-03-16 20:23:21*/
#include <cstdio>

int n;
double d;

int main()
{
  int i,T,h,m,s,sum,j;
  double t,y;
  char e;
  char op[20];
  bool flag;
  scanf("%d%lf",&n,&d);
  while (scanf("%d",&T)==1)
  {
    getchar();
    sum^=sum;
    flag=true;
    for (i=1;i<=n;i++)
    {
      e=getchar();
      if (e=='-')
      {
        for (j=1;j<=6;j++)
          getchar();
        flag=false;
      }
      else
      {
        ungetc(e,stdin);
        scanf("%d:%d:%d",&h,&m,&s);
        sum+=(h*60+m)*60+s;
      }
      getchar();
    }
    printf("%3d: ",T);
    if (flag)
    {
      t=sum;
      t/=d;
      y=t/60;
      m=y;
      t-=m*60;
      s=t+0.5;
      if (s>=60)
      {
        m++;
        s-=60;
      }
      printf("%d:%02d min/km\n",m,s);
    }
    else
      puts("-");
  }
  return 0;
}