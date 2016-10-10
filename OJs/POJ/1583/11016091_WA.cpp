//POJ 1583
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

char e[200];
char w[140];
int n,top;
int c[20000];
map <string,int> a;
string u[20000];
int mymax;

int main()
{
  int i,l,j;
  int t;
  string temp;
  n^=n;
  mymax^=mymax;
  memset(c,0,sizeof(c));
  while (gets(e))
  {
    l=strlen(e);
    i^=i;
    while (i<l)
    {
      while (!(isalpha(e[i]) || isdigit(e[i])))
        i++;
      j=i;
      t^=t;
      memset(w,0,sizeof(w));
      while (isalpha(e[j]) || isdigit(e[j]))
      {
	if (isupper(e[j]))
	  e[j]=tolower(e[j]);
        w[t]=e[j];
        t++;
        j++;
      }
      i=j;
      if (!w[0]) continue; 
      temp=w;
      if (a[temp]==0)
      {
        top++;
        a[temp]=top;
        u[top]=temp;
      }
      c[a[temp]]++;
      if (c[a[temp]]>mymax)
	mymax=c[a[temp]];
    }
  }
  l=0;
  for (i=1;i<=top;i++)
  {
    if (c[i]==mymax)
    {
      l++;
      u[l]=u[i];
    }
  }
  sort(u+1,u+1+l);
  printf("%d occurrences\n",mymax);
  for (i=1;i<=l;i++)
    cout<<u[i]<<endl;
  return 0;
}
