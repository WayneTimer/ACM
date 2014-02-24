/*This Code is Submitted by Timer for Problem 1155 at 2012-04-28 10:13:20*/
#include <cstdio>

using namespace std;

int main()
{
    int n,m,s;
    while (scanf("%d%d",&n,&m)==2)
    {
        if (n<1) printf("0\n");
          else
          {
            n++;
            s=n/2;
            s--;
            m=m-s;
            if (m<=0) printf("0\n");
              else printf("%d\n",m);
          }
    }
    return 0;
}
 