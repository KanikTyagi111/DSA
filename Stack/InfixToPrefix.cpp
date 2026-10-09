#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int prec(char c)
{
    if(c == '^')
    return 3;
    else if(c == '*' || c == '/')
    return 2;
    else if(c == '+' || c == '-')
    return 1;
    else
    return -1;
}

int main()
{
    stack<char> st;
    string s = "A+(B*C/D-E^F^I+G)/H";  
    reverse(s.begin(), s.end());
    string n = "";

    for(int i=0; i<s.size(); i++)
    {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z'))
        {
            n += s[i];
        }

        else if(s[i] == ')')
        {
            st.push(s[i]);
        }

        else if(s[i] == '(')
        {
            while(!st.empty() && st.top() != ')') 
            {
                n += st.top();
                st.pop();
            }

            if(!st.empty())
            {
                st.pop();
            }

        }

        else{
            while(!st.empty() && (  (prec(st.top()) > prec(s[i])) || (prec(st.top()) == prec(s[i]) && st.top() == '^')  )) 
            {
                n += st.top();
                st.pop();
            }

            st.push(s[i]);
        }
    }

    while(!st.empty())
    {
        n += st.top();
        st.pop();
    }

    reverse(n.begin(), n.end());
    reverse(s.begin(), s.end());

    cout<<"Infix Expression : "<<s<<endl;
    cout<<"Prefix Expression : "<<n<<endl;
}