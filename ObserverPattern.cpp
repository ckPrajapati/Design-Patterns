#include <iostream>
#include <set>

using namespace std;

// ---------------- Observer interface -----------------
class MyObserver {
    public:
        virtual void Notify() = 0;
};

// ---------------- Observable object -------------------
class MyObservable {
        static MyObservable* instance;
        set<MyObserver*> observers;
        MyObservable() { };
    public:
       static MyObservable* GetInstance();
       void AddObserver(MyObserver& o);
       void RemoveObserver(MyObserver& o);
       void NotifyObservers();
       void Trigger();
};

MyObservable* MyObservable::instance = NULL;

MyObservable* MyObservable::GetInstance()
{
    if ( instance == NULL ) {
       instance = new MyObservable();
    }

    return instance;
}

void MyObservable::AddObserver(MyObserver& o)
{
    observers.insert(&o);
}

void MyObservable::RemoveObserver(MyObserver& o)
{
    observers.erase(&o);
}

void MyObservable::NotifyObservers()
{
    set<MyObserver*>::iterator itr;
    for ( itr = observers.begin();
          itr != observers.end(); itr++ )
    (*itr)->Notify();
}

// TEST METHOD TO TRIGGER
// IN THE REAL SCENARIO THIS IS NOT REQUIRED
void MyObservable::Trigger()
{
    NotifyObservers();
}

// ------ Concrete class interested in notifications ---
class MyClass1 : public MyObserver {

        MyObservable* observable;

    public:
       MyClass1() {
          observable = MyObservable::GetInstance();
          observable->AddObserver(*this);
       }

       ~MyClass1() {
          observable->RemoveObserver(*this);
       }

       void Notify() {
            cout << "Received a change event in MyClass1" << endl;
       }
};

class MyClass2 : public MyObserver {
        MyObservable* observable;

      public:
        MyClass2() {
            observable = MyObservable::GetInstance();
            observable->AddObserver(*this);
        }

        ~MyClass2() {
            observable->RemoveObserver(*this);
        }

        void Notify() {
          cout << "Received a change event in MyClass2" << endl;
        }
};

main()
{
    MyObservable* observable = MyObservable::GetInstance();
    MyClass1* obj = new MyClass1();
    MyClass2* obj1 = new MyClass2();
    observable->Trigger();
}
