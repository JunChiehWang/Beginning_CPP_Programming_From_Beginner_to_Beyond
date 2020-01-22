#include<iostream>
#include<stack>
#include<vector>
#include<list>

template <typename T>
void display(std::stack<T> s){
    std::cout << "["; 
    while (!s.empty()){ // we cannot use iterator for stacks
        T elem = s.top();
        s.pop();
        std::cout << elem << " ";
    }
    std::cout << "]" << std::endl;
}
int main() {
    std::stack<int> s; // a stack of integers, default to a deque 
    std::stack<int, std::vector<int>> s1;
    std::stack<int, std::list<int>> s2;
    std::stack<int, std::deque<int>> s3;
    // I can also create stacks of integers, but the underlying 
    // container would be a vector or list or a deck 
    for (int i:{1,2,3,4,5}) 
        s.push(i);
    display(s);
    
    s.push(100);
    display(s);
    
    s.pop();
    s.pop();
    display(s);
    
    while(!s.empty()) {
        s.pop();
        display(s);
    }
    
    std::cout << "Size:" << s.size() << std::endl;
    
    s.push(10);
    display(s);
    s.top() = 100;
    display(s);
    return 0;
}