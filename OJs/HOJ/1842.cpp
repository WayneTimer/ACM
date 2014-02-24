/*This Code is Submitted by Timer for Problem 1842 at 2011-11-24 00:55:25*/
#include <stdio.h>



long mod(long a,long b,long c)

{

    long long result;

    int x[100000];

    int i,j;

    result=1;

    i=0;

    while(b)

    {

      x[i]=b%2;

      i++;

      b=b/2;

    }

    for(j=i-1;j>=0;j--)

    {

      result=(result*result)%c;

      if(x[j]==1)

      {

        result=(result*a)%c;

      }

    }

    return result;

}



int main()

{

    long n,m,t,o,p,u,q;

    long sum;

    scanf("%d",&o);

    for (p=1;p<=o;p++)

    {

        scanf("%ld",&t);

        scanf("%ld",&u);

        sum=0;

        for (q=1;q<=u;q++)

        {

            scanf("%ld%ld",&n,&m);

            sum=(sum+mod(n,m,t))%t;

        }

        printf("%ld\n",sum);

    }

    return 0;

}