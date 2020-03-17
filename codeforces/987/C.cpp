#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    ll size[n], cost[n];
    for(ll i=0;i<n;i++) 
        cin>>size[i];
    
    for(ll i=0;i<n;i++)
        cin>>cost[i];
    
    ll ans = 1e12;
    
    for(ll i=1;i<n-1;i++){
        ll cost1=1e10 , cost2=1e10;
        for(ll j=0;j<i;j++)
            if(size[j]<size[i])
                cost1 = min(cost1, cost[j]);
        
        for(ll j=i+1;j<n;j++)
            if(size[j]>size[i])
                cost2 = min(cost2, cost[j]);
        
        ll temp = cost[i] + cost1 + cost2;
        ans = min(temp,ans);
    }
     
    cout<< (ans>1e9 ? -1 : ans)<<endl;   
    
    return 0;
}