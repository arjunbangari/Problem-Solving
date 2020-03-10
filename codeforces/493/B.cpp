#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

ll lex(vector<ll> a, vector<ll> b){
    ll sz = min(a.size(),b.size());
    ll i=0;
    while(i<sz && a[i]==b[i])
        i++;
    if(i==sz){
        if(a.size()==b.size())
            return -1;
        else if(a.size()==sz)
            return 2;
        else
            return 1;
    } else {
        if(a[i]>b[i])
            return 1;
        else
            return 2;
    }
}

int main(){
    fast;
    ll n,last, fsum=0, ssum=0, val;
    cin>>n;
    vector<ll> first, second;
    
    for(ll i=0;i<n;i++){
        cin>>val;
        if(val>0){
            first.push_back(val);
            fsum += val;
            last = 1;
        } else {
            second.push_back(abs(val));
            ssum += abs(val);
            last = 2;
        }
    }
    
    if(fsum==ssum){
        ll temp = lex(first,second);
        if(temp==-1)
            cout<< ( last==1 ? "first" : "second" )<<endl;
        else
            cout<< ( temp==1 ? "first" : "second" )<<endl;
    } else {
        cout<< ( fsum>ssum ? "first" : "second" )<<endl;
    }
    
    return 0;
}