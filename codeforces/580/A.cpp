#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    fast; 
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll ans=0,i=0,j=0;
    
    while(i<n){
        j++;
        while(j<n && arr[j]>=arr[j-1])
            j++;
        
        if((j-i)>ans)
            ans = j-i;
        i = j;
    }
    cout<<ans<<"\n";
        
    return 0;
}
