/*This Code is Submitted by Timer for Problem 2589 at 2012-07-10 23:37:13*/
#include <cstdio>

using namespace std;

double v[5]={0,2.2046,0.4536,0.2642,3.7854};
char name[5][30]={"","lb","kg","g","l"};
int main()
{
    int t,p,op;
    double a,b;
    char e[30];
    scanf("%d",&t);
    for (p=1;p<=t;p++)
    {
        scanf("%lf",&a);
        getchar();
        gets(e);
        if (e[0]=='k')
        {
            op=1;
        }
        if (e[0]=='l')
          if (e[1]=='b')
            op=2;
          else op=3;
        if (e[0]=='g') op=4;
        b=a*v[op];
        printf("%d %.4lf %s\n",p,b,name[op]);
    }
    return 0;
}
 