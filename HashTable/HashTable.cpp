#include<iostream>
#include <list>

using namespace std; 
/*———————————————————————————————————————————————————————————————————————————*/
class Hashing{ 
    int hash_bucket;  // No. of buckets 
    list<int> *hashtable;  // Pointer to an array containing buckets 

    public: 
        Hashing(int V);  // Constructor 
        void insert_key(int val);  // inserts a key into hash table 
        void delete_key(int key);  // deletes a key from hash table 
        void displayHash();
        int Search(int key);
   
        // hash function to map values to key 
        int hashFunction(int x){ 
            return (x % hash_bucket); 
        } 
}; 
/*———————————————————————————————————————————————————————————————————————————*/
Hashing :: Hashing(int b){ 
    this->hash_bucket = b; 
    hashtable = new list<int> [hash_bucket]; 
} 
/*———————————————————————————————————————————————————————————————————————————*/
//insert to hash table
void Hashing :: insert_key(int key){ 
    int index = hashFunction(key); 
    hashtable[index].push_back(key);  
} 
/*———————————————————————————————————————————————————————————————————————————*/
void Hashing :: delete_key(int key){ 

    // get the hash index for key 
    int index = hashFunction(key); 
   
    // find the key in (i)th list 
    list <int> :: iterator i;
    
    for (i = hashtable[index].begin(); 
        i != hashtable[index].end(); i++){ 
        if (*i == key) 
            break; 
    }
    
    // if key is found in hash table, remove it 
    if (i != hashtable[index].end()) 
        hashtable[index].erase(i); 
    } 
/*———————————————————————————————————————————————————————————————————————————*/
// display the hash table 
void Hashing :: displayHash() { 
    for (int i = 0; i < hash_bucket; i++) { 
        cout << i; 
        for (int x : hashtable[i]) 
            cout << " ——> " << x; 
        cout << endl; 
    } 
}
/*———————————————————————————————————————————————————————————————————————————*/
int Hashing :: Search(int key){
    int i;
 
    for (i = 0; i < hash_bucket; i++){
        for (int x : hashtable[i]) 
          if (x == key)
            return i;
    }
    return 0;
}
/*———————————————————————————————————————————————————————————————————————————*/
// main program  
int main() { 

    int num;
    cout << "Enter the Number of Hash Buckets : ";
    cin >> num;
    cout << endl;

    int ch, a, b, key;
    cout << "1 —————> Insert \n";
    cout << "2 —————> Delete \n";
    cout << "3 —————> Display \n";
    cout << "4 —————> Check if an Element is Present \n";
    cout << "5 —————> Exit \n";
  
    Hashing h(num);
  
    do{
        cout << "\nEnter your choice : ";
        cin >> ch;
  
        switch(ch){
    
            case (1):
                cout << "Enter the value to be Inserted to the Hash Table : ";
                cin >> a;
                h.insert_key(a);
                break;
        
            case (2):
                cout << "Enter the value to be Deleted from the Hash Table : ";
                cin >> b;
                h.delete_key(b);
                break;
                
            case (3):
                cout << "\nHash Table : \n\n";
                h.displayHash(); 
                break;
                
            case (4):
                cout << "Enter the Element to be Checked : ";
                cin >> key;
              if (h.Search(key))
                cout << key << " is present in the Hash Table in bucket " << h.Search(key) << endl;
            else
                cout << key << " is not present in the Hash Table\n";
          break;
          
            case (5):
                break;
                
            default:
                cout << "Enter a value between 1 and 5";
        }
    }while(ch != 5);
   
  return 0; 
}
