#include <cstdio>
#include <cstring>

using namespace std;

int n,m,s;
int t[10];
bool map[310][310];
int link[310];
bool cover[310];

bool find(int i,int u)
{
  int k,q;
  for (k=1;k<=u;k++)
    if ((map[i][k])&&(!(cover[k])))
    {
      q=link[k];
      link[k]=i;
      cover[k]=true;
      if ((q==0)||(find(q,u))) return true;
      link[k]=q;
    }
  return false;
}

inline int cyr(char e)
{
  if (e=='S') return 1;
  if (e=='M') return 2;
  if (e=='L') return 3;
  if (e=='X') return 4;
  if (e=='T') return 5;
}

int main()
{
  char str[110];
  int i,l,q,w,u,j;
  t[0]=0;
  scanf("%s",str);
  while (strlen(str)!=10)
  {
    memset(map,false,sizeof(map));
    memset(link,0,sizeof(link));
    scanf("%d",&n);
    getchar();
    gets(str);
    for (i=1;i<=5;i++)
    {
      scanf("%d",&t[i]);
      t[i]=t[i]+t[i-1];
    }
    getchar();
    i=0;
    u=0;
    l=strlen(str);
    while (i<l)
    {
      u++;
      q=cyr(str[i]);
      w=cyr(str[i+1]);
      i=i+3;
      for (j=t[q-1]+1;j<=t[w];j++)
        map[u][j]=true;
    }
    m=t[5];
    if (m<n)
      printf("I'd rather not wear a shirt anyway...\n");
    else
    {
    for (i=1;i<=n;i++)
    {
      memset(cover,false,sizeof(cover));
      find(i,m);
    }
    s=0;
    for (i=1;i<=m;i++)
      if (link[i]!=0) s++;
    if (s>=n) 
      printf("T-shirts rock!\n");
    else
      printf("I'd rather not wear a shirt anyway...\n");
    }
    gets(str);
    scanf("%s",str);
  }
  return 0;
}