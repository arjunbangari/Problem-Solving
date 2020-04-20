#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// code begins here

int main(){
    fast;
    
    ll n,k;
    cin>>n>>k;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
        
    set<ll, greater <ll>> ms;
    map<ll,ll> index;

    for(ll i=0;i<n;i++){
        ms.insert(arr[i]);
        index[arr[i]] = i;
    }
    
    vector<ll> vis(n, 0);
    
    ll team = 1;
    vector<ll> teams(n);
    
    map<ll,ll> mp_left;
    map<ll,ll> mp_right;
    
    while(!ms.empty()){
        ll val = *ms.begin();
        ms.erase(*ms.begin());
        ll pos = index[val];
        vis[pos] = 1;
        teams[pos] = team;
        
        ll temp_count = 1, i=pos+1, left, right;
        
        while(temp_count<=k && i<n){
            if(vis[i])
                i = mp_right[i]+1;
            else{
                vis[i] = 1;
                ms.erase(arr[i]);
                teams[i] = team;
                temp_count++;
                i++;
            }
        }
        
        right = i-1;
        i = pos-1;
        temp_count = 1;
        
        while(i>=0 && temp_count<=k){
            if(vis[i])
                i = mp_left[i]-1;
            else{
                vis[i] = 1;
                ms.erase(arr[i]);
                teams[i] = team;
                temp_count++;
                i--;
            }
        }
        
        left = i+1;
        mp_left[right] = left;
        mp_right[left] = right;
        
        team = (team==1 ? 2 : 1);
    }

    for(ll i=0;i<n;i++)
        cout<<teams[i];
    
    return 0;
}