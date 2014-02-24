/*This Code is Submitted by Timer for Problem 2196 at 2012-02-20 20:01:36*/
#include <cstdio>
#include <cstring>

using namespace std;

struct job
{
  int time;
  double money;
} job[510];
struct income
{
  int time;
  double money;
} income[2100];

int main(void)
{
  int c,a,n,i,j,t,judge;
  double temp;
  scanf("%d",&c);
  for(a = 1;a <= c;a++)
  {
    scanf("%d",&n);
    for (i = 1;i <= n;i++)
      scanf("%d%lf",&job[i].time,&job[i].money);
      scanf("%d",&t);
      memset(income,0,sizeof(income));
      for (i = 1;i <= n;i++)
        for (j = t;j >= 1;j--)
        {
          judge = 0;
          if (j >= job[i].time)
          {
            temp = income[j - job[i].time].money + job[i].money;
            if(temp > income[j].money)
            {
              income[j].money = temp;
              judge = 1;
            }
          }
          if (judge)
            income[j].time = income[j - job[i].time].time + job[i].time;
        }
    printf("Problem %d: %d seconds scheduled for $%.2lf\n",a,income[t].time,income[t].money);
  }
  return 0;
}