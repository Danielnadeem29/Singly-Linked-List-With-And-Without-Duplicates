// Part (1) Implement the above singly linked list allowing the duplicate element.

#include<iostream>

using namespace std;

class singleList {

private:

    struct Node {

        int data;

        Node* next;

        Node(int x) : data(x), next(nullptr) {} // constructor

    };

    Node* head;





public:



    singleList() :head(nullptr) {}



    void display()

    {

        Node* tmp = head;

        while (tmp)

        {

            cout << "" << tmp->data << endl;

            tmp = tmp->next;

        }

    }



    bool SortedIsEmpty() const

    {

        return head == nullptr ? true : false;



    }



    int sortedGetLength() const

    {

        if (head == nullptr) return 0;

        int count = 0;

        for (Node* tmp = head; tmp->next != nullptr; count++)

        {

            tmp = tmp->next;

        }

        return count;

    }





    bool sortfind(int k, int& x)

    {

        if (k < 0 && k > sortedGetLength())

        {

            return false;

        }

        Node* tmp = head;

        int counter = 1;

        while (tmp)

        {

            if (counter == k)

            {

                x = tmp->data;

                return true;

            }

            counter++;

            tmp = tmp->next;

        }

        return false;

    }





    int SortSearch(int key)

    {

        int element = 0;



        Node* tmp = head;



        while (tmp != nullptr)

        {

            if (tmp->data == key)

            {

                // element = 0 ;

                return element;

            }

            element++;

            tmp = tmp->next;

            // element++;

        }

        cout << "The key not found: ";

        return -1;

    }



    void SortedInsert(int x)

    {

        // insert

        Node* value = new Node(x);

        // value -> data  = x;

         //value -> next = nullptr;



        if (!head || x <= head->data)                       // base case

        {

            value->next = head;

            head = value;

            return;

        }



        Node* tmp = head;

        while (tmp->next)

        {

            if (tmp->next->data >= x)

            {

                value->next = tmp->next;

                tmp->next = value;

                return;

            }

            tmp = tmp->next;

        }

        value->next = tmp->next;

        tmp->next = value;

    }



    void SortedDelete(int k, int& x, bool& success) {

        if (head == nullptr || k < 0)

        {

            success = false;

            return;

        }



        if (k == 0)

        {

            Node* temp = head;

            head = head->next;

            x = temp->data;

            delete temp;

            success = true;

            return;

        }



        Node* current = head;

        for (int i = 0; i < k - 1 && current->next != nullptr; i++)

        {

            current = current->next;

        }



        if (current->next == nullptr)

            success = false;

        else

        {

            Node* temp = current->next;

            current->next = temp->next;

            x = temp->data;

            delete temp;

            success = true;

        }

    }

};



int main()

{



    singleList code;



    code.SortedInsert(5);

    code.SortedInsert(3);

    code.SortedInsert(7);

    code.SortedInsert(9);

    code.SortedInsert(11);

    code.SortedInsert(5);





    cout << "List: " << endl;

    code.display();



    code.SortedInsert(7);



    cout << "List after adding 7:  " << endl;

    code.display();



    // find the element



    int find;

    if (code.sortfind(3, find))

        cout << "The value of element 3 is " << find << endl;

    else

        cout << " NO VALUE " << endl;



    int pos = code.SortSearch(7);

    if (pos != -1)

        cout << "The value was found at Element: " << pos << endl;

    else

        cout << "NO VALUE " << endl;



    // length of the list

    cout << "The length of the list is: " << code.sortedGetLength() << endl;



    // delete

    int deleteNum;

    bool success;

    code.SortedDelete(2, deleteNum, success);

    if (success)

        cout << "Element " << deleteNum << " has been deleted" << endl;

    else

        cout << "There is no value to delete" << endl;



    // after deletion



    cout << "new list: " << endl;

    code.display();



    pos = code.SortSearch(7);

    if (pos != -1)

        cout << "The value was found at Element: " << pos << endl;

    else

        cout << "NO VALUE " << endl;



    return 0;

}
//--------------------------------------------------------------------------------------------

//----------------------------------------------------------------------------------------------
//Part (2) Implement the above singly linked list without allowing the duplicate element.

