#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include<string>

using namespace std;

template <typename T>
class stack
{
	struct que
	{
		T data;
		que* next;

		que() {}

		que(T data, que* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};

	size_t size = 0;

	que* root = nullptr;

public:

	void push_back(T _data)
	{
		if (root != nullptr)
		{
			root = new que(_data, root);
		}
		else
		{
			root = new que(_data);
		}
		++size;
	}

	T pop_back()
	{
		if (size > 0)
		{
			T res = root->data;
			que* temp = root;
			root = root->next;
			delete temp;
			--size;
			return res;
		}
		throw exception("Stack is empty!");

	}

	void print()
	{
		que* temp = root;
		printf("\n");
		while (temp != nullptr)
		{
			printf("%c ", temp->data);
			temp = temp->next;
		}
		printf("\n");
	}

	bool isEmpty()
	{
		return (size == 0);
	}
};

bool checkbraces(char* _buff)
{
	int i = 0;
	stack<char> c;
	char g = 0;
	while (_buff[i] != '\0')
	{
		if (_buff[i] == '(' || _buff[i] == '[' || _buff[i] == '{')
		{
			c.push_back(_buff[i]);
		}
		else if (_buff[i] == ')' || _buff[i] == '}' || _buff[i] == ']')
		{
			if (c.isEmpty())
			{
				return false;
			}
			g = c.pop_back();
			if (g + 1 != _buff[i] && g + 2 != _buff[i])
			{
				printf("%c - %c\n", g, _buff[i]);
				return false;
			}
		}
		++i;
	}
	return c.isEmpty();
}

int main()
{
	stack<char> a;
	a.push_back('(');
	a.push_back('{');
	a.push_back('[');
	a.push_back('(');



	char buff[] = "([{} ({} [])])";

	printf("true = %d\n", checkbraces(buff));

	//a.print();
	system("pause");
	return 0;
}