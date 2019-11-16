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
    
    ll ans = 0;
    int flag = 0;
    
    for(ll i=0;i<n;i++){
        if(arr[i]==i)
            ans++;
        else{
            if(arr[arr[i]]==i)
                flag = 1;
        }
    }
    
    if(flag==1)
        ans+=2;
    else if(ans!=n)
        ans++;
    cout<<ans<<"\n";
    
    return 0;
}
