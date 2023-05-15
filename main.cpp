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
    void size_of();
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
    this->capacity = 0;
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
    delete[] this->list;
}

int SequentialList::push_front(int value)
{
    return 1;
}
int SequentialList::push_back(int value)
{
    return 1;

}
int SequentialList::insert(int index, int value)
{
    return 1;
    
}
int SequentialList::pop_front()
{
    return 1;
    
}
int SequentialList::pop_back()
{
    return 1;
    
}
int SequentialList::remove_at(int index)
{
    return 1;
    
}
void SequentialList::size_of()
{
    
}
int SequentialList::find(int value)
{
    return 1;
    
}
int SequentialList::remove_all()
{
    return 1;
    
}
void SequentialList::sort()
{
    
}
void SequentialList::reverse()
{
    
}