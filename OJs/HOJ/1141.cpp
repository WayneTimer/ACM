/*This Code is Submitted by Timer for Problem 1141 at 2013-03-05 21:43:04*/
#include <cstdio>
#include <cstring>

int a[7];
bool f[230000];
int s;

inline bool dp()
{
  int i,up,j,t,k;
  memset(f,false,sizeof(f));
  up=0;
  f[0]=true;
  for (i=1;i<=6;i++)
    for (j=up;j>=0;j--)
      if (f[j])
        for (k=1;k<=a[i];k++)
        {
          t=j+i*k;
          if (t==s) return true;
          if (t>s) break;
          f[t]=true;
          if (t>up) up=t;
        }
  return false;
}

int main()
{
  int i,T;
  bool flag;
  T^=T;
  while (1)
  {
    flag=true;
    s^=s;
    for (i=1;i<=6;i++)
    {
      scanf("%d",&a[i]);
      s+=a[i]*i;
      if (a[i]) flag=false;
    }
    if (flag) break;
    if (!(s&1))
    {
      s>>=1;
      flag=dp();
    }
    printf("Collection #%d:\n",++T);
    if (flag)
      puts("Can be divided.");
    else
      puts("Can't be divided.");
    puts("");
  }
  return 0;
}