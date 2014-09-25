import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;

public class prob65 {

	public static void main(String[] args) {

		BigInteger A[] =new BigInteger [103];

		
		for(int i=1;i<=100;i+=3) {
			A[i]=BigInteger.valueOf(1);
			A[i+1]=BigInteger.valueOf(2*(i+2)/3);
			A[i+2]=BigInteger.valueOf(1);
		}
		BigInteger num=A[99],g;
		BigInteger den=new BigInteger ("1"),temp;
		A[0]=BigInteger.valueOf(2);

		for(int i=98;i>=0;i--) {
			temp=num;
			num=den;
			den=temp;

			num=num.add(A[i].multiply(den));

			// g=gcd(num,den);

			// num=num.divide(g);
			// den=den.divide(g);
			// System.out.println(num+" "+ den);			
		}
		
		System.out.println(num+" "+ den);			
		System.out.println(sum_of_digits(num));
	}

	static BigInteger gcd(BigInteger a,BigInteger b) {
		if(b.equals(BigInteger.ZERO))
			return a;
		return gcd(b,a.remainder(b));
	}

	static BigInteger sum_of_digits(BigInteger a) {
		BigInteger ans=new BigInteger("0"),temp=a;
		BigInteger ten=new BigInteger ("10");

		while(!temp.equals(BigInteger.ZERO)) {
			ans=ans.add(temp.remainder(ten));
			temp=temp.divide(ten);
		}

		return ans;
	}
	void swap(BigInteger a,BigInteger b) {
		BigInteger temp=a;
		a=b;
		b=temp;
	}
}