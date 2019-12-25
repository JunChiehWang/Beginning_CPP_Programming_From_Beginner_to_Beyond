#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

int main (){
    std::ifstream in_file {"poem.txt"};
    std::ofstream out_file {"out.txt"};
    
    if (!in_file) {
        std::cout << "Cannot open poem.txt" << std::endl;
        return 1;
    } else {
        std::cout << "Open poem.txt" << std::endl;
    }
    
    if (!out_file) {
        std::cout << "Cannot open out.txt" << std::endl;
        return 1;
    } else {
        std::cout << "Open out.txt" << std::endl;
    }    
    /* sol 1:
    std::string line {};
    while (std::getline(in_file, line)) {
        out_file << line << std::endl;
    } 
    */
    // sol 2:
    char c;
    while (in_file.get(c)) {
        out_file.put(c);
    }
    
    in_file.close();
    out_file.close();
    
    return 0;
}