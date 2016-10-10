#include <cstdio>

using namespace std;

int main()
{
  int s,n;
  bool flag;
  while (scanf("%d",&n)==1)
  {
    flag=true;
    s=1;
    while (s<n)
    {
      if (flag) s=s*9;
        else s=s<<1;
      flag=!flag;
    }
    if (!flag) printf("Stan wins.\n");
      else printf("Ollie wins.\n");
  }
  return 0;
}