//#include<iostream>
//
//using namespace std;
//
//class singleList {
//
//private:
//
//    struct Node {
//
//        int data;
//
//        Node* next;
//
//        Node(int x) : data(x), next(nullptr) {} // constructor
//
//    };
//
//    Node* head;
//
//
//
//
//
//public:
//
//
//
//    singleList() :head(nullptr) {}
//
//
//
//    void display()
//
//    {
//
//        Node* tmp = head;
//
//        while (tmp)
//
//        {
//
//            cout << "" << tmp->data << endl;
//
//            tmp = tmp->next;
//
//        }
//
//    }
//
//
//
//    bool SortedIsEmpty() const
//
//    {
//
//        return head == nullptr ? true : false;
//
//
//
//    }
//
//
//
//    int sortedGetLength() const
//
//    {
//
//        if (head == nullptr) return 0;
//
//        int count = 0;
//
//        for (Node* tmp = head; tmp->next != nullptr; count++)
//
//        {
//
//            tmp = tmp->next;
//
//        }
//
//        return count;
//
//    }
//
//
//
//
//
//    bool sortfind(int k, int& x)
//
//    {
//
//        if (k < 0 && k > sortedGetLength())
//
//        {
//
//            return false;
//
//        }
//
//        Node* tmp = head;
//
//        int counter = 1;
//
//        while (tmp)
//
//        {
//
//            if (counter == k)
//
//            {
//
//                x = tmp->data;
//
//                return true;
//
//            }
//
//            counter++;
//
//            tmp = tmp->next;
//
//        }
//
//        return false;
//
//    }
//
//
//
//
//
//    int SortSearch(int key)
//
//    {
//
//        int element = 0;
//
//
//
//        Node* tmp = head;
//
//
//
//        while (tmp != nullptr)
//
//        {
//
//            if (tmp->data == key)
//
//            {
//
//                 element = 0 ;
//
//                return element;
//
//            }
//
//            element++;
//
//            tmp = tmp->next;
//
//             element++;
//
//        }
//
//        cout << "The key not found: ";
//
//        return -1;
//
//    }
//
//
//
//    void SortedInsert(int x)
//
//    {
//
//        Node* curr = head;
//
//        while (curr != nullptr)
//
//        {
//
//            if (curr->data == x)
//
//            {
//
//                return;
//
//            }
//
//            curr = curr->next;
//
//        }
//
//         insert
//
//        Node* value = new Node(x);
//
//
//
//        if (!head || x < head->data)                       // base case
//
//        {
//
//            value->next = head;
//
//            head = value;
//
//            return;
//
//        }
//
//
//
//        curr = head;
//
//        while (curr->next)
//
//        {
//
//            if (curr->next->data >= x)
//
//            {
//
//                value->next = curr->next;
//
//                curr->next = value;
//
//                return;
//
//            }
//
//            curr = curr->next;
//
//        }
//
//        value->next = curr->next;
//
//        curr->next = value;
//
//    }
//
//
//
//    void SortedDelete(int k, int& x, bool& success) {
//
//        if (head == nullptr || k < 0)
//
//        {
//
//            success = false;
//
//            return;
//
//        }
//
//
//
//        if (k == 0)
//
//        {
//
//            Node* temp = head;
//
//            head = head->next;
//
//            x = temp->data;
//
//            delete temp;
//
//            success = true;
//
//            return;
//
//        }
//
//
//
//        Node* current = head;
//
//        for (int i = 0; i < k - 1 && current->next != nullptr; i++)
//
//        {
//
//            current = current->next;
//
//        }
//
//
//
//        if (current->next == nullptr)
//
//            success = false;
//
//        else
//
//        {
//
//            Node* temp = current->next;
//
//            current->next = temp->next;
//
//            x = temp->data;
//
//            delete temp;
//
//            success = true;
//
//        }
//
//    }
//
//};
//
//
//
//int main()
//
//{
//
//
//
//    singleList code;
//
//
//
//    code.SortedInsert(5);
//
//    code.SortedInsert(7);
//
//    code.SortedInsert(9);
//
//    code.SortedInsert(11);
//
//    code.SortedInsert(5);
//
//
//
//    cout << "List: " << endl;
//
//    code.display();
//
//
//
//    code.SortedInsert(7);
//
//
//
//    cout << "List after adding 7:  " << endl;
//
//    code.display();
//
//
//
//     find the element
//
//
//
//    int find;
//
//    if (code.sortfind(3, find))
//
//        cout << "The value of element 3 is " << find << endl;
//
//    else
//
//        cout << " NO VALUE " << endl;
//
//
//
//    int pos = code.SortSearch(7);
//
//    if (pos != -1)
//
//        cout << "The value was found at Element: " << pos << endl;
//
//    else
//
//        cout << "NO VALUE " << endl;
//
//
//
//     length of the list
//
//    cout << "The length of the list is: " << code.sortedGetLength() << endl;
//
//
//
//     delete
//
//    int deleteNum;
//
//    bool success;
//
//    code.SortedDelete(2, deleteNum, success);
//
//    if (success)
//
//        cout << "Element " << deleteNum << " has been deleted" << endl;
//
//    else
//
//        cout << "There is no value to delete" << endl;
//
//
//
//     after deletion
//
//
//
//    cout << "new list: " << endl;
//
//    code.display();
//
//
//
//    pos = code.SortSearch(7);
//
//    if (pos != -1)
//
//        cout << "The value was found at Element: " << pos << endl;
//
//    else
//
//        cout << "NO VALUE " << endl;
//
//
//
//    return 0;
//
//}
//---------------------------------------------------------------------
//#include<iostream>
//#include<cstdlib> // Add this line for NULL
//
//using namespace std;
//
//class singleList {
//private:
//    struct Node {
//        int data;
//        Node* next;
//        Node(int x) : data(x), next(nullptr) {} // constructor
//    };
//
//    Node* head;
//
//public:
//    singleList() : head(nullptr) {}
//
//    void display() {
//        Node* tmp = head;
//        while (tmp) {
//            cout << "" << tmp->data << endl;
//            tmp = tmp->next;
//        }
//    }
//
//    bool SortedIsEmpty() const {
//        return head == nullptr ? true : false;
//    }
//
//    int sortedGetLength() const {
//        if (head == nullptr) return 0;
//        int count = 0;
//        for (Node* tmp = head; tmp->next != nullptr; count++) {
//            tmp = tmp->next;
//        }
//        return count;
//    }
//
//    bool sortfind(int k, int& x) {
//        if (k < 1 || k > sortedGetLength()) {
//            return false;
//        }
//        Node* tmp = head;
//        int counter = 1;
//        while (tmp) {
//            if (counter == k) {
//                x = tmp->data;
//                return true;
//            }
//            counter++;
//            tmp = tmp->next;
//        }
//        return false;
//    }
//
//    int SortSearch(int key) {
//        int element = 0;
//        Node* tmp = head;
//        while (tmp != nullptr) {
//            if (tmp->data == key) {
//                return element;
//            }
//            element++;
//            tmp = tmp->next;
//        }
//        cout << "The key not found: ";
//        return -1;
//    }
//
//    void SortedInsert(int x) {
//        Node* curr = head;
//        while (curr != nullptr) {
//            if (curr->data == x) {
//                return;
//            }
//            curr = curr->next;
//        }
//        // insert
//        Node* value = new Node(x);
//
//        if (!head || x < head->data) { // base case
//            value->next = head;
//            head = value;
//            return;
//        }
//
//        curr = head;
//        while (curr->next != nullptr) { // Fix the infinite loop
//            if (curr->next->data >= x) { // if greater return this else return x
//                value->next = curr->next;
//                curr->next = value;
//                return;
//            }
//            curr = curr->next;
//        }
//        value->next = curr->next;
//        curr->next = value;
//    }
//
//    void SortedDelete(int k, int& x, bool& success) {
//        if (head == nullptr || k < 0) {
//            success = false;
//            return;
//        }
//
//        if (k == 0) {
//            Node* temp = head;
//            head = head->next;
//            x = temp->data;
//            delete temp;
//            success = true;
//            return;
//        }
//
//        Node* current = head;
//        for (int i = 0; i < k - 1 && current->next != nullptr; i++) {
//            current = current->next;
//        }
//
//        if (current->next == nullptr)
//            success = false;
//        else {
//            Node* temp = current->next;
//            current->next = temp->next;
//            x = temp->data;
//            delete temp;
//            success = true;
//        }
//    }
//};
//
//int main() {
//    singleList code;
//
//    code.SortedInsert(5);
//    code.SortedInsert(7);
//    code.SortedInsert(9);
//    code.SortedInsert(11);
//    code.SortedInsert(5);
//
//    cout << "List: " << endl;
//    code.display();
//
//    code.SortedInsert(7);
//
//    cout << "List after adding 7:  " << endl;
//    code.display();
//
//    // Find the element
//    int find;
//    if (code.sortfind(3, find))
//        cout << "The value of element 3 is " << find << endl;
//    else
//        cout << " NO VALUE " << endl;
//
//    int pos = code.SortSearch(7);
//    if (pos != -1)
//        cout << "The value was found at Element: " << pos << endl;
//    else
//        cout << "NO VALUE " << endl;
//
//    // Length of the list
//    cout << "The length of the list is: " << code.sortedGetLength() << endl;
//
//    // Delete
//    int deleteNum;
//    bool success;
//    code.SortedDelete(2, deleteNum, success);
//    if (success)
//        cout << "Element " << deleteNum << " has been deleted" << endl;
//    else
//        cout << "There is no value to delete" << endl;
//
//    // After deletion
//    cout << "New list: " << endl;
//    code.display();
//
//    pos = code.SortSearch(7);
//    if (pos != -1)
//        cout << "The value was found at Element: " << pos << endl;
//    else
//        cout << "NO VALUE " << endl;
//
//    return 0;
//}
