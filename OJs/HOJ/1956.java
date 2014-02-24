/*This Code is Submitted by Timer for Problem 1956 at 2012-09-02 18:44:54*/
//HOJ 1956
import java.util.*;

public class Main
{
  static int[] a=new int[22];
  static int up,n;

  public static void mysort(int l,int r)
  {
    int i,j,mid,t;
    i=l;
    j=r;
    mid=a[(l+r)>>1];
    do
    {
      while (a[i]<mid) i++;
      while (a[j]>mid) j--;
      if (i<=j)
      {
        t=a[i];
        a[i]=a[j];
        a[j]=t;
        i++;
        j--;
      }
    } while (i<=j);
    if (l<j) mysort(l,j);
    if (i<r) mysort(i,r);
  }

  public static boolean DFS(int s,int sum,int v,int y)
  {
    int i;
    if (sum>=4) return true;
    for (i=y-1;i>=0;i--)
      if (((1<<i)&v)==0)
        if (s+a[i+1]<=up)
        {
          if ((i<n-1) && (a[i+1]==a[i+2]) && (((1<<(i+1))&v)==0))
            continue;
          else
          {
            if (s+a[i+1]==up)
              return (DFS(0,sum+1,v|(1<<i),n));
            else
              if (DFS(s+a[i+1],sum,v|(1<<i),i))
                return true;
            if (s==0) return false;
          }
        }
    return false;
  }

  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    int T=0;
    int s=0,i;
    T=cin.nextInt();
    while (T-->0)
    {
      s^=s;
      n=cin.nextInt();
      for (i=1;i<=n;i++)
      {
        a[i]=cin.nextInt();
        s+=a[i];
      }
      if (s%4!=0) 
      {
        System.out.println("no");
        continue;
      }
      s=s/4;
      up=s;
      mysort(1,n);
      if (a[n]>s) 
      {
        System.out.println("no");
        continue;
      }
      boolean flag=true;
      flag=DFS(0,0,0,n);
      if (flag) System.out.println("yes");
        else System.out.println("no");
    }
  }
}
 