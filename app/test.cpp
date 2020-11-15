#include <iostream>
#include <vector>

#include "string_index.hpp"

using namespace std;

int main(int argc, char **argv) {
	if (argc != 2) {
		cerr << "Usage:" << argv[0] << " <indexing_structure>" << endl;
		return 1;
	}

	string structure_name(argv[1]);
	eda::string_index::StringIndex<string> *index;

	if (structure_name.compare("trie") == 0) {
		index = new eda::trie::Trie<string>();
	}
	else {
		cerr << "error: structure " << structure_name << " is not supported. Supported structures: trie, radix_tree, ternary_search_tree" << endl;
		return 1;
	}

	vector<string> inputs, tests;

	inputs.push_back("hola");
	inputs.push_back("prueba");
	inputs.push_back("holo");
	inputs.push_back("ho");
	inputs.push_back("holograma");
	inputs.push_back("holo");

	tests.push_back("h");
	tests.push_back("ho");
	tests.push_back("hol");
	tests.push_back("holo");
	tests.push_back("prueba");
	tests.push_back("abc");
	tests.push_back("tmp");
	tests.push_back("");

	for (auto e : inputs) {
		index->insert(e, e);
	}

	for (auto e : tests) {
		cout << "Query: \"" << e << "\"" << endl;

		for (auto e : index->exact_match(e)) {
			cout << "  " << e << endl;
		}
	}

	index->print();

	delete index;

    return 0;
}
