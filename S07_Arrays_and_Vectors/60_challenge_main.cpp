#include <iostream>
#include <vector>

using namespace std;

    int main() {

    vector <int> vector1;  
    vector <int> vector2;
    vector <vector<int>> vector_2d;


    vector1.push_back(10);
    vector1.push_back(20);
    vector2.push_back(100);
    vector2.push_back(200);
    vector_2d.push_back(vector1);
    vector_2d.push_back(vector2);

    cout << "vector1" << endl;
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;
    cout << vector1.size() << endl;

    cout << "vector2" << endl;
    cout << vector2.at(0) << endl;
    cout << vector2.at(1) << endl;
    cout << vector2.size() << endl;

    cout << "vector_2d" << endl;
    cout << vector_2d.at(0).at(0) << endl;
    cout << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << endl;
    cout << vector_2d.at(1).at(1) << endl;
    cout << vector_2d.size() << endl;// it shows 2 because there are 2 objects
                                        

    vector1.at(0) = 1000;
    cout << "vector_2d" << endl;
    cout << vector_2d.at(0).at(0) << endl;
    cout << vector_2d.at(0).at(1) << endl;
    cout << vector_2d.at(1).at(0) << endl;
    cout << vector_2d.at(1).at(1) << endl;
    cout << vector_2d.size() << endl;

    cout << "vector1" << endl;
    cout << vector1.at(0) << endl;
    cout << vector1.at(1) << endl;
    cout << vector1.size() << endl;



    return 0;
}
