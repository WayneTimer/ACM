/*This Code is Submitted by Timer for Problem 2023 at 2012-09-10 20:10:32*/
//HOJ 2023
import java.util.*;

public class Main
{
  static char[] a=new char[2010];
  static char[] b=new char[2010];
  static char[] c=new char[2010];
  static int la,lb,lc;

  public static boolean cyr()
  {
    int i,j;
    boolean[][] f=new boolean[210][210];
    for (i=0;i<la;i++)
      for (j=0;j<lb;j++)
        f[i][j]=false;
    f[0][0]=true;
    for (i=0;i<=la;i++)
    {
      for (j=0;j<=lb;j++)
      {
        if ((i==0) && (j==0)) continue;
        if (i>0)
          if (f[i-1][j])
            if (a[i-1]==c[i+j-1]) f[i][j]=true;
        if (j>0)
          if (f[i][j-1])
            if (b[j-1]==c[i+j-1]) f[i][j]=true;
      }
    }
    if (f[la][lb]) return true;
      else return false;
  }

  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    int T,o;
    boolean flag;
    T=cin.nextInt();
    for (o=1;o<=T;o++)
    {
      String aa,bb,cc;
      aa=cin.next();
      bb=cin.next();
      cc=cin.next();
      a=aa.toCharArray();
      b=bb.toCharArray();
      c=cc.toCharArray();
      int i,j;
      la=aa.length();
      lb=bb.length();
      lc=cc.length();
      flag=cyr();
      System.out.print("Data set "+o+": ");
      if (flag) System.out.println("yes");
        else System.out.println("no");
    }
  }
}
 