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

int main(){
    fast;
    
    ll a,b,c,k;
    cin>>a>>b>>c>>k;
    
    ll ans = min(a,k);
    k -= ans;
    
    ll temp = max(0LL,min(b,k));
    k -= temp;
    
    temp = max(0LL,min(c,k));
    ans -= temp;
    
    cout<<ans<<endl;
    
    return 0;
}