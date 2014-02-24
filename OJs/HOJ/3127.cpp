/*This Code is Submitted by Timer for Problem 3127 at 2013-03-03 01:15:27*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct cyr
{
  int v,p;
};

char s[110][55];
int a[4];
int n,m;
cyr b[110];

bool operator < (cyr q,cyr w)
{
  if (q.v<w.v) return true;
  if (q.v>w.v) return false;
  if (q.p<w.p) return true;
  return false;
}

int main()
{
  int i,j,t;
  while (scanf("%d%d",&n,&m)==2)
  {
    for (i=1;i<=m;i++)
    {
      scanf("%s",s[i]);
      memset(a,0,sizeof(a));
      t^=t;
      for (j=0;j<n;j++)
      {
        if (s[i][j]=='A')
          t+=a[1]+a[2]+a[3];
        else if (s[i][j]=='C')
        {
          t+=a[2]+a[3];
          a[1]++;
        } 
        else if (s[i][j]=='G')
        {
          t+=a[3];
          a[2]++;
        }
        else 
          a[3]++;
      }
      b[i].v=t;
      b[i].p=i;
    }
    sort(b+1,b+1+m);
    for (i=1;i<=m;i++)
      printf("%s\n",s[b[i].p]);
    puts("");
  }
  return 0;
}