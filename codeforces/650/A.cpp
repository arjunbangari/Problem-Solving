#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,x,y,ans=0;
    cin>>n;
    map<ll,ll> mpx,mpy;
    map<pair<ll,ll>,ll> mp;
    for(ll i=0;i<n;i++){
        cin>>x>>y;
        auto temp = make_pair(x,y);
        mpx[x]++;
        mpy[y]++;
        mp[temp]++;
    }
    
    for(auto i: mpx)
        ans += (i.second*(i.second-1))/2;
    for(auto i: mpy)
        ans += (i.second*(i.second-1))/2;
    for(auto i: mp)
        ans -= (i.second*(i.second-1))/2;
    
    
    cout<<ans<<"\n";
        
    return 0;
}