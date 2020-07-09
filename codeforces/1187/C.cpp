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
    
    ll n,m;
    cin>>n>>m;
    
    vector<ll> arr(n+5), tmp(n+5);
    map<ll, vector<pll>> mp;
    
    for(ll i=0;i<m;i++){
        ll t,l,r;
        cin>>t>>l>>r;
        mp[t].push_back({l, r});
        
        if(t==1){
            for(ll j=l;j<r;j++)
                tmp[j] = 1;   
        }
    }
    
    arr[1] = 1000;
    for(ll i=1;i<n;i++){
        if(tmp[i])
            arr[i+1] = arr[i];
        else
            arr[i+1] = arr[i] - 1;
    }
    
    ll flag = 0;
    
    for(auto u: mp[0]){
        ll l = u.first, r = u.second, x = 1;
        for(ll i=l;i<r;i++){
            if(arr[i]>arr[i+1])
                x = 0;
        }
        if(x)
            flag = 1;
    }
    
    if(flag){
        cout<<"NO"<<endl;
        return 0;
    }

    cout<<"YES"<<endl;
    for(ll i=1;i<=n;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    
    return 0;
}