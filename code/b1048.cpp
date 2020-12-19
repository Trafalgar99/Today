#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
    string s1,s2;
    cin>>s1>>s2;
    string res = "";
    map<int,char>m;
    for(int i=0;i<10;i++)
        m[i] = '0'+i;
    m[10] = 'J';m[11] = 'Q';m[12] = 'K';
    if(s1.size()<s2.size())
    {
        string aux = "";
        for(string::size_type i=0;i<s2.size()-s1.size();i++)
            aux+='0';
        s1 = aux+s1;
    }
    if(s1.size()>s2.size())
    {
        string aux = "";
        for(string::size_type i=0;i<s1.size()-s2.size();i++)
            aux+='0';
        s2 = aux+s2;
    }
    

    for(int i=s2.size()-1,k=1;i>=0;i--,k++)
    {
        if(k%2==1)
        {
            res += m[((s2[i]-'0')+(s1[i]-'0'))%13];
        }
        else
        {
            int mid = s2[i]-'0'-(s1[i]-'0');
            if(mid<0) mid+=10;
            res += m[mid];
        }
    }
    string::size_type mm = res.size();
    for(int i=mm-1;i>=0;i--)
        cout<<res[i];
    cout<<endl;
    return 0;
}
