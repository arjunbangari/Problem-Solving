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
    
        ll n,m,k;
        cin>>n>>m>>k;
        
        ll each = n/k;
        
        ll x = min(each, m);
        
        ll rem = m - x;
        
        if(!rem){
            cout<<x<<endl;
            continue;
        }

        ll r = rem/(k-1) ;
        if(rem%(k-1)!=0)
            r++;
        
        cout<<x - r<<endl;
    }
    
    return 0;
}