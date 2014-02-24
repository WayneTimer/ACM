/*This Code is Submitted by Timer for Problem 3038 at 2012-08-09 19:10:25*/
#include <cstdio>
#include <cstring>

using namespace std;

int d[50];
int a,b;
int f[50][10];

int DFS(int x,int y,bool flag)
{
  if (x<0) return 1;
  if (!flag)
    if (f[x][y]!=-1) 
      return f[x][y];
  int i,s,up;
  s=0;
  if (flag) up=d[x];
    else up=9;
  for (i=y;i<=up;i++)
  {
    s+=DFS(x-1,i,flag&&(i==d[x]));
  }
  if (!flag) f[x][y]=s;
  return s;
}

int main()
{
  int i,t,ans;
  memset(f,-1,sizeof(f));
  while (scanf("%d%d",&a,&b)==2)
  {
    if (a>b)
    {
      t=a;
      a=b;
      b=t;
    }
    i=-1;
    a--;
    while (a>0)
    {
      i++;
      d[i]=a%10;
      a=a/10;
    }
    t=DFS(i,0,true);
    i=-1;
    while (b>0)
    {
      i++;
      d[i]=b%10;
      b=b/10;
    }
    ans=DFS(i,0,true);
    ans=ans-t;
    printf("%d\n",ans);
  }
  return 0;
}