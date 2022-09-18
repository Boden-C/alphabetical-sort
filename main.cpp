#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
void t(std::vector<std::string> &a, int l, size_t c){
    std::unordered_map<std::string, int> f = {
        {" ", 0}, {"-", 0}, {"'", 0}, {"À", 1}, {"ā", 1}, {"Ă", 1}, {"ă", 1}, {"á", 1}, {"æ", 1}, {"Æ", 1}, {"à", 1}, {"a", 1}, {"A", 1}, {"Ä", 1}, {"Å", 1}, {"å", 1}, {"ä", 1}, {"â", 1}, {"b", 2}, {"B", 2}, {"c", 3}, {"C", 3}, {"Ç", 3}, {"ç", 3}, {"d", 4}, {"D", 4}, {"e", 5}, {"E", 5}, {"ê", 5}, {"ë", 5}, {"è", 5}, {"é", 5}, {"È", 5}, {"É", 5}, {"Ê", 5}, {"Ë", 5}, {"f", 6}, {"F", 6}, {"g", 7}, {"G", 7}, {"h", 8}, {"H", 8}, {"i", 9}, {"I", 9}, {"¡", 9}, {"Ì", 9}, {"Í", 9}, {"Î", 9}, {"Ï", 9}, {"ï", 9}, {"î", 9}, {"ì", 9}, {"j", 10}, {"J", 10}, {"k", 11}, {"K", 11}, {"l", 12}, {"L", 12}, {"m", 13}, {"M", 13}, {"n", 14}, {"N", 14}, {"ñ", 14}, {"Ñ", 14}, {"o", 15}, {"O", 15}, {"ô", 15}, {"ö", 15}, {"ò", 15}, {"ó", 15}, {"Ò", 15}, {"Ó", 15}, {"Ô", 15}, {"Õ", 15}, {"Ö", 15}, {"p", 16}, {"P", 16}, {"q", 17}, {"Q", 17}, {"r", 18}, {"R", 18}, {"s", 19}, {"S", 19}, {"t", 20}, {"T", 20}, {"U", 21}, {"u", 21}, {"ü", 21}, {"û", 21}, {"v", 22}, {"V", 22}, {"w", 23}, {"W", 23}, {"x", 24}, {"X", 24}, {"y", 25}, {"Y", 25}, {"Ÿ", 25}, {"ý", 25}, {"z", 26}, {"Z", 26}};
    std::vector<std::string> n(l);
    std::vector<int> o(27, 0);
    std::vector<int> x(l);
    for (int i = 0; i < l; i++) {
        int y = c < a[i].size() ? (f.find(std::string(1, a[i][c])) == f.end() ? 0 : f.at(std::string(1, a[i][c]))) : 0;
        o[y]++;
        x[i] = y;
    }
    for (int i = 1; i < 26; i++){
        o[i] += o[i - 1];
    }
    for (int i = l - 1; i >= 0; i--) {
        if (c < a[i].size()) {
            int z = x[i];
            n[o[z] - 1] = a[i];
            o[z]--;
        } else {
            n[o[0] - 1] = a[i];
            o[0]--;
        }
    }
    for (int i = 0; i < l; i++){
        a[i] = n[i];
    }
}
void r(std::vector<std::string> &u, int l) {
    size_t m = u[0].size();
    for (int i = 1; i < l; i++){
        if (u[i].size() > m)
            m = u[i].size();
    }
    for (size_t c = m; c > 0; c--) {
        t(u, l, c - 1);
    }
}
int main(void){
    std::vector<std::string> v;
    for (std::string line; getline(std::cin, line);) {
        v.push_back(line);
    }
    r(v, v.size());
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i].c_str() << std::endl;
    }
    return 0;
}