#include <iostream>
using namespace std;
/*———————————————————————————————————————————————————————————————————————————*/
class Set{
    public:
        int count = 0;
        int set[100];
        void InsertToSet(Set*, int a);
        void UnionOfSets(Set*, Set*);
        void IntersectionOfSets(Set*, Set*);
        void DifferenceOfSets1(Set*, Set*);
        void DifferenceOfSets2(Set*, Set*);
        int CardinalityOfSet(Set*);
        int Membership(Set*, int key);
        void Display(Set*);
};
/*———————————————————————————————————————————————————————————————————————————*/
void Set :: InsertToSet(Set *s, int a){
  s->set[count] = a;
  s->count++;
}
/*———————————————————————————————————————————————————————————————————————————*/
void Set :: UnionOfSets(Set *s1, Set *s2){
  cout << "Union of set 1 and set 2 : {";
  int k;
  
  for (int a = 0; a < s1->count; a++){
    cout << s1->set[a] << " ,";
  }
  
    for (int i = 0; i < s2->count; i++){
      for (k = 0; k < s1->count; k++){
        if (s2->set[i] == s1->set[k]){
        break;
      }
    }
    
    if (k == s1->count){
        cout << s2->set[i] << " ,";
    }
  }
  cout << "}\n";
}
/*———————————————————————————————————————————————————————————————————————————*/
void Set :: IntersectionOfSets(Set *s1, Set *s2){
  cout<< "Intersection of set 1 and set 2 : {";
  
  for (int i = 0; i < s1->count; i++){
    for (int j = 0; j < s2->count; j++){
        if (s1->set[i] == s2->set[j])
          cout << s1->set[i] << " ,";
      }
  }
  cout << "}\n";
}
/*———————————————————————————————————————————————————————————————————————————*/
void Set :: DifferenceOfSets1(Set *s1, Set *s2){
   cout << "Difference of set 1 and set 2 : {";
   int l;
   
   for (int i = 0; i < s1->count; i++){
       for (l = 0; l < s2->count; l++){
          if (s1->set[i] == s2->set[l]){
              break;
         }
     }
     if (l == s2->count)
         cout << s1->set[i] << " ,";
   }
   cout << "}\n";
}
/*———————————————————————————————————————————————————————————————————————————*/
void Set :: DifferenceOfSets2(Set *s1, Set *s2){
   cout <<"Difference of set 2 and set 1 : {";
   int l;
   
   for (int i = 0; i < s2->count; i++){
       for (l = 0; l < s1->count; l++){
          if (s2->set[i] == s1->set[l]){
              break;
         }
     }
     if (l == s1->count)
         cout << s2->set[i] << " ,";
   }
   cout << "}\n";
}
/*———————————————————————————————————————————————————————————————————————————*/
int Set :: CardinalityOfSet(Set* s){
    return s->count;
}
/*———————————————————————————————————————————————————————————————————————————*/
int Set :: Membership(Set* s, int key){
    int i;
 
    for (i = 0; i < s->count; i++){
      if (s->set[i] == key)
        return 1;
    }
    return 0;
}
/*———————————————————————————————————————————————————————————————————————————*/
void Set :: Display(Set* s){
    cout << "{";
    for (int i = 0; i < s->count; i++){
        cout << s->set[i] << " ,";
  }
  cout << "}\n";
}
/*———————————————————————————————————————————————————————————————————————————*/
int main (){

Set s1, s2, obj;
int x, y, key;

int ch, val;
  cout << "1 —————> Insert in Set 1\n";
  cout << "2 —————> Insert in Set 2\n";
  cout << "3 —————> Union of Set 1 and Set 2\n";
  cout << "4 —————> Intersection of Set 1 and Set 2\n";
  cout << "5 —————> Difference between Sets (Set 1 - Set 2)\n";
  cout << "6 —————> Difference between Sets (Set 2 - Set 1)\n";
  cout << "7 —————> Cardinality of Set 1\n";
  cout << "8 —————> Cardinality of Set 2\n";
  cout << "9 —————> Check for Membership (Set 1)\n";
  cout << "10 —————> Check for Membership (Set 2)\n";
  cout << "11 —————> Display Set 1\n";
  cout << "12 —————> Display Set 2\n";
  cout << "13 —————> Exit\n";
  
  do{
    cout << "\nEnter your choice : ";
    cin >> ch;
  
    switch(ch){
    
        case 1:
            cout << "Enter the Element to be Added to the Set 1 : ";
            int a;
            cin >> a;
      s1.InsertToSet(&s1, a);
      break;
      
    case 2:
            cout << "Enter the Element to be Added to the Set 2 : ";
            int b;
            cin >> b;
      s2.InsertToSet(&s2, b);
      break;
      
        case 3:
      obj.UnionOfSets(&s1, &s2);
      break;
      
    case 4:
      obj.IntersectionOfSets(&s1, &s2);
      break;
      
    case 5:
      obj.DifferenceOfSets1(&s1, &s2);
      break;
      
    case 6:
      obj.DifferenceOfSets2(&s1, &s2);
      break;
      
    case 7:
          x = s1.CardinalityOfSet(&s1);
        cout << "Cardinality of Set 1 : " << x << "\n";
      break;
      
      case 8:
            y = s2.CardinalityOfSet(&s2);
      cout << "Cardinality of Set 2 : " << y << "\n";
      break;
      
        case 9:
            cout << "Enter the Element to be Checked : ";
            cin >> key;
          if (s1.Membership(&s1, key))
            cout << key << " is present in Set 1\n";
        else
            cout << key << " is not present in Set 1\n";
      break;
      
      case 10:
            cout << "Enter the Element to be Checked : ";
            cin >> key;
          if (s2.Membership(&s2, key))
            cout << key << " is present in Set 2\n";
        else
            cout << key << " is not present in Set 2\n";
      break;
      
      case 11:
            s1.Display(&s1);
      break;
      
      case 12:
            s2.Display(&s2);
      break;
      
        case 13:
      break;
      
    default :
      cout <<"Enter a Value between 1 and 13";
    }
  }while(ch != 13);
}
/*---------------------------------------------------------------------------*/
