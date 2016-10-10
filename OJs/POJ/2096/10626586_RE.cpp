#include <cstdio>

using namespace std;

int n,s;
double f[1001][1001];

int main()
{
  int i,j;
  scanf("%d%d",&n,&s);
  f[n][s]=0.0;
  for (i=n;i>=0;i--)
    for (j=s;j>=0;j--)
    {
      if ((i==n) && (j==s))
        continue;
      f[i][j]=( n*s + (n-i)*j*f[i+1][j] + i*(s-j)*f[i][j+1] + (n-i)*(s-j)*f[i+1][j+1] )/( n*s - i*j );
    }
  printf("%.4lf\n",f[0][0]);
  return 0;
}