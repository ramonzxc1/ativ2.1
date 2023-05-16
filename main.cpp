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
    this->list = NULL;
    this->size = 0;
    this->capacity = 10;
}
// Parametrized constructor that allocates an array of int with the given capacity.
SequentialList::SequentialList(int capacity)
{
    this->list = new int[capacity];
    this->size = 0;
    this->capacity = capacity;
}
// Destructor that destroys the array of int that the member list uses.
SequentialList::~SequentialList()
{
    if(this->list != NULL) delete[] this->list;
}

int SequentialList::push_front(int value)
{
    if(this->size+1 > this->capacity) return -1;
    if(this->size == 0)
    {
        this->size++;
        this->list[0] = value;
        return 1;
    }
    this->size++;
    for(int i=this->size-1; i>0; i--)
    {
        this->list[i] = this->list[i-1];
    }
    this->list[0] = value;
    return 1;
}
int SequentialList::push_back(int value)
{
    if(this->size+1 > this->capacity) return -1;
    this->size++;
    this->list[this->size-1] = value;
    return 1;
}
int SequentialList::insert(int index, int value)
{
    if(index < 0) return -1;
    if(index == 0)
    {
        this->push_front(value);
        return 1;
    }
    if(index == this->size)
    {
        this->push_back(value);
        return 1;
    }
    if(this->size == 0) return -1;
    if(index > this->size) return -1;
    
    this->size++;
    for(int i=this->size-1; i>index; i--)
    {
        this->list[i] = this->list[i-1];
    }
    this->list[index] = value;
    return 1;
}
int SequentialList::pop_front()
{
    if(this->size == 0) return -1;

    for(int i=0; i<this->size-1; i++)
    {
        this->list[i] = this->list[i+1];
    }
    this->size--;
    return 1;
    
}
int SequentialList::pop_back()
{
    if(this->size == 0) return -1;
    this->size--;
    return 1;
    
}
int SequentialList::remove_at(int index)
{
    if(this->size == 0) return -1;
    if(index < 0) return -1;
    if(index >= this->size) return -1;
    if(index == this->size-1)
    {
        this->pop_back();
        return 1;
    }
    if(index == 0)
    {
        this->pop_front();
        return 1;
    }

    for(int i=index; i<this->size; i++)
    {
        this->list[i] = this->list[i+1];
    }
    this->size--;
    return 1;
}
int SequentialList::size_of()
{
    return this->size;
}
int SequentialList::find(int value)
{
    if(this->size == 0) return -1;

    // binary search
    int left = 0;
    int right = this->size-1;
    while(left <= right)
    {
        int mid = left + (right-left)/2;

        if(this->list[mid] == value) return 1;
        
        if(this->list[mid] < value) left = mid + 1;
        else right = mid - 1;
    }

    return -1; 
}
int SequentialList::remove_all()
{
    if(this->size == 0) return -1;
    this->size = 0;
    return 1;
}
void SequentialList::sort()
{
    
}
void SequentialList::reverse()
{
    
}