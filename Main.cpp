#include <iostream>
#include "Point.h"
#include <string>
#include "Node.h"
#include "LinkedStack.h"

using namespace std;

int main() {

	LinkedStack<char>stack;

	//string letters = "ABC$CBA";
	string letters;
	cout << "Enter a capitalized string seperated by '$' " << endl;
	cin >> letters;


	int count = 0;
	int num;
	for (int i = 0; i < letters.size(); i++) {

		if (letters[i] >= 'A' && letters[i] <= 'Z') {
			stack.push(letters[i]);
			count++;
		}
		if (letters[i] == '$') {
			num = ((letters.size() - 1) - (count));
			for (int j = count; j > 0; j--) {
				char firstOp = stack.peek();
				i++;

				if (firstOp == letters[i]) {
					stack.pop();
				}
			}
			if (stack.isEmpty() && count == num) {
				cout << "String matches" << endl;
			}
			else
			{
				cout << "String does not match" << endl;
			}
		}
	}



	system("pause");
	return 0;
}