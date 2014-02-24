/*This Code is Submitted by Timer for Problem 1670 at 2012-08-31 18:07:34*/
//HOJ 1670
import java.util.*;

public class Main
{
  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    String s="";
    int l=0;
    int i=0;
    int t=0;
    int u=0;
    boolean flag=false;
    String a="";
    while (cin.hasNextLine())
    {
      a=cin.nextLine();
      l=a.length();
      i=1;
      t=1;
      u=0;
      flag=false;
      while (i<l)
      {
        while ((i<l) && (a.charAt(i)==a.charAt(i-1)) && (t<9))
        {
          t++;
          i++;
        }
        if (t!=1)
        {
          if (flag) System.out.print("1");
          flag=false;
            System.out.print(t);
            System.out.print(a.charAt(i-1));
            u=i;
            t=1;
            i++;
        }
        else
        {
          System.out.print("1");
          u=i-1;
          while ((i<l) && (a.charAt(i)!=a.charAt(i-1)))
          {
            if (a.charAt(i-1)=='1')
              System.out.print("11");
            else
              System.out.print(a.charAt(i-1));
            u=i;
            i++;
          }
          flag=true;
        }
      }
      if (u<l)
      {
        if (!flag)
          System.out.print("1");
        if (a.charAt(u)=='1')
          System.out.print("11");
        else
          System.out.print(a.charAt(u));
        System.out.print("1");
      } 
      System.out.println();
    }
  }
}
 