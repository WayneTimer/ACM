/*This Code is Submitted by Timer for Problem 2439 at 2013-03-13 19:53:27*/
// 水题。题意比较难理解
// 从一个string中，取出第i个字母和第i+D+1个字母凑成一对称为D-pairs
// 对于每个D，如果D-pairs都没有重复出现过，则称其为D-unique的
// 如果一个string的所有D-pairs都是D-unique的，则称其为surprising，否则是NOT surprising.
#include <cstdio>
#include <cstring>

bool f[26][26];
char a[82];

inline bool check(int x)
{
  int i;
  i=0;
  memset(f,false,sizeof(f));
  while (a[i+x])
  {
    if (f[a[i]-'A'][a[i+x]-'A']) return false;
    f[a[i]-'A'][a[i+x]-'A']=true;
    i++;
  }
  return true;
}

int main()
{
  int i;
  bool flag;
  scanf("%s",a);
  while (a[0]!='*')
  {
    flag=true;
    i=1;
    while (a[i])
    {
      if (!check(i))
      {
        flag=false;
        break;
      }
      i++;
    }
    printf("%s is ",a);
    if (flag) puts("surprising.");
    else puts("NOT surprising.");
    scanf("%s",a);
  }
  return 0;
}