#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll n;
    cin>>n;
    ll arr[n][n];
    
    ll posi,posj;
    
    for(ll i=0;i<n;i++){
        for(ll j=0;j<n;j++){
            cin>>arr[i][j];
            if(arr[i][j]==0){
                posi = i;
                posj = j;
            }
        }
    }
    
    set<ll> s;
    
    for(ll i=0;i<n;i++){
        if(i!=posi){
            ll temp = 0;
            for(ll j=0;j<n;j++){
                temp += arr[i][j];
            }
            s.insert(temp);
        }
    }
    
    for(ll i=0;i<n;i++){
        if(i!=posj){
            ll temp=0;
            for(ll j=0;j<n;j++){
                temp += arr[j][i];
            }
            s.insert(temp);
        }
    }

    if(posi!=posj){
        ll temp=0;
        for(ll i=0;i<n;i++)
            temp += arr[i][i];
        s.insert(temp);
    }
    if(posi!=(n-posj-1)){
        ll temp=0;
        for(ll i=0;i<n;i++)
            temp += arr[i][n-i-1];
        s.insert(temp);
    }
    
    ll sz = s.size();
    if(n==1)
        cout<<1<<endl;
    else if(sz!=1)
        cout<<-1<<endl;
    else{
        ll res = *s.begin();
        set<ll> s2;
        ll val1=0,val2=0;
        for(ll i=0;i<n;i++){
            val1 += arr[posi][i];
            val2 += arr[i][posj];
        }
        s2.insert(val1);
        s2.insert(val2);
        
        if(posi==posj){
            val1 = 0;
            for(ll i=0;i<n;i++)
                val1 += arr[i][i];
            s2.insert(val1);
        } else if(posi==(n-posj-1)){
            val1 = 0;
            for(ll i=0;i<n;i++)
                val1 += arr[i][n-i-1];
            s2.insert(val1);
        }
        
        ll sz2 = s2.size();
        if(sz2==1){
            ll v = *s2.begin();
            if(v<res)
                cout<<res-v<<endl;
            else
                cout<<-1<<endl;
        } else
            cout<<-1<<endl;
    }
    
    return 0;
}