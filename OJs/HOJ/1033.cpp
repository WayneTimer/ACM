/*This Code is Submitted by Timer for Problem 1033 at 2012-08-15 11:37:08*/
#include <cstdio>
#include <cstring>

using namespace std;

int fa[26];
int in[26],out[26];
bool used[26];
int n;

int find(int x)
{
  if (fa[x]==x) return x;
  fa[x]=find(fa[x]);
  return fa[x];
}

int main()
{
  int T,i,t,y,tt,yy;
  char e[1010];
  scanf("%d",&T);
  while (T--)
  {
    scanf("%d",&n);
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    memset(used,false,sizeof(used));
    for (i=0;i<26;i++)
      fa[i]=i;
    for (i=1;i<=n;i++)
    {
      scanf("%s",e);
      t=e[0]-'a';
      in[t]++;
      used[t]=true;
      y=e[strlen(e)-1]-'a';
      out[y]++;
      used[y]=true;
      tt=find(t);
      yy=find(y);
      if (tt!=yy)
      {
        fa[yy]=fa[tt];
        fa[y]=fa[tt];
      }
    }
    t=0;
    y=0;
    tt=0;
    bool flag;
    flag=true;
    for (i=0;i<26;i++)
    {
      if (used[i])
      {
        if (fa[i]==i)
          t++;
        if (in[i]!=out[i])
        {
          if ((in[i]-out[i])==1)
            y++;
          else
          if ((out[i]-in[i])==1)
            tt++;
          else
          {
            flag=false;
            break;
          }
        }
      }
    }
    if ((t>1) || (!flag))
      printf("The door cannot be opened.\n");
    else
    if (t==1)
      if (((y==0)&&(tt==0)) || ((y==1)&&(tt==1)))
        printf("Ordering is possible.\n");
      else
        printf("The door cannot be opened.\n");
  }
  return 0;
}