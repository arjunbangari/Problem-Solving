#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,m,a,b;
    cin>>n>>m;
    
    ll cnt[n+1] = {0};
    for(ll i=0;i<n;i++){
        cin>>a>>b;
        cnt[a]++;
        cnt[b]++;
    }
    
    ll node;
    for(ll i=1;i<=n;i++)
        if(!cnt[i])
            node = i;
    
    cout<<n-1<<endl;
    for(ll i=1;i<=n;i++){
        if(i!=node)
            cout<<i<<" "<<node<<endl;
    }
    
    return 0;
}