/*This Code is Submitted by Timer for Problem 1013 at 2012-09-09 22:58:41*/
//HOJ 1013
import java.util.*;
import java.math.*;

public class Main
{
  static BigInteger five=new BigInteger("5");
  static BigInteger one=new BigInteger("1");
  static BigInteger ten=new BigInteger("10");
  static BigInteger zero=new BigInteger("0");
  static BigInteger four=new BigInteger("4");
  static BigInteger two=new BigInteger("2");

  public static long cyr(BigInteger n)
  {
    long g;
    BigInteger temp;
    BigInteger sum=new BigInteger("1");
    temp=n.mod(five);
    g=temp.longValue();
    temp=n;
    while (g>0)
    {
      sum=sum.multiply(temp);
      temp=temp.subtract(one);
      g--;
    }
    temp=sum.mod(ten);
    while (temp.compareTo(zero)==0)
    {
      sum=sum.divide(ten);
      temp=sum.mod(ten);
    }
    g=temp.longValue();
    temp=n.divide(five);
    if (temp.compareTo(zero)==0) return g;
    BigInteger check;
    check=temp.mod(four);
    if (check.compareTo(one)==0) return ((g*2*cyr(temp))%10);
    if (check.compareTo(two)==0) return ((g*4*cyr(temp))%10);
    if (check.compareTo(zero)==0) return ((g*6*cyr(temp))%10);
      else return ((g*8*cyr(temp))%10);
  }

  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    BigInteger x=new BigInteger("0");
    String e;
    long ans;
    while (cin.hasNextLine())
    {
      e=cin.nextLine();
      x=new BigInteger(e);
      ans=cyr(x);
      System.out.println(ans);
    }
  }
}
 