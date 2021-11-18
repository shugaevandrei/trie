#include <iostream>
#include <string>
using namespace std;
struct Node
{
	int path = 0;
	int end = 0;
	int count = 0;
	Node* nexts[26]{0};
};
class Trie
{
private:
	Node* root;
public:
	Trie() {
		root = new Node; 
	}
	void insert(string word)
	{
		if (word.empty())
			return;
		Node* ptr = root;
		int index = 0;
		for (int i = 0; i < word.size(); i++)
		{
			index = word[i] - 'a';
			if (ptr->nexts[index] == nullptr)
				ptr->nexts[index] = new Node();
			ptr = ptr->nexts[index];
			ptr->path++;
		}
		ptr->end++;
	}
	int search(string word)
	{
		if (word.empty())
			return 0;
		Node* ptr = root;
		int index = 0;
		for (int i = 0; i < word.size(); i++)
		{
			index = word[i] - 'a';
			ptr = ptr->nexts[index];
		}
		return (*ptr).end;
	}
	void delete_(string word)
	{
		if (search(word) != 0)
		{
			Node* ptr = root; 
			int index = 0;
			for (int i = 0; i < word.size(); i++)
			{
				index = word[i] - 'a';
				if ((ptr->nexts[index])->path == 0) {
					ptr->nexts[index] = nullptr; 
					return;
				}
				ptr = ptr->nexts[index];
			}
			ptr->end--;
		}
	}
	int prefixNumber(string pre)
	{
		if (pre.empty())
			return 0;
		Node* ptr = root; 
		int index = 0;
		for (int i = 0; i < pre.size(); i++)
		{
			index = pre[i] - 'a';
			if (ptr->nexts[index] == nullptr) {
				return 0;
			}
			ptr = ptr->nexts[index];
		}
		return ptr->path;
	}
};
int main()
{
	Trie sol;
	sol.insert("hello");
	sol.insert("how are you");
	sol.insert("hi");
	sol.insert("bye");
	sol.insert("b");
	sol.insert("bye bye");
	sol.insert("sup");
	cout << "number of substitutions:" << sol.prefixNumber("b") << endl;
	cout << "number of substitutions:" << sol.prefixNumber("h") << endl;
	cout << "number of substitutions:" << sol.prefixNumber("s") << endl;
	return 0;
}