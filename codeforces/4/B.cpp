#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll d,sumtime,u,v;
    cin>>d>>sumtime;
    pair<ll,ll> arr[d];
    for(ll i=0;i<d;i++){
        cin>>u>>v;
        arr[i] = make_pair(u,v);
    }
    ll flag = 0;
    ll ans[d] = {0};
    
    for(ll i=0;i<d;i++){
        ans[i] = arr[i].first;
        sumtime -= arr[i].first;
    }
    if(sumtime<0)
        cout<<"NO"<<endl;
    else {
        for(ll i=0;i<d;i++){
            if(sumtime<0)
                break;
            ans[i] += min(sumtime,arr[i].second-arr[i].first);
            sumtime -= (arr[i].second - arr[i].first);
        }
        if(sumtime>0)
            cout<<"NO"<<endl;
        else{
            cout<<"YES"<<"\n";
            for(ll i=0;i<d;i++)
                cout<<ans[i]<<" ";
        }
    }
    
    
    return 0;
}