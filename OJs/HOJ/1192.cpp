/*This Code is Submitted by Timer for Problem 1192 at 2012-07-27 15:20:07*/
#include <cstdio>
#include <cstring>

using namespace std;

int way[12]={0,5,10,20,50,100,200,500,1000,2000,5000,10000};
int a;
long long f[30010];

void cyr()
{
  long long sum;
  int i,j;
  for(i=1;i<=11;i++)
  for(j=way[i];j<=30000;j+=5)
     f[j]+=f[j-way[i]];
}

int main()
{
  int x,y;
  long long s;
  double t;
  scanf("%d.%d",&x,&y);
  a=x*100+y;
  memset(f,0,sizeof(f));
  f[0]=1;
  cyr();
  while (a!=0)
  {
    s=f[a];
    t=a/100.0;
    printf("%6.2lf%17lld\n",t,s);
    scanf("%d.%d",&x,&y);
    a=x*100+y;
  }
  return 0;
}