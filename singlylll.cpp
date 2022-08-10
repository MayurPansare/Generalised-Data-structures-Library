#include<iostream>
using namespace std;

template<class T>
struct node
{
    T data;
    struct node *next;
};

template<class T>
class singlyll
{
    public:
       struct node<T> *Head;
       int Count;

    singlyll();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T , int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos();
    void Display();
    int CountNode();
};

template<class T>
singlyll<T>::singlyll()
{
    Head = NULL;
    Count = 0;
}

template<class T>
void singlyll<T>::InsertFirst(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Count++;
}

template<class T>
void singlyll<T>::InsertLast(T no)
{
    struct node<T> *newn = NULL;
    newn = new node<T>;
    newn->data = no;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        struct node<T> *temp = Head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    Count++;
}

template<class T>
void singlyll<T>::InsertAtPos(T no , int pos)
{
    int size;
    size = Count(*Head);
    if((Head == NULL) || (pos > (size +1)) || (pos <= 0))
    {
        return;
    }
    if( pos == 1 )
    {
        InsertFirst(no);
    }
    else if(pos == (size + 1))
    {
        InsertLast(no);
    }
    else
    {
        struct node<T> *newn = NULL;
        struct node<T> *temp = Head;

        newn = new node<T>;
        if (newn == NULL)
        {
            return;
        }

        newn -> next = NULL;
        newn -> data = no;

        for(int i = 1; i <= (pos-2); i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next = newn;
    }
    Count++;
}

template<class T>
void singlyll<T>::DeleteFirst()
{
    if (Head == NULL)
    {
        return;
    }
    else
    {
        struct node<T> *temp = Head;
        Head = temp->next;
        free(temp);
    }
    Count--;
}

template<class T>
void singlyll<T>::DeleteLast()
{
    if (Head == NULL)
    {
        return;
    }
    else if (Head->next!=NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        struct node<T> *temp1 = Head , *temp2 = NULL;
        while (temp1->next->next!=NULL)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = NULL;
        delete temp2;
    }
    Count--;
}

template<class T>
void singlyll<T>::DeleteAtPos()
{

}

template<class T>
void singlyll<T>::Display()
{
    cout<<"Elements from linked list are :"<<endl;
    struct node<T> *temp = Head;
    while (temp != NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

template<class T>
int singlyll<T>::CountNode()
{
    return Count;
}

int main()
{
    singlyll<int> obj1;


    obj1.InsertFirst(31);
    obj1.InsertFirst(21);
    obj1.InsertFirst(11);

    obj1.InsertLast(51);
    obj1.InsertLast(101);
    obj1.InsertLast(111);

    obj1.InsertAtPos(34 , 3);

    obj1.Display();
    cout<<"Number of nodes from linked list are :"<<obj1.CountNode()<<endl;

    obj1.DeleteFirst();
    obj1.Display();
    cout<<"Number of nodes from linked list are :"<<obj1.CountNode()<<endl;

    obj1.DeleteLast();
    obj1.Display();
    cout<<"Number of nodes from linked list are :"<<obj1.CountNode()<<endl;


    return 0;
}