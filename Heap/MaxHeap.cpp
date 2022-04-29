#include <iostream>
#include <climits>
using namespace std;
/*———————————————————————————————————————————————————————————————————————————*/
// Prototype of a utility function to swap two integers
void Swap(int* x, int* y);
/*———————————————————————————————————————————————————————————————————————————*/
// A class for Max Heap
class MaxHeap{
    int* harr; // pointer to array of elements in heap
    int capacity; // maximum possible size of max heap
    int HeapSize; // Current number of elements in ma  heap
public:
    // Constructor
    MaxHeap(int capacity);
  
    // to heapify a subtree with the root at given index
    void MaxHeapify(int);
  
    int parent(int i){
        return (i-1)/2;
    }
  
    // to get index of left child of node at index i
    int left(int i){
        return (2*i + 1);
    }
  
    // to get index of right child of node at index i
    int right(int i){
        return (2*i + 2);
    }
  
    // to extract the root which is the maximum element
    int ExtractMax();
  
    // Increases key value of key at index i to new_val
    void IncreaseKey(int i, int NewVal);
  
    // Returns the maximum key (key at root) from max heap
    int GetMax(){
        return harr[0];
    }
  
    // Deletes a key stored at index i
    void DeleteKey(int i);
  
    // Inserts a new key 'k'
    void InsertKey(int k);
    
    void HeapSort();
    
    void NthMax(int n);
    
    void Display();
};
/*———————————————————————————————————————————————————————————————————————————*/
// Constructor: Builds a heap from a given array a[] of given size
MaxHeap::MaxHeap(int cap){
    HeapSize = 0;
    capacity = cap;
    harr = new int[cap];
}
/*———————————————————————————————————————————————————————————————————————————*/
// Inserts a new key 'k'
void MaxHeap::InsertKey(int k){
    if (HeapSize == capacity){
        cout << "\nOverflow : Could not Insert the Key\n";
        return;
    }

    // First insert the new key at the end
    HeapSize++;
    int i = HeapSize - 1;
    harr[i] = k;
  
    // Fix the max heap property if it is violated
    while (i != 0 && harr[parent(i)] > harr[i]){
        Swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}
/*———————————————————————————————————————————————————————————————————————————*/
// Increases value of key at index 'i' to new_val.  It is assumed that new_val is larger than harr[i].
void MaxHeap::IncreaseKey(int i, int NewVal){
    harr[i] = NewVal;
    while (i != 0 && harr[parent(i)] > harr[i]){
        Swap(&harr[i], &harr[parent(i)]);
        i = parent(i);
    }
}
/*———————————————————————————————————————————————————————————————————————————*/
// Method to remove maximum element (or root) from max heap
int MaxHeap::ExtractMax(){
    if (HeapSize <= 0)
        return INT_MIN;
        
    if (HeapSize == 1){
        HeapSize--;
        return harr[0];
    }
  
    // Store the maximum value, and remove it from heap
    int root = harr[0];
    harr[0] = harr[HeapSize-1];
    HeapSize--;
    MaxHeapify(0);
  
    return root;
}
/*———————————————————————————————————————————————————————————————————————————*/
// This function deletes key at index i. It first reduced value to infinite, then calls extractMax()
void MaxHeap::DeleteKey(int i){
    IncreaseKey(i, INT_MAX);
    ExtractMax();
}
/*———————————————————————————————————————————————————————————————————————————*/
// A recursive method to heapify a subtree with the root at given index
// This method assumes that the subtrees are already heapified
void MaxHeap::MaxHeapify(int i){
    int l = left(i);
    int r = right(i);
    int largest = i;
    if (l < HeapSize && harr[l] > harr[i])
        largest = l;
    if (r < HeapSize && harr[r] > harr[largest])
        largest = r;
    if (largest != i){
        Swap(&harr[i], &harr[largest]);
        MaxHeapify(largest);
    }
}
/*———————————————————————————————————————————————————————————————————————————*/
void MaxHeap::HeapSort(){
    int x = HeapSize;

    for (int i = HeapSize - 1; i >= 0; i--) {
        // Move current root to end
        cout << harr[0] << " ";
        Swap(&harr[0], &harr[i]);
    
        HeapSize--;
        
        // call max heapify on the reduced heap
        MaxHeapify(0);
    }
    HeapSize = x;
}
/*———————————————————————————————————————————————————————————————————————————*/
void MaxHeap::NthMax(int n){
    int x = HeapSize;

    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        cout << harr[0] << " ";
        Swap(&harr[0], &harr[i]);
    
        HeapSize--;
        
        // call max heapify on the reduced heap
        MaxHeapify(0);
    }
    cout << n;
    DeleteKey(0);
    HeapSize = x;
}
/*———————————————————————————————————————————————————————————————————————————*/
void MaxHeap::Display(){
    for (int i = 0; i < HeapSize; ++i)
        cout << harr[i] << " ";
    cout << "\n";
}
/*———————————————————————————————————————————————————————————————————————————*/
// A utility function to swap two elements
void Swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}
/*———————————————————————————————————————————————————————————————————————————*/
// Driver program to test above functions
int main(){

    int size;
    cout << "Enter the Maximum Capacity of the Heap : ";
    cin >> size;
    MaxHeap h(size);
    
    int ch, a, b, c, d, n;
    cout << "\n1 —————> Insert Key \n";
    cout << "2 —————> Delete Key \n";
    cout << "3 —————> Increase Key \n";
    cout << "4 —————> Extract Max \n";
    cout << "5 —————> Get Max \n";
    cout << "6 —————> Heap Sort \n";
    cout << "7 —————> Delete the nth Maximum Element \n";
    cout << "8 —————> Display \n";
    cout << "9 —————> Exit \n";
  
    do{
        cout << "\nEnter your choice : ";
        cin >> ch;
  
        switch(ch){
    
            case (1):
                cout << "Enter the Key to be Inserted to the Max Heap : ";
                cin >> a;
                h.InsertKey(a);
                break;
        
            case (2):
                cout << "Enter the Index to be Deleted from the Max Heap : ";
                cin >> b;
                h.DeleteKey(b);
                break;
                
            case (3):
                cout << "Which Index do you want to Increase : ";
                cin >> c;
                cout << "Inrease to : ";
                cin >> d;
                h.IncreaseKey(c, d);
                break;
                
            case (4):
                cout << "Extract Max : " << h.ExtractMax() << endl;
                break;
                
            case (5):
                cout << "Get Max : " << h.GetMax() << endl;
                break;
                
            case (6):
                cout << "Heap Sort : ";
                h.HeapSort();
                cout << endl;
                break;
                
            case (7):
                cout << "Enter the value of n : ";
                cin >> n;
                h.NthMax(n);
                cout << endl;
                break;
                
            case (8):
                h.Display();
                break;
                
            case (9):
                break;
                
            default:
                cout << "Enter a value between 1 and 9";
        }
    }while(ch != 9);

    return 0;
}
