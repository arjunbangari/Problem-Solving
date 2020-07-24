#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n,m,a,b,ind;
    cin>>n>>m;
    
    vector<ll> arr(n), brr(m);
    
    cin>>a;
    for(ll i=0;i<a;i++){
        cin>>ind;
        arr[ind] = 1;
    }
    
    cin>>b;
    for(ll i=0;i<b;i++){
        cin>>ind;
        brr[ind] = 1;
    }
    
    ll i = 0;
    while(i<=1e7){
        ll temp1 = i%n;
        ll temp2 = i%m;
        if(arr[temp1] || brr[temp2]){
            arr[temp1] = 1;
            brr[temp2] = 1;
        }
        i++;
    }
    
    ll flag = 0;
    
    for(ll i=0;i<n;i++)
        if(!arr[i])
            flag = 1;
    
    for(ll j=0;j<m;j++)
        if(!brr[j])
            flag = 1;
    
    cout<< ( flag ? "No" : "Yes" )<<endl;
    
    return 0;
}