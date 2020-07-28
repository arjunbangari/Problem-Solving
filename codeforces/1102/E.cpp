#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 998244353;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    map<ll, ll> mp;
    for(ll i=0;i<n;i++)
        mp[arr[i]] = max(mp[arr[i]], i);
    
    vector<ll> rm(n);
    for(ll i=0;i<n;i++){
        rm[i] = mp[arr[i]];
        if(i!=0)
            rm[i] = max(rm[i], rm[i-1]);
    }
    
    ll i = 0, ans=1;
    while(i<n){
        ll j = i;
        while(j<n && rm[j]!=j)
            j = rm[j];
        
        if(j!=(n-1))
            ans = (ans*2)%mod;
        i = j+1;
    }
    
    cout<<ans<<endl;
    
    return 0;
}