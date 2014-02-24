/*This Code is Submitted by Timer for Problem 2014 at 2013-10-27 20:45:48*/
// HOJ 2014
// java大数
// f[0]=1,f[1]=1, f[i]=f[i-1]+2*f[i-2]
import java.util.*;
import java.math.*;

public class Main
{
  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    int i,n;
    BigInteger[] f=new BigInteger[251];
    BigInteger two=new BigInteger("2");
    BigInteger t;
    f[0]=new BigInteger("1");
    f[1]=new BigInteger("1");
    i=1;
    while (cin.hasNextInt())
    {
      n=cin.nextInt();
      while (n>i)
      {
        i++;
        t=two.multiply(f[i-2]);
        f[i]=t.add(f[i-1]);
      }
      System.out.println(f[n].toString());
    }
  }
};