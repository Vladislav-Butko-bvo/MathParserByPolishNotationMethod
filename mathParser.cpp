#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <sstream>
using namespace std;

//operations priority
struct Weigth
{
	int equal = -1;
	int sum = 1;
	int mult = 2;
	int dev = 2;
	int step = 3;
	int bktOpen = -100;
	int bktClose = -99;
};

//comparing the input with the names of the menu title tabs existing in the program
int command(string input_D)
{
	if (
		input_D.length() < 5 &&
		input_D[1] == 'e' &&
		input_D[2] == 'n' &&
		input_D[3] == 'd'
		)
	{
		return 1;	//terminate the program
	}
	else if
		(
			input_D.length() < 7 &&
			input_D[1] == 'a' &&
			input_D[2] == 'b' &&
			input_D[3] == 'o' &&
			input_D[4] == 'u' &&
			input_D[5] == 't'
			)
	{
		return 2;
	}
	else if
		(
			input_D.length() < 6 &&
			input_D[1] == 'n' &&
			input_D[2] == 'e' &&
			input_D[3] == 'w' &&
			input_D[4] == 's'
			)
	{
		return 3;
	}
	else if
		(
			input_D.length() < 5 &&
			input_D[1] == 'f' &&
			input_D[2] == 'a' &&
			input_D[3] == 'q'
			)
	{
		return 4;
	}
	else if
		(
			input_D.length() < 3 &&
			input_D[1] == '-'
			)
	{
		return 5;	//hide the steps of solving a mathematical expression
	}
	else if
		(
			input_D.length() < 3 &&
			input_D[1] == '+'
			)
	{
		return 6;	//show the steps of solving a mathematical expression
	}
	else
		return 0;	//no such menu tab exists
}

