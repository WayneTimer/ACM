/*This Code is Submitted by Timer for Problem 1944 at 2012-09-04 10:53:28*/
//HOJ 1944
import java.util.*;

public class Main
{
  static int k1,k2;
  static String s;

  public static int cyr1(int i,int j)
  {
    int t=0,tx=0,sum=0;
    int y;
    boolean flag=false;
    char v;
    y=i;
    while (i<=j)
    {
      v=s.charAt(i);
      if (v=='-')
      {
        if (flag) sum-=t;
          else sum+=t;
        t^=t;
        flag=true;
      }
      else
      if (v=='+')
      {
        if (flag) sum-=t;
          else sum+=t;
        t^=t;
        flag=false;
      }
      else
      if (v=='x')
      {
        if ((i==y) || (!((s.charAt(i-1)>='0') && (s.charAt(i-1)<='9'))))
          t=1;
        if (flag) tx-=t;
          else tx+=t;
        t^=t;
      }
      else
      {
        t=t*10;
        t=t+v-'0';
      }
      i++;
    }
    if (flag) sum-=t;
      else sum+=t;
    k1=tx;
    return sum;
  }

  public static int cyr2(int i,int j)
  {
    int t=0,tx=0,sum=0;
    boolean flag=false;
    char v;
    int y;
    y=i;
    while (i<=j)
    {
      v=s.charAt(i);
      if (v=='-')
      {
        if (flag) sum-=t;
          else sum+=t;
        t^=t;
        flag=true;
      }
      else
      if (v=='+')
      {
        if (flag) sum-=t;
          else sum+=t;
        t^=t;
        flag=false;
      }
      else
      if (v=='x')
      {
        if ((i==y) || (!((s.charAt(i-1)>='0') && (s.charAt(i-1)<='9'))))
          t=1;
        if (flag) tx-=t;
          else tx+=t;
        t^=t;
      }
      else
      {
        t=t*10;
        t=t+v-'0';
      }
      i++;
    }
    if (flag) sum-=t;
      else sum+=t;
    k2=tx;
    return sum;
  }

  public static int gcd(int a,int b)
  {
    int t;
    if (a<b)
    {
      t=a;
      a=b;
      b=t;
    }
    while (b!=0)
    {
      t=a%b;
      a=b;
      b=t;
    }
    return a;
  }

  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    int l,i;
    int u1,u2;
    while (cin.hasNextLine())
    {
      s=cin.nextLine();
      l=s.length();
      i=0;
      while (s.charAt(i)!='=') i++;
      u1=cyr1(0,i-1);
      u2=cyr2(i+1,l-1);
      u2=u2-u1;
      k1=k1-k2;
      if (k1==0)
      {
        if (u2==0)
          System.out.println("Infinite many solutions");
        else 
          System.out.println("No solution");
      }
      else
      {
        System.out.print("x=");
        u1=gcd(u2,k1);
        u2=u2/u1;
        k1=k1/u1;
        if (k1<0)
        {
          k1=-k1;
          u2=-u2;
        }
        System.out.print(u2);
        if (k1!=1)
          System.out.println("/"+k1);
        else
          System.out.println();
      }
    }
  }
}
 