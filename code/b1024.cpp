#include<iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    if(s[0] == '-') cout<<'-';
    
    int pos = s.find('E');
    int pot = s.find('.');
    int k;
    for(int i=pos+2;i<s.size();i++)
        if(s[i]!='0')
        {
            k = i;
            break;
        }
    int exp = 0;
    for(int i = k;i<s.size();i++)
    {
        exp = exp*10+(s[k]-'0');
    }
    
    if(s[pos+1]=='+')
    {
        int m = pos-pot-1; //小数点后的位数
        if(m<exp)//add 0
        {
            for(int i=1;i<pos;i++)
            {
                if(s[i]!='.')
                    cout<<s[i];
            }
            for(int i=0;i<exp-m-1;i++)
                cout<<'0';
            cout<<endl;
        }
        else if(m==exp)
        {
            for(int i=1;i<pos;i++)
            {
                if(s[i]!='.')
                    cout<<s[i];
            }
            cout<<endl;
        }
        else
        {
            for(int i=1;i<pos;i++)
            {
                if(i==pot+exp+1) cout<<'.';
                if(s[i]!='.')
                    cout<<s[i];
            }
        }
    }
    else
    {
        cout<<"0.";
        for(int i = 0;i<exp-1;i++)
            cout<<'0';
        for(int i=1;i<pos;i++)
        {
            if(s[i]!='.')
                cout<<s[i];
        }
        cout<<endl;
    }
    return 0;
}
