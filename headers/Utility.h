#ifndef UTILITY_H
#define UTILITY_H

#include <iostream>
#include <cctype> //eg. tolower
#include <regex>
#include "Vector.h"

/**
 * @class Utility
 * @brief Provides helper functions for data conversion and formatting
 */
class Utility {
    public:
        /**
        * @brief Converts a month number to its string name
        */
        const std::string* monthToStr(int monthNumber);

        /**
        * @brief Converts a month string to its integer type (1-12)
        */
        int monthStrToInt(const std::string& monthStr);

        /**
         * @brief Bubble sort algoirthm
         * @param array The pointer to the array to be sorted
         * @param size The current size of the array to be sorted
         * @return void
         */
        template <class V>
        void bubbleSort(V* array, int size);

        /**
         * @brief Creates a new sorted vector based on the current vector
         * @param original The original input vector
         * @return A new sorted Vector instance
         */
        template <class V>
        Vector<V> getSortedData(const Vector<V>& original);

        /**
         * @brief Craetes a new sorted unique vector based on the current vector
         * @param original The original input vector
         * @return A new sorted unique Vector instance
         */
        template <class V>
        Vector<V> getUniqueData(const Vector<V>& original);

        /**
         * @brief Compare two input values and return the one with greater value
         * @param a The first value
         * @param b The second value
         * @return The greater value
         */
        template <class T>
        T max(const T& a, const T& b);

};

template <class V>
void Utility::bubbleSort(V* array, int size){
    for (int i = 0; i < size - 1; i++) {
        bool isSwapped = false;
        for (int j = 0; j < size - 1 - i; j++) {
            if (array[j] > array[j + 1]) {
                V tempValue = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tempValue;
                isSwapped = true;
            }
        }
        if (!isSwapped) break;
    }
}

template <class V>
Vector<V> Utility::getSortedData(const Vector<V>& original){
    int n = original.GetSize();
    if (n == 0) return Vector<V>();

    V* copyData = new V[n];
    for (int i = 0; i < n; i++) {
        copyData[i] = original[i];
    }
    
    bubbleSort(copyData, n);

    Vector<V> newV; 
    for (int i = 0; i < n; i++) {
        newV.Insert(copyData[i], newV.GetSize());
    }

    delete[] copyData;
    return newV;
}

template <class V>
Vector<V> Utility::getUniqueData(const Vector<V>& original){
    Vector<V> sortedData = getSortedData(original);
    Vector<V> sortedUniqueData;
    for(int i = 0; i < sortedData.GetSize(); i++){
        if(i == 0 || sortedData[i] != sortedData[i-1]){
            sortedUniqueData.Insert(sortedData[i], sortedUniqueData.GetSize());
        }
    }
    return sortedUniqueData;
}

template <class T>
T Utility::max(const T& a, const T& b){
    return (a > b)? a: b;
}


#endif