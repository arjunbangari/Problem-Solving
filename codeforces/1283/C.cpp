#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    ll f[n+1],t[n+1] = {0};
    vector<ll> give;
    deque<ll> take;
    for(ll i=1;i<=n;i++){
        cin>>f[i];
        if(f[i]==0)
            give.push_back(i);
        else
            t[f[i]] = 1;
    }

    for(ll i=1;i<=n;i++)
        if(t[i]==0)
            take.push_back(i);
    
    ll sg = give.size();
    
    sort(give.begin(),give.end());
    
    for(ll i=0;i<sg-2;i++){
        if(take.front()!=give[i]){
            f[give[i]] = take.front();
            take.pop_front();
        } else {
            f[give[i]] = take.back();
            take.pop_back();
        }
    }
    
    if(take.front()==give[sg-2]){
        f[give[sg-2]]  = take.back();
        f[give[sg-1]] = take.front();
    } else if (take.back()==give[sg-1]){
        f[give[sg-2]] = take.back();
        f[give[sg-1]] = take.front();
    } else {
        f[give[sg-2]] = take.front();
        f[give[sg-1]] = take.back();
    }
    
    
    for(ll i=1;i<=n;i++)
        cout<<f[i]<<endl;
    
    return 0;
}