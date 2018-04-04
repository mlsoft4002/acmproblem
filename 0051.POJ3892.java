import java.math.BigInteger;
import java.util.Scanner;

public class Main
{
	static BigInteger n;
	static BigInteger k;

	public static void main(String[] args)
	{
		Scanner cin = new Scanner(System.in);
		BigInteger one = BigInteger.ONE;
		BigInteger two = BigInteger.valueOf(2);
		BigInteger zero = BigInteger.ZERO;

		BigInteger l, r, tmp, mid;
		mid = zero;
		while(cin.hasNext())
		{
			n = cin.nextBigInteger();
			k = cin.nextBigInteger();
			k = k.multiply(n);
			l = zero;
			r = k;
			while(l.compareTo(r) <= 0)
			{
				mid = l.add(r).divide(two);
				tmp = mid.multiply(mid);
				if(tmp.compareTo(k) == 0)
					break;
				if(tmp.compareTo(k) < 0)
					l = mid.add(one);
				else
					r = mid.subtract(one);
			}
			BigInteger p,q;
			p = mid;
			q = mid;

			while(true)
			{
			if(n.mod(p).equals(zero) && !p.equals(one) && !p.equals(n))
				{
					q = n.divide(p);
					break;
				}
			if(n.mod(q).equals(zero)&& !q.equals(one) && !q.equals(n))
				{
					p = n.divide(q);
					break;
				}
				p = p.add(one);
				q = q.subtract(one);
			}

			if(p.compareTo(q) > 0)
			{
				tmp = p;
				p = q;
				q = tmp;
			}
			System.out.println(p + " * " + q);
		}
	}
} 
