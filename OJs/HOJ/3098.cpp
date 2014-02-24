/*This Code is Submitted by Timer for Problem 3098 at 2012-03-05 13:18:29*/
#include <cstdio>
#include <cstring>

using namespace std;

int v[1001][1001];
long b[1001];
bool mark[1001];
int A,B,C,n,m;

long cyr(int x,int y)
{
  int i,j,k;
  long min,t;
  memset(b,0x3f,sizeof(b));
  memset(mark,false,sizeof(mark));
  b[x]=0;
  for (i=0;i<n;i++)
  {
    min=1000000;
    for (j=0;j<n;j++)
      if ((!mark[j])&&(b[j]<min))
      {
        k=j;
        min=b[j];
      }
    mark[k]=true;
    if (k==y) return min;
    for (j=0;j<n;j++)
      if (v[k][j]!=0)
      {
        t=b[k]+v[k][j];
        if (t<b[j]) b[j]=t;
      }
  }
  if (!mark[y]) return -1;
}

int main()
{
  int i,x,y,t;
  long t1,sum,t2; 
  while (scanf("%d%d",&n,&m)==2)
  {
    memset(v,0,sizeof(v));
    for (i=1;i<=m;i++)
    {
      scanf("%d%d%d",&x,&y,&t);
      if (v[x][y]==0) 
      {
        v[x][y]=t;
        v[y][x]=t;
      }
      else
      {
        if (t<v[x][y])
        {
          v[x][y]=t;
          v[y][x]=t;
        }
      }
    }
    scanf("%d%d%d",&A,&B,&C);
    if (n<3) 
    {
      printf("-1\n");
      continue;
    }
    sum=-1;
    t1=cyr(A,B);
    if (t1==-1) sum=-1;
      else
      {
        sum=t1; 
        t1=cyr(B,C);
        if (t1==-1) sum=-1;
          else sum=sum+t1;
      }
    t1=cyr(A,C);
    if (t1==-1) 
    {
      printf("%ld\n",sum);
      continue;
    }
    else
    {
      t2=cyr(C,B);
      if (t2==-1)
      {
        printf("%ld\n",sum);
        continue;
      }
      else
      {
        t1=t1+t2;
        if (sum==-1) sum=t1;
          else
            if (t1<sum) sum=t1;
      }
    }
    printf("%ld\n",sum);
  }
  return 0;
}