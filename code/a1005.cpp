#include<iostream>
#include<map>
using namespace std;

int main()
{
    string s;
    cin>>s;
    map<char,string> m;
    m['0'] = "zero"; m['3'] = "three"; m['6'] = "six";
    m['1'] = "one";  m['4'] = "four";   m['7'] = "seven";
    m['2'] = "two"; m['5'] = "five";    m['8'] = "eight"; m['9'] = "nine";
    int sum = 0;
    for(int i=0;i<s.size();i++)
        sum += (s[i]-'0');
    
    string res = to_string(sum);
    
//     cout<<s<<endl<<sum<<endl;
    for(int i=0;i<res.size();i++)
    {
        cout<<m[res[i]];
        if(i!=res.size()-1) cout<<' ';
    }
    
    cout<<endl;
    return 0;
}
