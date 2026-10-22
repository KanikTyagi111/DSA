#include<iostream>
#include<stack>
using namespace std;

int main() {
    string expression = "231*+9-"; 
    stack<int> st;

    for(char ch : expression) {
        if(isdigit(ch)) {
            st.push(ch - '0');
        }
        else {
            int op2 = st.top();
            st.pop();
            int op1 = st.top();
            st.pop();

            if(ch == '+') {
                st.push(op1+op2);
            }
            else if(ch == '-') {
                st.push(op1-op2);
            }
            else if(ch == '*') {
                st.push(op1*op2);
            }
            else if(ch == '/') {
                st.push(op1/op2);
            }
        }
    }

    cout<<"Postfix Result : "<<st.top();
    
}