/*This Code is Submitted by Timer for Problem 1985 at 2013-07-22 18:35:40*/
//HOJ 1985
import java.util.*;
import java.math.*;

public class Main
{
        public static void main(String[] args)
        {
                Scanner cin=new Scanner(System.in);
                String str,op;
                BigInteger a,b;
                while (cin.hasNext())
                {
                        str=cin.next();
                        if (str.charAt(0)=='+')
                          str=str.substring(1);
                        a=new BigInteger(str);
                        op=cin.next();
                        str=cin.next();
                        if (str.charAt(0)=='+')
                          str=str.substring(1);
                        b=new BigInteger(str);
                        str=op;
                        if (str.equals("+"))
                        {
                                a=a.add(b);
                                System.out.println(a.toString());
                        }
                        else if (str.equals("-"))
                        {
                                a=a.subtract(b);
                                System.out.println(a.toString());
                        }
                        else if (str.equals("*"))
                        {
                                a=a.multiply(b);
                                System.out.println(a.toString());
                        }
                        else if (str.equals("/"))
                        {
                                if (b.equals(BigInteger.ZERO))
                                {
                                        System.out.println("Divided by zero.");
                                        continue;
                                }
                                BigInteger c=a.divide(b);
                                BigInteger d=a.subtract(b.multiply(c));
                                System.out.println(c.toString()+" "+d.toString());
                        }
                        else if (str.equals("<"))
                        {
                                if (a.compareTo(b)<0)
                                        System.out.println("true");
                                else
                                        System.out.println("false");
                        }
                        else if (str.equals(">"))
                        {
                                if (a.compareTo(b)>0)
                                        System.out.println("true");
                                else
                                        System.out.println("false");
                        }
                        else
                        {
                                if (a.compareTo(b)==0)
                                        System.out.println("true");
                                else
                                        System.out.println("false");
                        }
                }
        }
};