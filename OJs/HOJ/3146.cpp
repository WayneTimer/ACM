/*This Code is Submitted by Timer for Problem 3146 at 2013-06-02 09:42:51*/
#include <cstdio>
#include <cstring>

char a[8];

inline int work()
{
  if (strcmp(a,"I")==0) return 1;
  if (strcmp(a,"II")==0) return 2;
  if (strcmp(a,"III")==0) return 3;
  if (strcmp(a,"IV")==0) return 4;
  if (strcmp(a,"V")==0) return 5;
  if (strcmp(a,"VI")==0) return 6;
  if (strcmp(a,"VII")==0) return 7;
  if (strcmp(a,"VIII")==0) return 8;
  if (strcmp(a,"IX")==0) return 9;
  if (strcmp(a,"X")==0) return 10;
  if (strcmp(a,"XI")==0) return 11;
  if (strcmp(a,"XII")==0) return 12;
}

int main()
{
  int i;
  i=0;
  while (scanf("%s",a)==1)
  {
    i++;
    printf("Case %d: %d\n",i,work());
  }
  return 0;
}