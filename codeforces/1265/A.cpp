#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)

int main(){
    fast;
    ll t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        s = '?' + s + '?';
    
        for(ll i=1;i<s.length()-1;i++){
            if(s[i]=='?'){
                ll arr[3] = {0,0,0};
                if(s[i-1]=='a' || s[i+1]=='a')
                    arr[0]++;
                if(s[i-1]=='b' || s[i+1]=='b')
                    arr[1]++;
                if(s[i-1]=='c' || s[i+1]=='c')
                    arr[2]++;
                if(arr[0]==0)
                    s[i] = 'a';
                else if(arr[1]==0)
                    s[i] = 'b';
                else
                    s[i] = 'c';
            }
        }
        ll flag = 0;
        for(ll i=1;i<s.length()-1;i++){
            //cout<<s[i];
            if(s[i]==s[i-1] || s[i]==s[i+1]){
                flag = 1;
                break;
            }
        }
        if(flag)
           cout<<-1;
        else
            for(ll i=1;i<s.length()-1;i++)
                cout<<s[i];
        cout<<"\n";
           
    }
    
    return 0;
}