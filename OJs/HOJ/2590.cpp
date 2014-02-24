/*This Code is Submitted by Timer for Problem 2590 at 2012-03-11 13:58:37*/
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
char v[28][6];
int n,r,c,x,y,w;

bool check(int g,int h)
{
  if (g>=r) return false;
  if (g<0) return false;
  if (h>=c) return false;
  if (h<0) return false;
  if ((a[g][h])!='\0') return false;
  return true;
}

void cyr(int u)
{
  int i;
  for (i=0;i<5;i++)
  {
    x=x+way[w].x;
    y=y+way[w].y;
    while (!check(x,y))
    {
      x=x-way[w].x;
      y=y-way[w].y;
      w++;
      if (w>=4) w=w%4;
      x=x+way[w].x;
      y=y+way[w].y;
    }
    a[x][y]=v[u][i];
  }
}

int main()
{
  int p,i,j,l;
  char e[81];
  memset(v,0,sizeof(v));
  memset(way,0,sizeof(way));
  way[0].y=1;
  way[1].x=1;
  way[2].y=-1;
  way[3].x=-1;
  strcpy(v[0],"00000");
  strcpy(v[1],"00001");
  strcpy(v[2],"00010");
  strcpy(v[3],"00011");
  strcpy(v[4],"00100");
  strcpy(v[5],"00101");  
  strcpy(v[6],"00110");
  strcpy(v[7],"00111");
  strcpy(v[8],"01000");
  strcpy(v[9],"01001");
  strcpy(v[10],"01010");
  strcpy(v[11],"01011");
  strcpy(v[12],"01100");
  strcpy(v[13],"01101");
  strcpy(v[14],"01110");
  strcpy(v[15],"01111");
  strcpy(v[16],"10000");
  strcpy(v[17],"10001");
  strcpy(v[18],"10010");
  strcpy(v[19],"10011");
  strcpy(v[20],"10100");
  strcpy(v[21],"10101");
  strcpy(v[22],"10110");
  strcpy(v[23],"10111");
  strcpy(v[24],"11000");
  strcpy(v[25],"11001");
  strcpy(v[26],"11010");
  scanf("%d",&n);
  for (p=1;p<=n;p++)
  {
    scanf("%d %d",&r,&c);
    memset(a,0,sizeof(a));
    x=0;
    y=-1;
    w=0;
    getchar();
    gets(e);
    l=strlen(e);
    for (i=0;i<l;i++)
      if (e[i]==' ') cyr(0);
        else cyr(e[i]-'A'+1);
    for (i=0;i<r;i++)
      for (j=0;j<c;j++)
        if (a[i][j]=='\0') a[i][j]='0';
    printf("%d ",p);
    for (i=0;i<r;i++)
      printf("%s",a[i]);
    printf("\n");
  }
  return 0;
}