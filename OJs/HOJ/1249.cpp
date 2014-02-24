/*This Code is Submitted by Timer for Problem 1249 at 2012-03-18 15:58:51*/
#include <cstdio>

using namespace std;

void MatrixChain(int n,int p[],int m[][11],int s[][11])
{
  int i,j,k,r,t;
  for(i=1;i<=n;i++) m[i][i]=0;
  for(r=2;r<=n;r++)
    for(i=1;i<=n-r+1;i++)
    {
      j=i+r-1;
      m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
      s[i][j]=i;
      for(k=i+1;k<j;k++)
      {
        t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
        if(t<m[i][j])
        {
          m[i][j]=t;
          s[i][j]=k;
        }
      }
    }
}

void output(int i,int j,int s[][11])
{
  if(i==j)
    printf("A%d",i);
  else
  {
    printf("(");
    output(i,s[i][j],s);
    printf(" x ");
    output(s[i][j]+1,j,s);
    printf(")");
  }
}

int main()
{
  int i,n,ca=1,p[11],m[11][11],s[11][11];
  scanf("%d",&n);
  while (n!=0)
  {
    for(i=1;i<=n;i++) 
      scanf("%d %d",&p[i-1],&p[i]);
    MatrixChain(n,p,m,s);
    printf("Case %d: ",ca++);
    output(1,n,s);
    printf("\n");
    scanf("%d",&n);
  }
  return 0;
}