#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

void parse_input(std::string, std::vector<int>&);
int compute_time(std::vector<int>, std::string);
std::string compute_locs(std::vector<int>);
void make_range(std::vector<int> &rangevec, int a_0, int a_1 = -1,  int stepsize=1);

int main(){
    int N_INPS;
    std::cin >> N_INPS;
    int a;
    std::vector<std::vector<int>> test_cases;
    std::string input;
    getline(std::cin, input);
    for (int i=0; i < N_INPS; i++) {
        getline(std::cin, input);
        getline(std::cin, input);
        std::vector<int> vec_input;
        parse_input(input, vec_input);
        test_cases.push_back(vec_input);
    }
    int total_time;
    std::string locations;
    for (std::vector<int> wts : test_cases){
        locations = compute_locs(wts);
        total_time = compute_time(wts, locations);
        std::cout << total_time << std::endl;
        std::cout << locations << std::endl;
    }
}

void parse_input(std::string inp, std::vector<int> &store){
    std::stringstream ss(inp);
    int num;
    while (ss >> num){
        store.push_back(num);
    }
}

std::string compute_locs(std::vector<int> weights){
    //std::vector<int> weights_sorted;
    //std::copy(weights, weights + weights.size() - 1, weights_sorted);
    std::vector<int> idx_sorted;
    make_range(idx_sorted, 1, weights.size()+1, 1);
    std::sort(idx_sorted.begin(), idx_sorted.end(), [&weights](int i, int j){return weights[i-1] > weights[j-1];});

    std::vector<int> left, right;
    right.push_back(0);
    for (int i=0; i < idx_sorted.size(); i++){
        if (i%2==0){
            right.push_back(idx_sorted[i]);
        } else {
            left.push_back(idx_sorted[i]);
        }
    }
    std::reverse(left.begin(), left.end());
    int locs[idx_sorted.size()+1];
    int curr_loc = 0;
    for (int building: left) {
        locs[building] = curr_loc;
        curr_loc++;
    }
    for (int building: right) {
        locs[building] = curr_loc;
        curr_loc++;
    }
    std::string locations = "";
    for (int i=0; i<idx_sorted.size()+1;i++){
        locations += std::to_string(locs[i]);
        if (i!=idx_sorted.size()) locations+=" ";
    }
    return locations;
}

int compute_time(std::vector<int> weights, std::string locations){
    std::vector<int> loc_vec;
    parse_input(locations, loc_vec);
    int total_time = 0;
    for (int i=0; i < weights.size(); i++){
        total_time += 2*weights[i]*abs(loc_vec[0] - loc_vec[i+1]);
    }
    return total_time;
}

void make_range(std::vector<int> &rangevec, int a_0, int a_1,  int stepsize){
    if (a_1==-1){
        for (int i=0; i<a_0; i+=stepsize){
            rangevec.push_back(i);
        }
    } else {
        for (int i=a_0; i<a_1; i+=stepsize){
            rangevec.push_back(i);
        }
    }
}