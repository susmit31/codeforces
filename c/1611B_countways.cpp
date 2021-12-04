#include <iostream>
#include <cstdio>
#include <vector>

int countways(int, int);

int main(){
    int N_INPS, a, b;
    std::cin>>N_INPS;
    std::vector <std::vector<int>> inputs;
    for (int i=0; i<N_INPS; i++){
        scanf("%d %d", &a, &b);
        std::vector<int> input{a,b};
        inputs.push_back(input);
    }
    for (std::vector<int> inp: inputs){
        std::cout<<countways(inp[0], inp[1])<<std::endl;
    }
}

int countways(int a, int b){
    if (a > b){
        return countways(b, a);
    } else if (a != 0 && b / a >= 3){
        return a;
    } else if (a==0){
        return 0;
    } else if (a==b){
        return a/2;
    } else{
        int d = b - a;
        int count = (int) (d/2);
        a -= count;
        b -= count*3;
        count += (int) ((a+b)/4);
        return count;
    }
}