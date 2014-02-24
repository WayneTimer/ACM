/*This Code is Submitted by Timer for Problem 3145 at 2013-04-14 20:18:30*/
/*
1、O(n)
2、内存限制在8M，a[]在int范围内，s在long long范围内
3、输入的a[]在-2~31+1~2^31(正常是在-2^31~2^31-1内)，就是输入时是longlong，再-1存入int数组a[]中
4、有正有负
5、单个的a[i]==s是不行的
6、2<=n<=1000000，-2^63<=s<=2^63-1
*/

#include <cstdio>

#define MAXN 1000000

int a[MAXN];
long long s;
int n;

int main()
{
  int l,r,i;
  long long t;
  bool flag;
  //freopen("a.txt","r",stdin);
  //freopen("aout.txt","w+",stdout);
  while (scanf("%d%lld",&n,&s)==2)
  {
    s-=2;
    for (i=0;i<n;i++)
    {
      scanf("%lld",&t);
      t--;
      a[i]=t;
    }
    l=0;
    r=n-1;
    flag=false;
    while (l<r)
    {
      t=a[l];
      t+=a[r];
      if (t==s)
      {
        flag=true;
        break;
      }
      if (t<s) l++;
      else r--;
    }
    if (flag) puts("Timer is everywhere.");
    else puts("Timer is dominating.");
  }
  return 0;
}