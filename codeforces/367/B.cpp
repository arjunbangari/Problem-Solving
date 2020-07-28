#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define all(v) (v).begin(),(v).end()
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n,m,p;
    cin>>n>>m>>p;
    
    vector<ll> arr(n), brr(m), vis(n);
    for(auto &u: arr)
        cin>>u;
    for(auto &u: brr)
        cin>>u;
    
    map<ll, ll> mp;
    for(auto u: brr)
        mp[u]++;
    
    vector<ll> ans;
    ll cnt = 0 ;
    
    for(ll i=0;i<n;i++){
        if((i+p*(m-1))>=n)
            break;
            
        if(!vis[i]){
            map<ll, ll> mp1;
            set<ll> s;
            
            for(ll j=i;j<= i + p*(m-1); j+=p){
                mp1[arr[j]]++;
                if(mp1[arr[j]]>mp[arr[j]])
                    s.insert(arr[j]);
            }
            
            ll l = i, r = i + p*(m-1);
            while(r<n){
                vis[l] = 1;
                if(s.empty()){
                    cnt++;
                    ans.push_back(l+1);
                }
                
                if((r+p)>=n)
                    break;
                r += p;
                
                mp1[arr[l]]--;
                if(mp1[arr[l]]<=mp[arr[l]])
                    s.erase(arr[l]);
                
                mp1[arr[r]]++;
                if(mp1[arr[r]]>mp[arr[r]])
                    s.insert(arr[r]);
                
                l += p;
            }
            
        }
    }
    
    // BRUTE FORCE
    
    // for(ll i=0;i<n;i++){
    //     if((i+p*(m-1))>=n)
    //         break;
        
    //     map<ll, ll> mp1;
    //     ll flag = 1;
    //     for(ll j=i;j<=i + p*(m-1);j+=p){
    //         mp1[arr[j]]++;
    //         if(mp1[arr[j]]>mp[arr[j]]){
    //             flag = 0;
    //             break;
    //         }
    //     }
        
    //     if(flag){
    //         cnt++;
    //         ans.push_back(i+1);
    //     }
    // }
    
    sort(ans.begin(), ans.end());
    
    cout<<cnt<<endl;
    for(auto u: ans)
        cout<<u<<" ";
    
    return 0;
}