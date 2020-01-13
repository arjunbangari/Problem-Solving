#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

int main(){
    fast;
    string arr;
    cin>>arr;
    ll n=arr.length() , flag=0,l;
    ll count[n];
    count[0] = (arr[0]=='?' ? 1 : 0 );
    for(ll i=1;i<n;i++)
        count[i] = (arr[i]=='?' ? count[i-1]+1 : count[i-1]);
    
    for(ll i=0;i<=n-26;i++){
        set<char> st;
        for(ll j=i;j<i+26;j++)
            st.insert(arr[j]);
        if((count[i+25]-((i-1)==-1 ? 0 : count[i-1]) + st.size()-1)==26){
            flag = 1;
            l = i;
            break;
        }
    }
    
    if(flag==1){
        unordered_set<char> us;
        stack<ll> ind;
        for(ll i=l;i<l+26;i++){
            if(arr[i]=='?')
                ind.push(i);
            else
                us.insert(arr[i]);
        }
        
        string al("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
        for(ll i=0;i<26;i++){
            if(us.find(al[i])==us.end()){
                ll val = ind.top();
                ind.pop();
                arr[val] = al[i];
            }
        }
        for(ll i=0;i<n;i++){
            if(arr[i]=='?')
                arr[i] = 'A';
        }
        cout<<arr<<endl;
    } else if(count[n-1]==0){
        ll sflag=0;
        for(ll i=0;i<=n-26;i++){
            set<char> st;
            for(ll j=i;j<i+26;j++)
                st.insert(arr[j]);
            if(st.size()==26){
                sflag=1;
                break;
            }
        }
        if(sflag)
            cout<<arr<<endl;
        else
            cout<<-1<<endl;
    } else {
        cout<<-1<<endl;
    }
    
    return 0;
}