/*This Code is Submitted by Timer for Problem 3091 at 2012-03-04 13:47:28*/
#include <cstdio>
#include <cstring>

using namespace std;

char up[250];
char down[250];
int T;

int main()
{
  int o,l1,l2,i,j,s;
  bool f;
  scanf("%d",&T);
  getchar();
  for (o=1;o<=T;o++)
  {
    gets(up);
    gets(down);
    l1=strlen(up);
    l2=strlen(down);
    s=0;
    for (i=0;i<l1;i++)
      if (up[i]=='_') s++;
    printf("%d\n",s);
    if ((s%2)==1)
    {
      if (up[l1-1]=='_')
      {
        up[l1]='_';
        up[l1+1]='\0';
        down[l2]=' ';
        down[l2+1]='\0';
      }
      else
      {
        down[l2]='|';
        down[l2+1]=' ';
        down[l2+2]='\0';
        up[l1]=' ';
        up[l1+1]='_';
        up[l1+2]='\0';
      }
    }
    else
    {
      if (up[l1-1]=='_')
      {
        up[l1]=' ';
        up[l1+1]=' ';
        up[l1+2]='\0';
        down[l2]='|';
        down[l2+1]='_';
        down[l2+2]='\0';
      }
      else
      {
        up[l1]=' ';
        up[l1+1]='\0';
        down[l2]='_';
        down[l2+1]='\0';
      }
    }
    l1=strlen(up);
    l2=strlen(down);
    if (up[l1-1]=='_')
    {
      up[l1]='_';
      up[l1+1]='\0';
      down[l2]=' ';
      down[l2+1]='\0';
    }
    else
    {
      down[l2]='|';
      down[l2+1]=' ';
      down[l2+2]='\0';
      up[l1]=' ';
      up[l1+1]='_';
      up[l1+2]='\0';
    }
    l1=strlen(up);
    l2=strlen(down);
    f=false;
    if (down[0]!='_') f=true;
    if (f) printf("  ");
      else printf(" ");
    printf("%s\n",up);
    if (f) printf("_|");
      else printf("_");
    printf("%s\n",down);
  }
  return 0;
}