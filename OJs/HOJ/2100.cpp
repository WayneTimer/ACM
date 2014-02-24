/*This Code is Submitted by Timer for Problem 2100 at 2012-04-18 12:46:17*/
#include <stdio.h>

int n;

void sub()
{
    long a,b,he,cha;
    int f;
    scanf("%ld %ld",&he,&cha);
    f=1;
    if (he<cha) f=0;
      else
      {
          a=he+cha;
          if ((a%2)!=0) f=0;
            else
            {
                a=a/2;
                b=he-a;
                if (a>=b) printf("%ld %ld\n",a,b);
                  else printf("%ld %ld\n",b,a);
            }
      }
    if (f==0) printf("impossible\n");
}

int main()
{
    int o;
    scanf("%d",&n);
    for (o=1;o<=n;o++)
      sub();
    return 0;
}