#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e5+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll a,b,n;
        cin>>a>>b>>n;
        
        if(a>b)
            swap(a,b);
            
        ll ans = 0;    
        
        while(1){
            if(b>n)
                break;
            ans++;
            a += b;
            swap(a,b);
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}