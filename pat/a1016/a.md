# PAT A1016

[题目链接](https://pintia.cn/problem-sets/994805342720868352/problems/994805493648703488)

大意：计算每个人在这个月的话费；



解题思路：

1. 选取的数据结构：

   ​	需要存储的有每个人的名字，和这个名字下的所有通话记录，并且要将此二者建立映射，

   采用`map<string,vector<record>>M`来存储，map内部的元素是一个个pair，他们会根据pair的first元素按字典序排好，这正好我们所需要的，其中的record定义为每一条记录:

   ```cpp
   struct record{
       int dd,hh,mm,t;
       string tag;
   }
   ```

   其中，t是将通话时刻换算为分钟的分钟数，这样会使后面的比较更简单。

2. 基本思路（算法基本步骤）：
   	+ 读入数据
   	+ 遍历map，遍历map下的每一个人物下的所有记录，检测记录是否合格
   	+ 若合格，计算时间，计算费用，按格式输出，若不合格，跳过，若一个人物没有合格的通话记录，不输出任何关于此人的信息；

解题代码：

```cpp
#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cstdio>
using namespace std;

struct record{
    int dd,hh,mm,t;
    string tag;
    
};
//数据存储
map<string,vector<record>>M;
double danjia[24];

bool cmp(record a,record b)
{
    return a.t<b.t;
}
int main()
{
    // -------- 读入数据 ----------------------
    for(int i=0;i<24;i++)
        cin>>danjia[i];
    int n;
    cin>>n;
    int month;
    for(int i=0;i<n;i++)
    {
        string name,tag;
        int date,hour,minute;char c; // c用于吞噬掉冒号
        cin>>name>>month>>c>>date>>c>>hour>>c>>minute>>tag;
        record temp;
        temp.dd = date;temp.hh=hour;temp.mm=minute;temp.tag = tag;
        temp.t = date*1440+hour*60+minute;
        M[name].emplace_back(temp);
    }
    // -----------------------------------------------
    
    // -------------- 遍历map元素 --------------------
    for(auto it = M.begin();it!=M.end();++it)
    {
        // it 相当于pair
        auto V = it->second; //为了方便起见，用V指向每一个名字下的vector
        sort(V.begin(),V.end(),cmp); //对该角色的所有通话时间排序
        double total  = 0; //记录当前角色的总话费
        
        for(int i=0;i<V.size();) // 从头枚举每一个时间
        {
            if(i+1<V.size()&&V[i].tag>V[i+1].tag) // 如果匹配成功
            {
                if(total == 0) //当匹配成功时，如果total==0，说明是第一次匹配成功，应当输出名字
                {
                    cout<<it->first<<' ';
                    printf("%02d\n",month); //都是同一个月
                }
                
                // ----- 时间模拟 ----- 绝妙！-----
                int t1 = V[i].t;
                int t2 = V[i+1].t;
                double fenzhang = 0; //某一次通话的花费
                for(int Time = t1;Time<t2;Time++)
                {
                    fenzhang += danjia[Time%1440/60]; //根据分钟数推出小时数
                }
                // --------------------
                printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n",V[i].dd,V[i].hh,V[i].mm,V[i+1].dd,V[i+1].hh,V[i+1].mm,V[i+1].t-V[i].t,fenzhang/100);
                i+=2; //匹配成功后，i和i+2俩条记录已经被使用过了，i+=2跳到下一对记录
                total += fenzhang; //总金额加
            }
            else{ //没有匹配成功 直接从下一个记录开始
                i++;
            }
        }
        if(total!=0) // 如果没有合法记录 total恒等于0，不会输出
            printf("Total amount: $%.2f\n",total/100);
    }
    return 0;
}
```

我的收获：



1. record的定义中，  很关键的一环就是计算了时刻的分钟数表示，大大化简了代码。

2. map的遍历方法：

   ```cpp
       for(auto it = M.begin();it!=M.end();++it)
       {
           auto V = it->second;
   ```

3. 关于时间模拟，之前从来没有见过这种写法，真的很妙，要学会使用

   ```cpp
   for(int Time = t1;Time<t2;Time++)
   {
          fenzhang += danjia[Time%1440/60]; //根据分钟数推出小时数
   }
   ```

4. 匹配成功的条件

   ```cpp
   if(i+1<V.size()&&V[i].tag>V[i+1].tag) 
   ```

   值得学习的是，在对i的遍历中，arr[i]的使用总是合法的，所以要对【i-1】,【i+1】用作下表时，一定要提前判断以防止越界访问。在这个表达式的后半段，是利用了tag的内容 on... / of...来区分的，利用了string的字典序进行判断，很精彩，以后要学会使用。