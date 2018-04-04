#include <iostream>
#include <stack>
#include <vector>
#include <stdio.h>

using namespace std;

int main()
{
    stack<int> nums;
    int M,N,K;
    int push_index = 1; // ѹջ����
    int index = 1; // �������ĳ�ջ����λ��
    int x; // Ҫ�ҵ�Ԫ��
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
            //x < push_index��Ӧ��ѹ�뵽indexΪֹ�����������������ж�
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
