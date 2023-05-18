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
    SequentialList(int input_capacity);
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
    void print();
};

int main()
{
    SequentialList list = SequentialList();

    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    list.print();
    list.remove_all();
    list.print();
    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(5);
    list.print();
    list.pop_back();
    list.pop_back();
    list.pop_front();
    list.pop_front();
    list.pop_front();
    list.print();
    list.insert(0, 1);
    list.insert(1, 2);
    list.insert(1, 3);
    list.insert(1, 4);
    list.insert(2, 5);
    list.print();
    list.remove_at(0);
    list.print();
    list.remove_at(2);
    list.print();
    cout << "Size of the list: " << list.size_of() << endl;
    list.sort();
    list.print();
    list.reverse();
    list.print();
    if(list.find(4) == 1) cout << "Value 4 is in the list.\n";
    if(list.find(10) == -1) cout << "Value 10 is not in the list.\n";


    return 0;
}

// Default constructor that initializes variables with NULL and 0.
SequentialList::SequentialList()
{
    list = new int[10];
    size = 0;
    capacity = 10;
}
// Parametrized constructor that allocates an array of int with the given capacity.
SequentialList::SequentialList(int input_capacity)
{
    list = new int[input_capacity];
    size = 0;
    capacity = input_capacity;
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
void SequentialList::sort() // bubble sort
{
    int n = size_of();
    bool swapped;
    int prov;

    for(int i=0; i < n-1; i++)
    {
        swapped = false;

        for(int j=0; j < n-1-i; j++)
        {
            if(list[j] > list[j+1])
            {
                prov = list[j];
                list[j] = list[j+1];
                list[j+1] = prov;
                swapped = true;
            }
        }
        if(!swapped) break;
    }
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
void SequentialList::print()
{
    if(size == 0) 
    {
        cout << "Empty list.\n";
        return;
    }

    for(int i=0; i<size_of(); i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;
}