#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int n;
map <string,int> h;
string s[20];

inline void init()
{
  int i,j;
  h.clear();
  s[1]="{}";
  h[s[1]]=1;
  for (i=2;i<=16;i++)
  {
    s[i]="{{}";
    for (j=2;j<i;j++)
      s[i]=s[i]+","+s[j];
    s[i]=s[i]+"}";
    h[s[i]]=i;
  }
}

int main()
{
  string t;
  int x;
  scanf("%d",&n);
  getchar();
  init();
  while (n--)
  {
    cin>>t;
    x=h[t]-1;
    cin>>t;
    x=x+h[t]-1;
    cout<<s[x+1]<<endl;
  }
  return 0;
}
