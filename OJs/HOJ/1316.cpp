/*This Code is Submitted by Timer for Problem 1316 at 2012-02-08 17:28:52*/
#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>

using namespace std;

const int v[5][5]=
  {
  {-1000,-3,-4,-2,-1},
  {-3,5,-1,-2,-1},
  {-4,-1,5,-3,-2},
  {-2,-2,-3,5,-2},
  {-1,-1,-2,-2,5}
  };
string q,w;
int n,m;
long f[151][151];

int cyr(char x)
{
  if (x=='A') return 1;
  if (x=='C') return 2;
  if (x=='G') return 3;
  if (x=='T') return 4;
  return 0;
}

long max(long x,long y,long z)
{
  long p;
  p=x;
  if (y>p) p=y;
  if (z>p) p=z;
  return p;
}

int main()
{
  int T,O;
  int i,j;
  long a1,a2,a3,t,t2;
  while (scanf("%d",&T)==1)
  {
    for (O=1;O<=T;O++)
    {
      scanf("%d",&n);
      cin>>q;
      scanf("%d",&m);
      cin>>w;
      memset(f,0,sizeof(f));
      for (i=1;i<=n;i++)
      {
        t=cyr(q[i-1]);
        f[i][0]=f[i-1][0]+v[t][0];
      }
      for (j=1;j<=m;j++)
      {
        t=cyr(w[j-1]);
        f[0][j]=f[0][j-1]+v[0][t];
      }
      for (i=1;i<=n;i++)
      {
        for (j=1;j<=m;j++)
        {
          t=cyr(q[i-1]);
          t2=cyr(w[j-1]);
          a1=f[i-1][j-1]+v[t][t2];
          t=cyr(q[i-1]);
          a2=f[i-1][j]+v[t][0];
          t=cyr(w[j-1]);
          a3=f[i][j-1]+v[0][t];
          f[i][j]=max(a1,a2,a3);
        }
      }
      printf("%ld\n",f[n][m]);
    }
  }
  return 0;
}