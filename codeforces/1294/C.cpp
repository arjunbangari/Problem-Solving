#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    ll t,n,x,y;
    cin>>t;
    while(t--){
        cin>>n;
        vector<ll> dv;
        
        for(ll i=1;i<=sqrt(n);i++){
            if(n%i==0){
                if(n/i==i)
                    dv.push_back(i);
                else{
                    dv.push_back(i);
                    dv.push_back(n/i);
                }
            }
        }
        
        sort(dv.begin(),dv.end());
        ll sz=dv.size();
        
        if(sz>4){
            ll flag = 0;
            for(ll i=1;i<sz;i++){
                for(ll j=i+1;j<sz;j++){
                    ll a = dv[i], b=dv[j];
                    if(n%(a*b)==0){
                        ll c = n/(a*b);
                        if(c!=1 && c!=a && c!=b){
                            cout<<"YES"<<endl;
                            cout<<a<<" "<<b<<" "<<c<<endl;
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag) break;
            }
            if(!flag)
                cout<<"NO"<<endl;
        } else
            cout<<"NO"<<endl;
        
    }
    return 0;
}