/*This Code is Submitted by Timer for Problem 1168 at 2012-11-18 22:11:33*/
#include <cstdio>
#include <cstring>

char e[60000];
int a[60000];
int n,s,x;
bool flag;
int q[60000];

void insert(int p,int now)
{
  if (e[p]==')')
  {
    a[now]=x;
    return;
  }
  if (e[p]=='L') 
    insert(p+1,now<<1);
  else if (e[p]=='R')
    insert(p+1,now<<1|1);
}

inline void work()
{
  if (e[1]==',') return;
  sscanf(e,"(%d",&x);
  int i;
  i^=i;
  while (e[i]!=',') i++;
  insert(i+1,1);
  return;
}

void check(int now)
{
  if (a[now]==-1) return;
  s++;
  check(now<<1);
  check(now<<1|1);
}

inline void output()
{
  int head,tail;
  printf("%d",a[1]);
  q[1]=1;
  head^=head;
  tail=1;
  do
  {
    head++;
    if (head!=1)
      printf(" %d",a[q[head]]);
    if (a[q[head]<<1]!=-1)
    {
      tail++;
      q[tail]=q[head]<<1;
    }
    if (a[q[head]<<1|1]!=-1)
    {
      tail++;
      q[tail]=q[head]<<1|1;
    }
  } while (head<tail);
  printf("\n");
}

int main()
{
  while (scanf("%s",e)==1)
  {
    memset(a,-1,sizeof(a));
    n^=n;
    s^=s;
    flag=true;
    while (e[1]!=')')
    {
      n++;
      work();
      scanf("%s",e);
    }
    check(1);
    if (flag && s==n && n!=0)
      output();
    else
      puts("not complete");
  }
  return 0;
}
 