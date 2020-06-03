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
    
    vector<ll> arr(n);
    for(auto &u: arr)
        cin>>u;
        
    map<ll, ll> mp1;  
    ll ans = inf;
    
    for(ll i=0;i<n;i++){
        map<ll, ll> mp2;
        ll j = n-1;
        while(j>=i){
            if(mp1[arr[j]] || mp2[arr[j]])
                break;
            mp2[arr[j]]++;
            j--;
        }
        if(j<=i)
            ans = n;
        ans = min(ans, j-i+1);
        if(mp1[arr[i]])
            break;
        mp1[arr[i]]++;
    }
    
    cout<<ans<<endl;
    
    return 0;
}