/*This Code is Submitted by Timer for Problem 1076 at 2012-08-30 23:06:24*/
/*
ID: linyicx1
LANG: JAVA
TASK: frac1
*/
import java.util.*;

class cyr
{
  int a;
  int b;
  double s;
  cyr()
  {
    a=0;
    b=0;
    s=0;
  }
}

public class Main
{
  public static void mysort(int l,int r,cyr[] a)
  {
    int i,j;
    double mid;
    cyr temp;
    i=l;
    j=r;
    mid=a[(l+r)/2].s;
    do
    {
      while (a[i].s<mid) i++;
      while (a[j].s>mid) j--;
      if (i<=j)
      {
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        i++;
        j--;
      }
    } while (i<=j);
    if (l<j) mysort(l,j,a);
    if (i<r) mysort(i,r,a);
  }

  static int gcd(int a,int b)
  {
    if (b==0) return a;
    return gcd(b,a%b);
  }

  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    int n,i,j,top;
    double q,w;
    cyr[] ans=new cyr[162*162];
    for (i=0;i<162*162;i++)
      ans[i]=new cyr();
    while (cin.hasNextInt())
    {
      top=0;
      n=cin.nextInt();
      for (i=1;i<n;i++)
        for (j=i+1;j<=n;j++)
        {
          if (i!=1)
            if (gcd(j,i)!=1) continue;
          top++;
          ans[top].a=i;
          ans[top].b=j;
          q=(double)i;
          w=(double)j;
          ans[top].s=q/w;
        }
      mysort(1,top,ans);
      System.out.println("0/1");
      for (i=1;i<=top;i++)
        System.out.println(ans[i].a+"/"+ans[i].b);
      System.out.println("1/1");
      System.out.println();
    }
  }
}