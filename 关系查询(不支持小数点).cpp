#include <iostream> // 导库
#include <vector> // 导库
#include <string> // 导库
using namespace std;


string search(vector<int> dr, int hgd, vector<string> p){
    int i = 0;
    int j = dr.size()-1;
    if(hgd>dr[j]){ // 判断是否出界
        return p[p.size()-1]; // 返回对应
    }
    // 初始化左右边界
    while (i <= j){
        int mid = (j-i)/2+i; // 中间值
        /* 讨论第一种情况 当好感值等于某个区间的值
         当值标为0时 dr[0]对同学 0//2==p[0]=="同学"
         当值标为1时 dr[1]对应家人 1//2==p[0]=="家人"
         当值标为2时 dr[2]对应父母 2//2==p[1]=="父母"
        **/
        if(dr[mid]==hgd){
            return p[mid/2];
        // 讨论第二种情况 当右指针对应的数 比好感度大 说明好感度不在j范围
        // 缩小范围 
        }else if(dr[mid] > hgd){
            j = mid-1;
        // 讨论第三种情况 当左指针对应的数 比好感度小 说明好感度超出i范围
        // 增大范围
        }else{
            i = mid+1;
        }
    }
    return p[i/2];
}

int main()
{
    // dr是取值范围 1-40 41-60 61-100
    // p是每个范围对应的名字 1-40是同学 41-60是家人 61-100是父母
    vector<int> dr({1,40,41,60,61,100});
    vector<string> p({"同学","家人","父母"});
    cout << (search(dr,51,p)) << endl;
    return 0;

}