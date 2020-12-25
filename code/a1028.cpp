#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct record{
    string id,name;
    int age;
};
int c;
bool cmp(record a, record b)
{
    if(c==1)
    {
        return a.id<b.id;
    }
    else if(c==2)
    {
        if(a.name!=b.name)
            return a.name<b.name;
        else
            return a.id<b.id;
    }
    else
    {
        if(a.age!=b.age)
            return a.age<b.age;
        else
            return a.id<b.id;
    }
}
int main()
{
    int n;
    cin>>n>>c;
    vector<record> vv;
    for(int i=0;i<n;i++)
    {
        record temp;
        string id,name;int age;
        cin>>id>>name>>age;
        temp = {id,name,age};
        vv.push_back(temp);
    }
    sort(vv.begin(),vv.end(),cmp);
    for(int i=0;i<vv.size();i++)
        cout<<vv[i].id<<' '<<vv[i].name<<' '<<vv[i].age<<endl; 
    return 0;
}
