#include <iostream>
#include <fstream>

int main() {
    std::ifstream in_file;
    in_file.open("test.txt");
    if(!in_file){
        
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    std::cout << "File is good to go" << std::endl;
    
    std::string line {};
    int num {};
    double total {};
    
    std::cout << "in 3 lines....." << std::endl;
    /*
    Hello
    100
    200.345
    */
    in_file >> line >> num >> total;
    std::cout << line << std::endl;
    std::cout << num << std::endl;
    std::cout << total << std::endl;
    
    std::cout << "in 1 line....." << std::endl;
    /*
    Hello 100 200.345
    */
    in_file >> line >> num >> total;
    std::cout << line << std::endl;
    std::cout << num << std::endl;
    std::cout << total << std::endl;
    
    in_file.close();
    return 0;
}