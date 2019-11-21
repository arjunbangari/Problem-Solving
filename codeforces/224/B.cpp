#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);
int main(){
    fast;
    ll n,k;
    cin>>n>>k;
    ll arr[n];
    map<int, int> mp;
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    ll i;
    for(i=0;i<n;i++){
        mp[arr[i]]++;
        //cout<<arr[i]<<" "<<mp.size()<<"\n";
        if(mp.size()>=k)
            break;
    }
    if (mp.size()<k)
        cout<<-1<<" "<<-1;
    else{
        ll j;
        for(j=0;j<i;j++){
            mp[arr[j]]--;
            if(mp[arr[j]]==0)
                break;
        }
        cout<<j+1<<" "<<i+1;
        
    }
    return 0;
}
