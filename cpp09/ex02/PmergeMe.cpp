#include "PmergeMe.hpp"

void PmergeMe::fordJohnsonVector(std::vector<int>& seq)
{
    if (seq.size() <= 1) return;

    std::vector<std::pair<int,int> > pairs;
    int straggler = -1;
    bool hasStraggler = false;

    for (size_t i = 0; i + 1 < seq.size(); i += 2)
    {
        int a = seq[i], b = seq[i+1];
        if (a < b) std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    if (seq.size() % 2 != 0)
    {
        straggler = seq.back();
        hasStraggler = true;
    }

    std::vector<int> mainChain;
    std::vector<int> pend;

    for (size_t i = 0; i < pairs.size(); i++)
        mainChain.push_back(pairs[i].first);

    fordJohnsonVector(mainChain);

    for (size_t i = 0; i < pairs.size(); i++)
        pend.push_back(pairs[i].second);

    seq.clear();
    seq.push_back(pend[0]);
    for (size_t i = 0; i < mainChain.size(); i++)
        seq.push_back(mainChain[i]);

    std::vector<int> order = getInsertionOrder((int)pend.size());

    for (size_t i = 0; i < order.size(); i++)
    {
        int idx = order[i] - 1;
        int val = pend[idx];
        std::vector<int>::iterator pos = std::lower_bound(seq.begin(), seq.end(), val);
        seq.insert(pos, val);
    }

    if (hasStraggler)
    {
        std::vector<int>::iterator pos = std::lower_bound(seq.begin(), seq.end(), straggler);
        seq.insert(pos, straggler);
    }
}