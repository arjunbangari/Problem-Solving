#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        ll arr[n];
        ll ans[n] = {0};
        for(ll i=0;i<n;i++){
            cin>>arr[i];
            arr[i]--;
        }

        for(ll i=0;i<n;i++){
            if(ans[i]==0){
                vector <ll> temp;
                temp.push_back(i);
                ll j = arr[i];
                ll count = 1;
                while(j!=i){
                    temp.push_back(j);
                    j = arr[j];
                    count++;
                }
                for(ll i=0;i<temp.size();i++){
                    ans[temp[i]] = count;
                }
            }
        }
        for(ll i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
