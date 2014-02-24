/*This Code is Submitted by Timer for Problem 2591 at 2012-03-11 13:59:57*/
#include <cstdio>
#include <cstring>

using namespace std;

struct clhs
{
  int x;
  int y;
};

clhs way[4];
char a[21][21];
int n,r,c,x,y,w;
bool fault;

bool check(int g,int h)
{
  if (g>=r) return false;
  if (g<0) return false;
  if (h>=c) return false;
  if (h<0) return false;
  if ((a[g][h])=='\0') return false;
  fault=true;
  return true;
}

int cyr()
{
  int i,tmp,sum;
  char name[5];
  for (i=0;i<5;i++)
  {
    x=x+way[w].x;
    y=y+way[w].y;
    fault=false;
    if (!check(x,y))
    {
      x=x-way[w].x;
      y=y-way[w].y;
      w++;
      if (w>=4) w=w%4;
      x=x+way[w].x;
      y=y+way[w].y;
      if (!check(x,y)) return -1;
    }
    if (!fault) return -1;
    name[i]=a[x][y];
    a[x][y]='\0';
  }
  tmp=1;
  sum=0;
  if (name[4]=='1') sum=1;
  for (i=3;i>=0;i--)
  {
    tmp=tmp*2;
    if (name[i]=='1') sum=sum+tmp;
  }
  return sum;
}

int main()
{
  int p,i,j,l,z,t;
  char e[500];
  memset(way,0,sizeof(way));
  way[0].y=1;
  way[1].x=1;
  way[2].y=-1;
  way[3].x=-1;
  scanf("%d",&n);
  for (p=1;p<=n;p++)
  {
    scanf("%d %d",&r,&c);
    memset(a,0,sizeof(a));
    getchar();
    gets(e);
    l=strlen(e);
    z=-1;
    for (i=0;i<r;i++)
      for (j=0;j<c;j++)
      {
        z++;
        a[i][j]=e[z];
      }
    x=0;
    y=-1;
    w=0;
    z=-1;
    t=cyr();
    memset(e,0,sizeof(e));
    while (t>=0)
    {
      z++;
      if (t==0) e[z]=' ';
        else e[z]='A'+t-1;
      t=cyr();
    }
    while (e[z]==' ') 
    {
      e[z]='\0';
      z--;
    }
    printf("%d ",p);
    printf("%s\n",e);
  }
  return 0;
}