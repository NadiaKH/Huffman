#ifndef TYPES_H
#define TYPES_H
#include <unordered_map>
#include <string>


template <typename T>
using freqTable_t = std::unordered_map<T, unsigned int>;

template<typename T>
using codeTable_t = std::unordered_map<T, std::string>;



#endif // TYPES_H
