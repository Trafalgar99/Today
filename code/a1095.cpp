#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

struct record{
    int hh,mm,ss,total;
    string tag;
};
int in_school[86400];
int out_school[86400]; 
map<string,vector<record> > M;
map<string,int>M2;
bool cmp(record a,record b)
{
    return a.total < b.total;
}
int N,K;
int main()
{
    cin>>N>>K;
    for(int i=0;i<N;i++)
    {
        string s;char c;
        record temp;
        cin>>s;
        scanf("%d:%d:%d",&temp.hh,&temp.mm,&temp.ss);
        cin>>temp.tag;
        temp.total = temp.hh*3600+temp.mm*60+temp.ss;
        M[s].push_back(temp);
    }
    for(auto it:M)
    {
        auto A = it.second;
        sort(A.begin(),A.end(),cmp);
        for(int i=0;i<A.size();)
        {
            if(A[i].tag=="in")
            {
                if(i+1<A.size()&&A[i+1].tag=="out")
                {
                    in_school[A[i].total]++;
                    out_school[A[i+1].total]++;
                    M2[it.first]+=A[i+1].total-A[i].total;
                    i+=2;
                }
                else
                    i++;
            }
            else
                i++;
        }
    }
    int car_num[86400] = {0};
    for(int i=0,j=0;i<86400;i++)
    {
        j+=in_school[i];
        j-=out_school[i];
        car_num[i] = j; 
    }
    for(int i=0;i<K;i++)
    {
        int hh,mm,ss;
        scanf("%d:%d:%d",&hh,&mm,&ss);
        int totalss = hh*3600+mm*60+ss;
        cout<<car_num[totalss]<<endl;
    }
    int maxtime = 0;
    vector<string>max_cars;
    for(auto it:M2)
    {
        if(it.second>maxtime)
        {
            maxtime = it.second;
            max_cars = {it.first};
        }
        else if(it.second==maxtime)
        {
            max_cars.push_back(it.first);
        }
    }
    sort(max_cars.begin(),max_cars.end());
    for(string each:max_cars)
    {
        cout<<each<<' ';
    }
    printf("%02d:%02d:%02d\n",maxtime/3600,maxtime/60%60,maxtime%60);
    return 0;
}
