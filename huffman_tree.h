#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <vector>
#include <queue>
#include <algorithm>

#include "types.h"
#include "node.h"


template<typename T>
struct HuffmanTree {
public:
    HuffmanTree(const freqTable_t<T> & umap){
        treeStorage_ = init(umap);
        for (size_t i = 0; i < treeStorage_.size(); i++) {
            treeStorage_[i].treeStorage_ = &treeStorage_;
        }
    }
    Node<T> * getRoot() {
        size_t indx = treeStorage_.size() - 1;
        return &(treeStorage_[indx]);
    }
private:
    std::vector<Node<T>> init(const freqTable_t<T> & umap);
    std::vector<Node<T>> treeStorage_;
    //size_t leafsNumber_;
};


template <typename T>
std::vector<Node<T>>
HuffmanTree<T>::init(const freqTable_t<T> & umap)  {
    std::vector<Node<T>> v;

    for (auto pair : umap) {
        v.emplace_back(pair.first, pair.second);
    }

    /*std::sort(v.begin(), v.end(), [](Node<T> & a, Node<T> & b) {
                                        return a.m_char < b.m_char;
                                    });
    leafsNumber_ = v.size();
    */

    auto cmp = [&v](size_t a, size_t b) {
        return v[a].getFreq() > v[b].getFreq();
    };

    std::priority_queue<size_t, std::vector<size_t>, decltype (cmp)> q(cmp);

    for (size_t i = 0; i < v.size(); i++) {
        q.push(i);
    }

    while(q.size() >= 2) {
        size_t a = q.top();
        q.pop();
        size_t b = q.top();
        q.pop();
        unsigned int freq = v[a].getFreq() + v[b].getFreq();
        v.emplace_back(a, b, freq);
        q.push(v.size() - 1);
    }

    return v;
}


#endif // HUFFMAN_TREE_H
