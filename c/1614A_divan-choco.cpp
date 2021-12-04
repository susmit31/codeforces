#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

std::vector<int> tokenize_and_parse(std::string);
int count_chocs(int, int, int, std::vector<int>);

int main(){
    int N_INPS;
    std::cin >> N_INPS;
    std::vector<int> choc_nums, lower_lims, upper_lims, budgets;
    std::vector<std::vector<int>> price_lists;
    int n, l, r, k;
    std::string prices;
    std::string params;
    for (int i=0; i < N_INPS; i++){
        scanf("%d %d %d %d\n", &n, &l, &r, &k);
        choc_nums.push_back(n);
        lower_lims.push_back(l);
        upper_lims.push_back(r);
        budgets.push_back(k);

        getline(std::cin, prices);
        price_lists.push_back(tokenize_and_parse(prices));
    }

    for (int i=0; i<N_INPS; i++){
        std::cout<<count_chocs(lower_lims[i],upper_lims[i],budgets[i],price_lists[i])<<std::endl;
    }
}

std::vector<int> tokenize_and_parse(std::string s){
    std::vector<int> output;
    std::stringstream ss(s);
    int num = 0;
    while (ss >> num){
        output.push_back(num);
    }
    return output;
}

int count_chocs(int l, int r, int k, std::vector<int> prices){
    std::sort(prices.begin(), prices.end());
    int count = 0;
    for (int price : prices){
        if (price >= l && price <= r && k >= price){
            count++;
            k -= price;
        }
    }
    return count;
}