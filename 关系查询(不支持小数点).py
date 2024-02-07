from typing import List
# 例子
# 1-40 同学
# 41-60 家人
# 61-100 父母

# 关系数据如下
dr = [1,40,41,60,61,100]
p = ["同学","家人","父母"]

# 设左右指针
def search(dr: List[int], hgd: int, p: List[str]) -> str:
    i = 0;j =len(dr)-1 # 指针
    if hgd > dr[-1]: # 先判断边界
        return p[-1]
    while i <= j:
        mid = (j-i)//2+i # 获取中间的值
        # 讨论第一种情况 当好感值等于某个区间的值
        # 当值标为0时 dr[0]对同学 0//2==p[0]=="同学"
        # 当值标为1时 dr[1]对应家人 1//2==p[0]=="家人"
        # 当值标为2时 dr[2]对应父母 2//2==p[1]=="父母"
        # 得出结论 p[i] = p[i//2]
        if dr[mid] == hgd:
            return p[mid//2]
        # 讨论第二种情况 当右指针对应的数 比好感度大 说明好感度不在j范围
        # 缩小范围 
        elif dr[mid] > hgd:
            j = mid-1
        # 讨论第三种情况 当左指针对应的数 比好感度小 说明好感度超出i范围
        # 增大范围
        else:
            i = mid+1
    return p[i//2]

print(search(dr,51,p))