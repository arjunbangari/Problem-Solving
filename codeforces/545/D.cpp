#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    ll n;
    cin>>n;
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    ll  wtime = 0,ans=0;
    
    for(ll i=0;i<n;i++){
        if(arr[i]>=wtime){
            ans++;
            wtime+=arr[i];
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
