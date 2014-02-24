/*This Code is Submitted by Timer for Problem 1868 at 2012-07-28 20:43:06*/
#include <cstdio>
#include <cstring>
#include <string>
#include <map>

using namespace std;

struct cyr
{
  int v; 
  int p;
  string x;
};

cyr f1[400010];
cyr f2[400010];
map <string,int> b;
map <string,int> step;

int BFS()
{
  int i,head,tail1,tail2,temp;
  int x;
  head=-1;
  tail1=0;
  tail2=0;
  do
  {
    head++;
    for (i=0;i<4;i++)
    {
      //----------------------------------------
      x=-1;
      if (i==0)
        if ((f1[head].p%3)!=0)
          x=f1[head].p-1;
      if (i==1)
        if ((f1[head].p%3)!=2)
          x=f1[head].p+1;
      if (i==2)
        x=f1[head].p-3;
      if (i==3)
        x=f1[head].p+3;
      if ( (x>=0) && (x<9) )
      {
        tail1++;
        f1[tail1]=f1[head];
        f1[tail1].x[f1[head].p]=f1[tail1].x[x];
        f1[tail1].x[x]='0';
        temp=b[f1[tail1].x];
        if (temp==1)
          tail1--;
        if (temp==2)
        {
          return (step[f1[tail1].x]+f1[tail1].v+1);
        }
        if (temp==0)
        {
          f1[tail1].v++;
          f1[tail1].p=x;
          b[f1[tail1].x]=1;
          step[f1[tail1].x]=f1[tail1].v;
        }
      }
      //-----------------------------------------
      //----------------------------------------
      x=-1;
      if (i==0)
        if ((f2[head].p%3)!=0)
          x=f2[head].p-1;
      if (i==1)
        if ((f2[head].p%3)!=2)
          x=f2[head].p+1;
      if (i==2)
        x=f2[head].p-3;
      if (i==3)
        x=f2[head].p+3;
      if ( (x>=0) && (x<9) )
      {
        tail2++;
        f2[tail2]=f2[head];
        f2[tail2].x[f2[head].p]=f2[tail2].x[x];
        f2[tail2].x[x]='0';
        temp=b[f2[tail2].x];
        if (temp==2)
          tail2--;
        if (temp==1)
        {
          return (step[f2[tail2].x]+f2[tail2].v+1);
        }
        if (temp==0)
        {
          f2[tail2].v++;
          f2[tail2].p=x;
          b[f2[tail2].x]=2;
          step[f2[tail2].x]=f2[tail2].v;
        }
      }
      //-----------------------------------------
    }
  } while (head<tail1);
  return -1;
}

bool clhs()
{
  int i,j,s1,s2,x1,x2;
  s1=0;
  s2=0;
  for (i=0;i<8;i++)
  {
    x1=0;
    x2=0;
    for (j=i+1;j<9;j++)
    {
      if (f1[0].x[j]!='0')
        if (f1[0].x[i]>f1[0].x[j]) x1++;
      if (f2[0].x[j]!='0')
        if (f2[0].x[i]>f2[0].x[j]) x2++;
    }
    s1+=x1;
    s2+=x2;
  }
  x1=s1&1;
  x2=s2&1;
  if (x1==x2) return false;
  return true;
}

int main()
{
  int T,i,j,y;
  char e[15];
  scanf("%d",&T);
  while (T--)
  {
    b.clear();
    step.clear();
    for (i=0;i<9;i++)
    {
      scanf("%d",&y);
      e[i]='0'+y;
      if (y==0) j=i;
    }
    e[9]='\0';
    f1[0].v=0;
    f1[0].x=e;
    f1[0].p=j;
    b[f1[0].x]=1;
    for (i=0;i<9;i++)
    {
      scanf("%d",&y);
      e[i]='0'+y;
      if (y==0) j=i;
    }
    f2[0].v=0;
    f2[0].x=e;
    f2[0].p=j;
    if (b[f2[0].x]==1) 
    {
      printf("0\n");
      continue;
    }
    b[f2[0].x]=2;
    if (clhs()) y=-1;
      else
        y=BFS();
    printf("%d\n",y);
  }
  return 0;
}