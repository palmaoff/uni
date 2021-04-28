#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Node
{
	Node* ptrs[26];
	bool eow;
};

bool is_consonant(char c)
{
	string consonants = "bcdfghjklmnpqrstvwxz";

	for (size_t i = 0; i < consonants.length(); i++)
		if (c == consonants[i])
			return 1;

	return 0;
}

void init(Node* &t)
{
	t = NULL;
}

void print(Node* t, string word)
{
	if (t->eow)
		cout << word << endl;
	for (int i = 0; i < 26; i++)
		if (t->ptrs[i])
			print(t->ptrs[i], word + char(i + 'a'));
}

// void print_new(Node* t, int tab)
// {
// 	if (t != NULL)
// 	{
// 		for (int i = 0; i < 26; i++)
// 			if (t->ptrs[i])
// 				print_new(t->ptrs[i], tab + 1);
// 	}
// }

void clear(Node* &t)
{
	for (int i = 0; i < 26; i++)
		if (t->ptrs[i])
			clear(t->ptrs[i]);
	t = NULL;
	delete t;
}

void add(Node* &t, const string &word, size_t i)
{
	if (t == NULL && word.length())
	{
		t = new Node;
		t->eow = false;
		for (size_t j = 0; j < 26; j++)
			t->ptrs[j] = NULL;
	}
	if (word.length() - 1 < i)
		t->eow = true;
	else
		add(t->ptrs[word[i] - 'a'], word, i + 1);
}

int consonant_letter(Node* t, int N, int count)
{
	int result = 0;

	if (count <= N)
	{
		if (count == N && t->eow)
			result += 1;
		for (int i = 0; i < 26; i++)
			if (t->ptrs[i])
				result += consonant_letter(t->ptrs[i], N,
					count + is_consonant('a' + i));
	}

	return result;
}

int main()
{
	Node* t;
	ifstream file("words.txt");
	string word;
	size_t N;

	if (!file)
	{
		cout << "no such file\n";
		return 0;
	}

	init(t);

	file >> N;

	while (!file.eof())
	{
		getline(file, word);
		if (word.length())
			add(t, word, 0);
	}

	print(t, "");

	cout << consonant_letter(t, N, 0);

	clear(t);
	file.close();

	return 0;
}
