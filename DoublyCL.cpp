///////////////////////////////////////////////////////////
//
// Description   :  DOUBLY CIRCULAR LINKEDLIST USING C++ WITH MENU DRIVEN
// Input         :  Int
// Output        :  Int
// Author        :  Vaibhav Khulkhule
// Date          :  14 May 2021
//
///////////////////////////////////////////////////////////

#include <iostream>

using namespace std;

typedef struct node
{
    int data;
    struct node * next;
    struct node * prev;
}NODE, *PNODE;

//////////////////////////////////////////////////
//
// Class Name  :  DoublyCL
// Description : This Class represents Doubly Circular linked list
//
//////////////////////////////////////////////////

class DoublyCL
{
    private : 
        PNODE Head;
        PNODE Tail;
        int iSize;
  
    ////////////////////////////////////////////////////////////
    //
    //
    // Class Name       :   DoublyCL
    // Function Date    :   14 May 2021
    // Function Author  :   Vaibhav Khulkhule
    // Parameters       :   NONE
    // Description      :   This Is Constructor Of Class DoublyCL
    //
    // Returns          :   NONE
    //
    //
    ////////////////////////////////////////////////////////////

    public :
        DoublyCL()
        {
            Head = NULL;
            Tail = NULL;
            iSize = 0;
        }

        void InsertFirst(int);
        void InsertLast(int);
        void InsertAtPos(int, int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
};

  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   InsertFirst()
  // Function Date    :   14 May 2021
  // Function Author  :   Vaibhav Khulkhule
  // Parameters       :   int 
  // Description      :   InsertFirst Function Add New Node At Beginning Of LinkedList 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////

void DoublyCL :: InsertFirst(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((Head == NULL) && (Tail == NULL)) // if(iSize == 0)
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn -> next = Head;
        Head -> prev = newn;
        Head = newn;
    }
    Tail -> next = Head;
    Head -> prev = Tail;
    iSize++;
}

  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   InsertLast()
  // Function Date    :   14 May 2021
  // Function Author  :   Vaibhav Khulkhule
  // Parameters       :   int 
  // Description      :   InsertLast Function Add New Node At End Of LinkedList 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////

