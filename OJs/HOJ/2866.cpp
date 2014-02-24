/*This Code is Submitted by Timer for Problem 2866 at 2012-08-10 13:26:00*/
#include <cstdio>
#include <cstring>

#define eps 1e-8

using namespace std;

int a,b;
double f1[7];
double f2[7];
double win,lose,e;
double cyr[2001][2001];

inline bool deng(double x,double y)
{
  x=y-x;
  if (x<-eps) return false;
  if (x>eps) return false;
  return true;
}

int main()
{
    int i,j;
    double max;
    while (scanf("%d%d",&a,&b)==2)
    {
        for (i=1;i<=6;i++)
          scanf("%lf",&f1[i]);
        for (i=1;i<=6;i++)
          scanf("%lf",&f2[i]);
        win=0;
        lose=0;
        for (i=6;i>=2;i--)
          for (j=i-1;j>=1;j--)
          {
            win+=f1[i]*f2[j];
            lose+=f2[i]*f1[j];
          }
        e=1.0-win-lose;
        win=win/(1-e);
        lose=lose/(1-e);
        memset(cyr,0,sizeof(cyr));
        cyr[a][b]=1;
        for (i=a;i>=1;i--)
          for (j=b;j>=0;j--)
            if ((i==a)&&(j==b)) continue;
              else
                if (j==0) cyr[i][j]=cyr[i][j+1]*win;
                  else
                    cyr[i][j]=cyr[i+1][j]*lose+cyr[i][j+1]*win;
        max=0;
        for (i=1;i<=a;i++)
          max+=cyr[i][0];
        if (max>1) max=1.0;
        printf("%.6lf\n",max);
    }
    return 0;
}