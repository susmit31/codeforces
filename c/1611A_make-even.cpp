#include <iostream>
#include <string>
#include <vector>

int num_steps(std::string);

int main(){
    int N_INPS;
    std::cin>>N_INPS;
    std::string input;
    std::vector <std::string> inputs;
    
    for (int i=0; i<N_INPS; i++){
        std::cin>>input;
        inputs.push_back(input);
    }
    for (std::string input : inputs){
        std::cout<<num_steps(input)<<std::endl;
    }
}

int num_steps(std::string input){
    char numstr[2];
    sprintf(numstr, "%c", input[input.length()-1]);
    if (atoi(numstr)%2 == 0) return 0;
    for (int i=0; i<input.length(); i++){
        sprintf(numstr,"%c",input[i]);
        if (atoi(numstr) % 2 ==0){
            if (i==0) return 1;
            else return 2;
        }
    }
    return -1;
}