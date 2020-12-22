#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

struct student{
    string id;
    int vice;
    int talent;
    int sum;
};
bool cmp(student a,student b)
{
    if(a.sum!=b.sum)
        return a.sum>b.sum;
    else if(a.vice!=b.vice)
        return a.vice>b.vice;
    else
        return a.id<b.id;
}
int main()
{
    int n,l,h;
    cin>>n>>l>>h;
    vector<vector<student>>vv(4);
    for(int i=0;i<n;i++)
    {
        string s;int t,v;
        cin>>s>>v>>t;
        if(t>=l&&v>=l)
        {
            student stu = {s,v,t,t+v};
            if(t>=h&&v>=h)
                vv[0].push_back(stu);
            else if(v>=h&&t<h)
                vv[1].push_back(stu);
            else if(v>=t)
                vv[2].push_back(stu);
            else
                vv[3].push_back(stu);
        }
    }
    int cnt = 0;
    for(int i=0;i<4;i++)
        cnt+=vv[i].size();
    cout<<cnt<<endl;
    
    for(int i=0;i<4;i++)
    {
        sort(vv[i].begin(),vv[i].end(),cmp);
        for(int j=0;j<vv[i].size();j++)
            cout<<vv[i][j].id<<' '<<vv[i][j].vice<<' '<<vv[i][j].talent<<endl;
    }
//     for(int i=0;i<4;i++)
//     {
//         for(int j=0;j<vv[i].size();j++)
//             cout<<vv[i][j].id<<endl;
//     }
    return 0;
}
