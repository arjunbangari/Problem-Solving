#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)



int main(){
    fast;
    ll l,r,k;
    cin>>l>>r>>k;
    
    vector<ll> ans;
    
    ll steps=0, temp=r;
    
    while(temp>0){
        temp/=k;
        steps++;
    }
    steps--;
    
    ll res=1;
    ans.push_back(1);
    
    while(steps--){
        res *= k;
        ans.push_back(res);
    }
    
    ll flag = 0;
    for(ll i : ans){
        if(i>=l && i<=r){
            cout<<i<<" ";
            flag = 1;
        }
    }
    
    if(!flag)
        cout<<-1<<endl;
    
    
    return 0;
}