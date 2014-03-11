#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;

ll f[2][102][1<<18]; //f[滚动数组][余数][选取情况的状态]
int m,n,u; //u是选取情况状态数
int mask[270000]; //选取状态
bool used[270000]; //表示某状态是否在之前出现过
int b[20]; //选取第i个的所有状态在mask[]中起始位置
int c[20]; //选取第i个的所有状态在mask[]中终止位置
int a[20]; //记录排序后各数位

int main()
{
  int i,j,k,t,tmp,last;
  int q,w;
  char s[22];
  memset(f,0,sizeof(f));
  memset(mask,0,sizeof(mask));
  memset(used,false,sizeof(used));
  scanf("%s %d",s,&m);
  n=strlen(s);
  for (i=0;i<n;i++)
    a[i]=s[i]-'0';
  sort(a,a+n);
  u=1;
  b[0]=1;
  c[0]=1;
  q=1;
  w=0;
  f[0][0][0]=1;
  for (i=1;i<=n;i++)
  {
    q^=w;
    w^=q;
    q^=w;
    for (k=b[i-1];k<=c[i-1];k++)
    {
      last=-1;
      for (j=0;j<n;j++)
      {
        if (a[j]==last) continue; //选取相同的数状态一样，不重复计算
        if (i==1 && a[j]==0) continue; //首位不为0
        if (!(mask[k] & (1<<j)))
        {
          int r;
          r=mask[k] | (1<<j);
          if (!used[r])
          {
            mask[++u]=r;
            used[r]=true;
          }
          for (t=0;t<m;t++)
            if (f[q][t][mask[k]])
            {
              tmp=(t*10+a[j])%m;
              f[w][tmp][r]+=f[q][t][mask[k]];
            }
          last=a[j];
        }
      }
    }
    b[i]=c[i-1]+1;
    c[i]=u;
  }
  printf("%I64d\n",f[w][0][(1<<n)-1]);
  return 0;
}
