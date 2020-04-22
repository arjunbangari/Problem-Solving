#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,m;
    cin>>n>>m;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll cnt[m] = {0};
    map<ll, vector<ll>> mp;
    
    queue<ll> extras;
    
    for(ll i=0;i<n;i++){
        cnt[arr[i]%m]++;
        mp[arr[i]%m].push_back(i);
    }

    ll req = n/m, mn=0;
    
    for(ll j=0;j<2;j++){
        for(ll i=0;i<m;i++){
            ll dif = cnt[i] - req;
            if(dif>0){
                for(ll j=0;j<dif;j++)
                    extras.push(mp[i][j]);
                cnt[i] = req;
            }
            
            else {
                dif = abs(dif);
                while(!extras.empty() && dif--){
                    ll val = extras.front();
                    extras.pop();
                    cnt[i]++;
                    mn += (i - arr[val]%m + m )%m;
                    arr[val] += (i - arr[val]%m + m )%m;
                }
            }
        }
    }
    
    cout<<mn<<endl;
    for(ll i=0;i<n;i++)
        cout<<arr[i]<<" ";
    
    return 0;
}