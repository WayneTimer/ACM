/*This Code is Submitted by Timer for Problem 1011 at 2012-08-24 22:09:58*/
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct cyr
{
  char s[110];
  int l;
};

int n,mymax,k,m,t;
cyr a[110];

bool operator < (cyr q,cyr w)
{
  if (strcmp(q.s,w.s)<0) return true;
  return false;
}

int main()
{
  int i,j,u,p,kong;
  while (scanf("%d",&n)==1)
  {
    memset(a,0,sizeof(a));
    mymax^=mymax;
    for (i=1;i<=n;i++)
    {
      scanf("%s",a[i].s);
      a[i].l=strlen(a[i].s);
      if (a[i].l>mymax) mymax=a[i].l;
    }
    mymax+=2;
    sort(a+1,a+n+1);
    m=62/mymax;
    k=n/m;
    t=n%m;
    if (t>0) k++;
      else t=m;
    t=n/k;
    if (n%k>0) m=t+1;
      else m=t;
    printf("------------------------------------------------------------\n");
    for (i=1;i<=k;i++)
    {
      p^=p;
      j=i;
      while (p<m)
      {
        p++;
        printf("%s",a[j].s);
        if (i==k)
          if (p>=t) break;
        kong=mymax-a[j].l;
        j+=k;
        if (p>t) j--;
        if (j>n) break;
        if (p<m)
          for (u=1;u<=kong;u++)
            printf(" ");
      }
      printf("\n");
    }
  }
  return 0;
}