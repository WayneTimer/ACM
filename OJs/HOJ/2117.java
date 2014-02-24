/*This Code is Submitted by Timer for Problem 2117 at 2013-02-23 15:33:59*/
//BigDecimal示例
import java.util.*;
import java.math.*;

public class Main
{
  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    BigDecimal a,b;
    String s;
    while (cin.hasNext())
    {
      s=cin.next();
      a=new BigDecimal(s);
      s=cin.next();
      b=new BigDecimal(s);
      a=a.divide(b,35,RoundingMode.DOWN);
      System.out.println(a.toString());
    }
  }
};