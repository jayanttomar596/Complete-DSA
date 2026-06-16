#include <iostream>
using namespace std;

int main() {
    
    int arr[5] = {1,2,3,4,5};
    char ch[6] = "abcde";

    cout<<arr<<endl;
    // isme pehle ke address print hoga

    cout<<ch<<endl;
    // But in character array it will print the whole array 

    // matlab cout function ka implementation is different for both integer and character array 

    char *c = &ch[0] ;
    cout<<c<<endl;
    // Again printed entire array 
    // isme yeh 1st character ka address uthayega aur jab tak agle address pe move kar karke print karta jayega jab tak isse null character na mile


    char temp = 'z';
    char *p = &temp ;

    cout<<p<<endl;

/*
z��m yeh ayya kyoki p points single character ('z') , but it isn't  start of a null-terminated string, cout keeps printing the memory contents from that address until it hits a null character ('\0'). 
The character 'z' is stored in the memory at p, but the characters at subsequent memory addresses after temp are not defined, and thus they may contain random or garbage values.
The characters �� represent invalid or random memory values that cout reads after 'z'.
Eventually, you might see m (or some other character) because there could be data in memory near temp that, when interpreted as characters, prints out something strange.
*/


    char *c = "abcde";
    // Above method is risky because in char ch[6] = "abcde" me temp memory me abcde store hoga fir alloted memory me copy ho jayega 

    // char *c = "abcde"; par isme temp memory me store karke uske first character ka address leke fir copy karega - RISKY - Read Only Meamory me ghus sakta hai 
    
    return 0;
}







// #include <iostream>
// using namespace std;

// int main() {
//     char arr[] = "hello";  // char array initialized with a string literal
//     char *p = arr;         // Pointer 'p' pointing to the first element of 'arr'

//     // Using pointer to traverse and print each character in the array
//     while (*p != '\0') {  // Loop until we reach the null terminator
//         cout << *p << " ";  // Dereference the pointer to print the character
//         p++;                // Move the pointer to the next character
//     }
//     cout << endl;

//     return 0;
// }







// #include <iostream>
// using namespace std;

// int main() {
//     char arr[] = "hello";  // char array initialized with a string literal

//     char *p = arr;         // Pointer 'p' pointing to the first character of 'arr'

//     // Loop through the array and print the address of each character
//     for (int i = 0; arr[i] != '\0'; i++) {
//         cout << "Character: " << arr[i] << " Address: " << (void*)&arr[i] << endl;
//     }

//     return 0;
// }





