#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>

int min_points(int, int);
void parse_input(std::string, int*);

int main(){
    int N_INPS;
    std::cin >> N_INPS;
    int width, height;
    std::vector<std::vector<int>> inputs;
    std::string inp_line;
    getline(std::cin, inp_line);
    int parsed[2];
    for (int i=0; i< N_INPS; i++){
        getline(std::cin, inp_line);
        parse_input(inp_line, parsed);
        width = parsed[0];
        height = parsed[1];
        inputs.push_back(std::vector<int> {width, height});
    }
    for (std::vector<int> dimensions: inputs){
        std::cout<<min_points(dimensions[0], dimensions[1])<<std::endl;
    }
}

int min_points(int width, int height){
    if (width < height){
        return min_points(height, width);
    }
    if (width==height && height==1) return 0;
    else if (height==1) return 1;
    else return 2;
}

void parse_input(std::string inp_str, int* output){
    std::stringstream ss(inp_str);
    int num, i=0;
    while (ss >> num){
        output[i] = num;
        i++;
    }
}