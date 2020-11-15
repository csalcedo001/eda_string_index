#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>
#include <random>

#include "functions.hpp"

using namespace std;

int main(int argc, char **argv) {
	// Check correct number of arguments
	if (argc != 2) {
		cerr << "Usage:" << argv[0] << " <data_path>" << endl;
		return 1;
	}


	// Check if first argument is valid
	string filename = argv[1];
	fstream file(filename, ios::in | ios::out);

	if (!file.is_open()) {
		cerr << "error: couldn't open file " << filename << endl;
		return 1;
	}

	string line;
	vector<string> queries;

	while (getline(file, line)) {
		queries.push_back(get_prefix(line));
	}

	int n;

	cin >> n;

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

	std::default_random_engine generator(seed);
	std::uniform_int_distribution<int> point_distribution(0, queries.size() - 1);

	cout << n << endl;

	for (int i = 0; i < n; i++) {
		int index = point_distribution(generator);
		cout << queries[index] << endl;
	}

	
	return 0;
}
