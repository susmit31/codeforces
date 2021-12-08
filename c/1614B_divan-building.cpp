#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

void parse_input(std::string, std::vector<long>&);
long long compute_time(std::vector<long>, std::string);
std::string compute_locs(std::vector<long>);
void make_range(std::vector<long> &rangevec, long a_0, long a_1 = -1,  long stepsize=1);

int main(){
    long N_INPS;
    std::cin >> N_INPS;
    long a;
    std::vector<std::vector<long>> test_cases;
    std::string input;
    getline(std::cin, input);
    for (long i=0; i < N_INPS; i++) {
        getline(std::cin, input);
        getline(std::cin, input);
        std::vector<long> vec_input;
        parse_input(input, vec_input);
        test_cases.push_back(vec_input);
    }
    long long total_time;
    std::string locations;
    for (std::vector<long> wts : test_cases){
        locations = compute_locs(wts);
        total_time = compute_time(wts, locations);
        std::cout << total_time << std::endl;
        std::cout << locations << std::endl;
    }
}

void parse_input(std::string inp, std::vector<long> &store){
    std::stringstream ss(inp);
    long num;
    while (ss >> num){
        store.push_back(num);
    }
}

std::string compute_locs(std::vector<long> weights){
    //std::vector<long> weights_sorted;
    //std::copy(weights, weights + weights.size() - 1, weights_sorted);
    std::vector<long> idx_sorted;
    make_range(idx_sorted, 1, weights.size()+1, 1);
    std::sort(idx_sorted.begin(), idx_sorted.end(), [&weights](long i, long j){return weights[i-1] > weights[j-1];});

    std::vector<long> left, right;
    right.push_back(0);
    for (long i=0; i < idx_sorted.size(); i++){
        if (i%2==0){
            right.push_back(idx_sorted[i]);
        } else {
            left.push_back(idx_sorted[i]);
        }
    }
    std::reverse(left.begin(), left.end());
    long locs[idx_sorted.size()+1];
    long curr_loc = 0;
    for (long building: left) {
        locs[building] = curr_loc;
        curr_loc++;
    }
    for (long building: right) {
        locs[building] = curr_loc;
        curr_loc++;
    }
    std::string locations = "";
    for (long i=0; i<idx_sorted.size()+1;i++){
        locations += std::to_string(locs[i]);
        if (i!=idx_sorted.size()) locations+=" ";
    }
    return locations;
}

long long compute_time(std::vector<long> weights, std::string locations){
    std::vector<long> loc_vec;
    parse_input(locations, loc_vec);
    long long total_time = 0;
    for (long i=0; i < weights.size(); i++){
        total_time += 2*((long long) weights[i])*((long long) abs(loc_vec[0] - loc_vec[i+1]));
    }
    return total_time;
}

void make_range(std::vector<long> &rangevec, long a_0, long a_1,  long stepsize){
    if (a_1==-1){
        for (long i=0; i<a_0; i+=stepsize){
            rangevec.push_back(i);
        }
    } else {
        for (long i=a_0; i<a_1; i+=stepsize){
            rangevec.push_back(i);
        }
    }
}