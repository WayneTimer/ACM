/*This Code is Submitted by Timer for Problem 3090 at 2012-04-18 13:15:48*/
import java.util.*;
import java.math.*;

public class Main
{
  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    String x=new String();
    while (cin.hasNext())
    {
    x=cin.next();
    BigInteger a=new BigInteger(x);
    x=cin.next();
    BigInteger b=new BigInteger(x);
    x=cin.next();
    BigInteger p=new BigInteger(x);
    BigInteger c=a.multiply(b);
    a=c.mod(p); 
    System.out.println(a.toString());
    }
  }
}