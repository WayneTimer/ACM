/*This Code is Submitted by Timer for Problem 1477 at 2012-03-14 23:53:09*/
#include <cstdio>
#include <cstring>

using namespace std;

char e1[100010],e2[100010];
long l1,l2;

int main()
{
  long i,j;
  while (scanf("%s %s",e1,e2)==2)
  {
    l1=strlen(e1);
    l2=strlen(e2);
    i=0;
    j=0;
    while (!((i>=l1)||(j>=l2)))
    {
      if (e1[i]==e2[j])
      {
        i++;
      }
      j++;
    }
    if (i>=l1) printf("Yes\n");
      else printf("No\n");
  }
  return 0;
}