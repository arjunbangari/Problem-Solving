#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define endl "\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

string nexts(string s) { 
    if (s == "") 
        return "a"; 
    int i = s.length() - 1; 
    while (s[i] == 'z' && i >= 0) 
        i--; 
    s[i++]++;
    while(i<s.length())
        s[i++] = 'a';
    return s;  
} 

int main(){
    fast;
    string s,t;
    cin>>s>>t;
    string k = nexts(s);
    if(k==t)
        cout<<"No such string"<<endl;
    else
        cout<<k<<endl;
    
    return 0;
}