#include<iostream>
#include<algorithm>
using namespace std;
#include<stack>


int calculate(string s)
{
    stack<int> st;
    int result = 0;
    int number = 0;
    int sign = 1;

    int last_number = 0; // for * and /
    char op = '+';       // previous operator

    for (int i = 0; i < s.length(); i++)
    {

        if (isdigit(s[i]))
        {
            number = number * 10 + (s[i] - '0');
        }

        // When operator OR end of string
        if ((!isdigit(s[i]) && s[i] != ' ') || i == s.length() - 1)
        {

            if (op == '+')
            {
                result += last_number;
                last_number = number;
            }
            else if (op == '-')
            {
                result += last_number;
                last_number = -number;
            }
            else if (op == '*')
            {
                last_number = last_number * number;
            }
            else if (op == '/')
            {
                last_number = last_number / number;
            }

            op = s[i];
            number = 0;
        }

        // Handle '('
        if (s[i] == '(')
        {
            st.push(result);
            st.push(last_number);
            st.push(op);

            result = 0;
            last_number = 0;
            op = '+';
        }

        // Handle ')'
        if (s[i] == ')')
        {

            result += last_number; // finish inner expression
            int bracket_value = result;

            char prev_op = st.top();
            st.pop();
            int prev_last = st.top();
            st.pop();
            int prev_result = st.top();
            st.pop();

            result = prev_result;
            last_number = prev_last;
            op = prev_op;

            number = bracket_value; // treat bracket as a number
        }
    }

    result += last_number;
    return result;
}

int main(){
    string s;
    cout<<"Enter String: ";
    cin>>s;
    cout<<"Output: ";
    cout<<calculate(s);
}