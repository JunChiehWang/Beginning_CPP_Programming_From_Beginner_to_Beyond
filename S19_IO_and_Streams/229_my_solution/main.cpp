#include <iostream>
#include <string>
#include <iomanip>
#include <fstream> 

int main() {
    std::string keyword {};
    std::cout << "Enter the substring to search for:" << std::endl;
    std::cin >> keyword;

    // open the file 
    std::ifstream in_file {};
    in_file.open("romeoandjuliet.txt");
    if (!in_file) {
        std::cout << "Cannot open the file" << std::endl;
        return 1;
    } else {
        std::cout << "Open the file, start processing..." << std::endl;
    }
    
    // read and compare the file
    std::string word {};
    size_t find {};
    int fre {0};
    while (in_file >> word) {
        // if (word == keyword) {fre=fre+1;}
        find = word.find(keyword);
        if (find != std::string::npos) {
            fre=fre+1;
        }
    }
    
    // output fre of the search 
    std::cout << "The substring " << keyword 
              << " was found " << fre << " times." << std::endl;
    
    return 0;
}
