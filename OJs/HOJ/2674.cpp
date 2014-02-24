/*This Code is Submitted by Timer for Problem 2674 at 2012-08-26 20:57:03*/
//HOJ 2674
#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

struct cyr
{
  string name;
  int s;
  int t;
  int AC[12];
  int ACfa[12];
  bool done[12];
  int last[12];
};

map <string,int> h;
cyr a[52];
int n,m;

bool operator < (cyr q,cyr w)
{
  if (q.s>w.s) return true;
  if (q.s<w.s) return false;
  if (q.t<w.t) return true;
  if (q.t>w.t) return false;
  int i;
  for (i=q.s;i>=1;i--)
  {
    if (q.AC[q.last[i]]<w.AC[w.last[i]])
      return true;
    if (q.AC[q.last[i]]>w.AC[w.last[i]])
      return false;
  }
  for (i=q.s;i>=1;i--)
  {
    if (q.ACfa[q.last[i]]>w.ACfa[w.last[i]])
      return true;
    if (q.ACfa[q.last[i]]<w.ACfa[w.last[i]])
      return false;
  }
  if (q.name<w.name) return true;
  return false;
}

int check(cyr q,cyr w)
{
  if (q.s>w.s) return 1;
  if (q.s<w.s) return 0;
  if (q.t<w.t) return 1;
  if (q.t>w.t) return 0;
  int i;
  for (i=q.s;i>=1;i--)
  {
    if (q.AC[q.last[i]]<w.AC[w.last[i]])
      return 1;
    if (q.AC[q.last[i]]>w.AC[w.last[i]])
      return 0;
  }
  for (i=q.s;i>=1;i--)
  {
    if (q.ACfa[q.last[i]]<w.ACfa[w.last[i]])
      return 1;
    if (q.ACfa[q.last[i]]>w.ACfa[w.last[i]])
      return 0;
  }
  return -1;
}

int main()
{
  int T,rank,i,j,x,num;
  string temp;
  char op[30],result[30];
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d%d",&n,&m);
    h.clear();
    for (i=1;i<=n;i++)
    {
      cin>>a[i].name;
      h[a[i].name]=i;
      a[i].s^=a[i].s;
      a[i].t^=a[i].t;
      for (j=0;j<12;j++)
      {
        a[i].AC[j]=0;
        a[i].ACfa[j]=0;
        a[i].done[j]=false;
        a[i].last[j]=0;
      }
    }
    for (i=1;i<=m;i++)
    {
      scanf("%d",&x);
      cin>>temp;
      j=h[temp];
      scanf("%s %s",op,result);
      num=op[0]-'A'+1;
      if (a[j].done[num]) continue;
      if (result[0]=='a')
      {
        a[j].s++;
        a[j].AC[num]=x;
        a[j].ACfa[num]+=x;
        a[j].done[num]=true;
        a[j].last[a[j].s]=num;
        a[j].t+=a[j].ACfa[num];
        continue;
      }
      a[j].ACfa[num]+=20;
    }
    sort(a+1,a+n+1);
    /*
    for (i=2;i<=4;i++)
    {
      cout<<a[i].name<<endl;
      for (j=a[i].s;j>=1;j--)
      {
        printf("%d ",a[i].AC[a[i].last[j]]);
        printf("%d\n",a[i].ACfa[a[i].last[j]]);
      }
    }
    */
    printf("1 ");
    cout<<a[1].name;
    printf(" %d %d\n",a[1].s,a[1].t);
    rank=1;
    for (i=2;i<=n;i++)
    {
      if (check(a[i-1],a[i])!=-1)
        rank=i;
      printf("%d ",rank);
      cout<<a[i].name;
      printf(" %d %d\n",a[i].s,a[i].t);
    }
  }
  return 0;
}
 