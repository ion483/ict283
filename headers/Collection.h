#ifndef COLLECTION_H
#define COLLECTION_H

#include "Vector.h"
#include <iostream>

/**
 * @class Collection 
 * @brief A container that stores elements of type U
 * @tparam U The type of elements stored in Collection
 * @author Edison
 * @version 01
 * @date 08/01/2026 Edison
 * @bug My program has no bugs.
 */
template <class U>
class Collection{
    public:

        /**
         * @brief Default constructor initializes Collection to default values
         * @return void
         */
        Collection();

        /**
         * @brief Collects value into the vector
         * @param value The element to be added to the vector
         * @return void
         */
        void collect(const U& value);

        /**
         * @brief Retrieves the size of the collection
         * @return The size as int
         */
        int getSize() const;

        /**
         * @brief Accesses the element at the specified index (non-const)
         * @param index The position of the element
         * @return Reference to the element at the index
         */
        U& operator[](int index);

        /**
         * @brief Accesses the element at the specified index (const)
         * @param index The position of the element
         * @return Const reference to the element at the index
         */
        const U& operator[](int index) const;
        
    private:
        int size; /**< The size of elements stored */
        Vector<U> v; /**< The internal vector for storing elements */
};

template <class U>
Collection<U>::Collection(): size(0){}

template <class U>
void Collection<U>::collect(const U& value){
    v.Insert(value, v.GetSize());
    size++;
}

template <class U>
int Collection<U>::getSize() const{
    return size;
}

template <class U>
U& Collection<U>::operator[](int index){
    return v[index];
}

template <class U>
const U& Collection<U>::operator[](int index) const{
    return v[index];
}

#endif