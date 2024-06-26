///////////////////////////////////////////////////////////
//
// Description   :  STACK USING LINKEDLIST IN C++ WITH Constructor And Distructor
// Input         :  Int
// Output        :  Int
// Author        :  Vaibhav Khulkhule
// Date          :  18 May 2021
//
///////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node * next;
} NODE, *PNODE;

//////////////////////////////////////////////////
//
// Class Name  : Stack
// Description : This Class represents User Defined Stack Creation Using Linkedlist
//
//////////////////////////////////////////////////


class Stack
{
    private:
        PNODE Head;
        int iSize;

    public:
        Stack(); // constructor
        ~Stack(); // distructor
        void Push(int); // void InsertFirst(int)
        int Pop(); // void DeleteFirst();
        int Peek(); // just return the value 
        void Display(); 
        int Count();
};

    ////////////////////////////////////////////////////////////
    //
    //
    // Class Name       :   Stack
    // Function Date    :   18 May 2021
    // Function Author  :   Vaibhav Khulkhule
    // Parameters       :   NONE
    // Description      :   This Is Constructor Of Class Stack
    //
    // Returns          :   NONE
    //
    //
    ////////////////////////////////////////////////////////////

Stack :: Stack() // constructor
{
    cout << "Inside Constructor \n";
    this -> Head = NULL; // Head = NULL;
    this -> iSize = 0;
}

////////////////////////////////////////////////////////////
    //
    //
    // Class Name       :   ~Stack
    // Function Date    :   18 May 2021
    // Function Author  :   Vaibhav Khulkhule
    // Parameters       :   NONE
    // Description      :   This Is Distructor Of Class Stack
    //
    // Returns          :   NONE
    //
    //
    ////////////////////////////////////////////////////////////

Stack :: ~Stack() 
{
    cout << "Inside Destructor \n";
    PNODE temp = NULL;

    while(Head != NULL)
    {
        temp = Head;
        Head = Head -> next;
        delete temp;
    }
}

  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   Push()
  // Function Date    :   18 May 2021
  // Function Author  :   Vaibhav Khulkhule
  // Parameters       :   int 
  // Description      :   Push Function Add New Node / Element At Top Of A Stack 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////

void Stack :: Push(int iNo) // insertfirst()
{
    PNODE newn = new NODE;
    newn -> data = iNo;
    newn -> next = NULL;

    newn -> next = Head;
    Head = newn;
    iSize++;
}

  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   Pop()
  // Function Date    :   18 May 2021
  // Function Author  :   Vaibhav Khulkhule
  // Parameters       :   -- 
  // Description      :   Pop Function Remove Node / Element From Top Of A Stack 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////

int Stack :: Pop() // delete first
{
    int iRet = -1;

    if(iSize == 0)
    {
        cout << "Stack Is Empty \n";
        //return iRet; stack is empty
    }
    else
    {
        PNODE temp = Head;
        Head = Head -> next;
        iRet = temp -> data; // iret madhe data kadun gatla
        delete temp;
        iSize--;
        //return iRet;
    }
    return iRet; // ani heta display kala popped element 
}

  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   Peek()
  // Function Date    :   18 May 2021
  // Function Author  :   Vaibhav Khulkhule
  // Parameters       :   -- 
  // Description      :   Peek Function Returns Top Most Node / Element Of A Stack 
  //
  // Returns          :   Int
  //                  :   Return Top Most Element Of The Stack
  //
  //
  ////////////////////////////////////////////////////////////

int Stack :: Peek()
{
    if(iSize == 0)
    {
        cout << "Stack Is Empty \n";
        return -1;
    }
    else
    {
        return Head -> data;
    }
}

    ////////////////////////////////////////////////////////////
    //
    //
    // Function Name    :   Display()
    // Function Date    :   18 May 2021
    // Function Author  :   Vaibhav Khulkhule
    // Parameters       :   ----
    // Description      :   Display Function Display The Nodes / Elements In Stack 
    //
    // Returns          :   NONE
    //
    //
    ////////////////////////////////////////////////////////////

void Stack :: Display()
{
    PNODE temp = Head;

    while(temp != NULL)
    {
        cout << temp -> data << "\t";
        temp = temp -> next;
    }
    cout << "\n";
}

    ////////////////////////////////////////////////////////////
    //
    //
    // Function Name    :   Count()
    // Function Date    :   18 May 2021
    // Function Author  :   Vaibhav Khulkhule
    // Parameters       :   ----
    // Description      :   Count Function Count Number Of Nodes / Elements In The Stack 
    //
    // Returns          :   int
    //                  :   Return Number Of Nodes / Elements In The Stack
    //
    //
    ////////////////////////////////////////////////////////////

int Stack :: Count()
{
    return this -> iSize;
}

//////////////////////////////////////////////////////////////
//
//
// Function Name   :   Entry Point Function
// Function Date   :   18 May 2021
// Function Author :   Vaibhav Khulkhule
// Brif Description :  Function Calls For Above Created Functions With Dynamic Input
//
//
//////////////////////////////////////////////////////////////

int main()
{
    Stack *sobj = new Stack; // it implicitelly calls constructor, due to this object is created inside stack // Stack sobj; static object creation
    int iOption = 1, iRet = 0, iNo = 0;

    while(iOption != 0)
    {
        cout << "Please Select The Option \n";
        cout << "1 : Push The Element \n";
        cout << "2 : Pop The Element \n";
        cout << "3 : Display The Elements \n";
        cout << "4 : Cout Number Of Elements \n";
        cout << "5 : Peek The Element \n";
        cout << "0 : Exit the Application \n";
        cin >> iOption;

        switch(iOption)
        {
            case 1 :
                cout << "Enter The Elements To Push : \n";
                cin >> iNo;
                sobj -> Push(iNo);
                break;
            
            case 2 :
                iRet = sobj -> Pop();
                cout << "Poped Elements is : " << iRet << "\n";
                break;

            case 3 :
                cout << "Elements Of Stack Are : \n";
                sobj -> Display();
                break;

            case 4 :
                iRet = sobj -> Count();
                cout << "Number Of Elements In Stack Are : " << iRet << "\n";
                break;

            case 5 :
                iRet = sobj -> Peek();
                cout << "Value Of Top Elements Is : " << iRet << "\n";
                break;

            case 0 :
                cout << "Thankyou For Using This Application \n";
                delete sobj; // it implicitely call the distructor, object memory is deallocated
                break;

            default :
                cout << "Please Enter The Proper Options \n";
                break;
        } // end of switch
    } // end of while
    return 0;
} // end of main