//input comparing with 14 common error patterns
int areTreatedUnccorect(string input_D, vector<char> stack_bkt, vector<int> stack_bkt2, bool error[])
{
	int nonExpresionBkt = 0;
	int BktON = 0;
	int a = 0, b = 0, c = 0, d = 0, e = 0, f = 0, g = 0, h = 0, v = 0, w = 0;
	for
		(
			unsigned int i = 0;
			i < input_D.length(); i++
			)
	{
		if (error[0] == false)
		{
			if
				(
					input_D[i] == '.' ||
					input_D[i] == '0' ||
					input_D[i] == '1' ||
					input_D[i] == '2' ||
					input_D[i] == '3' ||
					input_D[i] == '4' ||
					input_D[i] == '5' ||
					input_D[i] == '6' ||
					input_D[i] == '7' ||
					input_D[i] == '8' ||
					input_D[i] == '9' ||
					input_D[i] == '+' ||
					input_D[i] == '-' ||
					input_D[i] == '*' ||
					input_D[i] == '/' ||
					input_D[i] == '^' ||
					input_D[i] == ')' ||
					input_D[i] == '(' ||
					input_D[i] == '='
					)
			{
			}
			else
			{
				error[0] = true;
			}
		}
		if (error[1] == false && input_D[i] == '=' && i + 1 != input_D.length())
		{
			error[1] = true;
		}
		if (error[2] == false)
		{
			if (input_D[i] == '=')
			{
				c++;
			}
			else if (i + 1 == input_D.length() && c == 0)
			{
				error[2] = true;
			}
		}
		if (error[4] == false)
		{
			if (
				input_D[i] == '+' ||
				input_D[i] == '-' ||
				input_D[i] == '*' ||
				input_D[i] == '/' ||
				input_D[i] == '^'
				)
			{
				a++;
				if (a > 1)
					error[4] = true;
			}
		}
		if (error[5] == false)
		{
			if
				(
					input_D[i] == '+' ||
					input_D[i] == '-' ||
					input_D[i] == '*' ||
					input_D[i] == '/' ||
					input_D[i] == '^'
					)
			{
				b++;
			}
			else
			{
				a = 0;
			}
		}
		if (error[5] == false && i + 1 == input_D.length() && b == 0)
		{
			error[5] = true;
		}
		if (error[6] == false && i == 0)
		{
			if
				(
					input_D[i] == '+' ||
					input_D[i] == '*' ||
					input_D[i] == '/' ||
					input_D[i] == '^'
					)
			{
				error[6] = true;
			}
		}
		if (error[7] == false)
		{
			if (i + 1 == input_D.length())
			{
				if
					(
						input_D[i] == '+' ||
						input_D[i] == '-' ||
						input_D[i] == '*' ||
						input_D[i] == '/' ||
						input_D[i] == '^'
						)
				{
					error[7] = true;
				}
			}
			if (i + 2 == input_D.length() && input_D[i + 1] == '=')
			{
				if
					(
						input_D[i] == '+' ||
						input_D[i] == '-' ||
						input_D[i] == '*' ||
						input_D[i] == '/' ||
						input_D[i] == '^'
						)
				{
					error[7] = true;
				}
			}
		}
		if (error[9] == false || error[13] == false)
		{
			if
				(
					input_D[i] == '1' ||
					input_D[i] == '2' ||
					input_D[i] == '3' ||
					input_D[i] == '4' ||
					input_D[i] == '5' ||
					input_D[i] == '6' ||
					input_D[i] == '7' ||
					input_D[i] == '8' ||
					input_D[i] == '9'
					)
			{
				if (h == 0 && e > 0 && d == 0)
					error[9] = true;
				d++;
			}
			else if (input_D[i] == '0')
			{
				e++;
				if (h == 0 && e > 1 && d == 0)
					error[9] = true;
			}
			else if (input_D[i] == '.')
			{
				h++;
				if (d == 0 && e == 0)
					error[13] = true;
				else if (h > 1)
					error[13] = true;
				else if
					(
						input_D[i + 1] == '+' ||
						input_D[i + 1] == '-' ||
						input_D[i + 1] == '*' ||
						input_D[i + 1] == '/' ||
						input_D[i + 1] == '^' ||
						input_D[i + 1] == ')' ||
						input_D[i + 1] == '('
						)
					error[13] = true;
			}
			else
			{
				d = 0;
				e = 0;
				h = 0;
			}
		}
		if (input_D[i] == '(' || input_D[i] == ')')
			stack_bkt.push_back(input_D[i]);
		if (input_D[i] == '(')
			stack_bkt2.push_back(+i);
		else if (input_D[i] == ')')
			stack_bkt2.push_back(i * -1);
		if (error[10] == false && i + 1 == input_D.length())
		{
			for (unsigned int j = 0; j < stack_bkt.size(); j++)
			{
				BktON = 1;
				if (stack_bkt[j] == ')' && j != 0 && stack_bkt[j - 1] == '(')
				{
					stack_bkt.erase(stack_bkt.begin() + j);
					stack_bkt.erase(stack_bkt.begin() + j - 1);
					j = 0;
				}
			}
			if (stack_bkt.size() != 0)
				error[10] = true;
		}
		if (error[10] == false && i + 1 == input_D.length())
		{
			for (unsigned int j = 0; j < stack_bkt2.size(); j++)
			{
				int stack_bkt_end = 0;
				int stack_bkt_start = 0;

				if (stack_bkt2[j] < 0 && j != 0)
				{
					stack_bkt_end = (stack_bkt2[j] * -1) - 1;
					stack_bkt_start = stack_bkt2[j - 1] + 1;
					stack_bkt2.erase(stack_bkt2.begin() + j);
					stack_bkt2.erase(stack_bkt2.begin() + j - 1);
					j = 0;
					int b2 = 0;
					for
						(
							int i2 = stack_bkt_start;
							i2 <= stack_bkt_end; i2++
							)
					{
						nonExpresionBkt = 1;
						if
							(
								input_D[i2] == '+' ||
								input_D[i2] == '-' ||
								input_D[i2] == '*' ||
								input_D[i2] == '/' ||
								input_D[i2] == '^'
								)
						{
							b2++;
						}
						if (error[5] == false && i2 == stack_bkt_end && b2 == 0)
						{
							error[5] = true;
						}
						if (error[6] == false && i2 == stack_bkt_start)
						{
							if
								(
									input_D[i2] == '+' ||
									input_D[i2] == '*' ||
									input_D[i2] == '/' ||
									input_D[i2] == '^'
									)
							{
								error[6] = true;
							}
						}
						if (error[7] == false)
						{
							if (i2 == stack_bkt_end)
							{
								if
									(
										input_D[i2] == '+' ||
										input_D[i2] == '-' ||
										input_D[i2] == '*' ||
										input_D[i2] == '/' ||
										input_D[i2] == '^'
										)
								{
									error[7] = true;
								}
							}
						}
					}
				}
			}
		}
		if (error[12] == false && error[10] == false && i != 0 && input_D[i] == '(')
		{
			if
				(
					input_D[i - 1] == '+' ||
					input_D[i - 1] == '-' ||
					input_D[i - 1] == '*' ||
					input_D[i - 1] == '/' ||
					input_D[i - 1] == '^' ||
					input_D[i - 1] == '('
					)
			{
			}
			else
			{
				error[12] = true;
			}
		}
		if (error[12] == false && error[10] == false && i != 0 && i + 2 != input_D.length() && input_D[i] == ')')
		{
			if
				(
					input_D[i + 1] == '+' ||
					input_D[i + 1] == '-' ||
					input_D[i + 1] == '*' ||
					input_D[i + 1] == '/' ||
					input_D[i + 1] == '^' ||
					input_D[i + 1] == ')'
					)
			{
			}
			else
			{
				error[12] = true;
			}
		}
	}
	if (input_D.length())
	{
	}
	else
		error[8] = true;
	if (BktON == 1 && error[10] == false && nonExpresionBkt == 0)
	{
		error[8] = true;
	}
	if (fun_ierror(error)) {
		printf("||%-93s||\n", "ERROR_input: please, review \"Correct input istance\" and repeat");
		return 1;
	}
	else
		return 0;
}

