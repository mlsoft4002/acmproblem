#include<iostream> 
using namespace std;

#define N 30 
#define inf 1<<29 
#define MOD 2007 
#define LL long long 

int c[35][35] = { 0 };

//统计[0,n]中包含k个1的数量 
int slove(int n, int k){
	int sum = 0, tot = 0;
	for (int i = 31; i; i--){
		if (n&(1 << i)){
			tot++;
			if (tot>k)
				break;
			n ^= (1 << i);
		}
		if ((1 << (i - 1)) <= n)
			sum += c[i - 1][k - tot];
	}
	if (tot + n == k)  sum++;
	return sum;
}

int calc(int l, int r, int k){
	int len = 1;
	for (int i = 1; i <= 31; i++){
		int now = slove(r, i) - slove(l - 1, i);
		if (k <= now)  break;
		k -= now;
		len = i + 1;
	}
	int low = l, high = r, mid;
	while (low<high){
		//二分答案，然后查找[l,mid]中包含len个1的数量 
		mid = (int)(((LL)low + (LL)high) / 2);
		int now = slove(mid, len) - slove(l - 1, len);
		if (now<k)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

int main(){
	int t, l, r, k;
	for (int i = 0; i <= 32; i++){
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j<i; j++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &l, &r, &k);
		if (l == 0 && r == 0){
			printf("0\n");
			continue;
		}
		if (l >= 0 && r >= 0){
			if (l == 0){
				k--;
				l = 1;
			}
			if (k == 0){
				printf("0\n");
				continue;
			}
			printf("%d\n", calc(l, r, k));
		}
		else{
			if (r == 0){
				k--;
				r = -1;
			}
			//去掉最高位 
			l &= (~(1 << 31));
			r &= (~(1 << 31));
			cout << l << " " << r << endl;
			printf("%d\n", (1 << 31) | calc(l, r, k));
		}
	}
	return 0;
}
#include<iostream> 
using namespace std;

#define N 30 
#define inf 1<<29 
#define MOD 2007 
#define LL long long 

int c[35][35] = { 0 };

//统计[0,n]中包含k个1的数量 
int slove(int n, int k){
	int sum = 0, tot = 0;
	for (int i = 31; i; i--){
		if (n&(1 << i)){
			tot++;
			if (tot>k)
				break;
			n ^= (1 << i);
		}
		if ((1 << (i - 1)) <= n)
			sum += c[i - 1][k - tot];
	}
	if (tot + n == k)  sum++;
	return sum;
}

int calc(int l, int r, int k){
	int len = 1;
	for (int i = 1; i <= 31; i++){
		int now = slove(r, i) - slove(l - 1, i);
		if (k <= now)  break;
		k -= now;
		len = i + 1;
	}
	int low = l, high = r, mid;
	while (low<high){
		//二分答案，然后查找[l,mid]中包含len个1的数量 
		mid = (int)(((LL)low + (LL)high) / 2);
		int now = slove(mid, len) - slove(l - 1, len);
		if (now<k)
			low = mid + 1;
		else
			high = mid;
	}
	return low;
}

int main(){
	int t, l, r, k;
	for (int i = 0; i <= 32; i++){
		c[i][0] = c[i][i] = 1;
		for (int j = 1; j<i; j++)
			c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
	}
	scanf("%d", &t);
	while (t--){
		scanf("%d%d%d", &l, &r, &k);
		if (l == 0 && r == 0){
			printf("0\n");
			continue;
		}
		if (l >= 0 && r >= 0){
			if (l == 0){
				k--;
				l = 1;
			}
			if (k == 0){
				printf("0\n");
				continue;
			}
			printf("%d\n", calc(l, r, k));
		}
		else{
			if (r == 0){
				k--;
				r = -1;
			}
			//去掉最高位 
			l &= (~(1 << 31));
			r &= (~(1 << 31));
			cout << l << " " << r << endl;
			printf("%d\n", (1 << 31) | calc(l, r, k));
		}
	}
	return 0;
}
