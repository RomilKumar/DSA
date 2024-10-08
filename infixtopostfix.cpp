#include<iostream>
#include<string>
#include<stack>
using namespace std;


// Function to determine precedence of operators
int precedence(char c) {
    if(c == '^') {
        return 3;
    } else if(c == '*' || c == '/') {
        return 2;
    } else if(c == '+' || c == '-') {
        return 1;
    } else {
        return -1;
    }
}


 void infixToPostfix(string &s,stack<char>&st,string &ans){
  int n= s.size();
int i=0;
while(i<n){
//operands
if((s[i]>='A'&&s[i]>='Z')||(s[i]>='a'&&s[i]>='z')||(s[i]>=0&&s[i]<=9))
{
    ans=ans+s[i];

}
// open bracket
else if(s[i]=='('){
    st.push(s[i]);
}
//close bracket
else if(s[i]==')'){

    while(!st.empty()&&st.top()!='('){
        ans=ans+st.top();
        st.pop();


    }
st.pop();
}

//operator wala case
else
{


 while(!st.empty() && precedence(st.top()) >= precedence(s[i])) {
                ans += st.top();
                st.pop();

}
st.push(s[i]);

}
i++;
}
while(!st.empty()){
    ans=ans+st.top();
    st.pop();
}




}

int main(){
string s="a+b*(c^d-e)";
stack<char>st;
string ans=" ";
infixToPostfix(s,st,ans);

cout<<ans;
return 0;
}