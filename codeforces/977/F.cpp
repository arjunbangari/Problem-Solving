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
    
    vector<ll> arr(n);
    for(auto &i: arr)
        cin>>i;
        
    map<ll, ll> mp;
    
    for(auto u : arr)
        mp[u] = mp[u-1] + 1;
    
    ll mx=-1, val;
    
    for(auto u: mp){
        if(u.second>mx)
            val = u.first;
        mx = max(mx, u.second);
    }
    
    vector<ll> indices;
    
    for(ll i=n-1;i>=0;i--){
        if(arr[i]==val){
            indices.push_back(i+1);
            val--;
        }
    }
    
    reverse(indices.begin(), indices.end());
    
    cout<<mx<<endl;
    for(auto u: indices)
        cout<<u<<" ";
    
    return 0;
}