/*This Code is Submitted by Timer for Problem 2718 at 2012-05-01 23:33:30*/
import java.util.*;
import java.math.*;

public class Main
{
  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    BigInteger a=new BigInteger("1");
    BigInteger b=new BigInteger("1");
    BigInteger c=new BigInteger("1");
    BigInteger p=new BigInteger("10");
    int[] v=new int[50];
    int[] w=new int[11];
    int n=0;
    int i=0;
    int j=0;
    int t=0;
    n=cin.nextInt();
    for (i=1;i<=n;i++)
    {
      a=cin.nextBigInteger();
      b=cin.nextBigInteger();
      a=a.mod(p);
      v[1]=a.intValue();
      for (j=0;j<=9;j++)
        w[j]=0;
      w[v[1]]=1;
      j=1;
      t=(v[1]*v[1])%10;
      while (w[t]!=1)
      {
        j++;
        v[j]=t;
        w[t]=1;
        t=(t*v[1])%10;
      }
      c=BigInteger.valueOf(j);
      a=b.mod(c);
      t=a.intValue();
      if (t==0) t=j;
      System.out.println(v[t]);
    }
  }
};