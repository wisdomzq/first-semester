#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int leng[100005],n;
// 判断是否能切割出K条长度为mid的绳子
bool canCut(int p[], int mid, int k) {
    int count = 0;
    for (int i=0;i<n;i++) {
        count += p[i] / mid; // 每条绳子能切出几段长度为mid的绳子
        if (count >= k) return true; // 如果已经达到K条，提前结束
    }
    return count >= k;
}

int main() {
    int  k;
    cin >> n;
    
  
    int maxLen = 0;
    
    for (int i = 0; i < n; ++i) {
        cin >> leng[i];
        maxLen = max(maxLen, leng[i]);
    }
    
    cin >> k;
    
    int left = 1, right = maxLen;
    int result = 0;
    
    // 二分查找
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (canCut(leng, mid, k)) {
            result = mid; // mid是当前能够满足条件的最大长度
            left = mid + 1; // 尝试更大的长度
        } else {
            right = mid - 1; // 尝试更小的长度
        }
    }
    
    cout << result << endl;
    return 0;
}
