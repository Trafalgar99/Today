#include<iostream>

using namespace std;

int arr[1001];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        arr[x]++;
    }
    for(int i=0;i<1001;i++)
    {
        if(arr[i])
        {
            arr[i]--;
            if(m>i&&arr[m-i])
            {
                printf("%d %d", i, m - i);
                return 0;
            }
            arr[i]++;
        }
    }
        printf("No Solution");
    return 0;
}
