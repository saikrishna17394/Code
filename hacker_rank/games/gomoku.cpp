#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int,int> pi;

string s[15];
char p;

pi row(char c) {
    pi ans=pi(-1,-1);
    int kri=50;
    for(int i=0;i<15;i++) {
        for(int j=0;j<=10;j++) {
            int val=0,val1=0;
            int ind;
            int lad=10;
            for(int k=j;k<j+5;k++) {
                if(s[i][k]==c)
                    val++;
                if(s[i][k]=='.') {
                    val1++;
                    if(abs(k-j-2)<lad) {
                        ind=k;
                        lad=abs(k-j-2);
                    }
                }
            }
            if(val==4 && val1==1) {
                return pi(i,ind);
            }
            if(val==3 && val1==2 && (abs(i-7)+abs(ind-7))<kri) {
                ans=make_pair(i,ind);
                kri=abs(i-7)+abs(ind-7);
            }
        }
    }
    
    return ans;
}

pi row1(char c) {
    pi ans=pi(-1,-1);
    int kri=50;
    for(int i=0;i<15;i++) {
        for(int j=0;j<=10;j++) {
            int val=0,val1=0;
            int ind;
            for(int k=j;k<j+5;k++) {
                if(s[i][k]==c)
                    val++;
                if(s[i][k]=='.') {
                    val1++;
                    ind=k;
                }
                
            }
            if(val==4 && val1==1) {
                return pi(i,ind);
            }
        }
    }
    
    return ans;
}


pi col(char c) {
    pi ans=pi(-1,-1);
    int kri=50;
    for(int j=0;j<15;j++) {
        for(int i=0;i<=10;i++) {
            int val=0,val1=0;
            int ind,lad=10;
            for(int k=i;k<i+5;k++) {
                if(s[k][j]==c)
                    val++;
                if(s[k][j]=='.') {
                    val1++;
                    if(abs(k-i-2)<lad) {
                        ind=k;
                        lad=abs(k-i-2);
                    }
                }
                
            }
            if(val==4 && val1==1) {
                return pi(ind,j);
            }
            if(val==3 && val1==2 && (abs(ind-7)+abs(j-7))<kri) {
                ans=make_pair(ind,j);
                kri=abs(ind-7)+abs(j-7);
            }

        }
    }
    
    return ans;
}
pi col1(char c) {
    pi ans=pi(-1,-1);
    int kri=50;
    for(int j=0;j<15;j++) {
        for(int i=0;i<=10;i++) {
            int val=0,val1=0;
            int ind;
            for(int k=i;k<i+5;k++) {
                if(s[k][j]==c)
                    val++;
                if(s[k][j]=='.') {
                    val1++;
                    ind=k;
                }
                
            }
            if(val==4 && val1==1) {
                return pi(ind,j);
            }
        }
    }
    
    return ans;
}

pi di(char c) {
    pi ans=pi(-1,-1);
    int kri=50;
    for(int i=0;i<=10;i++) {
        for(int j=0;j<=10;j++) {
            int val=0,val1=0;
            int ind1,ind2,lad=10;
            for(int k=i,k1=j;k<i+5;k++,k1++) {
                if(s[k][k1]==c)
                    val++;
                if(s[k][k1]=='.') {
                    val1++;
                    if(abs(k-i-2)<lad) {
                        ind1=k;
                        ind2=k1;
                        lad=abs(k-i-2);
                    }
                }
                
            }
            if(val==4 && val1==1) {
                return pi(ind1,ind2);
            }
            if(val==3 && val1==2 && (abs(ind1-7)+abs(ind2-7))<kri) {
                 ans=make_pair(ind1,ind2);
                 kri=abs(ind1-7)+abs(ind2-7);
            }

        }
    }
    
    return ans;
}

pi di2(char c) {
    pi ans=pi(-1,-1);
    int kri=50;
    for(int i=0;i<=10;i++) {
        for(int j=0;j<=10;j++) {
            int val=0,val1=0;
            int ind1,ind2;
            for(int k=i,k1=j;k<i+5;k++,k1++) {
                if(s[k][k1]==c)
                    val++;
                if(s[k][k1]=='.') {
                    val1++;
                    ind1=k;
                    ind2=k1;
                }
                
            }
            if(val==4 && val1==1) {
                return pi(ind1,ind2);
            }
        }
    }
    
    return ans;
}

pi di1(char c) {
    pi ans=pi(-1,-1);

    int kri=50;
    for(int i=0;i<=10;i++) {
        for(int j=14;j>=4;j--) {
            int val=0,val1=0;
            int ind1,ind2,lad=10;
            for(int k=i,k1=j;k<i+5;k++,k1--) {
                if(s[k][k1]==c)
                    val++;
                if(s[k][k1]=='.') {
                    val1++;
                    if(abs(k-i-2)<lad) {
                        lad=abs(k-i-2);
                        ind1=k;
                        ind2=k1;
                    }
                }
                
            }
            if(val==4 && val1==1) {
                return pi(ind1,ind2);
            }
            if(val==3 && val1==2 && (abs(ind1-7)+abs(ind2-7))<kri) {
                 ans=make_pair(ind1,ind2);
                 kri=abs(ind1-7)+abs(ind2-7);
            }

        }
    }
    
    return ans;
}

