/*This Code is Submitted by Timer for Problem 1402 at 2012-02-20 19:58:54*/
#include <cstdio>
#include <cstring>

#define MAXN 51

using namespace std;

int q[51][51];
void cyr(void)
{
  int i,j;
  memset(q,0,sizeof(q));
  for (i=1;i<=50;i++)
    for (j=1;j<=50;j++)
    {
      if (i==j)
        q[j][i]=q[j][j-1]+1;
      else if (i < j)
        q[j][i] = q[j - i][i] + q[j][i - 1];
      else
        q[j][i] = q[j][j];
    }
}

int func2(int n)
{
  int i,j = 0,k,a[MAXN],b[MAXN] = {1};
  for (i = 1;i <= n;i += 2)
    a[j++] = i;
  for (i = 0;i < j;i++)
    for (k = a[i];k <= n;k++)
      b[k] += b[k - a[i]];
  return b[n];
}

int func3(int n)
{
  int i,k,a[MAXN],b[MAXN] = {1};
  for (i = 1;i <= n;i++)
    a[i - 1] = i;
  for (i = 0;i < n;i++)
    for (k = n;k >= a[i];k--)
      b[k] += b[k - a[i]];
  return b[n];
}

int main(void)
{
  int n,k;
  cyr();
  while (scanf("%d%d",&n,&k) == 2)
  {
    printf("%d\n",q[n][n]);
    if (n == k)
      printf("1\n");
    else
      printf("%d\n",q[n - k][k]);
    printf("%d\n",q[n][k]);
    printf("%d\n",func2(n));
    printf("%d\n",func3(n));
    printf("\n");
  }
  return 0;
}