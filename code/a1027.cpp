#include<iostream>
#include<string>
#include<map>

using namespace std;

int main()
{
    map<int,char> m;
    m[10] = 'A';
    m[11] = 'B';
    m[12] = 'C';
    int color[3];
    for(int i=0;i<3;i++)
        cin>>color[i];
    string s = "#";
    
    for(int i=0;i<3;i++)
    {
        int a = color[i]/13;int b = color[i]%13;
        if(a<10)
            s+=to_string(a);
        else 
            s+=m[a];
        if(b<10)
            s+=to_string(b);
        else
            s+=m[b];
    }
    cout<<s<<endl;
    
    return 0;
}
