/*This Code is Submitted by Timer for Problem 1081 at 2012-09-04 17:37:57*/
//HOJ 1081
import java.util.*;

public class Main
{
  static String s;
  static int[] x=new int[1010];
  static String[] y=new String[1010];
  static int[] a=new int[2010];

  public static void sortint(int l,int r)
  {
    int i,j,mid,t;
    i=l;
    j=r;
    mid=x[(l+r)>>1];
    do
    {
      while (x[i]<mid) i++;
      while (x[j]>mid) j--;
      if (i<=j)
      {
        t=x[i];
        x[i]=x[j];
        x[j]=t;
        i++;
        j--;
      }
    } while (i<=j);
    if (l<j) sortint(l,j);
    if (i<r) sortint(i,r);
  }

  public static void sortstring(int l,int r)
  {
    int i,j;
    String mid="",t="";
    i=l;
    j=r;
    mid=y[(l+r)>>1];
    do
    {
      while (y[i].compareToIgnoreCase(mid)<0) i++;
      while (y[j].compareToIgnoreCase(mid)>0) j--;
      if (i<=j)
      {
        t=y[i];
        y[i]=y[j];
        y[j]=t;
        i++;
        j--;
      }
    } while (i<=j);
    if (l<j) sortstring(l,j);
    if (i<r) sortstring(i,r);
  }

  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    int i=0,l;
    int n1=0,n2=0,n=0,next=0;
    int temp=0;
    String t="";
    char e;
    boolean flag;
    s=cin.nextLine();
    while (s.charAt(0)!='.')
    {
      l=s.length();
      i^=i;
      n^=n;
      n1^=n1;
      n2^=n2;
      temp^=temp;
      n^=n;
      t="";
      flag=false;
      while (i<l)
      {
        e=s.charAt(i);
        if (e==',' || e=='.') 
        {
          n++;
          a[n]=next;
          if (next==1)
          {
            n1++;
            if (flag) x[n1]=-temp;
              else x[n1]=temp;
            temp^=temp;
          }
          else
          {
            n2++;
            y[n2]=t;
            t="";
          }
          flag=false;
          i=i+2;
          continue;
        }
        if (e=='-')
        {
          flag=true;
          i++;
          continue;
        }
        if ((e>='0') && (e<='9'))
        {
          next=1;
          temp=temp*10;
          temp=temp+e-'0';
        }
        else
        {
          next=2;
          t=t.concat(String.valueOf(e));
        }
        i++;
      }
      if (n1>0) sortint(1,n1);
      if (n2>0) sortstring(1,n2);
      n1=0;
      n2=0;
      for (i=1;i<n;i++)
      {
        if (a[i]==1)
        {
          n1++;
          System.out.print(x[n1]);
        }
        else
        {
          n2++;
          System.out.print(y[n2]);
        }
        System.out.print(", ");
      }
      if (a[n]==1)
      {
        n1++;
        System.out.println(x[n1]+".");
      }
      else
      {
        n2++;
        System.out.println(y[n2]+".");
      }
      s=cin.nextLine();
    }
  }
}
 