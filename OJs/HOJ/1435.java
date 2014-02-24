/*This Code is Submitted by Timer for Problem 1435 at 2013-04-25 21:06:33*/
//HOJ 1435
import java.util.*;
import java.math.*;

public class Main
{
  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    BigInteger a=new BigInteger("0");
    BigInteger b;
    do
    {
      b=cin.nextBigInteger();
      if (b.equals(BigInteger.ZERO)) break;
      a=a.add(b);
    } while (true);
    System.out.println(a.toString());
  }
};