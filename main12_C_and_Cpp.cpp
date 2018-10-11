#include "stdafx.h" // for windows version
#include "cppcoding.h"
#include <string>
#include <windows.h>
#define NAME_SIZE 50 //Defines a macro

//Clases, Inheritance, Constractors, Destructors, Virtual Function, Virtual Destructor

class Person
{

    int id; // all member are private by default
    char name[NAME_SIZE];
public:

    Person(){id = 0;}
    //Person(int a){id = a;}

    virtual void aboutMe()
    {
        cout << "I am a person.\n";
    }

    virtual bool addCourse(string s) = 0;

    virtual ~Person(){ //virtual destructor will default call child destructor
        cout << "Deleting a person." << endl;
    }
};

class Student : public Person
{
public:

    void aboutMe()
    {
        cout << "I am a Studient.\n";
    }              

    bool addCourse(string s)
    {
        cout << "Deleting a Student " + s  << endl;
        return false;
    }

    ~Student(){
        cout << "Deleting a Student." << endl;
    }

};


class Teacher : public Person
{
public:

    void aboutMe(){
        cout << "I am a Teacher.\n";
    }
    bool addCourse(string s){
        cout << "Deleting a Student " + s  << endl;

        return true;
    }
};


//Default Values in function

void func(int a, int b=3)
{
    cout << a+b << " a + b" << endl;
    return;
}

//Overloading function
void func(string firstname, string lastname = "wang")
{
    cout << firstname + " " + lastname << " firstname + lastname" << endl;
}

void funcOp(int a, int b=3)
{
    cout << a+b << " a =+ b Operator Overloading" << endl;

}


//Pointers and References

void point_ref()
{
    int *p = new int();
    *p = 7;
    int *q = p;
    *q = 8;
    cout << *q << " pointed value" << endl;

    const int &b = 12;

    cout << b << " const ref" << endl;

    //pinter arithmetic
    int *pa = new int[2];
    pa[0] = 0;
    pa[1] = 1;
    pa++;
    cout << *pa << " point move up" << endl; // OUtputs 1

}

//Templates
template <class T> class ShiftedList{

    T* array;
    int offset, size;
public:
    ShiftedList(int sz) : offset(0), size(sz) {
        array = new T(size);
    }

    ~ShiftedList() {
        delete[] array;
    }

    void shiftBy(int n){
        offset = (offset + n) % size;
    }

    T getAt(int i){
        return array[convertIndex(i)];
    }

    void setAt(T item, int i){
        array[convertIndex(i)=item];
    }

private:
    int convertIndex(int i){
        int index = (i-offset) % size;
        while (index < 0) index += size;
        return index;
    }
};

//Inverview Questions
//12.1 Last K Lines: Write a method to print the last K lines of an input file using C++

void Last10line(char* inputfile)
{

    const int K = 10;
    ifstream f(inputfile);
    string astring[K];
    int index = 0;
    while(f.peek() !=EOF)
    {
        getline(f, astring[index%K]);
        index++;
    }
    int start = index > K ? (index % K ): 0;
    int count = min(K, index);
    for(int i = 0; i < count; i++){
        cout << astring[(start + i)%K] << endl;
    }

}

//12.2 Reverse string: Implement a fcuntion void reverse(char* str)
void reverse(char* str)
{

    cout << "input " << str << endl;
    char* str1;
    //char* str2;
    str1 = str;

    char* end = str;
    int count = 0;
    char tmp;
    if(str)
    {
        while(*end){
            ++end;
            count++;
        }
        --end;

        while(str<end){
            tmp = *str;
            *str++ = *end;
            *end-- = tmp;
        }
    }
    cout << "reverse " << str1 << endl;
}

//12.3 Hash Tabel vs STL MAP.
// In a has table, the item is stored by calling a hash function on ak key. Key->Index->item in table.
//Key : Value => Item.
//Key converty to index by Hash funciton such as 256('k') + 100('e') + 3('y') => 359 % 10 => 9 as hash table index for theis tiem.
//put all itmes with same key index to the item list and bind to the index.
//lookup up item, first get index, then get list of items, then get item value based on key.
//STL map insert the key/value paris into a binary search trye based on the key there is no need to handle collisions, and the tree is balance, the inter and lookup time is O(logN)

