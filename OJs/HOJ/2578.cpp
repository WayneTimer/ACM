/*This Code is Submitted by Timer for Problem 2578 at 2012-07-24 10:46:42*/
#include <cstdio>
#include <vector>

using namespace std;

struct cyr
{
  int mmin;
  int mmax;
};

int n;
vector <cyr> q;

int main()
{
  char a[12];
  cyr temp;
  int x,T,i;
  scanf("%d",&n);
  T=0;
  while (n!=0)
  {
    T++;
    q.clear();
    printf("Case %d\n",T);
    while (n--)
    {
      scanf("%s",a);
      if (a[1]=='u')
      {
        scanf("%d",&x);
        if (q.size()>0)
        {
        if (x>q.back().mmax)
          temp.mmax=x;
        else temp.mmax=q.back().mmax;
        if (x<q.back().mmin)
          temp.mmin=x;
        else temp.mmin=q.back().mmin;
        q.push_back(temp);
        }
        else
        {
          temp.mmax=x;
          temp.mmin=x;
          q.push_back(temp);
        }
      }
      if (a[1]=='o')
      {
        if (q.size()>0)
          q.pop_back();
      }
      if (a[1]=='a')
      {
        if (q.size()<=0) printf("null\n");
        else 
          printf("%d\n",q.back().mmax);
      }
      if (a[1]=='i')
      {
        if (q.size()<=0) printf("null\n");
        else
          printf("%d\n",q.back().mmin);
      }
    }
    scanf("%d",&n);
  }
  return 0;
}