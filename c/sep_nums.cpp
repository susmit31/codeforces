#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>

std::vector<int> sep_nums(std::string);
void display_vector(std::vector<int>);

int main(){
    int N_INPS;
    std::cin >> N_INPS;
    std::vector<std::string> inputs;
    std::string inp;
    std::cin.clear();
    for (int i=0; i<=N_INPS; i++){
        getline(std::cin, inp);
        inputs.push_back(inp);
    }
    for (std::string inp : inputs){
        display_vector(sep_nums(inp));
    }
}

void display_vector(std::vector<int> v){
    for (int i: v){
        std::cout << i << std::endl;
    }
}

std::vector<int> sep_nums(std::string s){
    std::vector<int> out;
    std::stringstream str_s(s);
    int num = 0;
    while (str_s >> num){
        out.push_back(num);
    }
    return out;
}