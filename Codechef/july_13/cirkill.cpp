#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
 
double dis(double x,double y) {
	return x*x+y*y;
}
 
int main() {
	double A[30][2],x,y,val,ans;
	int t,n,num2,num1;
	scanf("%d",&t);
	while(t--) {
		scanf("%d",&n);
		ans=0;
		num1=0;
		val=(double)1.0/(double)(n-3);
		//cout<<val<<endl;
		val=val/(double)(n*(n-1)*(n-2));
		//cout<<val<<endl;
		val*=6.0;
		num2=n*(n-1)*(n-2)*(n-3);
		num2/=6;
		//cout<<" "<<num<<endl;
		num1=0;
		//cout<<val<<" "<<1.0/val<<endl;
		//cout<<val<<endl;
		for(int i=0;i<n;i++)
			cin>>A[i][0]>>A[i][1];
		 
		double x1,x2,y1,y2,num;
		for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				for(int k=j+1;k<n;k++) {
					//cout<<"bhayya\n";
					x1=A[j][0]-A[i][0];
					y1=A[j][1]-A[i][1];
					x2=A[k][0]-A[i][0];
					y2=A[k][1]-A[i][1];
					//cout<<x1<<" "<<y1<<endl;
					//cout<<x2<<" "<<y2<<endl;
					if(y1*x2==x1*y2)
					continue;
					 
					x=y2*dis(x1,y1)-y1*dis(x2,y2);
					x/=2.0;
					x/=(y2*x1-y1*x2);
					y=x2*dis(x1,y1)-x1*dis(x2,y2);
					y=y/2.0;
					y/=(x2*y1-x1*y2);
					num=dis(x,y);
					//cout<<i<<" "<<j<<" "<<k<<endl;
					//cout<<x<<" "<<y<<endl;
					for(int l=0;l<n;l++) {
						if(l==i || l==j || l==k)
						continue;
						//cout<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
						//cout<<num<<endl;
						//cout<<A[l][0]-A[i][0]-x<<" "<<A[l][1]-A[i][1]-y<<endl;
						if((dis(A[l][0]-A[i][0]-x,A[l][1]-A[i][1]-y)-num)<=1.0e-12) {
							num1++;
							//cout<<"::"<<i<<" "<<j<<" "<<k<<" "<<l<<endl;
						}
					}	
				}
			}
		}
		//cout<<num1<<" "<<num<<endl;
		ans=(double)num1/(double)num2;
		printf("%.7f\n",ans);
	}
	return 0;
}