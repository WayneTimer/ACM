/*This Code is Submitted by Timer for Problem 1045 at 2012-08-15 19:26:02*/
#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  int x;
  int y;
};

cyr e[2000];
int begin;
int du[2000];
bool used[2000];
int edge;
int out[2000];
int num;

bool check(int u)
{
  int i;
  for (i=1;i<=u;i++)
  {
    if ((du[i]&1)==1)
      return false;
  }
  return true;
}

void sub(int u)
{
  int i;
  for (i=1;i<=edge;i++)
  {
    if (!used[i])
      if ((u==e[i].x)||(u==e[i].y))
      {
        used[i]=true;
        if (u==e[i].x)
          sub(e[i].y);
        else 
          sub(e[i].x);
        num++;
        out[num]=i;
      }
  }
}

int main()
{
  int i,x,y,s,max;
  scanf("%d%d",&x,&y);
  while (x|y)
  {
    memset(du,0,sizeof(du));
    memset(used,false,sizeof(used));
    edge=0;
    num=0;
    max=0;
    if (x<y)
      begin=x;
    else
      begin=y;
    if (x>max) max=x;
    if (y>max) max=y;
    while (x|y)
    {
      scanf("%d",&s);
      if (s>edge) edge=s;
      e[s].x=x;
      e[s].y=y;
      du[x]++;
      du[y]++;
      if (x>max) max=x;
      if (y>max) max=y;
      scanf("%d%d",&x,&y);
    }
    if (!check(max))
      printf("Round trip does not exist.\n");
    else
    {
      sub(begin);
      for (i=edge;i>1;i--)
        printf("%d ",out[i]);
      printf("%d\n",out[1]);
    }
    scanf("%d%d",&x,&y);
  }
  return 0;
}