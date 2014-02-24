/*This Code is Submitted by Timer for Problem 2640 at 2013-09-26 15:08:26*/
#include <cstdio>

struct eugin
{
  int x,y,z,p;
};

int n;
eugin a,b;

int main()
{
  char str[200];
  int i;
  while (scanf("%d",&n)==1)
  {
    a.x=0;
    a.y=0;
    a.z=0;
    a.p=0;
    b.x=0;
    b.y=0;
    b.z=0;
    b.p=0;
    gets(str);
    while (n--)
    {
      gets(str);
      i=0;
      do
      {
        if (str[i]=='k') a.x++;
        else if (str[i]=='f') a.y++;
        else if (str[i]=='p') a.z++;
        else if (str[i]=='i') a.p++;
        else if (str[i]=='c') b.x++;
        else if (str[i]=='b') b.y++;
        else b.z++;
        while (str[i] && str[i]!=' ') i++;
        if (!str[i]) break;
        i++;
      } while (str[i]);
    }
    if (a.x>a.y) a.y=a.x;
    if (a.y>a.z) a.z=a.y;
    if (a.z>a.p) a.p=a.z;
    if (b.x>b.y) b.y=b.x;
    if (b.y>b.z) b.z=b.y;
    printf("%d %d\n",a.p,b.z);
  }
  return 0;
}