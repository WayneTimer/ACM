#include <cstdio>
#include <cstring>
#include <cmath>

#define MAXN 500

struct cyr
{
  int x1,y1,x2,y2;
  int time;
};

int link[MAXN];
bool map[MAXN][MAXN];
bool cover[MAXN];
char str[50];
cyr p[MAXN];
int n;

inline int caltime()
{
  int t;
  t=(str[0]-'0')*10+str[1]-'0';
  t*=60;
  t=t+(str[3]-'0')*10+str[4]-'0';
  return t;
}

inline int work(cyr q,cyr w)
{
  int t;
  t=fabs(q.x1-q.x2)+fabs(q.y1-q.y2);
  t=t+fabs(q.x2-w.x1)+fabs(q.y2-w.y1);
  return t;
}

bool find(int i)
{
  int k,q;
  for (k=1;k<=n;k++)
    if (map[i][k] && !(cover[k]))
    {
      q=link[k];
      link[k]=i;
      cover[k]=true;
      if (q==0 || find(q)) return true;
      link[k]=q;
    }
  return false;
}

int main()
{
  int T;
  int i,s,j,temp;
  scanf("%d",&T);
  while (T--)
  {
    memset(link,0,sizeof(link));
    memset(map,false,sizeof(map));
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
      scanf("%s",str);
      p[i].time=caltime();
      scanf("%d%d%d%d",&p[i].x1,&p[i].y1,&p[i].x2,&p[i].y2);
    }
    for (i=1;i<n;i++)
      for (j=i+1;j<=n;j++)
      {
	temp=p[i].time+work(p[i],p[j]);
	if (temp<p[j].time) //由第二个样例可知，相等也不行
	  map[i][j]=true;
      }
    for (i=1;i<=n;i++)
    {
      memset(cover,false,sizeof(cover));
      find(i);
    }
    s^=s;
    for (i=1;i<=n;i++)
      if (link[i]) s++;
    printf("%d\n",n-s);
  }
  return 0;
}
