#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,k,x,y;
    cin>>n>>k;
    
    map<ll,ll> start;
    ll quarrels[n] = {0};
    
    ll skill[n], ans[n], temp[n];
    for(ll i=0;i<n;i++){
        cin>>skill[i];
        temp[i] = skill[i];
    }
    
    sort(temp, temp + n);
    
    ll i=0;
    while(i<n){
        start[temp[i]] = i;
        ll j = i+1;
        while(j<n && temp[j]==temp[i])
            j++;
        i = j;
    }
    
    while(k--){
        cin>>x>>y;
        x--;
        y--;
        if(skill[x]>skill[y])
            quarrels[x]++;
        if(skill[y]>skill[x])
            quarrels[y]++;
    }
    
    for(ll i=0;i<n;i++){
        ll num = start[skill[i]] - quarrels[i];
        ans[i] = num;
    }
    
    for(ll i=0;i<n;i++)
        cout<<ans[i]<<" ";
    
    return 0;
}