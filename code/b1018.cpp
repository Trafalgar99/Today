#include<iostream>
#include<vector>
#include<map>

using namespace std;

// 判断胜负 
int judge(char a,char b)
{
    if((a=='C'&&b=='J')||(a=='J'&&b=='B')||(a=='B'&&b=='C')) return 1;
    if((a=='C'&&b=='B')||(a=='J'&&b=='C')||(a=='B'&&b=='J')) return -1;
    return 0;
}

int main()
{
    int n;
    vector<pair<char,char>> context;
    int arr[2][3] = {0};
    
	//映射表 
    map<char,int> m;
    m['J'] = 0;
    m['C'] = 1;
    m['B'] = 2;
    map<int,char> rm;
    rm[0] = 'J';
    rm[1] = 'C';
    rm[2] = 'B';

    cin>>n;
    
    while(n--)
    {
        char a,b;
        cin>>a>>b;
        context.push_back({a,b});
    }
    
    int w1=0,l1=0,c1=0;
    int w2=0,l2=0,c2=0;
	// 统计胜负次数 
    for(auto e:context)
    {
        int res = judge(e.first,e.second);
        if(res==1)
        {
            w1++,l2++;
            arr[0][m[e.first]]++;
        }
        else if(res==-1)
        {
            l1++,w2++;
            arr[1][m[e.second]]++;
        }
        else
            c1++,c2++;
    }
    cout<<w1<<' '<<c1<<' '<<l1<<endl<<w2<<' '<<c2<<' '<<l2<<endl;
    
	//字典序查找最频繁的出拳 
	int max1 = arr[0][0],maxp1 = 0;
    for(int i=0;i<3;i++)
    {
        if(arr[0][i]>=max1)
        {
            max1 = arr[0][i];
            maxp1 = i;
        }
    }
    int max2 = arr[1][0],maxp2 = 0;
    for(int i=0;i<3;i++)
    {
        if(arr[1][i]>=max2)
        {
            max2 = arr[1][i];
            maxp2 = i;
        }
    }
    cout<<rm[maxp1]<<' '<<rm[maxp2]<<endl;
    return 0;
}
