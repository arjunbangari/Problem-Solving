#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
int main(){ 
    fast;
    ll n,x;
    cin>>n>>x;
    ll left=0,num=0,right=0,temp;
    for(ll i=0;i<n;i++){
        cin>>temp;
        if(temp==x) num++;
        else if (temp<x) left++;
        else right++;
    }
    ll ans=0;
    if(num==0){
        num++;
        n++;
        ans++;
    }
    ll med=(n+1)/2;
        
    if(med<=left){
        while(med<=left){
            n++;
            ans++;
            med = (n+1)/2;
        }
    }
    else if(med>(left+num)){
        while(med>(left+num)){
            left++;
            n++;
            ans++;
            med=(n+1)/2;
        }
    }
    cout<<ans<<"\n";
    
    
    return 0;
}