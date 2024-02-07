// calculater.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include<stack>
#include<string>

using namespace std;

int main(int argc, char* argv[])
{
	string str;
	stack <char>s;
	stack<string> o;


	if (!argv[1])    //if user do not enter the argument:
	{
		cout << "Enter a expression.Use \" \"  if using spaces between operand and operator:" << endl << "Example:calculater.exe 7+8*(3/7) or calculater.exe \"7 + 8 * ( 3 / 7 )\"";
	}

	{
		str = argv[1];


		//checking the expression is valid or not:

		string problem;
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == ' ')
			{
				continue;
			}
			else
			{
				problem = problem + str[i];
			}

		}

		bool flag = true;

		for (int i = 1; i < problem.length() && flag; i++)
		{
			if ((problem[i - 1] == '+' || problem[i - 1] == '-' || problem[i - 1] == '*' || problem[i - 1] == '/') && (problem[i] == '+' || problem[i] == '-' || problem[i] == '*' || problem[i] == '/'))
			{

				flag = false;                                  //If user enters operator after another operater: i.e= 7**8
			}
		}

		if ((problem[0] == '+' || problem[0] == '-' || problem[0] == '*' || problem[0] == '/') || (problem[problem.length() - 1] == '+' || problem[problem.length() - 1] == '-' || problem[problem.length() - 1] == '*' || problem[problem.length() - 1] == '/'))
		{

			flag = false;                                   //If user enters operator at starting and ending: i.e= *6+7 0r 7+3*
		}


		if (flag == false)
		{
			cout << "Invalid expression! " << endl << "Enter a valid expression:";
		}

		//changing the expression from Infix to post fix:

		if (flag)
		{

			for (int i = 0; i < str.length(); i++)
			{
				if (str[i] == ' ')
				{
					continue;
				}
				else if (s.empty())
				{
					if (str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '(' || str[i] == '{' || str[i] == '[')
					{
						s.push(str[i]);
					}
					else
					{
						string s;
						do {
							s = s + str[i];
							i++;
						} while (strr[i]=='0'||str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9');
						o.push(s);
						i--;
					}
				}
				else if (str[i] == '+')
				{
					if (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/')
					{
						do
						{
							o.push(string(1, s.top()));
							s.pop();

						} while (!s.empty() && s.top() != '(' && s.top() != '{' && s.top() != '[');
						s.push(str[i]);

					}
					else
					{
						s.push(str[i]);
					}
				}

				else if (str[i] == '-')
				{

					if (s.top() == '+' || s.top() == '-' || s.top() == '*' || s.top() == '/')
					{
						do
						{
							o.push(string(1, s.top()));
							s.pop();

						} while (!s.empty() && s.top() != '(' && s.top() != '{' && s.top() != '[');
						s.push(str[i]);


					}
					else
					{
						s.push(str[i]);
					}
				}

				else if (str[i] == '*')
				{
					if (s.top() == '*' || s.top() == '/')
					{
						o.push(string(1, s.top()));
						s.pop();
						s.push(str[i]);

					}
					else
					{
						s.push(str[i]);
					}

				}

				else if (str[i] == '/')
				{
					if (s.top() == '*' || s.top() == '/')
					{
						o.push(string(1, s.top()));
						s.pop();
						s.push(str[i]);

					}
					else
					{
						s.push(str[i]);
					}

				}

				else if (str[i] == '(' || str[i] == '{' || str[i] == '[')
				{
					s.push(str[i]);
				}

				else if (str[i] == ')')
				{
					do
					{
						o.push(string(1, s.top()));
						s.pop();

					} while (s.top() != '(');
					s.pop();

				}

				else if (str[i] == '}')
				{
					do
					{
						o.push(string(1, s.top()));
						s.pop();

					} while (s.top() != '{');
					s.pop();
				}

				else if (str[i] == ']')
				{
					do
					{
						o.push(string(1, s.top()));
						s.pop();

					} while (s.top() != '[');
					s.pop();
				}

				else
				{
					string s;
					do {

						s = s + str[i];
						i++;
					} while (str[i] == '1' || str[i] == '2' || str[i] == '3' || str[i] == '4' || str[i] == '5' || str[i] == '6' || str[i] == '7' || str[i] == '8' || str[i] == '9');
					o.push(s);
					i--;
				}


			}

			while (!s.empty())
			{
				o.push(string(1, s.top()));
				s.pop();
			}

			stack<string> a;

			while (!o.empty())                 // TO reverse the stack and make a correct format for calculation:
			{
				a.push(o.top());
				o.pop();
			}

			// solving the postfix expression

			float num;
			float temp1, temp2;
			float result;
			stack<float> c;

			while (!a.empty())
			{

				if (a.top() == "+" || a.top() == "-" || a.top() == "*" || a.top() == "/")
				{
					if (a.top() == "+")
					{
						temp2 = c.top();
						c.pop();
						temp1 = c.top();
						c.pop();

						result = temp1 + temp2;
						c.push(result);
					}

					else if (a.top() == "-")
					{
						temp2 = c.top();
						c.pop();
						temp1 = c.top();
						c.pop();

						result = temp1 - temp2;
						c.push(result);
					}

					else if (a.top() == "*")
					{
						temp2 = c.top();
						c.pop();
						temp1 = c.top();
						c.pop();

						result = temp1 * temp2;
						c.push(result);
					}

					else if (a.top() == "/")
					{
						temp2 = c.top();
						c.pop();
						temp1 = c.top();
						c.pop();

						result = temp1 / temp2;
						c.push(result);
					}

				}
				else
				{
					string t = a.top();
					num = 0;
					for (int i = 0; i < t.length(); i++)
					{
						num = num * 10 + (t[i] - '0');
					}
					c.push(num);
				}

				a.pop();

			}

			// showing the final result:	

			cout << problem << "= " << result;

		}

	}

	return 0;

}

