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
        string x;
        cin>>x;
        
        ll n = x.length();
        
        ll m = x[0]-'0';
        
        ll ans = (m-1)*10;
        ans += n*(n+1)/2;
        
        cout<<ans<<endl;
    }
    
    return 0;
}