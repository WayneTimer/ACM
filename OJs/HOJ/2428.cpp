/*This Code is Submitted by Timer for Problem 2428 at 2013-03-06 12:38:43*/
#include <cstdio>

int n;
char s[50];
bool flag;

int main()
{
  flag=false;
  while (scanf("%d",&n)==1 && n)
  {
    if (flag) puts("");
      else flag=true;
    while (n--)
    {
      scanf("%s",s);
      if (s[0]=='N')
        puts("wy");
      else if (s[0]=='I')
      {
        puts("wywcgs");
        scanf("%s",s);
        scanf("%s",s);
      }
      else if (s[0]=='G')
        puts("male");
      else if (s[0]=='C')
        puts("13*********");
      else if (s[0]=='H')
        puts("189.5cm");
      else if (s[0]=='W')
        puts("51kg");
      else if (s[0]=='B' && s[1]=='i')
        puts("1987-2-29");
      else if (s[0]=='B' && s[1]=='l')
        puts("^&$%#&%^@");
      else if (s[0]=='S')
        puts("Mars");
      else if (s[0]=='F')
      {
        scanf("%s",s);
        if (s[0]=='l')
          puts("e");
        else if (s[0]=='k')
        {
          puts("Graph");
          scanf("%s",s);
          scanf("%s",s);
        }
        else if (s[0]=='c')
          puts("sea blue");
      }
    }
  }
  return 0;
}