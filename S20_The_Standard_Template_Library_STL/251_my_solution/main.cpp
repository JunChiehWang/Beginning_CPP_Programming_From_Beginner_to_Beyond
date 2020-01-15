// Section 20
// Challenge 1
// Identifying palindrome strings using a deque
#include <cctype>
#include <deque>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    // You must implement this function.
    // Since we are learning the STL - use a deque to solve the problem.
    std::deque<int> tmp_back {};
    std::deque<int> tmp_front {};
    std::string tmp {};
    for (size_t i {0}; i < s.size(); i++) {
        //std::cout << i << std::endl;
        if (isalpha(s.at(i))) {
            tmp.push_back(toupper(s.at(i)));
            tmp_back.push_back(toupper(s.at(i)));
            tmp_front.push_front(toupper(s.at(i)));
        }
    }
    std::cout << "tmp: " << tmp << std::endl;
    for (size_t i {0}; i < tmp_back.size(); i++) {
        //std::cout << "front: " << tmp_front.at(i) << std::endl;
        //std::cout << "back: " << tmp_back.at(i) << std::endl;
        if (tmp_front.at(i) != tmp_back.at(i))
            return false;
    }

    return true;
}

int main()
{
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
    for(const auto& s : test_strings) {
        std::cout << std::setw(8) << std::left << is_palindrome(s)  << s << std::endl;
    }
    std::cout << std::endl;
    return 0;
}