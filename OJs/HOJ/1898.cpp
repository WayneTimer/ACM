/*This Code is Submitted by Timer for Problem 1898 at 2012-07-31 14:18:52*/
#include <cstdio>
#include <cstring>

using namespace std;

struct cyr
{
  int v;
  bool isword;
  cyr *next[26];
  cyr()
  {
    v=0;
    isword=false;
    memset(next,0,sizeof(next));
  }
};

cyr *root;
char Eng[100010][15];
int n;
char x[15],y[15];

void insert(char *str)
{
  int i,t;
  cyr *ptr=root;
  for (i=0;str[i];i++)
  {
    t=str[i]-'a';
    if (ptr->next[t]==NULL)
      ptr->next[t]=new cyr;
    ptr=ptr->next[t];
  }
  ptr->v=n;
  ptr->isword=true;
}

int find(char *str)
{
  int i,t;
  cyr *ptr=root;
  for (i=0;str[i];i++)
  {
    t=str[i]-'a';
    if (ptr->next[t]==NULL) return -1;
    ptr=ptr->next[t];
  }
  if (ptr->isword)
    return ptr->v;
  else return -1;
}

int main()
{
  char e[30];
  int t;
  gets(e);
  root=new cyr;
  n=0;
  while (sscanf(e,"%s%s",x,y)==2)
  {
    n++;
    strcpy(Eng[n],x);
    insert(y);
    gets(e);
  }
  while (gets(e))
  {
    t=find(e);
    if (t>0) printf("%s\n",Eng[t]);
      else printf("eh\n");
  }
  return 0;
}