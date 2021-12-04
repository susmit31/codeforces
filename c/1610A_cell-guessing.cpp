#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

int min_points(int, int);

int main(){
    int N_INPS;
    std::cin >> N_INPS;
    int width, height;
    std::vector<std::vector<int>> inputs;
    for (int i=0; i< N_INPS; i++){
        scanf("%d %d", &width, &height);
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