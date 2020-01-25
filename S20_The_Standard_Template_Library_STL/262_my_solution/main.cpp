// Section 20
// Challenge 4
// Identifying palindrome strings using a stack and queue
#include <cctype>
#include <stack>
#include <queue>
#include <iostream>
#include <string>
#include <iomanip>

bool is_palindrome(const std::string& s)
{
    //std::cout << "string send to function__" << s << "__" << std::endl;
    std::stack<int> st;
    std::queue<int> qu;
    for (char c:s) {
        if (isalpha(c)) {
            c = tolower(c);
            //std::cout << "alpha char c__" << c << "__" << std::endl;
            st.push(c);
            qu.push(c);
        }
    }
    for (size_t i {0}; i < st.size(); i++) {
        //std::cout << "stack:top:last " << st.top() << std::endl;
        char c1 = st.top();
        st.pop();
        //std::cout << "queue:front:first " << qu.front() << std::endl;
        char c2 = qu.front();
        qu.pop();
        if (c1 != c2) {
            //std::cout << "not equal: " << c1 << " " << c2 << std::endl;
            return false;
        }
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