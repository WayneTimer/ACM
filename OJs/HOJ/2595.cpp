/*This Code is Submitted by Timer for Problem 2595 at 2013-10-28 12:07:51*/
/*
f[i]=f[i-1]+4*f[i-2]+2*(f[i-3]+f[i-5]+...)+3*(f[i-4]+f[i-6]+...)
f[0]=1,f[1]=1,f[2]=5,f[3]=11
*/
#include <cstdio>

int f[1100];

int main()
{
  int i,n,T,j,s,o;
  f[0]=1;
  f[1]=1;
  f[2]=5;
  f[3]=11;
  i=3;
  scanf("%d",&T);
  for (o=1;o<=T;o++)
  {
    scanf("%d",&n);
    while (n>i)
    {
      i++;
      f[i]=f[i-1]+(f[i-2]<<2);
      s=0;
      for (j=i-3;j>=0;j-=2)
        s+=f[j];
      f[i]+=s<<1;
      s=0;
      for (j=i-4;j>=0;j-=2)
        s+=f[j];
      f[i]+=s*3;
    }
    printf("%d %d\n",o,f[n]);
  }
  return 0;
}