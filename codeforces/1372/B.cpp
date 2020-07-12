#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        if(n%2==0){
            cout<<n/2<<" "<<n/2<<endl;
            continue;
        }
        
        vector<ll> div;
        
        ll a=1, b=n-1, mn = n-1;
        for(ll i=2;i<=sqrt(n);i++){
            if(n%i==0){
                ll x = i, y = n-i;
                ll tmp = lcm(x,y);
                if(tmp<mn){
                    a = x;
                    b = y;
                }
                mn = min(mn, tmp);
                
                x = n/i;
                y = n-x;
                tmp = lcm(x,y);
                if(tmp<mn){
                    a = x;
                    b = y;
                }
                mn = min(mn, tmp);
            }
        }
        
        cout<<a<<" "<<b<<endl;
    }
    
    return 0;
}