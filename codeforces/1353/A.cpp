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
        ll n,m;
        cin>>n>>m;
        
        if(n==1){
            cout<<0<<endl;
        }
        else if(n==2){
            cout<<m<<endl;
        } else {
        
            ll temp = (n-1)/2;
            ll rem = m%temp;
            ll q = m/temp;
            
            ll ans = 2*(q*temp + rem);
            cout<<ans<<endl;
        }
        
    }
    
    return 0;
}