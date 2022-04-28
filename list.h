#include <iostream>
using namespace std;

template<typename KEY, typename VALUE >
struct NODE {
	KEY key;
	VALUE value;
	NODE* next;
	NODE* prev;
};

template<typename KEY>
class comparator { //функтор comparator
public:
	bool operator()(const KEY arg1, const KEY arg2)const {
		if (arg1 == arg2)
			return true;
		else
			return false;
	}
};


template<typename KEY,typename VALUE,class C=comparator<KEY>>
class LIST
{
	using node = NODE<KEY, VALUE>;
	public:
		C compr;
		node* head;
		node* tail;
		int kol = 0;
		LIST()
		{
			head = NULL;
			tail = head;
		}
		
		void add(KEY key, VALUE value)
		{
			node* add = new node;
			add->key = key;
			add->value = value;
			add->next = NULL;
			
			if (head == NULL)
			{
				head = add;
				head->prev = NULL;
			}
			else
			{
				node* current = head;
				while (current->next != NULL)
				{
					if (compr(current->key,key)==true)
					{
						cout << current->key << " " << key << endl;
						cout << "element is already exists" << endl;
						return;
					}
					current = current->next;
					if (compr(current->key, key) == true)
					{
						cout << current->key << " " << key << endl;
						cout << "element is already exists" << endl;
						return;
					}
				}
				current->next = add;
				current->next->prev = current;
				tail = current->next;
			}
			kol++;
		}
		void print()
		{
			node* current = head;
			while (current != NULL)
			{
				cout << current->key << ":" << current->value << " ";
				current = current->next;
			}
			cout << endl;
		}
		node* find(KEY key)
		{
			node* current = head;
			while (current != NULL)
			{
				if (current->key == key)
				{
					return current;
				}
				current=current->next;
			}
			return NULL;
		}
		void remove(KEY key)
		{
			node* suspect = find(key);
			if (suspect != NULL)
			{
				if (suspect == head)
				{
					head = suspect->next;
					suspect->next = NULL;
					suspect = NULL;
					head->prev = NULL;
				}
				else if (suspect == tail)
				{
					tail = suspect->prev;
					tail->next = NULL;
					suspect->prev = NULL;
					suspect = NULL;
				}
				else
				{
					node* back = suspect->prev;
					node* forward = suspect->next;
					back->next = forward;
					forward->prev = back;
					suspect->next = NULL;
					suspect->prev = NULL;
					suspect = NULL;
				}
				kol--;
			}
		}
		void delete_all()
		{
			node* current = tail;
			node* temp = current;
			while (current != NULL)
			{
				temp = current;
				current = current->prev;
				if (temp != tail)
				{
					temp->next = NULL;
				}
				temp->prev = NULL;
				temp = NULL;
			
			}
		}
};