/*This Code is Submitted by Timer for Problem 1368 at 2013-03-08 11:27:34*/
// HOJ 1368 java_BigInteger && java_BigDecimal
import java.util.*;
import java.math.*;

public class Main
{
  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    String str,op;
    while (cin.hasNext())
    {
      str=cin.next();
      op=cin.next();
      char e=op.charAt(0);
      if (e=='/')
      {
        BigDecimal a=new BigDecimal(str);
        BigInteger c=new BigInteger(str);
        str=cin.next();
        BigDecimal b=new BigDecimal(str);
        BigInteger d=new BigInteger(str);
        BigInteger ans;
        ans=c.divide(d);
        c=c.mod(d);
        int t=cin.nextInt();
        a=a.divide(b,t,RoundingMode.HALF_UP);
        System.out.println(ans.toString()+" "+c.toString()+" "+a.toPlainString());
      }
      else
      {
        BigInteger a=new BigInteger(str);
        str=cin.next();
        BigInteger b=new BigInteger(str);
        if (e=='+')
          a=a.add(b);
        else if (e=='-')
          a=a.subtract(b);
        else if (e=='*')
          a=a.multiply(b);
        System.out.println(a.toString());
      }
    }
  }
};