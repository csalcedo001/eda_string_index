#ifndef STRING_INDEX_STRING_INDEX_HPP_
#define STRING_INDEX_STRING_INDEX_HPP_

#include <vector>

namespace eda {

namespace string_index {

template <typename T>
class StringIndex {
public:
	virtual void insert(std::string, T) = 0;
	virtual std::vector<T> exact_match(std::string) = 0;
	virtual std::vector<T> partial_match(std::string) = 0;
	virtual long long size() = 0;
	virtual void print() = 0;
};

} // namespace string_index

} // namespace eda

#include "string_index/impl/string_index.ipp"

#endif // STRING_INDEX_STRING_INDEX_HPP_
