#include <iostream>
#include <unordered_map>
using namespace std;



int main() {
    
    // Creation
    unordered_map<string , int> m ;


    // Insertion

    // 1
    pair<string , int> p = make_pair("babbar" , 3) ;
    m.insert(p) ;

    // 2
    pair<string , int> pair2("love" , 2) ;
    m.insert(pair2) ;

    // 3
    m["mera"] = 1 ;

    // What will happen
    m["mera"] = 2 ;

    // Search
    cout << m["mera"] << endl;
    cout << m.at("babbar") << endl;


    // cout << m.at("unknownKey") << endl;
    // yeh uppar walla code error dega par isko niche walle ke bad daloge toh 0 ayega kyoki neeche walla code new entry dal deta hai pointing to 0
    cout << m["unknownKey"] << endl;
    cout << m.at("unknownKey") << endl;



    // size
    cout << m.size() << endl;

    // to check presense
    cout << m.count("bro") << endl;
    cout << m.count("love") << endl;


    cout << endl;

    // Erase
    m.erase("love") ;
    cout << m.size() << endl;


    // Iterator
    unordered_map<string , int> :: iterator it = m.begin() ;

    while(it != m.end())
    {
        cout << it->first << " " << it->second << endl;
        it++ ;
    }

    // unordered map me random order me print hogi par map use karne pe jis order me dali hongi ussi order me print hongi


    return 0;
}


