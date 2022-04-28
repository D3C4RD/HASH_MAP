#include "list.h"





template <typename KEY,typename VALUE,class C=comparator<KEY>>
class hash_map
{
private:
	LIST<KEY, VALUE> *arr;
	int size;
	void resize(int nsize)
	{
		LIST<KEY, VALUE>* temp = new LIST<KEY, VALUE>[nsize];
		int tsize = size;
		size = nsize;
		NODE<KEY, VALUE>* current;
		for (int i = 0; i < tsize; i++)
		{
			current = arr[i].head;
			while (current != NULL)
			{
				temp[hash_f(current->key)].add(current->key, current->value);
				current = current->next;
			}
		}
		arr = temp;
	}
	double C;
public:
	hash_map()
	{
		arr = new LIST<KEY, VALUE>[1];
		size = 1;
		C = 2.0;
	}
	hash_map(const hash_map &a)
	{
		C = a.C;
		size = a.size;
		arr = new LIST<KEY, VALUE>[a.size];
		NODE<KEY, VALUE>* current;
		for (int i = 0; i < a.size; i++)
		{
			current = a.arr[i].head;
			arr[i].delete_all();
			while (current != NULL)
			{
				arr[i].add(current->key, current->value);
				current = current->next;
			}
		}
	}
	void delete_all()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i].delete_all();
		}
	}
	int hash_f(KEY key)
	{
		return key % size;
	}
	void add(KEY key,VALUE value)
	{
		arr[hash_f(key)].add(key, value);
		
		if ((double)get_kol() / (double)size > C)
		{
			resize(2 * size + 1);
		}
	}

	NODE<KEY, VALUE>* operator[](KEY key)
	{
		NODE<KEY, VALUE>* t= arr[hash_f(key)].find(key);
		if (t != NULL)
		{
			return arr[hash_f(key)].find(key);
		}
		else
		{
			cout << "error in []" << endl;
		}
	}

	void remove(KEY key)
	{
		arr[hash_f(key)].remove(key);
	}

	int get_kol()
	{
		int kol = 0;
		LIST<KEY, VALUE> current;
		for (int i = 0; i < size; i++)
		{
			current = arr[i];
			kol += current.kol;
		}
		return kol;
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i].print();
		}
		cout <<  "kol=" << get_kol() << endl << endl;
	}
	
	double get_C()
	{
		return C;
	}

	double set_C(double a)
	{
		C = a;
	}
	double get_A()
	{
		return (double)get_kol / (double)size;
	}

	~hash_map()
	{
		delete_all();
	}
};


