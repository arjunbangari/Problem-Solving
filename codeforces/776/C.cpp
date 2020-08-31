#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e15;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,k;
    cin>>n>>k;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
    
    for(ll i=1;i<n;i++) 
        arr[i] += arr[i-1];
    
    map<ll, ll> mp;
    set<ll> s;
    
    if(abs(k)==1){
        s.insert(k);
        s.insert(1);
    } else {
        ll x = (ld)log2((ld)inf)/(ld)log2((ld)abs(k));
    
        ll i= 1;
        while(x--){
            s.insert(i);
            i *= k;
        }
    }
    
    ll ans = 0;
    
    for(ll i=0;i<n;i++){
        if(s.count(arr[i])) 
            ans++;
        
        for(auto u: s)
            ans += mp[arr[i]-u];
        
        mp[arr[i]]++;
    }
    
    cout<<ans<<endl;
    
    return 0;
}