//checking for the existence of an input error of one of 14 error types 
bool fun_ierror(bool error[]) {
	for (int i = 0; i < 13; i++) {
		if (error[i] == 1) {
			return 1;
		}
	}
	return 0;
}

//the operation execution
long double action(vector<char>* stack_A, long double a, long double b)
{
	switch (stack_A->back())
	{
	case '+': return a + b;
	case '*': return a * b;
	case '/': return a / b;
	case '^': return pow(a, b);
	default: exit(055); 
	}
}

//returning priority of operation in top of the stack operations 
int getAction2(vector<char>* stack_A, Weigth weigth)
{
	switch (stack_A->back())
	{
	case '+': return weigth.sum;
	case '*': return weigth.mult;
	case '/': return weigth.dev;
	case '^': return weigth.step;
	case '(': return weigth.bktOpen;
	default: exit(070); 
	}
}

//returning priority of next operation in the input
int getAction1(vector<char>* stack_A, string input_D, unsigned int i, Weigth weigth)
{
	switch (input_D[i])
	{
	case '+': return weigth.sum;
	case '*': return weigth.mult;
	case '/': return weigth.dev;
	case '^': return weigth.step;
	case ')': return weigth.bktClose;
	case '=': return weigth.equal;
	default: exit(0104);
	}
}

//the last operation in the operation stack is executed or a new operation is added to this stack
void count(vector<long double>* stack_N, vector<char>* stack_A, string input_D, unsigned int i, Weigth weigth, long double a, long double b, bool q)
{
	for (bool iter = 1; iter != 0; )
	{
		//if the next operation has a higher priority than the previous one, then add this operation to the operation stack
		if (stack_A->size() == 0 || getAction1(stack_A, input_D, i, weigth) > getAction2(stack_A, weigth))
		{
			stack_A->push_back(input_D[i]); iter = 0;
		}
		//otherwise, execute the last operation in the operation stack
		else if
			(
				getAction1(stack_A, input_D, i, weigth) < getAction2(stack_A, weigth) ||
				getAction1(stack_A, input_D, i, weigth) == getAction2(stack_A, weigth)
				)
		{
			b = stack_N->back();
			stack_N->pop_back();
			a = stack_N->back();
			stack_N->pop_back();
			stack_N->push_back(action(stack_A, a, b));
			ostringstream length;
			length.precision(14);
			length << a << stack_A->back() << b << stack_N->back();
			if (q)
				if (input_D[i] == ')')
					cout << "||" << '(' << a << stack_A->back() << b << ')' << '=' << stack_N->back() << right << setw(95 - 3 - length.str().size()) << "||" << setw(0) << left << '\n';
				else
					cout << "||" << a << stack_A->back() << b << '=' << stack_N->back() << right << setw(95 - 1 - length.str().size()) << "||" << setw(0) << left << '\n';
			length.str("");
			stack_A->pop_back();
		}
		else
			exit(0104); 
	}
}

