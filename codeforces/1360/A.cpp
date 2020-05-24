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
        ll a,b;
        cin>>a>>b;
        
        ll val1 = max(2*a, b);
        ll val2 = max(2*b, a);
        
        cout<<min(val1*val1, val2*val2)<<endl;
    }
    
    return 0;
}