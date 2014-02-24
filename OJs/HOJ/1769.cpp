/*This Code is Submitted by Timer for Problem 1769 at 2013-10-28 11:10:06*/
#include <cstdio>

int a[3];
int b[3];

inline void swap(int &x,int &y)
{
  int t;
  t=x;
  x=y;
  y=t;
}

inline void mysort(int f[])
{
  if (f[1]>f[0]) swap(f[0],f[1]);
  if (f[2]>f[0]) swap(f[0],f[2]);
  if (f[2]>f[1]) swap(f[1],f[2]);
}

int main()
{
  int p,q,r,s,i,j;
  double s1;
  while (scanf("%d%d%d%d",&p,&q,&r,&s)==4)
  {
    a[0]=p;
    a[1]=s;
    a[2]=r-s;
    b[0]=q;
    b[1]=p-q;
    b[2]=r;
    mysort(a);
    mysort(b);
    s1=1;
    for (i=0;i<3;i++)
    {
      if (a[i]<=b[i])
      {
        for (j=a[i]+1;j<=b[i];j++)
          s1/=j;
      }
      else
      {
        for (j=b[i]+1;j<=a[i];j++)
          s1*=j;
      }
    }
    printf("%.5lf\n",s1);
  }
  return 0;
}