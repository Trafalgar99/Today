#include<iostream>
#include<string>

using namespace std;

int main()
{
    int a,b;
    cin>>a>>b;
    int sum = a+b;
    if(sum<0) 
    {
        sum = -sum;
        cout<<'-';
    }
    string s = to_string(sum);
    
    string res = "";
    
    int k=0;
    for(int i=s.size()-1;i>=0;i--,k++)
    {
       if(k==3)
        {
            res+=',';
            k =0;
        }
        res+=s[i];

    }
    for(int i=res.size()-1;i>=0;i--)
    {
        cout<<res[i];
    }

    return 0;
}
