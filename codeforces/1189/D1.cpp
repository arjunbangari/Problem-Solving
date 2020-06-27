#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 998244353;
 
// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> v[n+1], sz(n+1);
    
    for(ll i=1;i<n;i++){
        ll a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
        sz[a]++;
        sz[b]++;
    }
    
    for(ll i=1;i<=n;i++){
        if(sz[i]==2){
            cout<<"NO"<<endl;
            return 0;
        }
    }
    
    cout<<"YES"<<endl;
    
    return 0;
}