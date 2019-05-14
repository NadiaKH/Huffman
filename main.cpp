#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <codecvt>
#include <unordered_map>
#include <queue>
#include <vector>
#include <stack>
#include <functional>


#include "huffman_tree.h"
#include "huffman_code.h"

using namespace std;




freqTable_t<wchar_t> GetFreq(wifstream & wfs) {
    wchar_t ch;
    unordered_map<wchar_t, unsigned int> umap;
    while(wfs.get(ch))
        umap[ch]++;
    return umap;
}



int main() {
    wifstream ifs("text");
    wofstream ofs("out");
    ifs.imbue(locale(ifs.getloc(), new codecvt_utf8<wchar_t>));
    ofs.imbue(locale(ofs.getloc(), new codecvt_utf8<wchar_t>));

    auto a = GetFreq(ifs);
    for (auto it : a) {
        cout << it.first << " " << it.second << endl;
    }

    HuffmanTree tree (a);
    HuffmanCode code(tree);

    for (auto it : a) {
        cout << code[it.first] << endl;
    }
}
