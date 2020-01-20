#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll num,a,b,c;
map<ll,ll> mp;

ll dp(ll n){
    if(n<0)
        return -1e7;
    if (n==0)
        return 0;
    if(mp.find(n)!=mp.end())
        return mp[n];
    ll ans = 1 + max(dp(n-a),max(dp(n-b),dp(n-c)));
    mp[n] = ans;
    return ans;
}

int main(){
    fast;
    cin>>num>>a>>b>>c;
    cout<<dp(num)<<endl;
    return 0;
}