/*This Code is Submitted by Timer for Problem 2462 at 2012-07-10 21:39:08*/
#include <cstdio>
#include <cstring>

using namespace std;

bool ch[300];

int main()
{
  int i,l;
  bool flag;
  char e[1000];
  memset(ch,false,sizeof(ch));
  ch['a']=true;
  ch['e']=true;
  ch['i']=true;
  ch['o']=true;
  ch['u']=true;
  while (gets(e))
  {
    flag=true;
    if (strcmp(e,"end")==0) break;
    l=strlen(e);
    if (!ch[e[0]]) flag=false;
    for (i=1;i<l;i++)
    {
      if (ch[e[i]]) flag=true;
      if (e[i-1]==e[i])
        if (!((e[i]=='e')||(e[i]=='o')))
        {
          flag=false;
          break;
        }
      if (i>=2)
      {
        if ((ch[e[i-2]]) && (ch[e[i-1]]) && (ch[e[i]]))
        {
          flag=false;
          break;
        }
        if ((ch[e[i-2]]==false) && (ch[e[i-1]]==false) && (ch[e[i]]==false))
        {
          flag=false;
          break;
        }
      }
    }
    printf("<%s> is ",e);
    if (!flag) printf("not ");
    printf("acceptable.\n");
  }
  return 0;
}