#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
    stack<int> nums;
    int M,N,K;
    int push_index = 1; // 压栈序列
    int index = 1; // 遍历到的出栈序列位置
    int x; // 要找的元素
    bool right_flag = false;
    cin >> M >> N >> K;
    vector<int> pop_sequence(N);
    for(int i = 0; i < K; i++){
        for(int j = 0; j < N; j++){
            cin >> pop_sequence[j];
        }
        push_index = 1;
        index = 1;
        while(!nums.empty()) nums.pop();
        right_flag = true;
        while(index < N){
            x = pop_sequence[index - 1];
            index++;
            if(x < push_index){
                if(!nums.empty() && nums.top() == x){
                    nums.pop();
                }else{
                    right_flag = false;
                    break;
                }
            }else if(x == push_index){
                push_index++;
            }else{ 
            //x < push_index，应该压入到index为止，弹出这个，再向后判断
                if(push_index > N) {
                    right_flag = false;
                    break;
                }
                for(; push_index <= x; push_index++){
                    nums.push(push_index);
                    if(nums.size() > M){
                        right_flag = false;
                        break;
                    }
                }
                nums.pop();
            }
        }
        if(right_flag) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
