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

vector<ll> v[maxn];
map<ll,ll> mp;

int main(){
    fast;
    
    ll n, m, a, b;
    cin>>n>>m;
    
    for(ll i=0;i<m;i++){
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    
    vector<pll> arr(n+1);
    arr[0] = {inf, 0};
    
    for(ll i=1;i<=n;i++){
        cin>>a;
        arr[i] = {a, i};
        mp[i] = a;
    }

    sort(arr.begin(), arr.end());
    
    for(ll i=0;i<n;i++){
        ll des = arr[i].first;
        
        ll tmp = (des*(des+1))/2;
        
        set<ll> s;
        
        for(auto u: v[arr[i].second]){
            if(mp[u]<=des)
                s.insert(mp[u]);
        }

        for(auto u: s) 
            tmp -= u;
        
        if(tmp!=des){
            cout<<-1<<endl;
            return 0;
        }
    }
    
    for(ll i=0;i<n;i++)
        cout<<arr[i].second<<" ";
    
    return 0;
}