/*This Code is Submitted by Timer for Problem 1160 at 2012-09-04 18:33:24*/
//HOJ 1160
import java.util.*;
import java.math.*;

public class Main
{
  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    double p,k,n;
    while (cin.hasNextDouble())
    {
      n=cin.nextDouble();
      p=cin.nextDouble();
      k=Math.pow(p,1/n);
      System.out.printf("%.0f\n",k);
    }
  }
}
 