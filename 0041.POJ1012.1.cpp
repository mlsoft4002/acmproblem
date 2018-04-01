#include <iostream>  
#include <string>  
#include <cstring>  
#include <algorithm>  
#include <cmath>  
#include <vector>  
using namespace std;  
  
int people[50];  
vector <int> kill;  
  
int main()  
{  
    int n,k=0;  
    while(cin>>n)  
    {  
        int result=n+1,rest=2*n,kill_num=1;  
        int n2=2*n;  
          
        memset(people,0,sizeof(people));  
        kill.clear();  
        while(1)  
        {  
            if(kill.size()==n)  
                break;  
            if((result+kill_num-1)%rest==0)  
            {  
                kill_num=rest;  
                rest--;  
                kill.push_back(rest);  
            }  
            else if((result+kill_num-1)%rest<=n)  
            {  
                kill_num=1;  
                kill.clear();  
                rest=n2;  
                result++;  
            }  
            else  
            {  
                kill_num=(result+kill_num-1)%rest;  
                rest--;  
                kill.push_back(kill_num);  
            }  
        }  
        cout<<result<<endl;  
    }  
  
    return 0;  
}
