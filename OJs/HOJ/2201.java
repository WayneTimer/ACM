/*This Code is Submitted by Timer for Problem 2201 at 2012-09-11 00:23:06*/
//HOJ 2201
import java.util.*;

public class Main
{
  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    int[] a=new int[1202];
    int n;
    int i,j;
    for (i=0;i<=1200;i++)
    {
      a[i]=i-600;
      a[i]=a[i]*a[i]*a[i];
    }
    n=cin.nextInt();
    boolean flag;
    while (n>0)
    {
      flag=false;
      for (i=0;i<=1200;i++)
      {
        for (j=1200;j>=i;j--)
        {
          if (a[i]+a[j]==n) 
          {
            flag=true;
            System.out.print(i-600);
            System.out.print(" ");
            System.out.println(j-600);
            break;
          }
          if (a[i]+a[j]<n) break;
        }
        if (flag) break;
      }
      if (!flag) System.out.println("impossible");
      n=cin.nextInt();
    }
  }
}
 