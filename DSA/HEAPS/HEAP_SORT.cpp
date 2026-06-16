#include <iostream>
#include <vector>
using namespace std;


// MAX HEAP
class heap 
{
public :
    int arr[100] ;
    int size ;

    heap()
    {
        arr[0] = -1 ;
        size = 0 ;
    }


    void insert(int val)
    {
        size = size + 1 ;
        int index = size ;
        arr[index] = val ;

        while(index > 1)
        {
            int parent = index/2 ;

            if (arr[parent] < arr[index])
            {
                swap(arr[parent] , arr[index]) ;
                index = parent ;
            }
            else
            {
                return ;
            }
        }
    }


    void print()
    {
        for (int i = 1 ; i <= size ; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }


    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to Delete" << endl;
            return ;
        }

        // Step1 : Put last element into first index
        arr[1] = arr[size] ;

        // Step2 : Remove last element
        size-- ;


        // Take root node to its correct position
        int i = 1 ;
        while(i < size)
        {
            int leftIndex = 2*i ;
            int rightIndex = 2*i + 1 ;

            if (leftIndex <= size && arr[i] < arr[leftIndex])
            {
                swap(arr[i] , arr[leftIndex]) ;
                i = leftIndex ;
            }
            else if (rightIndex <= size && arr[i] < arr[rightIndex])
            {
                swap(arr[i] , arr[rightIndex]) ;
                i = rightIndex ;
            }
            else
            {
                return ;
            }
        }
    }
};






// Heapify	: T.C. -> O(log n)	 S.C. -> O(log n) (recursion stack)
// Heap Creation : T.C. -> O(n)   S.C. -> O(log n) (recursion stack)

void heapify(int arr[] , int n , int i)
{

    int largest = i ;
    int left = 2*i ;
    int right = 2*i + 1 ;

    if (left <= n && arr[largest] < arr[left])
    {
        largest = left ;
    }

    if (right <= n && arr[largest] < arr[right])
    {
        largest = right ;
    }


    if (largest != i)
    {
        swap(arr[largest] , arr[i]) ;
        heapify(arr , n , largest) ;
    }
}



void heapSort(int arr[] , int n)
{
    int size = n ;

    while(size > 1)
    {
        // Step1 : Swap
        swap(arr[size] , arr[1]) ;
        size-- ;

        // Step2 
        heapify(arr , size , 1) ;
    }
}




class HEAP_SORT {
    private:
      void heapify(vector<int>& arr, int n, int i) {
          int largest = i;
          int left = 2 * i ;  // Corrected child index
          int right = 2 * i + 1; // Corrected child index
  
          if (left < n && arr[left] > arr[largest]) {
              largest = left;
          }
  
          if (right < n && arr[right] > arr[largest]) {
              largest = right;
          }
  
          if (largest != i) {
              swap(arr[i], arr[largest]);
              heapify(arr, n, largest);
          }
      }
  
    public:
      // Function to sort an array using Heap Sort.
      void heapSort(vector<int>& arr) {
          int n = arr.size();
  
          // Step 1: Build Max Heap (Bottom-Up Heapify)
          for (int i = n / 2 - 1; i >= 0; i--) {
              heapify(arr, n, i);
          }
  
          // Step 2: Extract elements from heap one by one
          for (int i = n - 1; i > 0; i--) {
              swap(arr[0], arr[i]); // Move current root to end
              heapify(arr, i, 0);   // Heapify reduced heap
          }
      }
};







int main() {

    heap h ;
    h.insert(50) ;
    h.insert(55) ;
    h.insert(53) ;
    h.insert(52) ;
    h.insert(54) ;
    h.print();


    int arr[6] = {-1 , 54 , 53 , 55 , 52 , 50} ;
    int n = 5 ;

    // Heap Creation
    for (int i = n/2 ; i > 0 ; i--)
    {
        heapify(arr , n , i) ;
    }

    cout << "Printing the array now " << endl;
    for (int i = 1 ; i <= n ; i++)
    {
        cout << arr[i] << " ";
    } cout << endl ;


    // HeapSort
    heapSort(arr,n) ;

    cout << "Printing the array now " << endl;
    for (int i = 1 ; i <= n ; i++)
    {
        cout << arr[i] << " ";
    } cout << endl ;





    vector<int> ar = {-1 , 4 , 5 , 2 , 3 , 1} ;
    int m = 5 ;

    
    cout << "Printing the array now " << endl;
    for (int i = 1 ; i <= m ; i++)
    {
        cout << ar[i] << " ";
    } cout << endl ;


    // HeapSort
    HEAP_SORT sol ;
    sol.heapSort(ar) ;

    cout << "Printing the array now " << endl;
    for (int i = 1 ; i <= m ; i++)
    {
        cout << ar[i] << " ";
    } cout << endl ;
    
    return 0;
}








