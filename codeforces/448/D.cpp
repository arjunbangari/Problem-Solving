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
    
    ll n,m,k;
    cin>>n>>m>>k;
    
    ll l = 1, r = n*m, ans;
    
    while(l<=r){
        ll mid = (l+r)/2;
        ll cnt = 0;
        
        for(ll i=1;i<=n;i++)
            cnt += min((mid-1)/i, m);
        
        if(cnt<k){
            ans = mid;
            l = mid+1;
        } else {
            r = mid-1;
        }
        
    }
    
    cout<<ans<<endl;
    
    return 0;
}