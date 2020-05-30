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

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    map<string, ll> mp;
    mp["ABC"] = inf;
    mp["A"] = inf; mp["B"] = inf; mp["C"] = inf;
    mp["AB"] = inf; mp["BC"] = inf; mp["AC"] = inf;
    
    for(ll i=0;i<n;i++){
        ll c;
        string s;
        cin>>c>>s;
        sort(s.begin(), s.end());
        mp[s] = min(mp[s], c);
    }
    
    ll ans = min(mp["ABC"], mp["A"] + mp["B"] + mp["C"]);
    ans = min(ans, mp["AB"] + mp["BC"] + mp["AC"] - max({mp["AB"],mp["BC"],mp["AC"]}));
    ans = min({ans, mp["AC"]+mp["B"], mp["AB"]+mp["C"], mp["BC"]+mp["A"] });
    
    cout<<(ans==inf ? -1 : ans )<<endl;
    
    return 0;
}