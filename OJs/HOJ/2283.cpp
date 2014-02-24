/*This Code is Submitted by Timer for Problem 2283 at 2012-07-25 22:43:15*/
#include <cstdio>
#include <cstring>

using namespace std;

char a[9][9];

int main()
{
  char e[100];
  int x,y,l,i,j;
  char u;
  memset(a,'!',sizeof(a));
  gets(e);
  i=7;
  l=strlen(e);
  while ((e[i]>='A')&&(e[i]<='Z'))
  {
    u=e[i];
    y=e[i+1]-'a'+1;
    x=e[i+2]-'0';
    a[x][y]=u;
    i+=4;
    if (i>(l-1)) break;
  }
  while (i<=(l-1))
  {
    y=e[i]-'a'+1;
    x=e[i+1]-'0';
    a[x][y]='P';
    i+=3;
  }
  gets(e);
  i=7;
  l=strlen(e);
  while ((e[i]>='A')&&(e[i]<='Z'))
  {
    u=e[i]+'a'-'A';
    y=e[i+1]-'a'+1;
    x=e[i+2]-'0';
    a[x][y]=u;
    i+=4;
    if (i>(l-1)) break;
  }
  while (i<=(l-1))
  {
    y=e[i]-'a'+1;
    x=e[i+1]-'0';
    a[x][y]='p';
    i+=3;
  }
  printf("+---+---+---+---+---+---+---+---+\n");
  for (i=8;i>=1;i--)
  {
    for (j=1;j<=8;j++)
    {
      printf("|");
      x=i+j;
      if (x&1) printf(".");
        else printf(":");
      if (a[i][j]!='!') printf("%c",a[i][j]);
        else
          if (x&1) printf(".");
            else printf(":");
      if (x&1) printf(".");
        else printf(":");
    }
    printf("|\n");
    printf("+---+---+---+---+---+---+---+---+\n");
  }
  return 0;
}