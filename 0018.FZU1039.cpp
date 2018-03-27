#include<iostream>
using std::cin;
using std::cout;
using std::endl;
#include<climits>

const size_t MAX_LINE = 30;    // ÐÐ
const size_t MAX_RANK = 30;    // ÁÐ

int array[MAX_LINE][MAX_RANK];
size_t line, rank;
bool has_saddle_point;

void input(void)
{
	size_t size;
	cin >> size;
	line = size;
	rank = size;
	for (size_t i(0); i != line; ++i)
	{
		for (size_t j(0); j != rank; ++j)
		{
			scanf("%d", &array[i][j]);
		}
	}
}

int get_max_in_line(const size_t& aim_line)
{
	int max(INT_MIN);
	for (size_t i(0); i != rank; ++i)
	{
		if (array[aim_line][i] > max)
		{
			max = array[aim_line][i];
		}
	}
	return max;
}

bool is_min_in_rank(const size_t& aim_rank, const int& value)
{
	for (size_t i(0); i != line; ++i)
	{
		if (array[i][aim_rank] < value)
			return 0;
	}
	return 1;
}

void output(size_t& i, size_t& j)
{
	has_saddle_point = 1;
	cout << i + 1 << ',' << j + 1 << ';';
}

void work(void)
{
	has_saddle_point = 0;
	input();
	for (size_t i(0); i != line; ++i)
	{
		int max(get_max_in_line(i));
		for (size_t j(0); j != rank; ++j)
		{
			if (array[i][j] == max && is_min_in_rank(j, array[i][j]))
				output(i, j);
		}
	}
	if (!has_saddle_point){
		cout << "NO;" << endl;
	}
}

int main(void)
{
	int times;
	cin >> times;
	while (times--)
	{
		work();
	}
	return 0;
}
