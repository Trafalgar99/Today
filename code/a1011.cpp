#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    int n = 3;
    map<int,char>m;
    m[0] = 'W';
    m[1] = 'T';
    m[2] = 'L';
    double b = 1.0;
    vector<int> v;
    while(n--)
    {
        double arr[3];
        for(int i=0;i<3;i++)
            cin>>arr[i];
        int maxp = 0;double max = arr[0];
        for(int i=0;i<3;i++)
        {
            if(arr[i]>max)
            {
                maxp = i;
                max = arr[i];
            }
        }
        b *= max;
        v.push_back(maxp);
    }
    for(auto e:v)
        cout<<m[e]<<' ';
    printf("%.2f",(b*0.65-1)*2);
    return 0;
}
