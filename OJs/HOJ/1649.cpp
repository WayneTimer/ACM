/*This Code is Submitted by Timer for Problem 1649 at 2012-03-15 23:28:47*/
#include <cstdio>
#include <cstring>

#define MAX 5000001

using namespace std;

unsigned short a[MAX];
unsigned short b[MAX];
long n;

int main()
{
  long j,i,x;
  bool f;
  memset(a,0,sizeof(a));
  memset(b,0,sizeof(b));
  a[1]=1;
  a[2]=2;
  a[3]=1;
  x=4;
  j=0;
  f=true;
  for (i=4;i<MAX;i++)
  {
    if (f) j++;
      else j--;
    if (j>x) 
    {
      x=x+2;
      j=j-2;
      f=false;
    }
    if (j<1)
    {
      j=1;
      f=true;
    }
    a[i]=j;
  }
  b[1]=1;
  x=3;
  j=0;
  f=true;
  for (i=2;i<MAX;i++)
  {
    if (f) j++;
      else j--;
    if (j>x)
    {
      x=x+2;
      j=j-2;
      f=false; 
    }
    if (j<1)
    {
      j=1;
      f=true;
    }
    b[i]=j;
  }
  while (scanf("%ld",&n)==1)
  {
    printf("TERM %ld IS %d/%d\n",n,b[n],a[n]);
  }
  return 0;
}