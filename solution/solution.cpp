#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "solution.h"
#include <faiss/IndexFlat.h>


void Solution::build(int d, const std::vector<float>& base) {
    
    index = new faiss::IndexYHYHFlat(d, 48);  // d维度和48的邻居数

    // 设置YHYH参数`
    index->yhyh.efConstruction = 128;

    // 添加数据到索引
    index->add(base.size() / d, base.data());
}

void Solution::search(const std::vector<float>& query, int* res) {
    // 查询设置
    std::vector<float> distances(10);
    std::vector<faiss::idx_t> indices(10);

    // 设置YHYH的搜索参数
    index->yhyh.efSearch = 160;

    // 执行搜索
    index->search(1, query.data(), 10, distances.data(), indices.data());

    // 将结果复制到输出数组
    for (int i = 0; i < 10; ++i) {
        res[i] = indices[i];
    }
}
