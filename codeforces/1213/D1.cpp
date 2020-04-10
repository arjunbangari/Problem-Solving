#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,k, ans=1e18;
    cin>>n>>k;
    
    ll arr[n];
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    
    ll sz[200005] = {0};
    vector<ll> v[200005];
    ll to_zero=0;
    
    for(ll i=0;i<n;i++){
        ll temp = 0;
        while(arr[i]>0){
            v[arr[i]].push_back(temp);
            sz[arr[i]]++;
            arr[i] /= 2;
            temp++;
        }
        to_zero += temp;
    }
    
    for(ll i=0;i<=200000;i++){
        if(sz[i]>=k){
            sort(v[i].begin(), v[i].end());
            ll sum = 0;
            for(ll j=0;j<k;j++)
                sum += v[i][j];
            ans = min(ans, sum);
        }
    }
    
    cout<<min(ans, to_zero)<<endl;
    
    return 0;
}