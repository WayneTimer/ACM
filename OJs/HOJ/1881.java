/*This Code is Submitted by Timer for Problem 1881 at 2012-04-30 13:07:24*/
import java.util.*;
import java.math.*;

public class Main
{
  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    BigInteger b=new BigInteger("10");
    BigInteger c=new BigInteger("1");
    BigInteger s=new BigInteger("1");
    BigInteger m=new BigInteger("1");
    BigInteger lin=new BigInteger("0");
    int i=0;
    int n=0;
    int flag=1;
    while (cin.hasNextInt())
    {
      n=cin.nextInt();
      m=BigInteger.valueOf(n);
      BigInteger a=new BigInteger("1");
      flag=1;
      i=1;
      while (flag==1)
      { 
        i++;
        a=a.multiply(b);
        a=a.add(c);
        s=a.mod(m);
        if (s.compareTo(lin)==0) flag=0;
      }
      System.out.println(i);
    }
  }
};