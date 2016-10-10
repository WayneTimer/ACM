import java.util.*;

class cyr
{
  String e;
  int v;
  int[] c=new int[26];
  cyr()
  {
    e="";
    v=0;
    for (int p=0;p<26;p++)
      c[p]=0;
  }
}

public class Main
{
  public static int comp(cyr q,cyr w)
  {
    if (q.v<w.v) return -1;
    if (q.v>w.v) return 1;
    return q.e.compareTo(w.e);
  }

  public static void mysort(int l,int r,cyr[] a)
  {
    int i,j;
    cyr mid,t;
    i=l;
    j=r;
    mid=a[(l+r)>>1];
    do
    {
      while (comp(a[i],mid)<0) i++;
      while (comp(a[j],mid)>0) j--;
      if (i<=j)
      {
	t=a[i];
	a[i]=a[j];
	a[j]=t;
	i++;
	j--;
      }
    } while (i<=j);
    if (l<j) mysort(l,j,a);
    if (i<r) mysort(i,r,a);
  }

  public static boolean cha(int[] q,int[] w)
  {
    int i;
    for (i=0;i<26;i++)
      if (q[i]!=w[i]) return false;
    return true;
  }

  public static void main(String[] args)
  {
    Scanner cin=new Scanner(System.in);
    String x;
    cyr[] a=new cyr[110];
    int i,n=0;
    for (i=0;i<110;i++)
      a[i]=new cyr();
    while (cin.hasNextLine())
    {
      n^=n;
      x=cin.nextLine();
      while (!x.equals("XXXXXX"))
      {
	int l;
	l=x.length();
	n++;
	a[n].e=x;
	a[n].v^=a[n].v;
	for (i=0;i<l;i++)
	{
	  int u=x.charAt(i)-'a';
	  a[n].c[u]++;
	  u=1<<u;
	  a[n].v=a[n].v|u;
	}
	x=cin.nextLine();
      }
      mysort(1,n,a);
      int up=1;
      for (i=2;i<=n;i++)
      {
	if (!a[i].e.equals(a[i-1].e))
	{
	  up++;
	  a[up]=a[i];
	}
      }
      x=cin.nextLine();
      while (!x.equals("XXXXXX"))
      {
	int l,t=0;
	int[] y=new int[26];
	for (i=0;i<26;i++)
	  y[i]=0;
	l=x.length();
	for (i=0;i<l;i++)
	{
	  int u=x.charAt(i)-'a';
	  y[u]++;
	  u=1<<u;
	  t=t|u;
	}
	boolean flag=true;
	for (i=1;i<=n;i++)
	  if (a[i].v==t) break;
	if (i<=n)
	{
	  for (int j=i;j<=n;j++)
	    if (a[j].v==t)
	    {
	      if (cha(a[j].c,y)) 
	      {
		flag=false;
	       	System.out.println(a[j].e);
	      }
	    }
	    else break;
	}
	if (flag)
	  System.out.println("NOT A VALID WORD");
	System.out.println("******");
	x=cin.nextLine();
      }
    }
  }
}
