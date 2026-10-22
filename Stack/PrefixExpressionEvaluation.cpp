#include<iostream>
#include<stack>
using namespace std;

int main() {
    string ch = "-+2*319"; 
    stack<int> st;

    for(int i=ch.size()-1; i>=0; i--) {
        if(isdigit(ch[i])) {
            st.push(ch[i] - '0');
        }
        else {
            int op1 = st.top();
            st.pop();
            int op2 = st.top();
            st.pop();

            if(ch[i] == '+') {
                st.push(op1+op2);
            }
            else if(ch[i] == '-') {
                st.push(op1-op2);
            }
            else if(ch[i] == '*') {
                st.push(op1*op2);
            }
            else if(ch[i] == '/') {
                st.push(op1/op2);
            }
        }
    }

    cout<<"Prefix Result : "<<st.top();
    
}