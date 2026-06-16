
// A 2D Vector can be initialized or populated in several ways depending on your requirements -






// 1.) Declaring and Resizing the 2D Vector

// If you know the dimensions of the 2D vector in advance, you can use the resize function: 

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int rows = 3, cols = 4; // Dimensions of the 2D vector
//     vector<vector<int> > vec(rows, vector<int>(cols, 0)); 
//     // Initialize with 0

//     // Display the 2D vector
//     for (int i = 0; i < rows; ++i) {
//         for (int j = 0; j < cols; ++j) {
//             cout << vec[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }




// 2.) Input from the User

// If you want the user to input values for the 2D vector:

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int rows, cols;
//     cout << "Enter number of rows and columns: ";
//     cin >> rows >> cols;

//     vector<vector<int> > vec(rows, vector<int>(cols));

//     cout << "Enter the elements:\n";
//     for (int i = 0; i < rows; ++i) {
//         for (int j = 0; j < cols; ++j) {
//             cin >> vec[i][j];
//         }
//     }

//     // Display the 2D vector
//     cout << "The 2D vector is:\n";
//     for (int i = 0; i < rows; ++i) {
//         for (int j = 0; j < cols; ++j) {
//             cout << vec[i][j] << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }




// 3.) Hardcoding Values

// You can directly assign values to a 2D vector like this:

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     vector<vector<int>> vec = {
//         {1, 2, 3},
//         {4, 5, 6},
//         {7, 8, 9}
//     };

//     // Display the 2D vector
//     for (const auto& row : vec) {
//         for (const auto& val : row) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }




// 4.) Dynamically Adding Rows and Columns

// If the size is not known beforehand and you want to dynamically add rows and elements:

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     vector<vector<int>> vec;

//     // Adding rows and elements dynamically
//     vec.push_back({1, 2, 3}); // First row
//     vec.push_back({4, 5});    // Second row
//     vec.push_back({6, 7, 8, 9}); // Third row

//     // Display the 2D vector
//     for (const auto& row : vec) {
//         for (const auto& val : row) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }




// 5.) Using Nested Loops to Populate

// You can construct the 2D vector row by row:

// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     vector<vector<int> > vec;
//     int rows = 3;

//     for (int i = 0; i < rows; ++i) {
//         vector<int> row; // Create a row
//         for (int j = 0; j < i + 1; ++j) { // Variable row sizes
//             row.push_back(i + j); // Populate the row
//         }
//         vec.push_back(row); // Add the row to 2D vector
//     }

//     // Display the 2D vector
//     for (const auto& row : vec) {
//         for (const auto& val : row) {
//             cout << val << " ";
//         }
//         cout << endl;
//     }
//     return 0;
// }


