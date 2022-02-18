#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

std::vector<int> parse_input(std::string);
void compute_solution(std::vector<int>);

int main(){
    // Read the number of test cases
    int N_TESTS;
    std::cin >> N_TESTS;
    // Prepare to read the test cases
    std::vector<std::vector <int>> test_cases;
    std::string inp_line;
    // Doing a "purposeless" getline to make sure getline
    // starts reading after the N_TESTS line
    std::getline(std::cin, inp_line);
    std::vector<int> parsed;
    
    for (int i=0; i<2*N_TESTS; i++){
        std::getline(std::cin, inp_line);
        if (i%2 == 1){
            parsed = parse_input(inp_line);
            test_cases.push_back(parsed);
        }
    }
    int i = 1;
    for (std::vector<int> test_case : test_cases){
        std::cout << "Case #" << i << ": ";
        compute_solution(test_case);
        std::cout<<"\n";
        i++;
    }
    return 0;
}

std::vector<int> parse_input(std::string line){
    std::stringstream ss(line);
    std::vector<int> output;
    int num;
    while (ss >> num){
        output.push_back(num);
    }
    return output;
}

void compute_solution(std::vector<int> cites){
    std::string hs;
    std::map<int, int> dist;
    for (int i=1; i<=cites.size(); i++){
        dist[i] = 0;
    }
    int h = 0;
    for (int cite: cites){
        if (cite > h){
            for (int j=1; j<=std::min(cite, (int)cites.size()); j++)
                dist[j] += 1;
            if (dist[h+1] >= h+1)
                h += 1;
        }
        hs += std::to_string(h) + " ";
    }
    hs = hs.substr(0, hs.length()-1);
    std::cout<<hs;
}