//conversion of two or more sequential digits into two-digit or larger numbers
long double rangeUP(vector<long double>* range, int j, int k)
{
	long double sum = 0;
	long double mult = 1;
		//a sequence of digits is converted into an integer. 
		//This sequence can be an integer in a mathematical expression or a part of a real (before/after decimal dot)
	for (int i = 0; i < j; i++)	
	{
		sum += (*range)[i] * mult;
		mult *= 10;
	}
		//if converted integer is part of real number after decimal dot, 
		//then it is divided by 10 as many times as there are digits in the converted integer
	if (k > 0)	
	{
		for (int i = 0; i < j; i++)
			sum /= 10.0;
	}
	return sum;
}

void getRange(vector<long double>* stack_N, vector<long double>* range, int j, int k, int m)
{
	while (range->size() != 0)	//removing all elements of the vector "range"
	{
		range->pop_back();
	}
	for (int i = 0; i < j; i++)	//digits before decimal dot are copied from "stack_N" array to "range" array
	{
		range->push_back(NULL);
		range->back() = stack_N->back();
		stack_N->pop_back();
	}
	
	if (k == 0){	//if input number is without decimal dot (integer number)
		stack_N->push_back(
			pow(-1, m) * 		//-1^m, m –  is the amount of minuses before the number,
			rangeUP(range, j, k));	//converts a sequence of digit-characters to a number
		//Example:
		//if the string -(-22) is encountered, then the action is performed: -1^2 = 1 * (2*10 + 2) = 22
		//if the string -22 is encountered, then the action is performed: -1^1 = -1 * (2*10 + 2) = -22
	}
	else if (k > 0)	//number before the operation is real
	{
		long double a;
		a = stack_N->back();	//integer number before decimal dot 
		stack_N->pop_back();
		stack_N->push_back(a + (pow(-1, m) * rangeUP(range, j, k)));
	}
	else
		exit(0112); 
}

//this function is called after encountering the symbol: '+', '-', '*', '/', '^', ')' and '=' while parsing
void stepByResult(vector<long double>* range, int* j, int* k, int* m, vector<long double>* stack_N, vector<char>* stack_A, string input_D, unsigned int i, Weigth weigth, long double a, long double b, bool q)
{
	if (*j > 0)	//if the previous number before the operation is real (with decimal dot)
		getRange(*&stack_N, range, *j, *k, *m);
	*j = 0; *k = 0; *m = 0;	//after each operation, the counter of the amount of digits before decimal dot of the last real number, decimal dots, minuses symbols is reset
	count(*&stack_N, *&stack_A, input_D, i, weigth, a, b, q);
}

