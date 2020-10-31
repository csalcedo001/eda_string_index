#include <iostream>
#include <vector>

#include "trie.hpp"

using namespace std;

int main() {
    eda::trie::Trie<string> trie;

	vector<string> test;

	test.push_back("hola");
	test.push_back("prueba");
	test.push_back("holo");
	test.push_back("ho");
	test.push_back("holograma");

	for (auto e : test) {
		trie.insert(e, e);
	}

	trie.print();

    return 0;
}
