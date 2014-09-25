import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

class cnr {
	
	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		BigInteger A[][] =new BigInteger [351][351];
		A[1][0]=BigInteger.valueOf(1);
		A[1][1]=BigInteger.valueOf(1);
		for(int i=2;i<351;i++) {
			A[i][0]=BigInteger.valueOf(1);
			A[i][i]=BigInteger.valueOf(1);
			for(int j=1;j<i;j++) {

				A[i][j]=A[i-1][j-1].add(A[i-1][j]);
				// System.out.println(i+" "+j+" "+A[i][j]);
			}
		}

		int t,n,k;
		BigInteger m;

		t=in.nextInt();
		for(int z=0;z<t;z++) {
			n=in.nextInt();
			k=in.nextInt();
			m=in.nextBigInteger();

			if(m.compareTo(A[n][k])==1)
				System.out.println("-1");
			else {
				for(int i=n;i>=1;i--) {
						if(i==1) {
							if(k==0)
								System.out.println("0");
							else
								System.out.println("1");
							continue;
						}

						
						if(i==k) {
							System.out.print("1");
							k--;
						}
						else if(m.compareTo(A[i-1][k])==1) {
							System.out.print("1");
							// System.out.println("\n"+i+" "+k+" "+m);
							m=m.subtract(A[i-1][k]);
							k--;
							// System.out.println("\n"+i+" "+k+" "+m);
							// find(n-1,k-1,sub(m,ncr[n-1][k]));
						}
						else {
							System.out.print("0");
							// find(n-1,k,m);
						}

				}
			}
		}
		
	}

}