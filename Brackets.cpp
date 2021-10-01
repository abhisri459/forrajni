#include<bits/stdc++.h>
using namespace std;

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}
    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }
    char type;
    int position;
};

int main() {
    string text;
    getline(cin, text);
	int error_pos = 0;
    stack <Bracket> opening_brackets_stack;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];

        if (next == '(' || next == '[' || next == '{') {
            Bracket b(next, position+1);
			opening_brackets_stack.push(b);
        }
		
        if (next == ')' || next == ']' || next == '}') {
            if(opening_brackets_stack.empty()) {
				error_pos = position + 1;
				break;
			}
			Bracket top = opening_brackets_stack.top();
			opening_brackets_stack.pop();
			if(!top.Matchc(next)) {
				error_pos = position + 1;
				break;
			}
        }
    }
	if(error_pos==0 && opening_brackets_stack.empty())
		cout << "Success";
	else {
		if(error_pos == 0) {
			while(opening_brackets_stack.size()>1)
				opening_brackets_stack.pop();
			error_pos = opening_brackets_stack.top().position;
		}
		cout << error_pos;
	}
    return 0;
}
