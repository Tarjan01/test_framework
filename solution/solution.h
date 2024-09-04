
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "IndexYHYH.h"


class Solution {
private:
    faiss::IndexYHYH* index = nullptr;

public:
    void build(int d, const std::vector<float>& base);

    void search(const std::vector<float>& query, int* res);

};
