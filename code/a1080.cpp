#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

struct applicant{
    int Ge,Gi,G,prefer[5],rnk,id;
};
struct school{
    int quota,last;
    vector<int> admitted;
};
int N,M,K; //学生数，学校数，志愿数
school s[100];
applicant a[40000];
bool cmp(applicant a,applicant b)
{
    if(a.G!=b.G) return a.G>b.G;
    return a.Ge>b.Ge;
}
int main()
{
    cin>>N>>M>>K;
    for(int i=0;i<M;i++)
        cin>>s[i].quota;
    for(int i=0;i<N;i++)
    {
        cin>>a[i].Ge>>a[i].Gi;
        for(int j=0;j<K;j++)
            cin>>a[i].prefer[j];
        a[i].G = a[i].Ge+a[i].Gi;
        a[i].id = i;
    }
    sort(a,a+N,cmp);
    //生成排名
    for(int i=0;i<N;i++)
    {
        if(i==0||a[i].G!=a[i-1].G||a[i].Ge!=a[i-1].Ge)a[i].rnk=i+1;
        else a[i].rnk = a[i-1].rnk;
    }
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<K;j++)
        {
            int ss = a[i].prefer[j]; //报考的学校编号
            if(s[ss].admitted.size()<s[ss].quota||a[i].rnk==a[s[ss].last].rnk)
            {
                s[ss].admitted.emplace_back(a[i].id);
                s[ss].last = i;
                break;
            }
        }
    }
    for(int i=0;i<M;i++)
    {
        sort(s[i].admitted.begin(),s[i].admitted.end());
        for(int j=0;j<s[i].admitted.size();j++)
        {
            if(j) cout<<' ';
            cout<<s[i].admitted[j];
        }
        cout<<endl;
    }
    return 0;
}
