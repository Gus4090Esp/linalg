//
//  connectedlist.h
//  linalg
//
//  Created by Gustavo Espinoza on 7/15/22.
//

#ifndef connectedlist_h
#define connectedlist_h
#include<stdio.h>

template<class T> class connectedlist{
protected:
    T item;
    connectedlist* next;
public:
    //default constructor
    connectedlist():next(0){
    };
    
    //constructor
    connectedlist(T&t, connectedlist* N = 0): item(t), next(N){
    };
    
    // read item field
    const T& operator()() const{
        return item;
    };
    
    // read next
    const connectedlist* readNext() const{
        return next;
    };
    
    // copy constructor
    const connectedlist& operator=(const connectedlist&);
    connectedlist(const connectedlist&l):item(l()), next(l.next ? new connectedlist(*l.next):0){
    };
    
    // destructor
    ~connectedlist(){
        delete next;
        next = 0;
    };
    
    //last item
    connectedlist& last(){
        return next ? next -> last(): *this;
    };
    
    // number of times
    int length() const{
        return next ? next -> length() + 1: 1;
    };
    
    //append item
    void append(const T&t){
        last().next = new connectedlist(t);
    }
    
    // insert item in the second place
    void insertNextItem(T &t){
        next = new connectedlist(t, next);
    };
    
    // insert item at the beginning
    void insertFirstItem(T &t){
        next = new connectedlist(item, next);
        item = t;
    };
    
    void dropNextItem();
    void dropFirstItem();
    void truncateItems(double);
    const connectedlist& operator+=(connectedlist&);
    connectedlist& order(int);
};

// assignment operator
template<class T> const connectedlist<T>& connectedlist<T>::operator=(const connectedlist<T> &L){
    if (this != &L) {
        item = L();
        if (next) {
            if (L.next) {
                *next = *L.next;
            } else {
                delete next;
                next = 0;
            };
        };
    } else {
        if (L.next) {
            next = new connectedlist(*L.next);
        };
    };
    return *this;
}


// dropping the next item
template<class T> void connectedlist<T>::dropNextItem(){
    if (next) {
        if (next -> next) {
            connectedlist<T>* keep = next;
            next = next -> next;
            keep -> item.~T();
        }
        else {
            delete next;
            next = 0;
        };
    }
    else {
        std::cout << "error: cannot drop nonexist next time " << std::endl;
    };
};

//truncate certain items
template<class T> void connectedlist<T>::truncateItems(double threshold){
    if (next) {
        if (abs(next->item.getValue()) <= threshold) {
            dropNextItem();
            truncateItems(threshold);
        }
        else {
            next->truncateItems(threshold);
        };
    };
    if (next&&(abs(item.getValue()) <= threshold)) {
        dropFirstItem();
    }; 
};

// print a connected list
template<class T> void print(const connectedlist<T> &L){
    std::cout << L() << std::endl;
    if (L.readnext()) {
        print(*L.readNext());
    };
};



#endif /* connectedlist_h */
