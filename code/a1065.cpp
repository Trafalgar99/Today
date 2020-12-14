#include<iostream>

using namespace std;

int main()
{
    int k;
    cin>>k;
//     cout<<"klklkl"<<k<<endl;
    int t = 1;
    for(int i=1;i<=k;i++)
    {
        bool flag;
        long long a,b,c;
//         cin>>a>>b>>c;
         // blog 走起   惊天大秘密
        scanf("%d%d%d", &a, &b, &c); 
        printf("%lld %lld %lld \n",a,b,c);
//              ?????????????????????????
        long long r = a+b;
        if(a>0&&b>0&&r<0) flag = true;
        else if(a<0&&b<0&&r>=0) flag = false;
        else if(r>c) flag = true;
        else flag = false;
        
        if(flag==true) cout<<"Case #"<<t++<<": true"<<endl;
        else cout<<"Case #"<<t++<<": false"<<endl;
    }
    
    return 0;
}
