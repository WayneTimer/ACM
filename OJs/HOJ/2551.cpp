/*This Code is Submitted by Timer for Problem 2551 at 2012-07-25 17:39:05*/
#include <cstdio>
#include <cstring>
#include <map>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

short times[4097];
string name[4097],temp;
short pages,all,uu;
map <string,set<string> > word;
map <string,int> lin;
bool flag;

bool comp(int ee,int rr)
{
  if (times[ee]==times[rr])
    return (name[ee]<name[rr]);
  return (times[ee]>times[rr]);
}

int main()
{
  string x;
  char y[110];
  int u,i;
  flag=false;
  all=0;
  while (scanf("%s",y)==1)
  {
    word.clear();
    x=y;
    if (flag) printf("\n");
    printf("<case>\n");
    pages=0;
    memset(times,0,sizeof(times));
    lin.clear();
    scanf("%s",y);
    x=y;
    while (x!="<query>")
    {
      scanf("%s",y);
      scanf("%s",y);
      temp=y;
      if (lin[temp]==0)
      {
        pages++;
        name[pages]=temp;
        lin[temp]=pages;
      }
      uu=lin[temp];
      scanf("%s",y);
      scanf("%s",y);
      scanf("%s",y);
      x=y;
      while (x!="</text>")
      {
        word[x].insert(temp);
        scanf("%s",y);
        x=y;
      }
      scanf("%s",y);
      scanf("%s",y);
      x=y;
      while (x!="</link>")
      {
        if (lin[x]==0)
        {
          pages++;
          lin[x]=pages;
          name[pages]=x;
        }
        u=lin[x];
        times[u]++;
        scanf("%s",y);
        x=y;
      }
      scanf("%s",y);
      scanf("%s",y);
      x=y;
    }
    scanf("%s",y);
    x=y;
    while (x!="</query>")
    {
      int t;
      short a[4097];
      printf("  <reply query=\"%s\">\n",x.c_str());
      //cout<<"  <reply query=\""<<x<<"\">"<<endl;
      if (word[x].empty())
        printf("    Sorry, not found...\n");
      else
      {
        set <string>::iterator it;
        t=-1;
        for (it=word[x].begin();it!=word[x].end();it++)
        {
          t++;
          a[t]=lin[*it];
        }
        sort(a,a+t+1,comp);
        for (i=0;i<=t;i++)
          printf("    %s\n",name[a[i]].c_str());
      }
      printf("  </reply>\n");
      scanf("%s",y);
      x=y;
    }
    scanf("%s",y);
    x=y;
    flag=true;
    printf("</case>\n");
  }
  return 0;
}