#include<iostream>
#include<string>

using namespace std;

string num[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
string pow [5] = {"Shi","Bai","Qian","Wan","Yi"};

int main()
{
      string s;
    
    cin>>s;
        int left = 0, right = s.size()-1;
    int len = s.size();
    if(s[0] == '-')
    {
        cout<<"Fu";
        left++;
    }
    while(left+4<=right)
    {
        right -= 4;
    }
    
    while(left<len)
    {
        bool flag = false;
        bool isPrint = false;
        while(left<=right)
        {
            if(left>0&&s[left]=='0')
                flag = true;
            else
            {
                if(flag == true)
                {
                    cout<<" ling";
                    flag = false;
                }
                if(left>0) cout<<' ';
                cout<<num[s[left]-'0'];
                isPrint = true;
                if(left!=right)
                    cout<<" "<<pow[right-left-1];
            }
            left++;
        }
        if(isPrint==true&&right!=len-1)
            cout<<" "<<pow[(len-1-right)/4+2];
        right+=4;
    }

    return 0;
}
