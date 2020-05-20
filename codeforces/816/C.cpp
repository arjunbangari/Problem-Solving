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
ll arr[105][105], brr[105][105];
ll n,m;

void transpose() { 
    for (ll i = 0; i < m; i++) 
        for (ll j = 0; j < n; j++) 
            brr[i][j] = arr[j][i]; 
    
    swap(n,m);
    
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            arr[i][j] = brr[i][j];
        
} 

int main(){
    fast;

    cin>>n>>m;
    
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            cin>>arr[i][j];
    
    ll flag = 0;
    
    if(m<n){
        transpose();
        flag = 1;
    }
    
    for(ll i=0;i<n;i++)
        for(ll j=0;j<m;j++)
            brr[i][j] = 0;
        
    ll minimum;
    vector<pair<string, ll>> ans;
    
    for(ll i=0;i<n;i++){
        ll mn = inf;
        for(ll j=0;j<m;j++){
            mn = min(mn, arr[i][j]);
        }
        
        if(i==0)
            minimum = mn;
        
        for(ll j=0;j<m;j++)
            brr[i][j] = mn;
        
        while(mn){
            if(flag)
                ans.push_back({"col", i+1});
            else
                ans.push_back({"row", i+1});
            mn--;
        }
    }
    
    for(ll j=0;j<m;j++){
        if(arr[0][j]>minimum){
            ll diff = arr[0][j] - minimum;
            
            for(ll i=0;i<n;i++)
                brr[i][j] += diff;
            
            while(diff){
                if(flag)
                    ans.push_back({"row", j+1});
                else
                    ans.push_back({"col", j+1});
                diff--;
            }
        }
    }
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<m;j++){
            if(arr[i][j]!=brr[i][j]){
                cout<<-1<<endl;
                return 0;
            }
        }
    }
    
    ll sz = ans.size();
    
    cout<<sz<<endl;
    
    for(auto u: ans)
        cout<<u.first<<" "<<u.second<<endl;
    
    return 0;
}