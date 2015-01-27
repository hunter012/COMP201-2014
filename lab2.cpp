#include <fstream>
#include <iostream>
#include <sstream>
#include <stack>
#include <string>
using namespace std;

int evaluate (int opn1, char token, int opn2)
  { int result;
    switch (token)
      {
        case '+' : result = opn1 + opn2;
		break;
        case '-' : result = opn1 - opn2;
		break;
        case '*' : result = opn1 * opn2;
		break;
        case '/' : result = opn1 / opn2;
		break;
        case '^' : result = opn1 ^ opn2;
		break;
      }
    return result;
  }
int priority(char a)
 {
    int temp;
    if (a == '^')
        temp = 3;
    else  if (a == '*' || a == '/')
        temp = 2;
    else  if (a == '+' || a == '-')
        temp = 1;
    else if ( a == '(')
        temp = 0;
    return temp;
}

int main()
{
    string aline;
    string st;;
    int result;
    int  opn2, opn1, temp;

    stack<char> ostack;
    stack<int> istack;
    stringstream output2;
    stringstream output;
    getline(cin,aline);
    st = output.str();
    for (int i = 0; i < aline.length(); i++)
    {
          if(aline[i] == ' ')
              i++;
                if (aline[i] == '+' || aline[i] == '-' || aline[i] == '*' || aline[i] == '/' || aline[i] == '^')
                {
                    while (!ostack.empty() && priority(ostack.top()) >= priority(aline[i]))
                     {
                       output << ostack.top();
                       ostack.pop();
                     }
                  ostack.push(aline[i]);
                }
              else if (aline[i] == '(')
              {
                ostack.push(aline[i]);
              }
              else if (aline[i] == ')')
        {
                 while (ostack.top() != '(')
                {
                    output << ostack.top();
                    ostack.pop();
                }
                 ostack.pop();
        }
           else
             {
            output << aline[i];
             }
    }
    while (!ostack.empty())
     {
        output << ostack.top();
        ostack.pop();
     }

      cout<<aline<<endl;
    cout << output.str() << endl;
st = output.str();
for (int i=0; i < st.length(); i++)
  {
      if (st[i] != '+' && st[i] != '-' & st[i] != '*' & st[i] != '/' & st[i] != '^')
        {
        temp =  st[i] - 48;
           cout<< "temp " << temp <<endl;
          istack.push(temp);
        }
         else
          {
          char token = st[i];
            cout<<"token "<< token <<endl;
        opn2 =  istack.top();
              cout<<"opn2 " << opn2 <<endl;
            istack.pop();
        opn1 =  istack.top();
            cout<<"opn1 " << opn1 <<endl;
              istack.pop();

          result = evaluate(opn1, token, opn2);
          istack.push(result);
          cout <<" result " << result<<endl;
          istack.push(st[i]);
     }
 }
  }