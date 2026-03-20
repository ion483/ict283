#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include <vector>

/**
 * @class Vector
 * @brief Represents a container that mimics std::vector
 * @tparam V The element datatype stored in the vector
 * @author Edison
 * @version 01
 * @date 08/01/2026 Edison
 * @bug My program has no bugs.
 */

template <class V>
class Vector{
    public:

        /**
         * @brief Default constructor initializes an empty vector
         * @return void
         */
        Vector();

        /**
         * @brief Destructor, cleans up allocated memory
         * @return void
         */
        ~Vector();

        /**
         * @brief Paremeterized constructor. Creates a new vector with specified capacity and filled with input value
         * @param capacity The initial capacity of the vector.
         * @param defaultValue The default values to initialize the elements
         * @return void
         */
        Vector(const int& capacity, V defaultValue);

        /**
         * @brief Inserts a new element to a specified index in the vector
         * @param value The new element value
         * @param index The index to insert at
         * @return void
         */
        void Insert(const V& value, size_t index);

        /**
         * @brief Deletes an element at a specified index in the vector
         * @param index The index where element will be deleted
         * @return void
         */
        void DeleteAt(size_t index);

        /**
         * @brief Accesses an element by index(non const version)
         * @param index The position
         * @return Reference to the element
         * @throws std::out_of_range if index is invalid
         */
        V& operator[](size_t index);

        /**
         * @brief Accesses an element by index(const version)
         * @param index The position
         * @return Const reference to the element
         * @throws std::out_of_range if index is invalid
         */
        const V& operator[](size_t index) const;

        /**
         * @brief Check if the vector is empty
         * @return True if the vector is empty, false otherwise
         */
        bool IsEmpty() const;

        /**
         * @brief Return the size of the data vector
         * @return An integer representing the size of data vector
         */
        int GetSize() const;

    private:
        std::vector<V> data;
};

template <class V>
Vector<V>::Vector(){}

template <class V>
Vector<V>::~Vector(){}

template <class V>
Vector<V>::Vector(const int& capacity, V defaultValue){
    int finalCapacity;
    if(capacity > 0){
        finalCapacity = capacity;
        data.resize(finalCapacity);
    }else{
        finalCapacity = 5;
        data.resize(finalCapacity); // 5 default size
    }
    for(int i = 0; i < finalCapacity; i++){
        data[i] = defaultValue;
    }
}

template <class V>
void Vector<V>::Insert(const V& value, size_t index){
    if(index < 0 || index > GetSize()){
        throw std::out_of_range("Out of range");
    }else if(index == GetSize()){
        data.push_back(value);
    }else{
        data.insert(data.begin()+index, value);
    }
}

template <class V>
void Vector<V>::DeleteAt(size_t index){
    if(index < 0 || index >= GetSize()){
        throw std::out_of_range("Out of range");
    }
    data.erase(data.begin()+index);
}

template <class V>
int Vector<V>::GetSize() const{
    return data.size();
}

template <class V>
V& Vector<V>::operator[](size_t index){
    if(index < 0 || index >= GetSize()){
        throw std::out_of_range("Out of range");
    }
    return data[index];
}

template <class V>
const V& Vector<V>::operator[](size_t index) const{
    if(index < 0 || index >= GetSize()){
        throw std::out_of_range("Out of range");
    }
    return data[index];
}

template <class V>
bool Vector<V>::IsEmpty() const{
    return (GetSize() == 0);
}

#endif