#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

int main (){
    std::ifstream infile {"input.txt"};
    std::ofstream outfile {"output.txt"};
    
    if (!infile) {
        std::cerr << "cannot open input.txt" << std::endl;
    }
    if (!outfile) {
        std::cerr << "Cannot open output.txt" << std::endl;
    }
    
    std::string line {};
    int count {0};
    while (getline(infile, line)) {
        
        // find line contains not only spaces
        if (line.find_first_not_of(' ') != std::string::npos) {
            count = count + 1;
            std::cout << std::setw(10) << std::left << count << line << std::endl;
            outfile << std::setw(10) << std::left << count << line << std::endl;
        } else {
            std::cout << std::endl;
            outfile << std::endl;
        }
                  
    }
    
    infile.close();
    outfile.close();
    
    return 0;
}