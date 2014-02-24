/*This Code is Submitted by Timer for Problem 1102 at 2012-08-11 09:38:28*/
#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  int x;
  int y;
};

struct seg
{
  cyr a;
  cyr b;
};

seg l[16];
int n;
bool b[16][16];

inline int max(int x,int y)
{
  if (x>=y) return x;
  return y;
}

inline int min(int x,int y)
{
  if (x<=y) return x;
  return y;
}

inline int chaji(cyr q,cyr w,cyr e)
{
  int x1,y1,x2,y2;
  x1=w.x-q.x;
  y1=w.y-q.y;
  x2=e.x-q.x;
  y2=e.y-q.y;
  return ((x1*y2)-(x2*y1));
}

inline int relation(seg u,seg v)
{
  if (min(u.a.x,u.b.x)>max(v.a.x,v.b.x)) return 0;
  if (min(u.a.y,u.b.y)>max(v.a.y,v.b.y)) return 0;
  if (min(v.a.x,v.b.x)>max(u.a.x,u.b.x)) return 0;
  if (min(v.a.y,v.b.y)>max(u.a.y,u.b.y)) return 0;
  if ((chaji(u.a,u.b,v.a)*chaji(u.a,u.b,v.b))>0) return 0;
  if ((chaji(v.a,v.b,u.a)*chaji(v.a,v.b,u.b))>0) return 0;
  return 1;
}

int main()
{
  int i,x,y,j,k;
  scanf("%d",&n);
  while (n)
  {
    memset(b,false,sizeof(b));
    for (i=1;i<=n;i++)
      scanf("%d%d%d%d",&l[i].a.x,&l[i].a.y,&l[i].b.x,&l[i].b.y);
    for (x=1;x<=n;x++)
      for (y=1;y<=n;y++)
        if (x==y)
          b[x][x]=true;
        else
          if (relation(l[x],l[y])>0)
          {
            b[x][y]=true;
            b[y][x]=true;
          }
    for (k=1;k<=n;k++)
      for (i=1;i<=n;i++)
      {
        if (b[k][i])
          for (j=1;j<=n;j++)
            if (b[k][j])
            {
              b[i][j]=true;
              b[j][i]=true;
            }
      }
    scanf("%d%d",&x,&y);
    while (x|y)
    {
      if (b[x][y])
        printf("CONNECTED\n");
      else
        printf("NOT CONNECTED\n");
      scanf("%d%d",&x,&y);
    }
    scanf("%d",&n);
  }
  return 0;
}