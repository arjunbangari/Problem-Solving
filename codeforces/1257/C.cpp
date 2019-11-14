#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n+1];
        ll mem[n+1] = {0};
        ll ans = 10000000;
        for(ll i=1;i<=n;i++){
            cin>>arr[i];
            if(mem[arr[i]]!=0){
                ans = min(ans, i-mem[arr[i]]);
                mem[arr[i]] = i;
            }
            else{
                mem[arr[i]]= i;
            }
        }
        if(ans==10000000){
            cout<<-1<<"\n";
        } else
            cout<<ans+1<<"\n";
    }
    return 0;
}
