#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 2e5+5;
ll const mod = 1e9+7;

// code begins here

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(2*n);
    for(auto &u: arr)
        cin>>u;
    
    sort(arr.begin(), arr.end());
    ll sum1 = 0, sum2 = 0;
    
    for(ll i=0;i<2*n;i++){
        if(i<n)
            sum1 += arr[i];
        else
            sum2 += arr[i];
    }
    
    if(sum1==sum2){
        cout<<-1<<endl;
    } else {
        for(auto u: arr)
            cout<<u<<" ";
    }
    
    return 0;
}