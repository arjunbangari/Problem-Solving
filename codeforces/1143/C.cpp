#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    
    ll n,a;
    cin>>n;
    
    vector<ll> v[n+1], c(n+1);
    
    for(ll i=1;i<=n;i++){
        cin>>a>>c[i];
        if(a!=-1)
            v[a].push_back(i);
    }
    
    vector<ll> ans;
    
    for(ll i=1;i<=n;i++){
        if(c[i]==1){
            ll flag = 0;
            for(ll u: v[i]){
                if(!c[u]){
                    flag = 1;
                    break;
                }
            }
            if(!flag)
                ans.push_back(i);
        }
    }
    
    if((ll)ans.size()==0)
        cout<<-1<<endl;
    else{
        for(ll u: ans)
            cout<<u<<" "; 
    }
    
    return 0;
}