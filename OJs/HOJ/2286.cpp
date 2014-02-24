/*This Code is Submitted by Timer for Problem 2286 at 2012-07-25 20:47:54*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct cyr
{
  int x;
  char y;
};

char v[7];
int s1[7],s2[7];
cyr b1[7][100],b2[7][100];

bool comp1(cyr q,cyr w)
{
  if (q.x==w.x)
    return (q.y<w.y);
  return (q.x>w.x);
}

bool comp2(cyr q,cyr w)
{
  if (q.x==w.x)
    return (q.y<w.y);
  return (q.x<w.x);
}

int main()
{
  char e[100];
  int i,j,p;
  v[1]='K';
  v[2]='Q';
  v[3]='R';
  v[4]='B';
  v[5]='N';
  memset(s1,0,sizeof(s2));
  memset(s2,0,sizeof(s2));
  memset(b1,0,sizeof(b1));
  memset(b2,0,sizeof(b2));
  gets(e);
  i=9;
  while (gets(e))
  {
    i--;
    p=2;
    j=0;
    while (p<=32)
    {
      j++;
      switch (e[p])
      {
        case 'k':
          s1[1]++;
          b1[1][s1[1]].x=i;
          b1[1][s1[1]].y=j+'a'-1;
          break;
        case 'K':
          s2[1]++;
          b2[1][s2[1]].x=i;
          b2[1][s2[1]].y=j+'a'-1;
          break;
        case 'q':
          s1[2]++;
          b1[2][s1[2]].x=i;
          b1[2][s1[2]].y=j+'a'-1;
          break;
        case 'Q':
          s2[2]++;
          b2[2][s2[2]].x=i;
          b2[2][s2[2]].y=j+'a'-1;
          break;
        case 'r':
          s1[3]++;
          b1[3][s1[3]].x=i;
          b1[3][s1[3]].y=j+'a'-1;
          break;
        case 'R':
          s2[3]++;
          b2[3][s2[3]].x=i;
          b2[3][s2[3]].y=j+'a'-1;
          break;
        case 'b':
          s1[4]++;
          b1[4][s1[4]].x=i;
          b1[4][s1[4]].y=j+'a'-1;
          break;
        case 'B':
          s2[4]++;
          b2[4][s2[4]].x=i;
          b2[4][s2[4]].y=j+'a'-1;
          break;
        case 'n':
          s1[5]++;
          b1[5][s1[5]].x=i;
          b1[5][s1[5]].y=j+'a'-1;
          break;
        case 'N':
          s2[5]++;
          b2[5][s2[5]].x=i;
          b2[5][s2[5]].y=j+'a'-1;
          break;
        case 'p':
          s1[6]++;
          b1[6][s1[6]].x=i;
          b1[6][s1[6]].y=j+'a'-1;
          break;
        case 'P':
          s2[6]++;
          b2[6][s2[6]].x=i;
          b2[6][s2[6]].y=j+'a'-1;
          break;
      } 
      p+=4;
    }
    gets(e);
  }
  for (i=1;i<=6;i++)
  {
    sort(b1[i]+1,b1[i]+s1[i]+1,comp1);
    sort(b2[i]+1,b2[i]+s2[i]+1,comp2);
  }
  bool flag;
  flag=false;
  printf("White: ");
  for (i=1;i<=6;i++)
  {
    for (j=1;j<=s2[i];j++)
    {
      if (flag) printf(",");
      if (i!=6) printf("%c",v[i]);
      printf("%c%d",b2[i][j].y,b2[i][j].x);
      flag=true;
    }
  }
  flag=false;
  printf("\n");
  printf("Black: ");
  for (i=1;i<=6;i++)
  {
    for (j=1;j<=s1[i];j++)
    {
      if (flag) printf(",");
      if (i!=6) printf("%c",v[i]);
      printf("%c%d",b1[i][j].y,b1[i][j].x);
      flag=true;
    }
  }
  printf("\n");
  return 0;
}