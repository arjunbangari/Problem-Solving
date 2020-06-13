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
    
    // ll t;
    // cin>>t;
    
    // while(t--){
        ll n;
        cin>>n;
        
        vector<ll> arr(n), brr(n, -1);
        for(auto &u: arr)
            cin>>u;
    
        set<ll> s;
        for(auto u: arr)
            s.insert(u);
        
        for(ll i=1;i<n;i++){
            if(arr[i]!=arr[i-1])
                brr[i] = arr[i-1];
        }
        
        ll cur = 0;
        
        for(ll i=0;i<n;i++){
            if(brr[i]!=-1)
                continue;
            
            while(s.count(cur))
                cur++;
            brr[i] = cur;
            cur++;
        }
        
        // for(ll i=0;i<n;i++)
        //     cout<<brr[i]<<" ";
        // cout<<endl;
        
        vector<ll> crr(maxn, 0);
        cur = 0;
        
        for(ll i=0;i<n;i++){
            crr[brr[i]] = 1;
            while(crr[cur])
                cur++;
            
            if(arr[i]!=cur){
                cout<<-1<<endl;
                return 0;
            }
        }
        
        
        for(ll i=0;i<n;i++)
            cout<<brr[i]<<" ";
            
        cout<<endl;
        
    // }
    
    return 0;
}
