#include<iostream>

using namespace std;

int main()
{
    int x1,y1,z1,x2,y2,z2;
    scanf("%d.%d.%d %d.%d.%d",&x1,&y1,&z1,&x2,&y2,&z2);
    
    int k1 = z1+z2;int a1 = 0;

        a1 += k1/29;
        k1 %= 29;

    
    int k2 = y2+y1+a1;int a2 = 0;

            a2 += k2/17;
        k2 %= 17;


    long long k3 = x1+x2+a2;
    
    printf("%lld",k3);
    cout<<'.'<<k2<<'.'<<k1<<endl;
    
    return 0;
}	
