#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

void display_vec(std::vector<std::vector<long>>);
long long max_sum(std::vector<long long>);
long long compute_sum(std::vector<long long>);

int main(){
    int N_INPS;
    std::cin >> N_INPS;
    std::vector<std::vector<long long>> inputs;
    int n;
    long long a;
    for (int i=0; i<N_INPS; i++){
        std::vector<long long> nums;
        std::cin >> n;
        for (int j=0; j < n; j++){
            std::cin >> a;
            nums.push_back(a);
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        inputs.push_back(nums);
    }
    for (std::vector<long long> inp : inputs){
        std::cout << max_sum(inp) << std::endl;
    }
    return 0;
}

void display_vec(std::vector<std::vector<long>> vec){
    for (std::vector<long> v: vec){
        for (long num : v) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

long long max_sum(std::vector<long long> nums){
    long long sum;
    int counteven=0;
    for (int i=0; i<nums.size(); i++){
        while (nums[i]%2 == 0){
            nums[i] /= 2;
            counteven++;
        }
    }
    std::sort(nums.begin(), nums.end());
    nums[nums.size()-1] *= pow(2, counteven);
    sum = compute_sum(nums);
    return sum;
}

long long compute_sum(std::vector<long long> nums){
    long long sum = 0;
    for (long long i: nums){
        sum += i;
    }
    return sum;
}