#include <iostream>
using namespace std;
/*———————————————————————————————————————————————————————————————————————————*/
class DisjointSet{
    public:
        int* rank;
        int* parent;
        int n;
        
        // Constructor 
        DisjointSet(int n){
            rank = new int[n];
            parent = new int[n];
            this->n = n;
            makeSet();
        }
        
        void makeSet();
        int find(int x);
        int PrintRank(int x);
        void Union(int x, int y);
        void NoOfConnectedComponents();
        void Display();
};
/*———————————————————————————————————————————————————————————————————————————*/
void DisjointSet :: makeSet(){
    for (int i = 0; i < n; i++){
        parent[i] = i;
    }
}
/*———————————————————————————————————————————————————————————————————————————*/
int DisjointSet :: find(int x){

    // Find the representative of the set that x is an element
    if (parent[x] != x){
        parent[x] = find(parent[x]);
    }
    return parent[x];
}
/*———————————————————————————————————————————————————————————————————————————*/
int DisjointSet :: PrintRank(int x){
    return rank[x];
}
/*———————————————————————————————————————————————————————————————————————————*/
void DisjointSet :: NoOfConnectedComponents(){
    int count = 0;
    for(int i = 0; i < n; i++){
        if (parent[i] == i)
            count++;
    }
    cout << "No. of Connected Components : " << count << endl;
}
/*———————————————————————————————————————————————————————————————————————————*/
void DisjointSet :: Union(int x, int y){
 
    // Find current sets of x and y
    int xset = find(x);
    int yset = find(y);
 
    // If they are already in same set
    if (xset == yset){
        cout << "Cycle Detected!! \n";
        return;
    }
    // Put smaller ranked item under bigger ranked item if ranks are different
    if (rank[xset] < rank[yset]) {
        parent[xset] = yset;
    }
    
    else if (rank[xset] > rank[yset]){
        parent[yset] = xset;
    }
    
    // If ranks are same, then increment rank.
    else{
       parent[yset] = xset;
       rank[xset] = rank[xset] + 1;
    }
    cout << "No Cycle Detected \n";
}
/*———————————————————————————————————————————————————————————————————————————*/
void DisjointSet :: Display(){
    
    cout << "\n   Set : ";
    for(int i = 0; i < n; i++){
        cout << i << " ";
    }
    cout << endl;
    
    cout << "Parent : ";
    for(int i = 0; i < n; i++){
        cout << parent[i] << " ";
    }
    cout << endl;
    
    cout << "  Rank : ";
    for(int i = 0; i < n; i++){
        cout << rank[i] << " ";
    }
    cout << endl;
}
/*———————————————————————————————————————————————————————————————————————————*/
int main(){

    int num, choice, n1, n2;
   
    cout << "Enter the Number of Sets : ";
    cin >> num;
    cout << endl;
   
    DisjointSet obj(num);
       
    cout << "1 —————> Union By Rank and Cycle Detection \n";
    cout << "2 —————> Root of an Element \n";
    cout << "3 —————> Rank of an Element \n";
    cout << "4 —————> Check if Two Numbers Belong to the Same Set \n";
    cout << "5 —————> No. of Connected Components \n";
    cout << "6 —————> Display \n";
    cout << "7 —————> Exit \n";

    do{
        cout << "\nENTER THE CHOICE : ";
        cin >> choice;
        
        switch(choice){
   
            case 1:
                cout << "Enter The Number 1 : ";
                cin >> n1;
                cout << "Enter The Number 2 : ";
                cin >> n2;
                
                if (n1 > num || n2 > num){
                    cout << "Invalid Set ID.\n";
                    break;
                }
            
                obj.Union(n1, n2);
                break;
       
            case 2:
                cout << "Enter The Number : ";
                cin >> n1;
                
                cout << "Root of " << n1 << " : " << obj.find(n1) << endl;
                break;
                
            case 3:
                cout << "Enter The Number : ";
                cin >> n1;
                
                cout << "Rank of " << n1 << " : " << obj.PrintRank(n1) << endl;
                break;
                
            case 4:
                cout << "Enter The Number 1 : ";
                cin >> n1;
                cout << "Enter The Number 2 : ";
                cin >> n2;
                
                if (n1 >= num || n2 >= num){
                    cout << "Invalid Set ID.\n";
                    break;
                }
                
                if (obj.find(n1) == obj.find(n2))
                    cout << "Yes\n";
                else
                    cout << "No\n";
                break;
   
            case 5 :
                obj.NoOfConnectedComponents();
                break;
                
            case 6 :
                obj.Display();
                break;
                
            case 7 :
                break;
        }
    }while(choice != 7);
    return 0;
}
