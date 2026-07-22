#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// ================= Max Heap =================
class MaxHeap {
private:
    priority_queue<int> pq;

public:
    void push(int x) {
        pq.push(x);
    }

    void pop() {
        if (!pq.empty())
            pq.pop();
    }

    int peek() {
        if (pq.empty())
            return -1;
        return pq.top();
    }

    int size() {
        return pq.size();
    }

    bool isEmpty() {
        return pq.empty();
    }
};

// ================= Min Heap (Manual) =================
class MinHeap {
private:
    vector<int> heap;

public:
    void push(int x) {
        heap.push_back(x);
        int curr = heap.size() - 1;

        // Heapify Up
        while (curr > 0) {
            int parent = (curr - 1) / 2;
            if (heap[curr] < heap[parent]) {
                swap(heap[curr], heap[parent]);
                curr = parent;
            } else {
                break;
            }
        }
    }

    void pop() {
        if (heap.empty())
            return;

        heap[0] = heap.back();
        heap.pop_back();

        int n = heap.size();
        int curr = 0;

        // Heapify Down
        while (true) {
            int smallest = curr;
            int left = 2 * curr + 1;
            int right = 2 * curr + 2;

            if (left < n && heap[left] < heap[smallest])
                smallest = left;

            if (right < n && heap[right] < heap[smallest])
                smallest = right;

            if (smallest != curr) {
                swap(heap[curr], heap[smallest]);
                curr = smallest;
            } else {
                break;
            }
        }
    }

    int peek() {
        if (heap.empty())
            return -1;
        return heap[0];
    }

    int size() {
        return heap.size();
    }

    bool isEmpty() {
        return heap.empty();
    }

    void printHeap() {
        cout << "Heap: ";
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

// ================= Main =================
int main() {

    // Test Max Heap
    cout << "===== Max Heap Implementation =====" << endl;

    MaxHeap maxHeap;

    cout << "Inserting: 10, 20, 15, 30, 5" << endl;
    maxHeap.push(10);
    maxHeap.push(20);
    maxHeap.push(15);
    maxHeap.push(30);
    maxHeap.push(5);

    cout << "Size: " << maxHeap.size() << endl;
    cout << "Peek (max element): " << maxHeap.peek() << endl;

    cout << "\nRemoving elements in order:" << endl;
    while (!maxHeap.isEmpty()) {
        cout << "Top: " << maxHeap.peek() << endl;
        maxHeap.pop();
    }

    cout << "Size after all removals: " << maxHeap.size() << endl;
    cout << "Peek on empty heap: " << maxHeap.peek() << endl;

    // Test Min Heap
    cout << "\n===== Min Heap Implementation =====" << endl;

    MinHeap minHeap;

    cout << "Inserting: 10, 20, 15, 30, 5" << endl;
    minHeap.push(10);
    minHeap.push(20);
    minHeap.push(15);
    minHeap.push(30);
    minHeap.push(5);

    minHeap.printHeap();

    cout << "Size: " << minHeap.size() << endl;
    cout << "Peek (min element): " << minHeap.peek() << endl;

    cout << "\nRemoving elements in order:" << endl;
    while (!minHeap.isEmpty()) {
        cout << "Top: " << minHeap.peek() << endl;
        minHeap.pop();
        if (!minHeap.isEmpty())
            minHeap.printHeap();
    }

    cout << "Size after all removals: " << minHeap.size() << endl;
    cout << "Peek on empty heap: " << minHeap.peek() << endl;

    // Additional Test
    cout << "\n===== Additional Min Heap Test =====" << endl;

    MinHeap minHeap2;

    vector<int> arr = {50, 30, 20, 15, 10, 8, 16};

    cout << "Inserting: ";
    for (int x : arr) {
        cout << x << " ";
        minHeap2.push(x);
    }
    cout << endl;

    minHeap2.printHeap();

    cout << "Min element: " << minHeap2.peek() << endl;

    return 0;
}