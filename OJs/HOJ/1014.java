/*This Code is Submitted by Timer for Problem 1014 at 2012-03-10 00:29:11*/
import java.util.*;
import java.math.*;

public class Main
{
  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    BigInteger one=new BigInteger("0");
    BigInteger sum=new BigInteger("0");
    BigInteger s=new BigInteger("0");
    BigInteger t=new BigInteger("0");
    BigInteger x=new BigInteger("1");
    BigInteger bb=new BigInteger("1");
    BigInteger q=new BigInteger("1");
    String e="";
    long b=0;
    int l=0;
    char p;
    b=cin.nextLong();
    while (b!=0)
    {
      bb=one.valueOf(b);
      s=new BigInteger("0");
      sum=new BigInteger("0");
      e=cin.next();
      l=e.length()-1;
      x=new BigInteger("1");
      while (l>=0)
      {
        p=e.charAt(l);
        t=new BigInteger(e.valueOf(p));
        s=s.add(t);
        q=x.multiply(t);
        sum=sum.add(q);
        x=x.multiply(bb); 
        l--;
      }
      t=sum.mod(s);
      if (t.compareTo(one)==0) System.out.println("yes");
        else System.out.println("no");
      b=cin.nextLong();
    }
  }
}