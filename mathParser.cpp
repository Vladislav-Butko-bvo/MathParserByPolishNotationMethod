//--------------------------------------------------
//Идея: https://www.youtube.com/watch?v=Vk-tGND2bfc%D1%84 
//Примечание: за основу взял пример из этого видео; но реализация полностью моя;
//Также, из функционала, добавил унарный минус и плавающую точку.
//--------------------------------------------------
//Цель пользователя: испытать алгоритм на ошибки компилятора, вылеты или неправильные ответы
//--------------------------------------------------
//Примечание к исходному коду:
//В местах где используються условные операторы предусмотрен экстренный выход exit();
//для if это else exit(). для switch это default: exit().
//--------------------------------------------------
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <stdio.h>
#include <sstream>
using namespace std;

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
int command(string input_D)
{
	if (
		input_D.length() < 5 &&
		input_D[1] == 'e' &&
		input_D[2] == 'n' &&
		input_D[3] == 'd'
		)
	{
		return 1;
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
		return 5;
	}
	else if
		(
			input_D.length() < 3 &&
			input_D[1] == '+'
			)
	{
		return 6;
	}
	else
		return 0;
}
bool fun_ierror(bool error[]) {
	for (int i = 0; i < 13; i++) {
		if (error[i] == 1) {
			return 1;
		}
	}
	return 0;
}
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

long double action(vector<char>* stack_A, long double a, long double b)
{
	switch (stack_A->back())
	{
	case '+': return a + b;
	case '*': return a * b;
	case '/': return a / b;
	case '^': return pow(a, b);
	default: exit(055); // ЭКСТРЕННЫЙ ВЫХОД
	}
}
int getAction2(vector<char>* stack_A, Weigth weigth)
{
	switch (stack_A->back())
	{
	case '+': return weigth.sum;
	case '*': return weigth.mult;
	case '/': return weigth.dev;
	case '^': return weigth.step;
	case '(': return weigth.bktOpen;
	default: exit(070); // ЭКСТРЕННЫЙ ВЫХОД
	}
}
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
	default: exit(0104); // ЭКСТРЕННЫЙ ВЫХОД
	}
}
void count(vector<long double>* stack_N, vector<char>* stack_A, string input_D, unsigned int i, Weigth weigth, long double a, long double b, bool q)
{
	for (bool iter = 1; iter != 0; )
	{
		if (stack_A->size() == 0 || getAction1(stack_A, input_D, i, weigth) > getAction2(stack_A, weigth))
		{
			stack_A->push_back(input_D[i]); iter = 0;
		}
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
			exit(0104); // ЭКСТРЕННЫЙ ВЫХОД
	}
}

long double rangeUP(vector<long double>* range, int j, int k)
{
	long double sum = 0;
	long double mult = 1;
	for (int i = 0; i < j; i++)
	{
		sum += (*range)[i] * mult;
		mult *= 10;
	}
	if (k > 0)
	{
		for (int i = 0; i < j; i++)
			sum /= 10.0;
	}
	return sum;
}

void getRange(vector<long double>* stack_N, vector<long double>* range, int j, int k, int m)
{
	while (range->size() != 0)
	{
		range->pop_back();
	}
	for (int i = 0; i < j; i++)
	{
		range->push_back(NULL);
		range->back() = stack_N->back();
		stack_N->pop_back();
	}
	if (k == 0)
		stack_N->push_back(pow(-1, m) * rangeUP(range, j, k));
	else if (k > 0)
	{
		long double a;
		a = stack_N->back();
		stack_N->pop_back();
		stack_N->push_back(a + (pow(-1, m) * rangeUP(range, j, k)));
	}
	else
		exit(0112); // ЭКСТРЕННЫЙ ВЫХОД
}
void stepByResult(vector<long double>* range, int* j, int* k, int* m, vector<long double>* stack_N, vector<char>* stack_A, string input_D, unsigned int i, Weigth weigth, long double a, long double b, bool q)
{
	if (*j > 0)
		getRange(*&stack_N, range, *j, *k, *m);
	*j = 0; *k = 0; *m = 0;
	count(*&stack_N, *&stack_A, input_D, i, weigth, a, b, q);
}

int main()
{
	Weigth weigth;
	int j;
	int k;
	int m;
	int n;
	bool q = 0;
	bool error[13];
	vector<long double> range;
	vector<long double> stack_N;
	vector<char> stack_A;
	vector<char> stack_bkt;
	vector<int> stack_bkt2;
	string input_D;
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
	for (bool iter = 1; iter != 0; )
	{
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
		if (input_D[0] == '%')
		{
			switch (command(input_D))
			{
			case 0:
				printf("||%-93s||\n", "ERROR_0: command undefined"); continue;
			case 1:
				iter = 0; continue;
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
			case 5:
				q = 0;
				printf("||%-93s||\n", "result steps turned off");
				continue;
			case 6:
				q = 1;
				printf("||%-93s||\n", "result steps turned on");
				continue;
			default: exit(0111); // ЭКСТРЕННЫЙ ВЫХОД
			}
		}
		if (areTreatedUnccorect(input_D, stack_bkt, stack_bkt2, error))
			continue;
		for (unsigned int i = 0; i < input_D.length(); i++)
		{
			long double a = 0;
			long double b = 0;
			switch (input_D[i])
			{
			case '.':
				if (j > 0)
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
				if (i != 0)
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
						input_D[i] = '+';
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
			default: exit(0557); // ЭКСТРЕННЫЙ ВЫХОД
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
			exit(0565); // ЭКСТРЕННЫЙ ВЫХОД
	}
	return 0;
}