void DoublyCL :: InsertLast(int iNo)
{
    PNODE newn = NULL;
    newn = new NODE;
    newn -> data = iNo;
    newn -> next = NULL;
    newn -> prev = NULL;

    if((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
       Tail -> next = newn;
       newn -> prev = Tail;
       Tail = newn;
    }
    Tail -> next = Head;
    Head -> prev = Tail;
    iSize++;
}

  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   InsertAtPos()
  // Function Date    :   14 May 2021
  // Function Author  :   Vaibhav Khulkhule
  // Parameters       :   int, int
  // Description      :   InsertAtPosition Function Add New Node At Given Position In The LinkedList 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////

void DoublyCL :: InsertAtPos(int iNo, int iPos)
{
    if((iPos < 1) || (iPos > iSize + 1))
    {
        return;
    }
    if(iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if(iPos == iSize + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        PNODE newn = new NODE;
        newn -> data = iNo;
        newn -> next = NULL;
        newn -> prev = NULL;

        PNODE temp = Head;
        for(int i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }
        newn -> next = temp -> next;
        temp -> next -> prev = newn;
        temp -> next = newn;
        newn -> prev = temp;
        iSize++;
    }
}

  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   DeleteFirst()
  // Function Date    :   14 May 2021
  // Function Author  :   Vaibhav Khulkhule
  // Parameters       :   ----
  // Description      :   DeleteFirst Function Remove The Node From Beginning Of The LinkedList 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////

void DoublyCL :: DeleteFirst()
{
    if(iSize == 0)
    {
        return;
    }
    else if(iSize == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
        iSize = 0;
    }
    else
    {
        Head = Head -> next;
        delete (Tail -> next); // delete(Head -> prev);
        Tail -> next = Head;
        Head -> prev = Tail;
        iSize--;
    }
}

  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   DeleteLast()
  // Function Date    :   14 May 2021
  // Function Author  :   Vaibhav Khulkhule
  // Parameters       :   ----
  // Description      :   DeleteLast Function Remove The Node At End Of The LinkedList 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////

void DoublyCL :: DeleteLast()
{
    if(iSize == 0)
    {
        return;
    }
    else if(iSize == 1)
    {
        delete Tail;
        Head = NULL;
        Tail = NULL;
        iSize = 0;
    }
    else
    {
        Tail = Tail -> prev;
        delete Tail -> next; // delete(Head -> prev)
        Tail -> next = Head;
        Head -> prev = Tail;
        iSize--;
    }
}

  ////////////////////////////////////////////////////////////
  //
  //
  // Function Name    :   DeleteAtPos()
  // Function Date    :   14 May 2021
  // Function Author  :   Vaibhav Khulkhule
  // Parameters       :   int
  // Description      :   DeleteAtPosition Function Remove Existing Node At Any Position In The LinkedList 
  //
  // Returns          :   NONE
  //
  //
  ////////////////////////////////////////////////////////////

void DoublyCL :: DeleteAtPos(int iPos)
{
    if((iPos < 1) || (iPos > iSize))
    {
        return;
    }
    if(iPos == 1)
    {
        DeleteFirst();
    }
    else if(iPos == iSize)
    {
        DeleteLast();
    }
    else
    {
        PNODE temp = Head;
        for(int i = 1; i < iPos - 1; i++)
        {
            temp = temp -> next;
        }
        temp -> next = temp -> next -> next;
        delete(temp->next->prev);
        temp -> next -> prev = temp;
        iSize--;
    }
}

    ////////////////////////////////////////////////////////////
    //
    //
    // Function Name    :   Display()
    // Function Date    :   14 May 2021
    // Function Author  :   Vaibhav Khulkhule
    // Parameters       :   ----
    // Description      :   Display Function Display The Nodes In LinkedList 
    //
    // Returns          :   NONE
    //
    //
    ////////////////////////////////////////////////////////////

void DoublyCL :: Display()
{
    PNODE temp = Head;
    for (int i = 1; i <= iSize; i++)
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
    // Function Date    :   14 May 2021
    // Function Author  :   Vaibhav Khulkhule
    // Parameters       :   ----
    // Description      :   Count Function Count Number Of Nodes In LinkedList 
    //
    // Returns          :   int
    //                  :   Return Number Of Nodes In LinkedList
    //
    //
    ////////////////////////////////////////////////////////////

int DoublyCL :: Count()
{
    return iSize;
}

//////////////////////////////////////////////////////////////
//
//
// Function Name   :   Entry Point Function
// Function Date   :   14 May 2021
// Function Author :   Vaibhav Khulkhule
// Brif Description :  Function Calls For Above Created Functions With Dynamic Input
//
//
//////////////////////////////////////////////////////////////

int main()
{
    int iChoice = 1, iNo = 0, iRet = 0, iPos = 0;
    DoublyCL obj;

    while(iChoice != 0)
    {
        cout << "Enter Your Choice : \n";
        cout << "1 : Insert First \n";
        cout << "2 : Insert Last \n";
        cout << "3 : Insert At Position \n";
        cout << "4 : Delete First \n";
        cout << "5 : Delete Last \n";
        cout << "6 : Delete At Position \n";
        cout << "7 : Display The Linkedlist \n";
        cout << "8 : Count The Linkedlist Nodes \n";
        cout << "0 : Exit the Application \n";
        cin >> iChoice;

        switch(iChoice)
        {
            case 1 :
                cout << "Enter Number : \n";
                cin >> iNo;
                obj.InsertFirst(iNo);
                break;

            case 2 :
                cout << "Enter Number : \n";
                cin >> iNo;
                obj.InsertLast(iNo);
                break;

            case 3 :
                cout << "Enter Number : \n";
                cin >> iNo;
                cout << "Enter Position : \n";
                cin >> iPos;
                obj.InsertAtPos(iNo, iPos);
                break;

            case 4 :
                obj.DeleteFirst();
                break;

            case 5 : 
                obj.DeleteLast();
                break;

            case 6 :
                cout << "Enter Position : \n";
                cin >> iPos;
                obj.DeleteAtPos(iPos);
                break;

            case 7 : 
                cout << "Elements Of Nodes Are : \n";
                obj.Display();
                break;

            case 8 :
                iRet = obj.Count();
                cout << "Number Of Nodes Are : " << iRet << "\n";
                break;

            case 0 :
                cout << "Thankyou For using the application \n";
                break;

            default : 
                cout << "Please Give Valid Input \n";
                break;
        } // end of switch
    } // end of while
    return 0;
} // end of main
