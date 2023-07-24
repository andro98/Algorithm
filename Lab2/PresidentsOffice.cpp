#include<iostream>
#include <set>
#include<vector>

struct Point {
	int x;
	int y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

int main()
{
	int n, m;
	char c;
	std::cin >> n >> m >> c;
	// INITIALIZE
	char** office = new char* [n];
	for (int i = 0; i < n; i++) {
		office[i] = new char[m];
	}
	// INPUT OFFICE
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> office[i][j];
		}
	}

	std::vector<Point> president_location;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (office[i][j] == c) {
				president_location.push_back(Point(i, j));
			}
		}
	}

	std::set<char> deputies;
	for (Point point : president_location)
	{
		int president_i = point.x;
		int president_j = point.y;
		if (president_i - 1 >= 0 && office[president_i - 1][president_j] != c && office[president_i - 1][president_j] != '.') {
			deputies.insert(office[president_i - 1][president_j]);
		}
		if (president_i + 1 < n && office[president_i + 1][president_j] != c && office[president_i + 1][president_j] != '.') {
			deputies.insert(office[president_i + 1][president_j]);
		}
		if (president_j - 1 >= 0 && office[president_i][president_j - 1] != c && office[president_i][president_j - 1] != '.') {
			deputies.insert(office[president_i][president_j - 1]);
		}
		if (president_j + 1 < m && office[president_i][president_j + 1] != c && office[president_i][president_j + 1] != '.') {
			deputies.insert(office[president_i][president_j + 1]);
		}
	}

	std::cout << deputies.size();

	// DEINIT
	for (int i = 0; i < n; i++) {
		delete[]office[i];
	}
	delete[]office;
	return 0;
}