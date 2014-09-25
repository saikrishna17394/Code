#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <cstring>
#include <list>
#define lli long long int
using namespace std;

lli A[4000000],B[2000],ans=0,num,val;
int main() {
	for(lli i=0;i<55;i++) {
		A[i]=(100003-200003*(i+1)+ 300007*(i+1)*(i+1)*(i+1))%1000000;
		if(A[i]<0)
			cout<<"ayya\n";
		//while(A[i]<0)
		//	A[i]+=1000000;
		A[i]-=500000;
	}
	for(int i=55;i<4000000;i++) {
		A[i]=(A[i-24]+A[i-55]+1000000)%1000000;
		if(A[i]<0)
			cout<<"ayya\n";
		
		//while(A[i]<0)
		//	A[i]+=1000000;
		A[i]-=500000;
	}

	num=0,val=0;
	for(int num=0;num<2000;num++) {
		int i=num*2000;
		B[0]=A[i];
		val=max(val,B[0]);
		i++;
		for(int j=1;j<2000;j++,i++) {
			B[j]=max(A[i],A[i]+B[j-1]);
			val=max(val,B[j]);
		}
	}

	ans=max(ans,val);
	cout<<ans<<endl;
	ans=0;
	for(int num=0;num<2000;num++) {
		int i=num;
		B[0]=A[i];
		ans=max(ans,B[0]);
		i+=2000;
		for(int j=1;j<2000;j++,i+=2000) {
			B[j]=max(A[i],A[i]+B[j-1]);
			ans=max(ans,B[j]);
		}
	}
	cout<<ans<<endl;
	ans=0;
	for(int num=0;num<2000;num++) {
		int i=num;
		B[0]=A[i];
		ans=max(ans,B[0]);
		i+=2001;
		for(int j=1;j<(2000-num);j++,i+=2001) {
			B[j]=max(A[i],A[i]+B[j-1]);
			ans=max(ans,B[j]);
		}
		i=num*2000;
		B[0]=A[i];
		ans=max(ans,B[0]);
		i+=2001;
		for(int j=1;j<(2000-num);j++,i+=2001) {
			B[j]=max(A[i],A[i]+B[j-1]);
			ans=max(ans,B[j]);
		}

	}
	cout<<ans<<endl;
	ans=0;
	for(int num=0;num<2000;num++) {
		int i=1999-num;
		B[0]=A[i];
		ans=max(ans,B[0]);
		i+=1999;
		for(int j=1;j<(2000-num);j++,i+=1999) {
			B[j]=max(A[i],A[i]+B[j-1]);
			ans=max(ans,B[j]);
		}
		i=num*2000+1999;
		B[0]=A[i];
		ans=max(ans,B[0]);
		i+=1999;
		for(int j=1;j<(2000-num);j++,i+=1999) {
			B[j]=max(A[i],A[i]+B[j-1]);
			ans=max(ans,B[j]);
		}

	}

	cout<<ans<<endl;

	return 0;
}