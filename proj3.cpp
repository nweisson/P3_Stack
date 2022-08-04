#include <iostream>
#include "Stack.h"

using namespace std;
using namespace cop4530;

// functions
int postfix_calc(string exp);
string infix2postfix(string exp);
bool checkOp(char c);
int precedence(char c);

int main(){

    string userInput = " "; // to hold infix or postfix string
    int numResult = 0;
    string postfix = " ";   // postfix expression
    char choice = ' ';      // user choice

    do{
        cout << endl;
        cout << "Please enter an infix expression: ";
        getline(cin, userInput);  // get pf expression
        cout << endl;

        postfix = infix2postfix(userInput); // call function


        cout << "The postfix expression is: " << postfix << " = " << postfix_calc(postfix) << endl;   // output

        cout << "\nContinue? (y or n): ";       // if y, continue program
        cin >> choice;
        cin.ignore();


    } while (toupper(choice) == 'Y');


}
// check if char is operator
bool checkOp(char c){

  if (c == '+' || c == '-' || c == '*' || c == '/'){
      return true;
  }
  else{
      return false;
  }

}
// set precedence based on operator
int precedence(char c){

    int p;

    if (c == '*' || c == '/'){
        p = 2;
    }
    else if (c == '+' || c == '-'){
        p = 1;
    }
    else{
        p = 0;
    }

    return p;   // return precedence


}

int postfix_calc(string exp){

    Stack <int> s;

    for (int i = 0; i < exp.length(); i++) // loop through exp
    {

        if ( exp[i] >= '0' &&  exp[i] <= '9') // if char is num push to stack
        {
            s.push( exp[i] - '0');
        }

        else
        {
           // hold 2 numbers in respective vars
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();

            switch (exp[i]) // switch used for operator condition
            {
                case '+': // if char is +
                    s.push(y + x);
                    break;
                case '-': // if char is -
                    s.push(y - x);
                    break;
                case '*': // if char is *
                    s.push(y * x);
                    break;
                case '/': // if char is /
                    s.push(y / x);
                    break;
                default:
                    break;
            }
        }
    }

    return s.top(); // return result

}

// infix to postfix
string infix2postfix(string exp){

    Stack<char> s;  // stack to hold chars in exp
    string result;

    for (int i = 0; i < exp.length(); i++){
        if ((exp[i] >= '0' && exp[i] <= '9'))   // if char is number, add to result
        {
            result += exp[i];
        }
        else if (exp[i] == '('){    // push to stack when ( is found
            s.push(exp[i]);
        }
        else if (exp[i] == ')'){
            while ((s.top() != '(') && (!s.empty())){   // add top of stack to result and pop
                char key = s.top();
                result+=key;
                s.pop();
            }
            if (s.top() == '('){    // if top is (, pop it from the stack
                s.pop();
            }
        }
        else if (checkOp(exp[i])){  // check if char is operator
            if (s.empty()){
                s.push(exp[i]); // if stack empty, push operator to stack
            }
            else{

                if (precedence(exp[i]) >= precedence(s.top())) // push to stack if precedence gt or equal neighbor
                {
                    s.push(exp[i]);
                }
                else{
                    while (!s.empty() && precedence(exp[i]) <= precedence(s.top())){ // add char to result and pop
                        result+=s.top();
                        s.pop();
                    }
                    s.push(exp[i]); // push char to stack
                }
            }
        }

    }

    while (!s.empty()){
        result+=s.top();    // pop remaining chars
        s.pop();
    }

    return result;     /* return postfix expression
                        * note: operator issues with more complicated infix expressions, simple ones like
                        * 1 + 2 work fine */


}
