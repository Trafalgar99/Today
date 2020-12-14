#include<iostream>
#include<vector>
using namespace std;

int main()
{
	
    int x1,y1,x2,y2;
    vector<int>v;
//     bool isOdd = false;
    while(cin>>x1>>y1)
    {
        if(x1==0&&y1==0)
        {
            v.push_back(0);
            v.push_back(0);
        }
        x2 = x1*y1;
        y2 = y1-1;
        if(y2>=0){
            v.push_back(x2);
            v.push_back(y2);
        }
    }
    bool flag = false;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]!=0) flag = true;
    }
    if(flag == false)
        cout<<0<<" "<<0<<endl;
    else{
    int i=0;
    for(;i<v.size()-1;i++)
    {
        cout<<v[i]<<' ';
    }
    cout<<v[i];
    }
    return 0;
}
