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
    void automatically_test();
    void manually_test();
    void check_if_size_is_negative();
};

int main()
{
    int capac;
    cout << "Enter the maximum capacity for the list: ";
    cin >> capac;
    SequentialList list = SequentialList(capac);

    //SequentialList list = SequentialList();
    int option;

    while(true)
    {
        cout << "Choose the option for testing the implemented sequential list:\n";
        cout << "1 - Automatically test;\n";
        cout << "2 - Manually test;\n";
        cout << "3 - Terminate the program.\n";
        cout << "Option: ";
        cin >> option;
        cout << endl;

        switch(option)
        {
            case 1:
                list.automatically_test();
                break;
            case 2:
                list.manually_test();
                break;
            case 3:
                cout << "Terminating the program...\n\n";
                break;
            default:
                cout << "Wrong input, please try 1-3.\n\n";
                break;
        }

        if(option == 3) break;
    }
    
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
    check_if_size_is_negative();
    if(size == capacity)
    {
        cout << "The list is at maximum capacity! Can't push_front anything.\n\n";
        return -1;
    }
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
    check_if_size_is_negative();
    if(size == capacity) 
    {
        cout << "The list is at maximum capacity! Can't push_back anything.\n\n";
        return -1;
    }
    size++;
    list[size-1] = value;
    return 1;
}
int SequentialList::insert(int index, int value)
{
    check_if_size_is_negative();
    if(index < 0) 
    {
        cout << "Negative index! Can't insert anything.\n\n";
        return -1;
    }
    if(index > size) 
    {
        cout << "Index greater than size! Can't insert anything.\n\n";
        return -1;
    }
    
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
    if(size == capacity) 
    {
        cout << "The list is at maximum capacity! Can't insert anything.\n\n";
        return -1;
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
    check_if_size_is_negative();
    if(size == 0)
    {
        cout << "Empty list.\n\n";
        return -1;
    }

    for(int i=0; i<size-1; i++)
    {
        list[i] = list[i+1];
    }
    size--;
    return 1;
    
}
int SequentialList::pop_back()
{
    check_if_size_is_negative();
    if(size == 0)
    {
        cout << "Empty list.\n\n";
        return -1;
    }
    size--;
    return 1;
    
}
int SequentialList::remove_at(int index)
{
    check_if_size_is_negative();
    if(size == 0)
    {
        cout << "Empty list.\n\n";
        return -1;
    }
    if(index < 0) 
    {
        cout << "Negative index! Can't remove anything.\n\n";
        return -1;
    }
    if(index >= size) 
    {
        cout << "Index greater or equal size! Can't remove anything.\n\n";
        return -1;
    }

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
    check_if_size_is_negative();
    return size;
}
int SequentialList::find(int value)
{
    check_if_size_is_negative();
    if(size == 0)
    {
        cout << "Empty list.\n\n";
        return -1;
    }

    // sequential search
    for(int i=0; i<size; i++)
    {
        if(list[i] == value) return 1;
    }

    return -1; 
}
int SequentialList::remove_all()
{
    check_if_size_is_negative();
    if(size == 0)
    {
        cout << "Empty list.\n\n";
        return -1;
    }
    size = 0;
    return 1;
}
void SequentialList::sort() // bubble sort
{
    check_if_size_is_negative();
    if(size == 0)
    {
        cout << "Empty list.\n\n";
    }
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
    check_if_size_is_negative();
    if(size == 0)
    {
        cout << "Empty list.\n\n";
    }
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
    check_if_size_is_negative();
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

void SequentialList::check_if_size_is_negative()
{
    if(size < 0)
    {
        cerr << "FATAL ERROR! Size is negative! Terminating the program...\n";
        exit;
    }
}

void SequentialList::automatically_test()
{
    remove_all();
    push_back(1);
    push_back(2);
    push_back(3);
    push_back(4);
    push_back(5);
    print();
    remove_all();
    print();
    push_front(1);
    push_front(2);
    push_front(3);
    push_front(4);
    push_front(5);
    print();
    pop_back();
    pop_back();
    pop_front();
    pop_front();
    pop_front();
    print();
    insert(0, 1);
    insert(1, 2);
    insert(1, 3);
    insert(1, 4);
    insert(2, 5);
    print();
    remove_at(0);
    print();
    remove_at(2);
    print();
    cout << "Size of the list: " << size_of() << endl;
    sort();
    print();
    reverse();
    print();
    if(find(4) == 1) cout << "Value 4 is in the list.\n";
    if(find(10) == -1) cout << "Value 10 is not in the list.\n";
    cout << endl;
}

void SequentialList::manually_test()
{
    remove_all();

    int temp_option, temp_value, temp_index;
    while(true)
    {
        cout << "Here are the implemented methods:\n";
        cout << "1 - push_front;\n";
        cout << "2 - push_back;\n";
        cout << "3 - insert;\n";
        cout << "4 - pop_front;\n";
        cout << "5 - pop_back;\n";
        cout << "6 - remove_at;\n";
        cout << "7 - size_of;\n";
        cout << "8 - find;\n";
        cout << "9 - remove_all;\n";
        cout << "10 - sort;\n";
        cout << "11 - reverse;\n";
        cout << "12 - print;\n";
        cout << "13 - Terminate the manual test;\n";
        cout << "Option: ";
        cin >> temp_option;
        cout << endl;

        switch(temp_option)
        {
            case 1:
                cout << "Enter the value to push_front: ";
                cin >> temp_value;
                cout << endl;
                cout << push_front(temp_value) << " is the return of push_front()\n\n";
                break;
            case 2:
                cout << "Enter the value to push_back: ";
                cin >> temp_value;
                cout << endl;
                cout << push_back(temp_value) << " is the return of push_back()\n\n";
                break;
            case 3:
                cout << "Enter the index to insert: ";
                cin >> temp_index;
                cout << "Enter the value to insert: ";
                cin >> temp_value;
                cout << endl;
                cout << insert(temp_index, temp_value) << " is the return of insert()\n\n";
                break;
            case 4:
                cout << pop_front() << " is the return of pop_front()\n\n";
                break;
            case 5:
                cout << pop_back() << " is the return of pop_back()\n\n";
                break;
            case 6:
                cout << "Enter the index to remove_at: ";
                cin >> temp_index;
                cout << endl;
                cout << remove_at(temp_index) << " is the return of remove_at()\n\n";
                break;
            case 7:
                cout << size_of() << " is the return of size_of()\n\n";
                break;
            case 8:
                cout << "Enter the value you want to find: ";
                cin >> temp_value;
                cout << endl;
                cout << find(temp_value) << " is the return of find()\n\n";
                break;
            case 9:
                cout << remove_all() << " is the return of find()\n\n";
                break;
            case 10:
                sort();
                break;
            case 11:
                reverse();
                break;
            case 12:
                print();
                cout << endl;
                break;
            case 13:
                cout << "Terminating the manual test...\n\n";
                break;
            default:
                cout << "Wrong input, please try 1-3.\n\n";
                break;
        }

        if(temp_option == 13) break;
    }
}