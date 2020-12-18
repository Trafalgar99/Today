#include<iostream>
#include<map>
#include<string>

using namespace std;

int power[17] = {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};

char z2m[11] = {'1','0','X','9','8','7','6','5','4','3','2'};

int main()
{
    
    int n;
    cin>>n;
    int cnt = 0;
    while(n--)
    {
        string s;
        cin>>s;
        bool ok = true;
        for(int i=0;i<17;i++)
        {
            if(s[i]=='X')
            {
                ok = false;
                break;
            }
        }
        if(ok==false)
        {
            cout<<s<<endl;
            cnt++;
        }
        else
        {
            int sum = 0;
            for(int i=0;i<17;i++)
            {
                int t;
                if(s[i]=='X')
                    t = 10;
                else t = s[i]-'0';
                sum+=power[i]*t;
            }
            char key = z2m[sum%11];
            if(key!=s[17]) 
            {
                cout<<s<<endl;
                cnt++;
            }            
        }

    }

    if(cnt == 0) puts("All passed");
    return 0;
}