int main()
{
	Weigth weigth;
	int j;		//counting the number of digits before decimal dot
	int k;		//incremented if decimal dot occurs
	int m;		//incremented if minus symbol occurs		
	int n;		//counter of the amount of nested mathematical expressions (opening brackets)
	bool q = 0; 			//is responsible for enabling/disabling the steps of solving a mathematical expression
	bool error[13];			//an array consisting of binary values ​​indicating the presence of a certain type of syntax error of entered mathematical expression   
	vector<long double> range; 	//an array of digits separated by mathematical signs (from these digits decimal numbers of the corresponding bit rate are formed)
	vector<long double> stack_N;	//stack of numbers
	vector<char> stack_A;		//stack of operations
	vector<char> stack_bkt;
	vector<int> stack_bkt2;
	string input_D;			//user input
	cout << setprecision(14);
	printf("||%-93s||\n", "__________________________Are welcome to parser of math expressions!_________________________");
	printf("||%-93s||\n", "-------------------------------------------PASSPORT------------------------------------------");
	printf("||%-93s||\n", "Significant digits (precision): 14.");
	printf("||%-93s||\n", "Input errors are blocked and displayed.");
	printf("||%-93s||\n", "Functionals: 1) actions as +,-,*,/,^; 2) brackets; 3) nested brackets;");
	printf("||%-93s||\n", "4) floating point numbers; 5) unary minus.");
	printf("||%-93s||\n", "Correct input instance:1+2-3*4/5^6+(66+115)+((2+2)*2)+1.2-0.033+(-2)+(-2+2)="); // Result:191.166232 
	printf("||%-93s||\n", "Difined commands:");
	printf("||%-93s||\n", "status             | command");
	printf("||%-93s||\n", "                   | %end   (to complete programm)");
	printf("||%-93s||\n", "                   | %about (to view commentaries to how it's work)");
	printf("||%-93s||\n", "                   | %news  (to view news of developing process)");
	printf("||%-93s||\n", "                   | %faq   (to view common quetions)");
	printf("||%-93s||\n", "default            | %-     (turn off result steps)");
	printf("||%-93s||\n", "                   | %+     (turn on result steps)");
	
	for (bool iter = 1; iter != 0; )	//user input in cycle (input new math ex. or menu tab title with symbol '%')
	{
		//clearing variables and vectors at the beginning of a new iteration
		j = 0;
		k = 0;
		m = 0;
		n = 0;
		for (int i = 0; i < sizeof(error) / sizeof(error[0]); i++)
			error[i] = false;
		for (unsigned int i = 0; i < range.size(); i++)
			range.pop_back();
		for (unsigned int i = 0; i < stack_N.size(); i++)
			stack_N.pop_back();
		for (unsigned int i = 0; i < stack_A.size(); i++)
			stack_A.pop_back();
		
		ostringstream length;
		length << iter;
		printf("||%-93s||\n", "---------------------------------------------------------------------------------------------");
		printf("||>");
		getline(cin, input_D);
		if (input_D[0] == '%')		//the % sign means that the user is selecting a menu tab in the console interface 
		{
			switch (command(input_D))	//comparing the input with the names of the menu title tabs existing in the program
			{
			case 0:				//displaying a message about an error in writing the name of the menu tab and giving the user a try to enter the name again
				printf("||%-93s||\n", "ERROR_0: command undefined"); continue;	
			case 1:
				iter = 0; continue; 	//terminate the programm
			case 2:
				printf("||%-93s||\n", "-----------------------------ABOUT OF SOURCE CODE AND ALGORITM-------------------------------");
				printf("||%-93s||\n", "Idea: https://www.youtube.com/watch?v=Vk-tGND2bfc%D1%84");
				printf("||%-93s||\n", "Note: I took the example from this video as a basis; but the implementation is completely");
				printf("||%-93s||\n", "mine; also, from the functionality, added unary minus and floating point.");
				printf("||%-93s||\n", "----------------------------");
				printf("||%-93s||\n", "User goal: test the algorithm for compiler errors, crashes and incorrect answers");
				printf("||%-93s||\n", "----------------------------");
				printf("||%-93s||\n", "Note on the source code: In places where conditional operators are used, an emergency exit is");
				printf("||%-93s||\n", "provided \"exit()\"; for \"if\" this is \"else exit()\". for switch it's \"default: exit()\".");
				continue;
			case 3:
				printf("||%-93s||\n", "-------------------------------------------NEWS----------------------------------------------");
				printf("||%-93s||\n", "1. You can have incorrect enter and don't afraid that program will be crashed!");
				printf("||%-93s||\n", "2. Current version is stable. Big additions aren't planned yet.");
				printf("||%-93s||\n", "3. We're planning some a minor: 1) to wide up count of significant digit;");
				continue;
			case 4:
				printf("||%-93s||\n", "--------------------------------------------FAQ----------------------------------------------");
				printf("||%-93s||\n", "1. How to enter -1+2? - It's correct. Also you can enter (-1)+2");
				printf("||%-93s||\n", "2. How to enter 1.2345? - It's correct, cuz froating point supports");
				printf("||%-93s||\n", "3. How to enter 1.2345e-4? - It's incorrect. Will be true: 1.2345/10^4, cuz expotial input");
				printf("||%-93s||\n", "   don't supports");
				printf("||%-93s||\n", "4. Why it don't worked: 1,2345? - Be correct 1.2345. Exists only one implementation of");
				printf("||%-93s||\n", "   floating point by dot symbol \".\"");
				printf("||%-93s||\n", "5. Why it don't worked: \"1+2= \"? - Be correct 1+2=. You have entered space symbol in the");
				printf("||%-93s||\n", "   end. Be careful for it!");
				printf("||%-93s||\n", "6. Why it don't worked: \"1+-2=\"? - Be correct 1+(-2)=. Like to math rules operators hafta");
				printf("||%-93s||\n", "   be separated each from other by brakets");
				printf("||%-93s||\n", "7. What's mean significant digits? - It's mean limit on num precision. 14 digits for example:");
				printf("||%-93s||\n", "   0.99999999999999 or 0.0099999999999999 or 9999999.9999999 or 99999999999999 or");
				printf("||%-93s||\n", "   overfloved num will be imaged as exponential notation or with rounding.");
				continue;
			case 5:		//displaying a message about turning on the display mode of the steps of executing a mathematical expression
				q = 0;
				printf("||%-93s||\n", "result steps turned off");
				continue;
			case 6:		//displaying a message about turning off the display mode of the steps of executing a mathematical expression
				q = 1;
				printf("||%-93s||\n", "result steps turned on");
				continue;
			default: exit(0111); 
			}
		}
		
		if (areTreatedUnccorect(input_D, stack_bkt, stack_bkt2, error))	
			continue;	//if a mathematical expression has syntax errors, 
					//then a message about an input error is displayed 
					//and a try to enter the math ex. again is given
		
		for (unsigned int i = 0; i < input_D.length(); i++) //if there are no input errors, character-by-character parsing of the mathematical expression is performed
		{
			long double a = 0;
			long double b = 0;
			switch (input_D[i])
			{
			case '.':
				if (j > 0)	//if there are a digits before decimal dot
					getRange(&stack_N, &range, j, k, m);
				j = 0; k = 1;
				break;
			case '0': stack_N.push_back(0); j++; break;
			case '1': stack_N.push_back(1); j++; break;
			case '2': stack_N.push_back(2); j++; break;
			case '3': stack_N.push_back(3); j++; break;
			case '4': stack_N.push_back(4); j++; break;
			case '5': stack_N.push_back(5); j++; break;
			case '6': stack_N.push_back(6); j++; break;
			case '7': stack_N.push_back(7); j++; break;
			case '8': stack_N.push_back(8); j++; break;
			case '9': stack_N.push_back(9); j++; break;
			case '+': stepByResult(&range, &j, &k, &m, &stack_N, &stack_A, input_D, i, weigth, a, b, q); break;
			case '-':
				if (i != 0)	//not the first character is parsed
				{
					if
						(
							input_D[i - 1] == '0' ||
							input_D[i - 1] == '1' ||
							input_D[i - 1] == '2' ||
							input_D[i - 1] == '3' ||
							input_D[i - 1] == '4' ||
							input_D[i - 1] == '5' ||
							input_D[i - 1] == '6' ||
							input_D[i - 1] == '7' ||
							input_D[i - 1] == '8' ||
							input_D[i - 1] == '9' ||
							input_D[i - 1] == ')'
							)
					{
						input_D[i] = '+';	//the subtraction operation is replaced by the addition operation of a negative number
						stepByResult(&range, &j, &k, &m, &stack_N, &stack_A, input_D, i, weigth, a, b, q);
					}
				}
				m++; break;
			case '*': stepByResult(&range, &j, &k, &m, &stack_N, &stack_A, input_D, i, weigth, a, b, q); break;
			case '/': stepByResult(&range, &j, &k, &m, &stack_N, &stack_A, input_D, i, weigth, a, b, q); break;
			case '^': stepByResult(&range, &j, &k, &m, &stack_N, &stack_A, input_D, i, weigth, a, b, q); break;
			case ')': stepByResult(&range, &j, &k, &m, &stack_N, &stack_A, input_D, i, weigth, a, b, q);
				j++;
				stack_A.pop_back();
				stack_A.pop_back();
				if (n > 0)
				{
					m = 1; n--;
				}
				break;
			case '(':
				if (m > 0)
				{
					m = 0; n++;
				}
				stack_A.push_back('(');
				break;
			case '=': stepByResult(&range, &j, &k, &m, &stack_N, &stack_A, input_D, i, weigth, a, b, q); break;
			default: exit(0557); 
			}
		}
		if (stack_A.back() == '=')
		{
			ostringstream length;
			length.precision(14);
			length << stack_N.back();
			cout << "||Result=" << stack_N.back() << right << setw(88 - length.str().size()) << "||" << setw(0) << left << '\n';
			length.str("");
		}
		else
			exit(0565);
	}
	return 0;
}
