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
    
    ll n;
    cin>>n;
    
    string l, r;
    cin>>l>>r;
    
    map<char, set<ll>> mp;
    for(ll i=0;i<n;i++)
        mp[r[i]].insert(i);
    
    vector<pair<ll,ll>> ans;
    vector<ll> left, right;
    
    vector<ll> vis(n, 0);
    
    for(ll i=0;i<n;i++){
        if(l[i]=='?')
            left.push_back(i);
        else if(!mp[l[i]].empty()){
            ll pos = *mp[l[i]].begin();
            mp[l[i]].erase(mp[l[i]].begin());
            ans.push_back({i, pos});
            vis[pos] = 1;
        } 
        else if(!mp['?'].empty()){
            ll pos = *mp['?'].begin();
            mp['?'].erase(mp['?'].begin());
            ans.push_back({i, pos});
            vis[pos] = 1;
        }
    }
    
    for(ll i=0;i<n;i++)
        if(!vis[i])
            right.push_back(i);
    
    auto itr1 = left.begin();
    auto itr2 = right.begin();
    
    while(1){
        if(itr1==left.end())
            break;
        if(itr2==right.end())
            break;
        ans.push_back({*itr1, *itr2});
        itr1++;
        itr2++;
    }
    
    ll k = ans.size();
    
    cout<<k<<endl;
    for(auto u: ans)
        cout<<u.first+1<<" "<<u.second+1<<endl;
    
    
    return 0;
}