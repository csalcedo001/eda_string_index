#include <iostream>
#include <vector>
#include <fstream>

#include "trie.hpp"

using namespace std;

string get_prefix(string path) {
	int start = path.length() - 1;
	int end = path.length() - 1;

	while (start >= 0) {
		if (path[start] == '.') {
			end = start - 1;
			break;
		}

		start--;
	}

	while (start >= 0) {
		if (path[start] == '/') break;
		start--;
	}

	start++;

	return path.substr(start, end - start + 1);
}

int main(int argc, char **argv) {
	if (argc != 2) {
		cerr << "Usage:./bin/file <data path>" << endl;
		return 1;
	}

	string filename = argv[1];
	ifstream file(filename);

    eda::trie::Trie<string> trie;

	string line;

	while (getline(file, line)) {
		string prefix = get_prefix(line);

		trie.insert(prefix, line);
	}

	cout << "Processing finished" << endl;

	string name;

	while (getline(cin, name)) {
		for (auto e : trie.get(name)) {
			cout << "  " << e << endl;
		}
	}

    return 0;
}
