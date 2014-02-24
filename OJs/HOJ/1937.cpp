/*This Code is Submitted by Timer for Problem 1937 at 2012-03-04 14:42:00*/
#include <cstdio>
#include <cstring>
#define MAX 1000001
#define MM 26200000

using namespace std;

long a[MAX];
bool cyr[10];
bool p[MM];

bool check(long x)
{
  long t,r,xx;
  xx=x;
  memset(cyr,false,sizeof(cyr));
  t=x%10;
  cyr[t]=true;
  x=x/10;
  while (x>0)
  {
    if (p[x]) return true;
    r=x%10;
    if (cyr[r]) 
    {
      p[xx]=true;
      return true;
    }
      else cyr[r]=true;
    x=x/10;
  }
  return false;
}

int main()
{
  long i,n,s;
  memset(a,0,sizeof(a));
  a[1]=1;
  a[2]=2;
  a[3]=3;
  a[4]=4;
  a[5]=5;
  a[6]=6;
  a[7]=7;
  a[8]=8;
  a[9]=9;
  a[10]=10;
  s=10;
  i=10;
  memset(p,false,sizeof(p));
  while (s<MAX)
  {
    i++;
    if (!check(i))
    {
      s++;
      a[s]=i;
    }
  }
  scanf("%ld",&n);
  while (n!=0)
  {
    printf("%ld\n",a[n]);
    scanf("%ld",&n);
  }
  return 0;
}