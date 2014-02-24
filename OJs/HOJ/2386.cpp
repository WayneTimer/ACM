/*This Code is Submitted by Timer for Problem 2386 at 2013-02-04 01:38:05*/
//找有多少个全排列子序列，ans=全排列子序列数+1
//因为只要存在全排列子序列，则其中肯定存在1~k中所有数，
//那么，最后那个不是全排列的子序列中选取一个不存在的数即可满足要求
#include <cstdio>
#include <cstring>

#define MAXK 10001

int n,k;
bool a[MAXK];

int main()
{
  int s,x,ans;
  while (scanf("%d%d",&n,&k)==2)
  {
    memset(a+1,false,sizeof(bool)*k);
    s^=s;
    ans^=ans;
    while (n--)
    {
      scanf("%d",&x);
      if (!a[x]) 
      {
        s++;
        a[x]=true;
        if (s>=k) 
        {
          ans++;
          s^=s;
          memset(a+1,false,sizeof(bool)*k);
        }
      }
    }
    printf("%d\n",ans+1);
  }
  return 0;
}