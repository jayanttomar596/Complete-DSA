#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Comparator for the priority queue (Min-Heap)
class compare {
public:
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val; // Min-Heap: smallest value at the top
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;

        int k = lists.size();
        if (k == 0)
            return nullptr;

        // Step 1: Push all non-null linked list heads into minHeap
        for (int i = 0; i < k; i++) {
            if (lists[i] != nullptr) {
                minHeap.push(lists[i]);
            }
        }

        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        // Step 2: Merge process using priority queue
        while (!minHeap.empty()) {
            ListNode* top = minHeap.top();
            minHeap.pop();

            if (top->next != nullptr) {
                minHeap.push(top->next);
            }

            if (head == nullptr) {
                head = top;
                tail = top;
            } 
            else {
                tail->next = top;
                tail = top;
            }
        }

        return head;
    }
};

// Function to print the linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Function to create a linked list from a vector of values
ListNode* createLinkedList(vector<int> values) {
    if (values.empty()) return nullptr;
    
    ListNode* head = new ListNode(values[0]);
    ListNode* current = head;
    
    for (size_t i = 1; i < values.size(); i++) {
        current->next = new ListNode(values[i]);
        current = current->next;
    }
    
    return head;
}

// Main function to test the implementation
int main() {
    // Creating test linked lists
    vector<ListNode*> lists;
    
    lists.push_back(createLinkedList({1, 4, 5}));
    lists.push_back(createLinkedList({1, 3, 4}));
    lists.push_back(createLinkedList({2, 6}));

    // Merging k sorted linked lists
    Solution sol;
    ListNode* mergedHead = sol.mergeKLists(lists);

    // Printing the final merged linked list
    cout << "Merged Linked List: ";
    printList(mergedHead);

    return 0;
}

