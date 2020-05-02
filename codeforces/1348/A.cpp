#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

long long binpow(long long a, long long b) {
    if (b == 0)
        return 1;
    long long res = binpow(a, b / 2);
    if (b % 2)
        return res * res * a;
    else
        return res * res;
}

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        ll a = binpow(2,n);
        ll temp = n/2;
        temp--;
        ll b = 0;
        
        for(ll i=1;i<=temp;i++)
            a += binpow(2,i);
            
        for(ll i=temp+1;i<n;i++)
            b += binpow(2,i);
            
        cout<<a-b<<endl;
    }
    
    return 0;
}