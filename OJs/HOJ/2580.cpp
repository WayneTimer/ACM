/*This Code is Submitted by Timer for Problem 2580 at 2013-03-21 02:14:30*/
#include <cstdio>

int s;
char a[10010];

int main()
{
  int i;
  scanf("%s",a);
  while (1)
  {
    if (a[0]=='e' && a[1]=='n' && a[2]=='d')
      if (a[3]=='\0') break;
    i=0;
    s=0;
    while (a[i])
    {
      s*=62;
      if (a[i]<='9') s+=a[i]-'0';
      else if (a[i]<='Z') s+=a[i]-'A'+10;
      else s+=a[i]-'a'+36;
      s%=61;
      i++;
    }
    if (s==0) puts("yes");
    else puts("no");
    scanf("%s",a);
  }
  return 0;
}