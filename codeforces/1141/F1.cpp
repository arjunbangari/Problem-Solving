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

bool cmp(const pll &a, const pll &b) { 
    return (a.second < b.second); 
}

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
        
    map<ll, vector<pll>> mp;
    
    for(ll i=0;i<n;i++){
        ll sum = 0;
        for(ll j=i;j<n;j++){
            sum += arr[j];
            mp[sum].push_back({i, j});
        }
    }
    
    ll ans = -1;
    vector<pll> blocks;
    
    for(auto u: mp){
        ll cnt = 0, last = -1;
        vector<pll> tmp;
        
        sort(u.second.begin(), u.second.end(), cmp);
        
        for(auto v: u.second){
            if(v.first>last){
                cnt++;
                tmp.push_back(v);
                last = v.second;
            }
        }
        
        if(cnt>ans)
            blocks = tmp;
        ans = max(ans, cnt);
    }
    
    cout<<ans<<endl;
    for(auto u: blocks)
        cout<<u.first+1<<" "<<u.second+1<<endl;
    
    return 0;
}