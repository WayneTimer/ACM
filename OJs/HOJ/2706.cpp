/*This Code is Submitted by Timer for Problem 2706 at 2012-07-28 10:13:57*/
#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  int x;
  int y;
  int v;
  int s;
};

const int maxtail=100010;
const int UP=99999999;
const int way[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
cyr f[maxtail];
bool b[101][101][16];
char a[101][101];
int key[256];
int n,m;
int minstep;

inline bool check(int x,int y,int vv)
{
  if (x<0) return false;
  if (x>=n) return false;
  if (y<0) return false;
  if (y>=m) return false;
  if (key[a[x][y]]<0) return false;
  if (b[x][y][vv]) return false;
  int u;
  u=key[a[x][y]];
  if ((u>=4) && (u<=7))
  {
    u=u-4;
    if (vv & (1<<u)) return true;
      else return false;
  }
  return true;
}

void sub()
{
  int i,head,tail;
  int x,y;
  head=-1;
  tail=0;
  do
  {
    head++;
    for (i=0;i<4;i++)
    {
      x=f[head].x+way[i][0];
      y=f[head].y+way[i][1];
      if (check(x,y,f[head].v))
      {
        if (key[a[x][y]]==9)
        {
          minstep=f[head].s+1;
          return;
        }
        tail++;
        f[tail].x=x;
        f[tail].y=y;
        f[tail].v=f[head].v;
        if (key[a[x][y]]<=3)
          f[tail].v=f[tail].v | (1<<key[a[x][y]]);
        f[tail].s=f[head].s+1;
        b[x][y][f[head].v]=true;
        b[x][y][f[tail].v]=true;
      }
    }
  } while (head<tail);
}

int main()
{
  int i,j;
  char e;
  bool flag;
  memset(key,0,sizeof(key));
  key['b']=0;
  key['y']=1;
  key['r']=2;
  key['g']=3;
  key['B']=4;
  key['Y']=5;
  key['R']=6;
  key['G']=7;
  key['.']=8;
  key['*']=8;
  key['X']=9;
  key['#']=-1;
  scanf("%d%d",&n,&m);
  while (n||m)
  {
    flag=true;
    memset(b,false,sizeof(b));
    for (i=0;i<n;i++)
    {
      scanf("%s",a[i]);
      if (flag)
        for (j=0;j<m;j++)
          if (a[i][j]=='*')
          {
            f[0].x=i;
            f[0].y=j;
            f[0].v=0;
            f[0].s=0;
            b[i][j][0]=true;
            flag=false;
            break;
          }
    }
    minstep=UP;
    sub();
    if (minstep<UP)
      printf("Escape possible in %d steps.\n",minstep);
    else 
      printf("The poor student is trapped!\n");
    scanf("%d%d",&n,&m);
  }
  return 0;
}