#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll b,p,f, h, c;
        cin>>b>>p>>f>>h>>c;
        
        if(h<c){
            swap(h,c);
            swap(p, f);
        }        
        
        ll ans = 0;
        ll x = min(b/2, p);
        ans += x*h;
        b -= 2*x;
        
        x = min(b/2, f);
        ans += x*c;
        
        cout<<ans<<endl;
        
        
    }
    
    return 0;
}