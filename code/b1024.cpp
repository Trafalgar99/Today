#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s;
    cin>>s;
    if(s[0] == '-') cout<<'-';
    
    int pos = s.find('E');

//     cout<<pot<<endl;

    int exp = 0;
    for(int i = pos+2;i<s.size();i++)
    {
        exp = exp*10+(s[i]-'0');
    }
    
    if(exp == 0)
    {
        for(int i=1;i<pos;i++)
            cout<<s[i];
    }
    
    if(s[pos+1]=='+')
    {   
        for(int i=1;i<pos;i++)
        {
            if(s[i]=='.') continue;
            cout<<s[i];
            if(i==exp+2&&pos-3!=exp)
                cout<<'.';

        }
        for(int i=0;i<exp-(pos-3);i++)
        cout<<'0'<<endl;

    }
    else
    {
        cout<<"0.";
        for(int i = 0;i<exp-1;i++)
            cout<<'0';
        cout<<s[1];
        for(int i=3;i<pos;i++)
        {
//             if(s[i]=='.') continue;
            cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}
