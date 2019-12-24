#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

int score_func(std::string sol, std::string std) {
    size_t sol_len {sol.length()}; // size of solution
    size_t std_len {std.length()}; // size of answer by student
    // std::cout << "len of sol = " << sol_len << std::endl;
    // std::cout << "len of sol by student = " << std_len << std::endl;
    // check length of solution
    if (sol_len != std_len) {
        std::cerr << "length of sol = " << sol_len 
                  << ", while length of std_ans = " <<  std_len 
                  << std::endl;
    }
    int score {0};
    for (size_t i {0}; i < sol_len; i++) {
        if (sol[i] == std[i]) {
            score = score + 1;
        }
    }
    return score;
};

int main () {
    // read file 
    std::ifstream in_file {};
    in_file.open("test.txt");
    if(!in_file) {
        std::cerr << "Cannot read in files" << std::endl;}
    else {std::cout << "Find the file !" << std::endl;}
    
    // get solution
    std::string sol {};
    int score {};
    // std::getline(in_file, sol);  length of sol = 6 
    in_file >> sol; // length of sol = 5 
    std::cout << sol.length() << std::endl;

    std::cout << std::setw(18) << std::left << "Student" 
              << std::setw(12) << std::left << "Score" << std::endl;
    std::cout << "------------------------------" << std::endl;
    std::string name {}, ans {};
    double total {0}, ave {0};
    size_t num_std {0};
    while (in_file >> name >> ans) {
        score = score_func(sol, ans);
        std::cout << std::setw(18) << std::left << name 
                  << std::setw(12) << std::left << score << std::endl;
        total = total + score;
        num_std = num_std + 1; 
    }
    std::cout << "------------------------------" << std::endl;
    ave = total/num_std;
    std::cout << std::setw(18) << std::left << "Average score" 
              << std::setw(12) << std::left << ave << std::endl;
    

    return 0;
}
