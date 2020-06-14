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

int main(){
    fast;
    
    ll n;
    cin>>n;
    
    vector<ll> arr(n), cnt(5, 0), brr;
    for(auto &u: arr)
        cin>>u;

    for(auto u: arr)
        cnt[u]++;
    
    if(cnt[1]>=3){
        brr.push_back(1);
        brr.push_back(1);
        brr.push_back(1);
        cnt[1] -= 3;
    }
    else if(cnt[1]>=1 && cnt[2]>=1){
        brr.push_back(2);
        brr.push_back(1);
        cnt[1]--;
        cnt[2]--;
    }
    
    while(cnt[2]){
        brr.push_back(2);
        cnt[2]--;
    }
    
    while(cnt[1]){
        brr.push_back(1);
        cnt[1]--;
    }
    
    for(auto u: brr)
        cout<<u<<" ";
    
    
    
    
    return 0;
}
