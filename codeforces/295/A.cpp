#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,m,k,x,y;
    cin>>n>>m>>k;
    ll arr[n+2];
    for(ll i=1;i<=n;i++)
        cin>>arr[i];
    
    ll operations[m+1][3];
    for(ll i=1;i<=m;i++)
        cin>>operations[i][0]>>operations[i][1]>>operations[i][2];
        
    ll freq[m+2] = {0};
    
    for(ll i=0;i<k;i++){
        cin>>x>>y;
        freq[x]++;
        freq[y+1]--;
    }
    
    for(ll i=1;i<=m;i++)
        freq[i] += freq[i-1];
    
    ll temp[n+2] = {0};
        
    for(ll i=1;i<=m;i++){
        ll val = operations[i][2]*freq[i];
        temp[operations[i][0]]+=val;
        temp[operations[i][1]+1] -= val;
    }
    
    for(ll i=2;i<=n;i++)
        temp[i] += temp[i-1];
    
    for(ll i=1;i<=n;i++)
        cout<<arr[i]+temp[i]<<" ";
    cout<<endl;
    
    return 0;
}