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

bool isSubsetSum(vector<ll> set, ll n, ll sum) { 
    bool subset[n + 1][sum + 1]; 

    for (int i = 0; i <= n; i++) 
        subset[i][0] = true; 
  
    for (int i = 1; i <= sum; i++) 
        subset[0][i] = false; 
  
    for (int i = 1; i <= n; i++) { 
        for (int j = 1; j <= sum; j++) { 
            if (j < set[i - 1]) 
                subset[i][j] = subset[i - 1][j]; 
            if (j >= set[i - 1]) 
                subset[i][j] = subset[i - 1][j] || subset[i - 1][j - set[i - 1]]; 
        } 
    } 
  
    return subset[n][sum]; 
} 
 

int main(){
    fast;
    
    ll t;
    cin>>t;
    
    while(t--){
        ll n;
        cin>>n;
        
        vector<ll> arr(2*n);
        for(auto &u: arr)
            cin>>u;
            
        vector<ll> brr;
        map<ll, ll> mp;
        
        for(ll i=0;i<2*n;i++)
            mp[arr[i]] = i;
        
        ll cur = 2*n, last = 2*n;

        for(ll i=2*n-1;i>=0;i--){
            if(arr[i]==cur){
                brr.push_back(last-i);
                last = i;
                
                while(cur>0 && mp[cur]>=i)
                    cur--;
            }
        }
        
        ll sz = brr.size();
        
        cout<< (isSubsetSum(brr, sz, n) ? "YES" : "NO" )<<endl; 
    }
    
    return 0;
}