#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int res = 0, last = 0;
    
    for(int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        
        if(x > last) res += x - last;
        last = x;
    }
    
    cout << res << endl;
    return 0;
}


春春幼儿园举办了一年一度的“积木大赛”。

今年比赛的内容是搭建一座宽度为n的大厦，大厦可以看成由n块宽度为1的积木组成，第i块积木的最终高度需要是hi。

在搭建开始之前，没有任何积木（可以看成块高度为?0?的积木）。

接下来每次操作，小朋友们可以选择一段连续区间[L,R]，然后将第L块到第R块之间（含第?L?块和第?R?块）所有积木的高度分别增加1。

小M是个聪明的小朋友，她很快想出了建造大厦的最佳策略，使得建造所需的操作次数最少。

但她不是一个勤于动手的孩子，所以想请你帮忙实现这个策略，并求出最少的操作次数。

输入格式
输入包含两行，第一行包含一个整数n，表示大厦的宽度。?

第二行包含n个整数，第i个整数为hi。

输出格式
仅一行，即建造所需的最少操作数。

数据范围
1≤n≤105,
0≤hi≤10000
输入样例：
5
2 3 4 1 2
输出样例：
5
