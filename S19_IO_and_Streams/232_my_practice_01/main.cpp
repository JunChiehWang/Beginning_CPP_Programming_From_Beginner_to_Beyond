#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

int main () {
    std::ofstream out_file {"output.txt",std::ios::app};
    if(!out_file) {
        std::cout << "Cannot open file" << std::endl;
        return 1;
    } else {
        std::cout << "Open the file, start processing..." << std::endl;
    }
    
    std::string line {};
    std::cout << "Enter something to write to the file:" << std::endl;
    std::getline(std::cin, line);
    out_file << line << std::endl;
    
    out_file.close();
    
    return 0;
}