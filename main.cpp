#include <iostream>

using namespace std;

// A class that simulates a sequencial list with some methods.
class SequentialList
{
private:
    // Data members.

    int *list;
    int size;
    int capacity;

public:
    // Constructors and destructor.

    SequentialList();
    SequentialList(int capacity);
    ~SequentialList();

    // Methods.

    int push_front(int value);
    int push_back(int value);
    int insert(int index, int value);
    int pop_front();
    int pop_back();
    int remove_at(int index);
    int size_of();
    int find(int value);
    int remove_all();
    void sort();
    void reverse();
};

int main()
{
    SequentialList list;
    return 0;
}

// Default constructor that initializes variables with NULL and 0.
SequentialList::SequentialList()
{
    list = NULL;
    size = 0;
    capacity = 10;
}
// Parametrized constructor that allocates an array of int with the given capacity.
SequentialList::SequentialList(int capacity)
{
    list = new int[capacity];
    size = 0;
    capacity = capacity;
}
// Destructor that destroys the array of int that the member list uses.
SequentialList::~SequentialList()
{
    if(list != NULL) delete[] list;
}

int SequentialList::push_front(int value)
{
    if(size < 0) return -1;
    if(size+1 > capacity) return -1;
    if(size == 0)
    {
        size++;
        list[0] = value;
        return 1;
    }
    size++;
    for(int i=size-1; i>0; i--)
    {
        list[i] = list[i-1];
    }
    list[0] = value;
    return 1;
}
int SequentialList::push_back(int value)
{
    if(size < 0) return -1;
    if(size+1 > capacity) return -1;
    size++;
    list[size-1] = value;
    return 1;
}
int SequentialList::insert(int index, int value)
{
    if(size < 0) return -1;
    if(index > size) return -1;
    if(index < 0) return -1;

    if(index == 0)
    {
        push_front(value);
        return 1;
    }
    if(index == size)
    {
        push_back(value);
        return 1;
    }    
    
    size++;
    for(int i=size-1; i>index; i--)
    {
        list[i] = list[i-1];
    }
    list[index] = value;
    return 1;
}
int SequentialList::pop_front()
{
    if(size <= 0) return -1;

    for(int i=0; i<size-1; i++)
    {
        list[i] = list[i+1];
    }
    size--;
    return 1;
    
}
int SequentialList::pop_back()
{
    if(size <= 0) return -1;
    size--;
    return 1;
    
}
int SequentialList::remove_at(int index)
{
    if(size <= 0) return -1;
    if(index < 0) return -1;
    if(index >= size) return -1;

    if(index == size-1)
    {
        pop_back();
        return 1;
    }
    if(index == 0)
    {
        pop_front();
        return 1;
    }

    for(int i=index; i < size-1; i++)
    {
        list[i] = list[i+1];
    }
    size--;
    return 1;
}
int SequentialList::size_of()
{
    return size;
}
int SequentialList::find(int value)
{
    if(this->size <= 0) return -1;

    // binary search
    int left = 0;
    int right = size-1;
    while(left <= right)
    {
        int mid = left + (right-left)/2;

        if(list[mid] == value) return 1;
        
        if(list[mid] < value) left = mid + 1;
        else right = mid - 1;
    }

    return -1; 
}
int SequentialList::remove_all()
{
    if(size <= 0) return -1;
    size = 0;
    return 1;
}
void SequentialList::sort()
{
    
}
void SequentialList::reverse()
{
	int temp;
    for(int i=0; i < size/2; i++)
	{
		temp = list[i];
		list[i] = list[size-1-i];
		list[size-1-i] = temp;
	}
}