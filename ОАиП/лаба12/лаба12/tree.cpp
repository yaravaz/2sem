#include "tree.h"
int sum = 0;

void Tree::AddNode(int k)
{


	if (this->node == NULL)
	{
		this->node = new Node;
		this->node->count = 1;
		this->node->key = k;
		this->node->left = this->node->right = NULL;
		return;
	}

	Node* temp = this->node;

	while (true)
	{

		if (k == temp->key)
		{
			temp->count++;
			return;
		}

		if (k < temp->key)
		{
			if (temp->left == NULL)
			{
				temp->left = new Node;
				temp->left->count = 1;
				temp->left->key = k;
				temp->left->left = temp->left->right = NULL;
				return;
			}
			else
			{
				temp = temp->left;
				continue;
			}

		}

		if (k > temp->key)
		{
			if (temp->right == NULL)
			{
				temp->right = new Node;
				temp->right->count = 1;
				temp->right->key = k;
				temp->right->left = temp->right->right = NULL;
				return;
			}
			else
			{
				temp = temp->right;
				continue;
			}

		}
	}
}

void Tree::PrintTree(Node* temp, int tab)
{
	int i;
	if (temp != NULL)
	{
		PrintTree(temp->right, tab + 1);
		for (i = 1; i <= tab; i++)
			cout << "  ";
		cout << temp->key << endl;
		PrintTree(temp->left, tab + 1);
	}
}
void Tree::Delete(int key)
{
	Node* Del, * Prev_Del, * R, * Prev_R;
	Del = this->node;
	Prev_Del = NULL;
	while (Del != NULL && Del->key != key)
	{
		Prev_Del = Del;
		if (Del->key > key)
			Del = Del->left;
		else
			Del = Del->right;
	}
	if (Del == NULL)
	{
		puts("\nДерево пустое");
	}
	if (Del->right == NULL)
		R = Del->left;
	else
		if (Del->left == NULL)
			R = Del->right;
		else
		{
			Prev_R = Del;
			R = Del->left;
			while (R->right != NULL)
			{
				Prev_R = R;
				R = R->right;
			}
			if (Prev_R == Del)
				R->right = Del->right;
			else
			{
				R->right = Del->right;
				Prev_R->right = R->left;
				R->left = Prev_R;
			}
		}
	if (Del == this->node) this->node = R;
	else
		if (Del->key < Prev_Del->key)
			Prev_Del->left = R;
		else
			Prev_Del->right = R;
	int tmp = Del->key;
	cout << "\nНомер удаляемого элемента " << tmp << endl;
	delete Del;
	cout << endl;
}


void Tree::DirectBypass(Node* temp)
{
	if (temp)
	{
		cout << temp->key << "  ";
		if (temp->left)
			DirectBypass(temp->left);
		if (temp->right)
			DirectBypass(temp->right);
	}
}

void Tree::ReverseBypass(Node* temp)
{
	if (temp)
	{
		if (temp->left)
			ReverseBypass(temp->left);
		cout << temp->key << "  ";
		if (temp->right)
			ReverseBypass(temp->right);
	}
}


void Tree::DownScan(Node* temp)
{
	if (temp != NULL)
	{
		DownScan(temp->left);
		DownScan(temp->right);
		cout << temp->key << "  ";
	}

}

int Tree::Height(Node* temp)
{
	if (!temp)
		return 0;

	int leftHeight = Height(temp->left);
	int rightHeight = Height(temp->right);

	return 1 + std::max(leftHeight, rightHeight);
}


bool Tree::IsBalanced(Node* temp)
{
	if (!temp)
		return true;

	int rightHeight = Height(temp->right);
	int leftHeight = Height(temp->left);

	int diff = std::abs(leftHeight - rightHeight);

	if (diff >= 2)
		return false;

	return IsBalanced(temp->left) && IsBalanced(temp->right);
}


int Tree::check_right(Node* temp)
{
	if (temp) {
		if (temp->left)
		{
			check_right(temp->left);
			sum++;
		}
		if (temp->right)
			check_right(temp->right);

		return sum;
	}
}

extern int sum2;
int Tree::sumtask(Node* temp)
{
	if (temp != NULL)
	{
		sumtask(temp->left);
		sumtask(temp->right);
		sum2 += temp->key;
	}
	return sum2;
}
void Tree::countRoot(Node*temp, int key, int count) {

	if (temp != NULL)
	{
		if (key == temp->key)
		{
			cout << "количество ветвей: " << count << endl;
		}
		if (key < temp->key)
			return countRoot(temp->left, key, count + 1);
		else
			return countRoot(temp->right, key, count + 1);
	}
}