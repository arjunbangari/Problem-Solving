#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,sx,sy;
    cin>>n>>sx>>sy;
    
    vector<pair<ll, pll>> v;
    v.push_back({0, {sx+1, sy}});
    v.push_back({0, {sx-1, sy}});
    v.push_back({0, {sx, sy-1}});
    v.push_back({0, {sx, sy+1}});
    
    for(ll i=0;i<n;i++){
        ll x,y;
        cin>>x>>y;
        
        if(x>sx)
            v[0].first++;
        if(x<sx)
            v[1].first++;
        if(y>sy)
            v[3].first++;
        if(y<sy)
            v[2].first++;
    }
    
    sort(all(v));
    
    cout<<v[3].first<<endl;
    cout<<v[3].second.first<<" "<<v[3].second.second<<endl;
    
    return 0;
}