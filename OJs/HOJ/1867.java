/*This Code is Submitted by Timer for Problem 1867 at 2012-09-07 01:57:34*/
//HOJ 1867
import java.util.*;

class cyr
{
  public int v,s;
  cyr(int vv,int ss)
  {
    v=vv;
    s=ss;
  }
}

public class Main
{
  static cyr[] a=new cyr[1000002];
  static int n,q,m,xx,yy;
  static boolean flag=false;
  static boolean[] f=new boolean[10000004];

  public static void list()
  {
    int i,j;
    for (i=2;i<10000004;i++)
      f[i]=true;
    for (i=2;i<5000002;i++)
      if (f[i])
        for (j=2;j*i<10000004;j++)
          f[i*j]=false;
  }

  public static boolean check(int x)
  {
    int i;
    if (x<2) return false;
    return f[x];
  }

  public static int lowbit(int x)
  {
    return (x&(-x));
  }

  public static int sum(int x)
  {
    int t;
    t=0;
    while (x>0)
    {
      t+=a[x].s;
      x=x-lowbit(x);
    }
    return t;
  }

  public static void add(int x,int v)
  {
    while (x<=n)
    {
      a[x].s+=v;
      x=x+lowbit(x);
    }
  }

  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    int T=0;
    int op,i,ans;
    for (i=0;i<1000002;i++)
      a[i]=new cyr(0,0);
    list();
    n=cin.nextInt();
    q=cin.nextInt();
    m=cin.nextInt();
    while (!((n==0) && (q==0) && (m==0)))
    {
      T++;
      System.out.println("CASE #"+T+":");
      flag=check(m);
      for (i=1;i<=n;i++)
        a[i].s=0;
      if (flag)
      {
        for (i=1;i<=n;i++)
        {
          a[i].v=m;
          add(i,1);
        }
      }
      else
      {
        for (i=1;i<=n;i++)
          a[i].v=m;
      }
      while (q-->0)
      {
        op=cin.nextInt();
        xx=cin.nextInt();
        yy=cin.nextInt();
        if (op==0) 
        {
          boolean f1,f2;
          f1=check(a[xx].v);
          a[xx].v+=yy;
          f2=check(a[xx].v);
          if ((!f1) && (f2)) add(xx,1);
          if ((f1) && (!f2)) add(xx,-1);
        }
        else
        {
          ans=sum(yy)-sum(xx-1);
          System.out.println(ans);
        }
      }
      System.out.println();
      n=cin.nextInt();
      q=cin.nextInt();
      m=cin.nextInt();
    }
  }
}
 