#include <bits/stdc++.h>
using namespace std;
 
typedef long long int ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
 
ll const inf = 1e18;
ll const maxn = 2e6+5;
ll const mod = 1e9+7;
 
// code begins here

int main(){
    fast;
    
    ll n, haszero=0, sum=0;
    cin>>n;
    
    vector<ll> arr(n);
    for(auto &u: arr){
        cin>>u;
        if(u==0)
            haszero = 1;
        sum += u;
    }
    
    if(!haszero){
        cout<<-1<<endl;
        return 0;
    }
        
    map<ll, vector<ll>> mp;
    
    for(auto u: arr)
        mp[u%3].push_back(u);
    
    vector<ll> ans;
    
    for(auto u: mp[0])
        ans.push_back(u);
    
    sort(mp[1].rbegin(), mp[1].rend());
    sort(mp[2].rbegin(), mp[2].rend());

    if(sum%3==1){
        if(!mp[1].empty())
            mp[1].pop_back();
        else{
            mp[2].pop_back();
            mp[2].pop_back();
        }
    }
    
    if(sum%3==2){
        if(!mp[2].empty())
            mp[2].pop_back();
        else{
            mp[1].pop_back();
            mp[1].pop_back();
        }
    }
    
    for(auto u: mp[1])
        ans.push_back(u);
    for(auto u: mp[2])  
        ans.push_back(u);
    
    sort(ans.rbegin(), ans.rend());
    
    if(ans[0]==0){
        cout<<0<<endl;
        return 0;
    }
    
    for(auto u: ans)
        cout<<u;
    
    return 0;
}