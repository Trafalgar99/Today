#include<iostream>
#include<map>
using namespace std;

int main()
{
    string s;
    map<char,int>M;
    M['P']=0;M['A']=0;M['T']=0;M['e']=0;M['s']=0;M['t']=0;
    cin>>s;
    for(auto e:s)
    {
        if(M.count(e)>0)
        {
            M[e]++;
        }
    }
    string str = "PATest";
    for(int i=0;;i++)
    {
        if((M['P']+M['A']+M['T']+M['e']+M['s']+M['t'])!=0)
        {
            if(M[str[i]]>0)
            {
                cout<<str[i];
                M[str[i]]--;
            }
            else
            {
                continue;
            }
        }
        else
        {
            break;
        }
    }

}
