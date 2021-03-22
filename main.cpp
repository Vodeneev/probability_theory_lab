#include <iostream>
#include <stdio.h>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

int count(double p)
{
	double _rand = ((double)rand()) / RAND_MAX;
	int count = 1;
	while (_rand > p)
	{
		_rand = ((double)rand()) / RAND_MAX;
		count++;
	}
	return count;
}

int main()
{
	srand(time(0));
	setlocale(LC_ALL, "ru");
	cout << "Введите вероятность события: "<< endl;
	double p;
	cin >> p;
	cout << "Введите количество экспериментов: "<< endl;
	int N_ex;
	cin >> N_ex;
	int N;
	vector<int> temp;
	for (int i = 0; i < N_ex; i++)
	{
		N = count(p);
		temp.push_back(N);
		cout << endl << "Было совершено " << N << ' ' << "циклов";
	}
	sort(temp.begin(), temp.end());

	vector<pair<int, int>> y(temp[temp.size() - 1]);

	for (int i = 0; i < N_ex; i++)
	{
		y[temp[i] - 1].first = temp[i];
		y[temp[i] - 1].second++;
	}
	
	cout << endl << endl << "          ";

	for (int i = 0; i < y.size(); i++)
	{
		if (y[i].second == 0)
			continue;
		else
			cout << y[i].first << ' ' << ' ' << ' ';
	}

	cout << endl << endl << "          ";

	for (int i = 0; i < y.size(); i++)
	{
		if (y[i].second == 0)
			continue;
		else
			cout << y[i].second << ' ' << ' ' << ' ';
	}

	cout << endl << endl << "          ";

	for (int i = 0; i < y.size(); i++)
	{
		if (y[i].second == 0)
			continue;
		else
			cout << double(y[i].second) / N_ex << ' ' <<' ' <<' ';
	}

	cout << endl << endl;
}