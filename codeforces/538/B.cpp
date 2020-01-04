#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
vector<ll> arr;

ll binary(ll x){
	ll temp;
	while(x!=0){
		temp=x%10;
		if(temp>1)
			return 0;
		x=x/10;
	}
	return 1;
}

void func(ll n){
    if(binary(n)){
        arr.push_back(n);
        return;
    } else {
        string s = to_string(n);
        for(ll i=0;i<s.length();i++){
            if(s[i]!='0' && s[i]!='1')
                s[i] = '1';
        }
        ll val = stoi(s);
        arr.push_back(val);
        func(n-val);
    }
}

int main(){
    fast;
    ll n;
    cin>>n;
    func(n);
    ll sz = arr.size();
    cout<<sz<<"\n";
    for(ll i=0;i<sz;i++)
        cout<<arr[i]<<" ";
    return 0;
}