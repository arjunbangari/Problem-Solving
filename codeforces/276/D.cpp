#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll compute(ll n){
    ll ans = 0;
    ll base = 1;
    while(n!=0){
        ans += base;
        n /= 2;
        base *= 2;
    }
    
    return ans;
}

int main(){
    fast;
    
    ll l,r;
    cin>>l>>r;
    
    if(l==r)
        cout<<0<<endl;
    else {
        ll temp = l^r;
        cout<<compute(temp)<<endl;
    }
    
    return 0;
}