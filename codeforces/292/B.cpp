#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,m,x,y;
    cin>>n>>m;
    
    ll sz[n+1] = {0};
    
    for(ll i=0;i<m;i++){
        cin>>x>>y;
        sz[x]++;
        sz[y]++;
    }
    
    ll cnt[n+1] = {0};
    for(ll i=1;i<=n;i++)
        cnt[sz[i]]++;
    
    string ans;
    
    if(m==n){
        ans = ( cnt[2]==n ? "ring topology" : "unknown topology");
    } else if(m==(n-1)){
        if(cnt[1]==2 && cnt[2]==(n-2))
            ans = "bus topology";
        else if(cnt[1]==(n-1) && cnt[n-1]==1)
            ans = "star topology";
        else
            ans = "unknown topology";
    } else
        ans = "unknown topology";
    
    cout<<ans<<endl;
    
    return 0;
}