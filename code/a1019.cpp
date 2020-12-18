#include<iostream>

using namespace std;

int main()
{
    int n,b;
    cin>>n>>b;
    
    // ------------- 进制转换模板
    int z[40],num=0;
    do{
        z[num++] = n%b;
        n /= b;
    }while(n!=0);
    
    bool equ = true;
    for(int i=0;i<=num/2;i++)
    {
        if(z[i]!=z[num-1-i])
        {
            equ = false;
            break;
        }
    }
    if(equ == true)
        puts("Yes");
    else puts("No");
    
    for(int i=num-1;i>=0;i--)
    {
        cout<<z[i];
        if(i!=0) cout<<' ';
    }
    return 0;
}
