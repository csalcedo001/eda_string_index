#include "functions.hpp"

#include <string>

std::string get_prefix(std::string path) {
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
