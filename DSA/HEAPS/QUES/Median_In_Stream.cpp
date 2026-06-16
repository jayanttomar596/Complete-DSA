//  Median in a stream



/*

Problem statement
Given that integers are read from a data stream. Your task is to find the median of the elements read so far.

Median is the middle value in an ordered integer list. If the size of the list is even there is no middle value. So the median is the floor of the average of the two middle values.

For example :
[2,3,4] - median is 3.
[2,3] - median is floor((2+3)/2) = 2.

*/






#include <iostream>
#include <queue>
#include <vector>
using namespace std;




class MedianFinder {
    private:
        priority_queue<int> maxHeap; // lower half (max heap)
        priority_queue<int, vector<int>, greater<int>> minHeap; // upper half (min heap)
    
    public:
        MedianFinder() {
            // Constructor: no initialization needed here
        }
        
        void addNum(int num) {
            // Step 1: Push to maxHeap (lower half)
            maxHeap.push(num);
    
            // Step 2: Balance: move top from maxHeap to minHeap
            minHeap.push(maxHeap.top());
            maxHeap.pop();
    
            // Step 3: Ensure maxHeap has >= minHeap size
            if (maxHeap.size() < minHeap.size()) {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        
        double findMedian() {
            if (maxHeap.size() > minHeap.size()) {
                return maxHeap.top(); // odd case
            } else {
                return (maxHeap.top() + minHeap.top()) / 2.0; // even case
            }
        }
};





int signum(int a , int b)
{
    if (a == b)
        return 0 ;
    else if (a > b)
        return 1 ;
    else
        return -1 ;    
}




void callMedian(int element , priority_queue<int> &maxi , priority_queue<int , vector<int> , greater<int> > &mini , int &median)
{

    switch(signum(maxi.size() , mini.size()))
    {

        case 0 : if (element > median)
                {
                    mini.push(element) ;
                    median = mini.top() ;
                }
                else
                {
                    maxi.push(element) ;
                    median = maxi.top() ;
                }
            break ;

        case 1 : if (element > median){
                    mini.push(element) ;
                    median = (mini.top() + maxi.top())/2 ;
                }        
                else
                {
                    mini.push(maxi.top());
                    maxi.pop() ;
                    maxi.push(element) ;
                    median = (mini.top() + maxi.top())/2 ;
                }
            break ;

        case -1 : if (element > median)
                { 
                    maxi.push(mini.top()) ;
                    mini.pop() ;
                    mini.push(element) ;
                    median = (mini.top() + maxi.top())/2 ;
                }
                else
                {
                    maxi.push(element) ;
                    median = (mini.top() + maxi.top())/2 ;
                }
            break;    
                      
    }
}





// T.C. -> O(NlogN)
// S.C. -> O(N)

vector<int> findMedian(vector<int> &arr , int n)
{
    vector<int> ans ;
    priority_queue<int> maxheap ;
    priority_queue<int , vector<int> , greater<int> > minheap ;
    int median = 0 ;

    for (int i = 0 ; i < n ; i++)
    {
        callMedian(arr[i] , maxheap , minheap , median) ;
        ans.push_back(median) ;
    }

    return ans ;
}



void print_vector(vector<int> v)
{
    for (int i = 0 ; i < v.size() ; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}







int main() {

    vector<int> v = {1 ,2 ,3} ;

    cout << "\nVector : ";
    print_vector(v) ;

    cout << endl;


    vector<int> ans = findMedian(v , v.size()) ;

    cout << "\nMedian Vector : ";
    print_vector(ans) ;
    cout << endl;
    // Output : 1 1 2


    vector<int> ans2 ;
    MedianFinder obj ;
    for (int i = 0 ; i < v.size() ; i++)
    {
        obj.addNum(v[i]);
        ans2.push_back(obj.findMedian()) ;
    }

    print_vector(ans2);
    
    return 0;
}



