/*This Code is Submitted by Timer for Problem 2981 at 2012-08-06 13:38:26*/
#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  char v;
  int l;
  int r;
  int cnt;
};

const int maxword=100100;
cyr a[maxword];
int max,n,tail;
char e[100001];
char ans[100001];
bool flag;

void insert(char *str)
{
  int p,i;
  p=1;
  i=0;
  while (str[i])
  {
    if (a[p].l==0)
    {
      tail++;
      a[tail].v=str[i];
      a[tail].cnt++;
      a[p].l=tail;
      p=tail;
    }
    else
    {
      p=a[p].l;
      while ((a[p].v!=str[i]) && (a[p].r!=0))
        p=a[p].r;
      if (a[p].v!=str[i])
      {
        tail++;
        a[tail].v=str[i];
        a[tail].cnt++;
        a[p].r=tail;
        p=tail;
      }
      else
        a[p].cnt++;
    }
    i++;
  }
}

void DFS(int dep,int p)
{
  if ((dep>=max) && (a[p].cnt>1))
  {
    if (flag)
    {  
      strcpy(ans,e);
      flag=false;
    }
    else
    if (dep>max)
      strcpy(ans,e);
    else
      if (strcmp(e,ans)<0)
        strcpy(ans,e);
    max=dep;
  }
  if (a[p].l!=0)
    {
      e[dep]=a[a[p].l].v;
      DFS(dep+1,a[p].l);
      e[dep]='\0';
    }
  if (a[p].r!=0)
    if (a[a[p].r].cnt>1)
    {
      e[dep-1]=a[a[p].r].v;
      e[dep]='\0';
      DFS(dep,a[p].r);
      e[dep-1]='\0';
    }
}

int main()
{
  int T;
  scanf("%d",&n);
  T=0;
  while (n)
  {
    getchar();
    memset(a,0,sizeof(a));
    tail=1;
    while (n--)
    {
      gets(e);
      insert(e);
    }
    memset(e,0,sizeof(e));
    memset(ans,0,sizeof(ans));
    max=0;
    flag=true;
    DFS(0,1);
    T++;
    printf("Case %d: %d\n",T,max);
    printf("%s\n",ans);
    scanf("%d",&n);
  }
  return 0;
}