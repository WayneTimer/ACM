/*This Code is Submitted by Timer for Problem 2342 at 2012-07-10 15:01:11*/
#include <cstdio>
#include <cstring>

using namespace std;

const int max=10000;
int a[10050];
int p[10050];
bool ch[10050];
int w;

void prime()
{
  int i,j;
  memset(ch,true,sizeof(ch));
  memset(p,0,sizeof(p));
  w=0;
  ch[0]=false;
  ch[1]=false;
  for (i=2;i<=max;i++)
    if (ch[i])
    {
      w++;
      p[w]=i;
      for (j=2;(i*j<=max);j++)
        ch[i*j]=false;
    }
}

int main()
{
  int i,j;
  int s,n;
  memset(a,0,sizeof(a));
  a[0]=0;
  a[1]=0;
  prime();
  for (i=1;i<=w;i++)
  {
    s=p[i];
    a[s]++;
    for (j=i+1;j<=w;j++)
    {
      s+=p[j];
      if (s>max) break;
      a[s]++;
    }
  }
  scanf("%d",&n);
  while (n!=0)
  {
    printf("%d\n",a[n]);
    scanf("%d",&n);
  }
  return 0;
}