#include <iostream>
#include <fstream>
#include <iomanip>


int main() {
    std::ifstream in_file;
    std::string line {};
    int num;
    double total;
    
    in_file.open("./test.txt");
    if (!in_file) {
        std::cerr << "'problem opening file" << std::endl;
        return 1;
    }
    
    while (in_file >> line >> num >> total) {
        std::cout << std::setw(10) << std::left << line
                  << std::setw(10) << std::left << num
                  << std::setw(10) << total
                << std::endl;
    }
    in_file.close();
    
    
    return 0;
} 