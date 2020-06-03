#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
typedef pair<ll,ll> pll;
#define endl "\n";
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll const inf = 1e18;
ll const maxn = 1e6+5;
ll const mod = 1e9+7;

// code begins here

bool cmp1(const pair<int,int> &a, const pair<int,int> &b) { 
    return (a.first-a.second)>(b.first-b.second);
} 

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<pll> arr(n);
    
    for(ll i=0;i<n;i++)
        cin>>arr[i].first>>arr[i].second;
    
    sort(arr.begin(), arr.end(), cmp1);
    
    ll sum = 0;
    
    for(ll i=0;i<n;i++)
        sum += arr[i].first*(i) + arr[i].second*(n-i-1);
    
    cout<<sum<<endl;
    
    return 0;
}