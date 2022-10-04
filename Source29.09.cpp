#include <iostream>
using namespace std;

template<class T>
struct Elem
{
    T data;
    Elem<T>* next;
    Elem<T>* prev;
};
template<class T>
class QueueList
{

    Elem<T>* Head;
    Elem<T>* Tail;

    int Count;
public:
    QueueList();
    void AddTail(T a); // 1 2 3 4 5
    Elem<T> Extract();
    bool IsEmpty();
    void Print();
    int GetCount();
    T GetFirst();// 1
    ~QueueList();
};

template<class T>
QueueList<T>::QueueList()
{
    Head = Tail = nullptr;
    Count = 0;
}

template<class T>
void QueueList<T>::AddTail(T a)
{
    Elem<T>* temp = new Elem<T>;
    temp->next = 0;
    temp->data = a;
    temp->prev = Tail;
    if (Tail != 0)
    {
        Tail->next = temp;
    }
    if (Count == 0)
    {
        Head = Tail = temp;
    }
    else
    {
        Tail = temp;
    }
    Count++;
}

template<class T>
Elem<T> QueueList<T>::Extract()
{
    Elem<T>* temp = Head;
    Head->prev = nullptr;
    Head = Head->next;
    Elem<T> buf;
    buf.data = temp->data;
    delete[]temp;

    Count--;
    return buf;
}

template<class T>
bool QueueList<T>::IsEmpty()
{
    if (Count != 0)
    {
        return false;
    }

    else
    {
        return false;
    }
}

template<class T>
void QueueList<T>::Print()
{
    if (Count != 0)
    {
        Elem<T>* temp = Head;
        while (temp->next != 0)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << " ";
        cout << "\n";
    }
}

template<class T>
int QueueList<T>::GetCount()
{
    return Count;
}

template<class T>
T QueueList<T>::GetFirst()
{
    return Head->data;
}

template<class T>
QueueList<T>::~QueueList()
{
    while (Count != 0)
    {
        Elem<T>* del = Head;
        Head = Head->next;
        delete[]del;
        Count--;
    }
}

int main()
{
    QueueList<int> Ls;
    const int size = 5;
    int arr[size] = { 10,20,30,40,50 };
    for (int i = 0; i < size; i++)
    {
        Ls.AddTail(arr[i]);
    }
    cout << "array:\n";
    Ls.Print();
    cout << endl << Ls.GetFirst();
    cout << endl << Ls.GetCount();
    cout << endl << Ls.IsEmpty();
    cout << endl;

    cout << endl << Ls.Extract().data;
    cout << endl;
    Ls.Print();
    cout << endl << Ls.GetCount();
}