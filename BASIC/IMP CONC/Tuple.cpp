#include <iostream>
#include <tuple>
using namespace std;

int main() {
    tuple<int, double, string> t(10, 3.14, "Hello");

    cout << get<0>(t) << endl; // 10
    cout << get<1>(t) << endl; // 3.14
    cout << get<2>(t) << endl; // Hello

    return 0;
}
