#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

struct cyr
{
  char s[62];
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
  int i,j,u,p;
  while (scanf("%d",&n)==1)
  {
    mymax^=mymax;
    for (i=1;i<=n;i++)
    {
      scanf("%s",a[i].s);
      a[i].l=strlen(a[i].s);
      if (a[i].l>mymax) mymax=a[i].l;
    }
    mymax+=2;
    sort(a+1,a+n+1);
    m=(60-mymax+2)/mymax;
    m++;
    k=n/m;
    t=n%m;
    if (t>0) k++;
      else t=m;
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
        if (p<m)
          for (u=1;u<=mymax-a[j].l;u++)
            printf(" ");
        j+=k;
        if (p>t) j--;
      }
      printf("\n");
    }
  }
  return 0;
}