#include <iostream>
#include <vector>
#include <fstream>

#include "string_index.hpp"

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
	if (argc != 3) {
		cerr << "Usage:" << argv[0] << " <data_path> <indexing_structure>" << endl;
		return 1;
	}


	string filename = argv[1];
	ifstream file(filename);

	if (!file.is_open()) {
		cerr << "error: couldn't open file " << filename << endl;
		return 1;
	}


	string structure_name(argv[2]);
	eda::string_index::StringIndex<string> *index;

	if (structure_name.compare("trie") == 0) {
		index = new eda::trie::Trie<string>();
	}
	else {
		cerr << "error: structure \"" << structure_name << "\" is not supported. Supported structures: trie, radix_tree, ternary_search_tree" << endl;
		return 1;
	}

	string line;

	while (getline(file, line)) {
		string prefix = get_prefix(line);

		index->insert(prefix, line);
	}

	cout << "Processing finished" << endl;

	string name;

	while (getline(cin, name)) {
		auto matches = index->partial_match(name);

		cout << "Matches: " << matches.size() << endl;
		
		for (auto match : matches) {
			cout << "  " << match << endl;
		}
		cout << endl;
	}

	delete index;

    return 0;
}
