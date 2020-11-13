#include <iostream>
#include <vector>
#include <fstream>

#include "string_index.hpp"
#include "functions.hpp"

using namespace std;

int main(int argc, char **argv) {
	if (argc != 3) {
		cerr << "Usage:" << argv[0] << " <data_path> <indexing_structure>" << endl;
		return 1;
	}


	string filename = argv[1];
	fstream file(filename, ios::in | ios::out);

	if (!file.is_open()) {
		cerr << "error: couldn't open file " << filename << endl;
		return 1;
	}


	string structure_name(argv[2]);
	eda::string_index::StringIndex<long long> *index;

	if (structure_name.compare("trie") == 0) {
		index = new eda::trie::Trie<long long>();
	}
	else if (structure_name.compare("radix_tree") == 0) {
		index = new eda::radix_tree::RadixTree<long long>();
	}
	else if (structure_name.compare("ternary_search_tree") == 0) {
		index = new eda::ternary_search_tree::TernarySearchTree<long long>();
	}
	else {
		cerr << "error: structure \"" << structure_name << "\" is not supported. Supported structures: trie, radix_tree, ternary_search_tree" << endl;
		return 1;
	}

	string line;
	long long position = file.tellg();

	while (getline(file, line)) {
		string prefix = get_prefix(line);

		index->insert(prefix, position);

		position = file.tellg();
	}

	cout << "Processing finished" << endl;

	string name;

	file.clear();


	while (getline(cin, name)) {
		auto matches = index->partial_match(name);

		cout << "Matches: " << matches.size() << endl;
		
		for (auto match : matches) {
			file.seekg(match, file.beg);

			string result;

			getline(file, result);

			cout << "  " << result << endl;

		}
		cout << endl;
	}

	delete index;

    return 0;
}
