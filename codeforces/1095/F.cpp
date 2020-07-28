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
ll const mod = 1e9+7;

// code begins here

ll id[maxn];

void initialise(ll n){
    for(ll i=0;i<=n;i++)
        id[i] = i;
}

ll root(ll i){
    while(i!=id[i]){
        id[i] = id[id[i]];
        i = id[i];
    }
    return i;
}

void merge(ll x, ll y){
    ll p = root(x);
    ll q = root(y);
    id[p] = q;
}

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    vector<pll> arr(n);
    for(ll i=0;i<n;i++){
        ll x;
        cin>>x;
        arr[i] = {x, i+1};
    }
    
    sort(arr.begin(), arr.end());
    multiset<pair<ll, pll>> ms;
    
    for(ll i=1;i<n;i++){
        ll cost = arr[0].first + arr[i].first;
        ms.insert(make_pair(cost, make_pair(arr[0].second, arr[i].second)));
    }
    
    for(ll i=0;i<m;i++){
        ll x,y,w;
        cin>>x>>y>>w;
        ms.insert(make_pair(w, make_pair(x, y)));
    }
    
    initialise(n);
    ll ans = 0;
    
    while(!ms.empty()){
        auto val = *ms.begin();
        ms.erase(ms.begin());
        
        ll cost = val.first, x = val.second.first, y = val.second.second;
        
        if(root(x)==root(y))
            continue;
        
        // cout<<cost<<" "<<x<<" "<<y<<endl;
        
        ans += cost;
        merge(x, y);
    }
    
    cout<<ans<<endl;
    
    return 0;
}