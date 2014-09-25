import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

class a {
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);

		int t;
		Long b,n,q1,q2,r1,r2,num,num1,ex;

		BigInteger bi1,bi2,yo;

		t=in.nextInt();
		for(int z=0;z<t;z++) {
			n=in.nextLong();
			b=in.nextLong();

			yo=BigInteger.valueOf(b.longValue());

			q1=1/b;
			r1=1%b;
			q1=q1%2;
			// System.out.println(q1+" "+r1);

			for (long i=2;i<=n;i++) {
				// System.out.println(i);
				q2=i/b;
				r2=i%b;

				q2=q2%2;

				// System.out.println(q2+" "+r2);

				if(b%2!=0) 
					q1=q1*q2+q1*r2+q2*r1;
				else
					q1=q1*r2+q2*r1;;
				
				q1=q1%2;


				bi1=BigInteger.valueOf(r1);
				bi2=BigInteger.valueOf(r2);

				bi1=bi1.multiply(bi2);

				BigInteger bi[]=bi1.divideAndRemainder(yo);

				num=bi[0].longValue();
				q1=q1+num;
				r1=bi[1].longValue();

				q1=q1%2;
				// System.out.println(q1+" "+r1);
			}

			if(q1==0)
				System.out.println("Even");
			else
				System.out.println("Odd");
		}
		
	}

}