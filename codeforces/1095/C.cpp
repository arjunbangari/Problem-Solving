#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

int main(){
    ll n,k;
    cin>>n>>k;
    string binary = bitset<32>(n).to_string();
    ll count=0;
    ll max_count= 0;
    queue<ll> q;
    
    for(ll i=0;i<32;i++){
        if(binary[i]=='1'){
            count++;
            ll temp = (ll)(pow(2,31-i));
            max_count+= temp;
            q.push(temp);
        }
    }
    
    if(count>k || max_count<k){
        cout<<"NO"<<endl;
    } else {
        while(count!=k){
            ll val = q.front();
            q.pop();
            if(val!=1){
                q.push(val/2);
                q.push(val/2);
                count++;
            } else 
                q.push(val);
        }
        cout<<"YES"<<endl;
        while(!q.empty()){
            cout<<q.front()<<" ";
            q.pop();
        }
    }
    
    return 0;
}