pi di3(char c) {
    pi ans=pi(-1,-1);

    int kri=50;
    for(int i=0;i<=10;i++) {
        for(int j=14;j>=4;j--) {
            int val=0,val1=0;
            int ind1,ind2;
            for(int k=i,k1=j;k<i+5;k++,k1--) {
                if(s[k][k1]==c)
                    val++;
                if(s[k][k1]=='.') {
                    val1++;
                    ind1=k;
                    ind2=k1;
                }
                
            }
            if(val==4 && val1==1) {
                return pi(ind1,ind2);
            }
        }
    }
    
    return ans;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s1;
    cin>>s1;
    p=s1[0];
    cin>>s1;
    int num;
    cin>>num;
    
    for(int i=0;i<15;i++)
        cin>>s[i];
    bool val=false;
    
    if(num==1) {
        cout<<"H:8\n";
        return 0;
    }
    
    if(num==2) {
        cout<<"I:9\n";
        return 0;
    }

    if(num==3) {
        if(s[6][6]=='W')
            cout<<"E:11\n";
        else
            cout<<"E:5\n";
        return 0;
    }
    char ch;
    pi ans;

    ans=row1(p);
    if(ans!=pi(-1,-1)) {
        ch='A'+ans.second;
        cout<<ch<<":"<<ans.first+1<<endl;
        return 0;
    }
    
    ans=col1(p);
    if(ans!=pi(-1,-1)) {
        ch='A'+ans.second;
        cout<<ch<<":"<<ans.first+1<<endl;
        return 0;
    }
    
    ans=di2(p);
    if(ans!=pi(-1,-1)) {
        ch='A'+ans.second;
        cout<<ch<<":"<<ans.first+1<<endl;
        return 0;
    }
    
    ans=di3(p);
    if(ans!=pi(-1,-1)) {
        ch='A'+ans.second;
        cout<<ch<<":"<<ans.first+1<<endl;
        return 0;
    }

    if(p=='W')
        p='B';
    else
        p='W';

    ans=row1(p);
    if(ans!=pi(-1,-1)) {
        ch='A'+ans.second;
        cout<<ch<<":"<<ans.first+1<<endl;
        return 0;
    }
    
    ans=col1(p);
    if(ans!=pi(-1,-1)) {
        ch='A'+ans.second;
        cout<<ch<<":"<<ans.first+1<<endl;
        return 0;
    }
    
    ans=di2(p);
    if(ans!=pi(-1,-1)) {
        ch='A'+ans.second;
        cout<<ch<<":"<<ans.first+1<<endl;
        return 0;
    }
    
    ans=di3(p);
    if(ans!=pi(-1,-1)) {
        ch='A'+ans.second;
        cout<<ch<<":"<<ans.first+1<<endl;
        return 0;
    }
    
    
    ans=di(p);
    if(ans!=pi(-1,-1)) {
        ch='A'+ans.second;
        cout<<ch<<":"<<ans.first+1<<endl;
        return 0;
    }
    
    ans=di1(p);
    if(ans!=pi(-1,-1)) {
        ch='A'+ans.second;
        cout<<ch<<":"<<ans.first+1<<endl;
        return 0;
    }
    ans=row(p);
    if(ans!=pi(-1,-1)) {
        ch='A'+ans.second;
        cout<<ch<<":"<<ans.first+1<<endl;
        return 0;
    }
    
    ans=col(p);
    if(ans!=pi(-1,-1)) {
        ch='A'+ans.second;
        cout<<ch<<":"<<ans.first+1<<endl;
        return 0;
    }

    if(p=='W')
        p='B';
    else
        p='W';

    ans=row(p);
    if(ans!=pi(-1,-1)) {
        ch='A'+ans.second;
        cout<<ch<<":"<<ans.first+1<<endl;
        return 0;
    }
    
    ans=col(p);
    if(ans!=pi(-1,-1)) {
        ch='A'+ans.second;
        cout<<ch<<":"<<ans.first+1<<endl;
        return 0;
    }
    
    ans=di(p);
    if(ans!=pi(-1,-1)) {
        ch='A'+ans.second;
        cout<<ch<<":"<<ans.first+1<<endl;
        return 0;
    }
    
    ans=di1(p);
    if(ans!=pi(-1,-1)) {
        ch='A'+ans.second;
        cout<<ch<<":"<<ans.first+1<<endl;
        return 0;
    }


    for(int i=6;i<13;i++) {
        for(int j=6;j<13;j++) {
            if(s[i][j]=='.') {
                char c='A'+j;
                cout<<c<<":"<<i+1<<endl;
                return 0;
            }

        }
    }
    for(int i=0;i<15;i++) {
        for(int j=0;j<15;j++) {
            if(s[i][j]=='.') {
                char c='A'+j;
                cout<<c<<":"<<i+1<<endl;
                return 0;
            }
        }
    }

    return 0;
}
