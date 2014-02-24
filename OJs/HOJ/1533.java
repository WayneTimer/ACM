/*This Code is Submitted by Timer for Problem 1533 at 2012-01-28 14:50:41*/
//HOJ 1533
import java.util.*;
import java.math.*;

public class Main
{
  public static void main(String[] args)
  {
    int i=1;
    int n=1;
    int x=1;
    int j=1;
    int t=2;
    int t2=1;
    int p=2;
    Scanner cin=new Scanner(System.in);
    BigInteger v[]=new BigInteger[3];
    v[0]=new BigInteger("0");
    v[1]=new BigInteger("1");
    v[2]=new BigInteger("1");
    while (cin.hasNextInt())
    {
      x=cin.nextInt();
      v[0]=new BigInteger("0");
      v[1]=new BigInteger("1");
      v[2]=new BigInteger("1");
      t=2;
      t2=1;
      p=2;
      if (x<=2) 
      {
        System.out.println(v[x].toString());
        continue;
      }
      for (j=3;j<=x;j++)
      {
        p++;
        if (p>=3) p=p%3;
        t=p-1;
        if (t<0) t=t+3;
        t2=p-2;
        if (t2<0) t2=t2+3;
        v[p]=v[t].add(v[t2]);
      }
      System.out.println(v[p].toString());
    }
  }
}