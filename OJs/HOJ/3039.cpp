/*This Code is Submitted by Timer for Problem 3039 at 2012-08-09 19:11:01*/
#include <cstdio>
#include <cstring>

using namespace std;

int a,b,n;
int d[50];
int f[50][10][500];
int temp;

int DFS(int x,int y,bool flag)
{
  if (x<0)
    if ((temp%n)==0)
      return 1;
    else 
      return 0;
  if (!flag)
    if (f[x][y][(y+temp)%n]!=-1)
      return f[x][y][(y+temp)%n];
  int i,up,s;
  if (flag) up=d[x];
    else up=9;
  s=0;
  for (i=0;i<=up;i++)
  {
    temp+=i;
    s+=DFS(x-1,i,flag&&(i==d[x]));
    temp-=i;
  }
  if (!flag) f[x][y][(y+temp)%n]=s;
  return s;
}

int main()
{
  int t,i,ans;
  while (scanf("%d%d%d",&a,&b,&n)==3)
  {
    memset(f,-1,sizeof(f));
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
    temp=0;
    t=DFS(i,0,true);
    i=-1;
    while (b>0)
    {
      i++;
      d[i]=b%10;
      b=b/10;
    }
    temp=0;
    ans=DFS(i,0,true);
    ans=ans-t;
    printf("%d\n",ans);
  }
  return 0;
}