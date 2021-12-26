#include <iostream>
#include <stack>

using namespace std;  
/*———————————————————————————————————————————————————————————————————————————*/
bool IsOperator(char);  
bool IsOperand(char);
int precedence(char); 
bool eqlOrhigher(char, char);  
string convert(string);  
/*———————————————————————————————————————————————————————————————————————————*/
int main(){  
    string infix_expression, postfix_expression;  
    int ch;
  
    do {  
        cout << "Enter an infix expression : " << endl;  
        getline (cin, infix_expression);  
        postfix_expression = convert(infix_expression); 
      
        cout << "\nYour Infix expression is : " << infix_expression;  
        cout << "\nPostfix expression is : " << postfix_expression; 
      
        cout << "\n\nDo you want to enter another infix expression (1/0) ? ";  
        cin >> ch;  
    } while(ch == 1);  
  
    return 0;  
}  
/*———————————————————————————————————————————————————————————————————————————*/
// define the IsOperator() function to validate whether any symbol is operator. If the symbol is operator, it returns true, otherwise false.
bool IsOperator(char c){  
    if(c == '+' || c == '-' || c == '*' || c == '/' || c == '^' )  
        return true;     
    return false;  
}  
/*———————————————————————————————————————————————————————————————————————————*/
// IsOperand() function is used to validate whether the character is operand. 
bool IsOperand(char c){
  
    // Define the character in between A to Z. If not, it returns False.
    if( c >= 'A' && c <= 'Z')  
        return true;  

    // Define the character in between a to z. If not, it returns False.
    if (c >= 'a' && c <= 'z')  
        return true; 
  
    // Define the character in between 0 to 9. If not, it returns False.  
    if(c >= '0' && c <= '9')   
        return true;  

    return false;  
}
/*———————————————————————————————————————————————————————————————————————————*/
// precedence() function is used to define the precedence to the operator.
int precedence(char op){  
    if(op == '+' || op == '-')  // it defines the lowest precedence
        return 1;  
    if (op == '*' || op == '/')  
        return 2;  
    if(op == '^')  // exponent operator has the highest precedence 
        return 3;       
return 0; 
}
/*———————————————————————————————————————————————————————————————————————————*/
// eqlOrhigher() function is used to check the higher or equal precedence of the two operators in infix expression. 
bool eqlOrhigher (char op1, char op2){  
    int p1 = precedence(op1);  
    int p2 = precedence(op2);  
  
    if (p1 == p2){  
        if (op1 == '^' )  
            return false;  
        return true;  
    }  
    return  (p1 > p2 ? true : false);  
}  
/*———————————————————————————————————————————————————————————————————————————*/
// string convert() function is used to convert the infix expression to the postfix expression of the Stack 
string convert(string infix){  
    stack <char> S;  
    string postfix = "";    
    char ch;  
  
    S.push('(');  
    infix += ')';  
  
    for (int i = 0; i < infix.length(); i++){  
        ch = infix[i];  
  
        if(ch == ' ' && !IsOperator(infix[i+1])){
            postfix += ' ';
            continue;
        }
             
        if(ch == '(')  
            S.push(ch);
             
             
        else if(IsOperand(ch)){
            postfix += ch;
        }
             
        else if(IsOperator(ch)){  
            while(!S.empty() && eqlOrhigher(S.top(), ch)){
                postfix += S.top();
                S.pop();
            }
            S.push(ch);
            
        }
          
        else if(ch == ')'){  
            while(!S.empty() && S.top() != '('){  
                postfix += S.top();  
                S.pop();
            }  
            S.pop();
        }  
    }  
    return postfix;  
}
/*———————————————————————————————————————————————————————————————————————————*/
