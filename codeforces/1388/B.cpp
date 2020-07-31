#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef double db;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	lli t;
	cin>>t;
	while(t--){
		lli n;
		cin>>n;
		string s="";
		for(lli i=0;i<n;i++){
			s += '9';
		}
		lli tm=n/4;
		lli tp=n%4;
		for(lli i=0;i<tm;i++){
			s[n-i-1]='8';
		}
		if(tp>=1){
			s[n-tm-1]='8';
		}
		cout<<s<<"\n";
	}
	return 0;
}