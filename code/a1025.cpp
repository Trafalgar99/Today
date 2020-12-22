#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

struct student{
    string id;
    int score;
    int location_number;
    int local_rank;
}stu[30010];

// sort函数用的比较函数
bool cmp(student a,student b)
{
    if(a.score!=b.score)
        return a.score>b.score;
    else
        return a.id<b.id;
}

int main()
{
    int n;
    int cnt = 0;
    int kk=0;
    cin>>n;
    for(int j=1;j<=n;j++)
    {
        int n1;
        cin>>n1;
        cnt+=n1;
        for(int i=0;i<n1;i++)
        {
            string s;int score;
            cin>>s>>score;
            stu[kk++] = {s,score,j};
        }
        sort(stu+cnt-n1,stu+cnt,cmp);
        stu[cnt-n1].local_rank = 1;
        for(int l=cnt-n1+1;l<cnt;l++)
        {
            if(stu[l].score==stu[l-1].score)
                stu[l].local_rank = stu[l-1].local_rank;
            else
                stu[l].local_rank = l+1-(cnt-n1);
        }
    }
    
//     for(int i=0;i<cnt;i++)
//         cout<<stu[i].id<<' '<<stu[i].local_rank<<endl;
    sort(stu,stu+cnt,cmp);
    cout<<cnt<<endl;
    int r = 1;
    for(int i=0;i<cnt;i++)
    {
        if(i>0&&stu[i].score!=stu[i-1].score)
            r = i+1;
        cout<<stu[i].id<<' ';
        cout<<r<<' '<<stu[i].location_number<<' '<<stu[i].local_rank<<endl;
    }
    return 0;
}
