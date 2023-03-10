// Problem 1: You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

// Solution Approach:- Traverse the array and When any operand comes then just push it into stack.
// And when any operator comes pop the stack two times and store the values into variable.
// And then perform the operation And then push the reult into stack again.
// And after end of loop return the stack top value as result.

// Time Complexity: O(n)
// Space Complexity: O(n)

int evalRPN(vector<string> &tokens)
{
    stack<long long> st;
    int foper = 0, soper = 0, len = tokens.size();

    for (int i = 0; i < len; i++)
    {
        if (tokens[i] == "+")
        {
            soper = st.top();
            st.pop();
            foper = st.top();
            st.pop();
            st.push(foper + soper);
        }
        else if (tokens[i] == "-")
        {
            soper = st.top();
            st.pop();
            foper = st.top();
            st.pop();
            st.push(foper - soper);
        }
        else if (tokens[i] == "*")
        {
            soper = st.top();
            st.pop();
            foper = st.top();
            st.pop();
            st.push(foper * soper);
        }
        else if (tokens[i] == "/")
        {
            soper = st.top();
            st.pop();
            foper = st.top();
            st.pop();
            st.push(foper / soper);
        }
        else
        {
            st.push(stoi(tokens[i]));
        }
    }
    return st.top();
}