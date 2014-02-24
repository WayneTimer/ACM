/*This Code is Submitted by Timer for Problem 1452 at 2012-09-20 21:08:59*/
#include <cstdio>
#include <cstring>

char a[30],b[30];

int cyr(int x,int l,int r)
{
  if (l>r) return x-1;
  int i,t;
  i=l;
  while (i<=r && a[x]!=b[i]) i++;
  t=cyr(x+1,l,i-1);
  t=cyr(t+1,i+1,r);
  putchar(a[x]);
  return t;
}

int main()
{
  while (scanf("%s %s",a,b)==2)
  {
    cyr(0,0,strlen(b)-1);
    puts("");
  }
  return 0;
}