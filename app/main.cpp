#include <iostream>
#include <vector>
#include <optional>

#include "trie.hpp"

using namespace std;

int main() {
    eda::trie::Trie<string> trie;

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
	tests.push_back("");

	for (auto e : inputs) {
		trie.insert(e, e);
	}

	for (auto e : tests) {
		cout << "Query: \"" << e << "\"" << endl;
		auto values = trie.get(e);

		for (auto e : values.value_or(vector<string>())) {
			cout << "  " << e << endl;
		}
	}

	trie.print();

    return 0;
}
