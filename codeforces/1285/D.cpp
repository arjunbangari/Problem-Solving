#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll func(vector<ll> v , ll cur){
    if(v.size()==0 || cur<0)
        return 0;
    vector<ll> one,zero;
    for(ll i: v){
        string s = bitset<30>(i).to_string();
        if(s[30-cur]=='1')
            one.push_back(i);
        else
            zero.push_back(i);
    }
    
    if(one.size()==0)
        return func(zero,cur-1);
    if(zero.size()==0)
        return func(one,cur-1);
    return (1<<(cur-1)) + min(func(one,cur-1), func(zero,cur-1));
}

int main(){
    fast;
    ll n;
    cin>>n;
    vector<ll> arr(n);
    for(ll i=0;i<n;i++)
        cin>>arr[i];
    cout<<func(arr,30)<<endl;
    return 0;
}