//12.4 How do virtual function s work in C++, The virtual function in the base class becomes virtual in each of the derived classes adn virual function are sresolved at run time.

//12.5 Shllow vs Deep copy.
// A shallow copy copies all the member values from one object to anotehr, A deep copy doese all this and also deep copies any pointer ojbects.

struct Test{
    char *ptr;
};

Test shallow_copy(Test & src){
    Test dst;
    dst.ptr = src.ptr;
    return dst;
}

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
Test deep_copy(Test src){
    Test dst;
    dst.ptr = (char*)malloc(strlen(src.ptr)+1);
    strcpy(dst.ptr, src.ptr);
    return dst;
}

//12.6 Volatile in C. the value of data could be changed by outside of function.
volatile int opt = 1;
void Fun(void){
    start:
//    int opt =1;
    if (opt==1) goto start;
    else return;
}

//12.7 Vitual Base Class: need make sure all child functions implatmented and called.
class Foo{
public:
    virtual void f(){cout << "f() from Foo" << endl;}
    virtual ~Foo(){cout << "Foo desctucted" << endl;}
};

class Bar : public Foo {
public:
    void f(){cout << "f() from Bar" << endl;}
    ~Bar(){cout << "Bar desctucted" << endl;}
};

//12.8 Copy Node: Copy Node structure as parameter and returns a complete copy of the node.


struct Node {
	int iName;
	Node(int i) { iName = i; }
	Node *ptr1 = NULL;
	Node *ptr2 = NULL;
};

#include <map>

typedef map<Node*, Node*> NodeMap;

Node * copy_recursive(Node * cur, NodeMap & nodeMap) {
    if(cur==NULL)
        return  NULL;

    NodeMap::iterator i = nodeMap.find(cur);

    if(i!=nodeMap.end()){
        return i->second;
    }

    Node * node = new Node(cur->iName);

    nodeMap[cur] = node;
    node->ptr1 = copy_recursive(cur->ptr1, nodeMap);
    node->ptr2 = copy_recursive(cur->ptr2, nodeMap);
    return node;
}

Node * copy_structure(Node * root){
    NodeMap nodeMap;
    return copy_recursive(root, nodeMap);
}

//12.9 Smart point ?

//12.10

//12.11 2D Alloc
int ** my2DAlloc(int rows, int cols)
{
    int** rowptr;
    int i;
    rowptr = (int **) malloc(rows * sizeof(int*));
    for(i=0; i<rows; i++){
        rowptr[i] = (int*) malloc(cols * sizeof(int));
    }
    return rowptr;
}

int main12(){

    Student * p = new Student();
    Person * p1 = new Student();
    Teacher * p2 = new Teacher();
    p->aboutMe(); //prints "I am a student."
    p1->aboutMe(); //prints "I am a person."
    p2->aboutMe(); //prints "I am a teacher."

    delete p; // Important! Make sure to delete allocated memory
    delete p1; // Important! Make sure to delete allocated memory
    delete p2; // Important! Make sure to delete allocated memory

    func(4);
    func(4, 5);
    func("Henry");
    func("Henry", "Li");

    funcOp(4, 5);

    point_ref();

    char input[] = "testdata.txt";
    Last10line(input);
    reverse(input);

    Test src;
    src.ptr = "Henry";
    Test dst;

    dst = shallow_copy(src);
    dst = deep_copy(src);

    Foo *f = new Bar();
    f->f();
    delete f;
    int i = 0;

    Node * root = new Node(i++);
    root->ptr1 = new Node(i++);
    root->ptr2 = new Node(i++);

    root->ptr1->ptr1 = new Node(i++);
    root->ptr1->ptr2 = new Node(i++);

    root->ptr2->ptr1 = new Node(i++);
    root->ptr2->ptr2 = new Node(i++);

    root->ptr1->ptr1->ptr1 = new Node(i++);
    root->ptr1->ptr1->ptr2 = new Node(i++);

    root->ptr2->ptr2->ptr1 = new Node(i++);
    root->ptr2->ptr2->ptr2 = new Node(i++);

    Node * copy = copy_structure(root);

    if(copy==NULL)
        return 1;

    return 0;
}

