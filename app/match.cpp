#include <iostream>
#include <vector>
#include <fstream>
#include <chrono>

// #include "string_index.hpp"
#include "trie/trie.hpp"
// #include "radix_tree/radix_tree.hpp"
#include "ternary_search_tree/ternary_search_tree.hpp"
#include "functions.hpp"

using namespace std;

int main(int argc, char **argv) {
	// Check correct number of arguments
	if (argc != 4) {
		cerr << "Usage:" << argv[0] << " <data_path> <indexing_structure> <match_type>" << endl;
		return 1;
	}


	// Check if first argument is valid
	string filename = argv[1];
	fstream file(filename, ios::in | ios::out);

	if (!file.is_open()) {
		cerr << "error: couldn't open file " << filename << endl;
		return 1;
	}


	// Check if second argument is valid
	string structure_name(argv[2]);
	eda::string_index::StringIndex<long long> *index;

	if (structure_name.compare("trie") == 0) {
		index = new eda::trie::Trie<long long>();
	}
	// else if (structure_name.compare("radix_tree") == 0) {
	// 	index = new eda::radix_tree::RadixTree<long long>();
	// }
	else if (structure_name.compare("ternary_search_tree") == 0) {
		index = new eda::ternary_search_tree::TernarySearchTree<long long>();
	}
	else {
		cerr << "error: structure \"" << structure_name << "\" is not supported. Supported structures: trie, radix_tree, ternary_search_tree" << endl;
		return 1;
	}


	// Check if third argument is valid
	string match_type(argv[3]);
	bool exact_match;

	if (match_type == "exact") {
		exact_match = true;
	}
	else if (match_type == "partial") {
		exact_match = false;
	}
	else {
		cerr << "error: match type \"" << match_type << "\" is not supported. Supported match types: exact, partial" << endl;
		return 1;
	}


	// Index file elements
	string line;
	long long position = file.tellg();

	while (getline(file, line)) {
		string prefix = get_prefix(line);

		index->insert(prefix, position);

		position = file.tellg();
	}

	file.clear();

	cout << "Processing finished" << endl;
	cout << "RAM in use: " << index->size() << " B" << endl;


	// Answer filename queries
	string name;

	auto begin = chrono::steady_clock::now();
	auto end = begin;

	double total_time = 0;
	int total_queries = 0;

	while (getline(cin, name)) {
		vector<long long> matches;

		begin = chrono::steady_clock::now();
		if (exact_match) {
			matches = index->exact_match(name);
		}
		else {
			matches = index->partial_match(name);
		}
		end = chrono::steady_clock::now();

		total_time += chrono::duration_cast<chrono::microseconds>(end - begin).count();
		
		total_queries++;

		cout << "Matches: " << matches.size() << endl;
		
		for (auto match : matches) {
			file.seekg(match, file.beg);

			string result;

			getline(file, result);

			cout << "  " << result << endl;

		}
		cout << endl;
	}

	cout << "Average query time: " << total_time / total_queries << " us" << endl;

	delete index;

    return 0;
}
