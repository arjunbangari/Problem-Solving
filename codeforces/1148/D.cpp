#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e5+5;
ll const mod = 1e9+7;

// code begins here

bool cmp1(const pll &a, const pll &b) { 
    return a.second<b.second;
} 

bool cmp2(const pll &a, const pll &b) { 
    return a.first>b.first;
} 

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    map<pll, ll> mp;
    vector<pll> arr, brr;
    for(ll i=0;i<n;i++){
        ll a,b;
        cin>>a>>b;
        if(a>b) 
            arr.push_back({a,b});
        else
            brr.push_back({a,b});
        mp[{a,b}] = i+1;
    }
    
    ll sz = arr.size();
    if(sz>(n-sz)){
        sort(arr.begin(), arr.end(), cmp1);
        
        cout<<sz<<endl;
        for(auto u: arr)
            cout<<mp[u]<<" ";
        
    } else {
        sort(brr.begin(), brr.end(), cmp2);
        
        cout<<n-sz<<endl;
        for(auto u: brr)
            cout<<mp[u]<<" ";
    }
    
    return 0;
}