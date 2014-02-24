/*This Code is Submitted by Timer for Problem 1422 at 2013-03-07 20:23:08*/
// BFS
#include <cstdio>
#include <cstring>

struct cyr
{
  int x,y,z;
};

bool b[10][10][10];
bool a[10][10][10];
int n;
cyr s,e;
cyr w[6];
cyr c[5000];
int ans[5000];

inline bool check(cyr t)
{
  if (t.x<0 || t.x>=n) return false;
  if (t.y<0 || t.y>=n) return false;
  if (t.z<0 || t.z>=n) return false;
  if (!a[t.x][t.y][t.z]) return false;
  if (!b[t.x][t.y][t.z]) return false;
  return true;
}

inline void BFS()
{
  int head,tail,i;
  cyr t;
  if (s.x==e.x && s.y==e.y && s.z==e.z)
  {
    printf("%d 0\n",n);
    return;
  }
  memset(b,true,sizeof(b));
  b[s.x][s.y][s.z]=false;
  head=0;
  tail=1;
  c[1]=s;
  ans[1]=0;
  do
  {
    head++;
    for (i=0;i<6;i++)
    {
      t.x=c[head].x+w[i].x;
      t.y=c[head].y+w[i].y;
      t.z=c[head].z+w[i].z;
      if (check(t))
      {
        if (t.x==e.x && t.y==e.y && t.z==e.z)
        {
          printf("%d %d\n",n,ans[head]+1);
          return;
        }
        b[t.x][t.y][t.z]=false;
        tail++;
        c[tail]=t;
        ans[tail]=ans[head]+1;
      }
    }
  } while (head<tail);
  puts("NO ROUTE");
}

int main()
{
  int i,j,k;
  char str[20];
  memset(w,0,sizeof(w));
  w[0].x=-1;
  w[1].y=1;
  w[2].x=1;
  w[3].y=-1;
  w[4].z=1;
  w[5].z=-1;
  while (scanf("%s",str)==1)
  {
    scanf("%d",&n);
    for (k=0;k<n;k++)
      for (i=0;i<n;i++)
      {
        scanf("%s",str);
        for (j=0;j<n;j++)
          if (str[j]=='O')
            a[i][j][k]=true;
          else 
            a[i][j][k]=false;
      }
    scanf("%d%d%d",&s.y,&s.x,&s.z);
    scanf("%d%d%d",&e.y,&e.x,&e.z);
    scanf("%s",str);
    BFS();
  }
  return 0;
}