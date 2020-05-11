#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<pll> arr(n);
    
    for(ll i=0;i<n;i++){
        cin>>arr[i].first;
        arr[i].second = i+1;
    }
    
    if(n==2){
        cout<<1<<endl;
        return 0;
    }
        
    sort(arr.begin(), arr.end());
    
    ll d = arr[2].first - arr[1].first;
    ll flag = 1;
    
    for(ll i=3;i<n;i++){
        ll cur = arr[i].first - arr[i-1].first;
        if(cur!=d)
            flag = 0;
    }
    
    if(flag){
        cout<<arr[0].second<<endl;
        return 0;
    }
    
    d = arr[2].first - arr[0].first;
    flag = 1;
    
    for(ll i=3;i<n;i++){
        ll cur = arr[i].first - arr[i-1].first;
        if(cur!=d)
            flag = 0;
    }
    
    if(flag){
        cout<<arr[1].second<<endl;
        return 0;
    }
    
    d = arr[1].first - arr[0].first;
    flag = 1;
    ll ind=-1;
    
    for(ll i=2;i<n;i++){
        ll cur = arr[i].first - arr[i-1].first;
        if(cur!=d){
            ind = i;
            break;
        }
    }
    
    if(ind==(n-1)){
        cout<<arr[n-1].second<<endl;
        return 0;
    }
    
    if((arr[ind+1].first - arr[ind-1].first)!=d){
        cout<<-1<<endl;
        return 0;
    }
    
    for(ll i=ind+2;i<n;i++){
        ll cur = arr[i].first - arr[i-1].first;
        if(cur!=d)
            flag = 0;
    }
    
    cout<< ( flag ? arr[ind].second : -1 ) <<endl;
    
    return 0;
}