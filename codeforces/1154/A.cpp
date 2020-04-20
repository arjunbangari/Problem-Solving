#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7l;

// code begins here

int main(){
    fast;
    
    ll arr[4];
    for(ll i=0;i<4;i++)
        cin>>arr[i];
    sort(arr, arr+4);
    
    cout<<arr[3] - arr[0]<<" "<<arr[3] - arr[2]<<" "<<arr[3] - arr[1]<<endl;
    
    
    
    return 0;
}