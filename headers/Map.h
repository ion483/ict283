#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <stdexcept>
#include <map>

/**
 * @class Map
 * @brief A wrapper around std::map providing additional functionalities
 * @tparam Key The type of keys in the map
 * @tparam Value The type of values in the map
 * @author Edison
 * @version 01
 * @date 08/01/2026 Edison
 * @bug My program has no bugs.
 */

template <class Key, class Value>
class Map{
    public:

        /**
         * @brief Default constructor
         * @return void
         */
        Map();

        /**
         * @brief Default destructor
         * @return void
         */
        ~Map();

        /**
         * @brief Returns an iterator to the begin of the map
         * @return Iterator to the first element
         */
        typename std::map<Key, Value>::iterator begin();

        /**
         * @brief Returns an iterator to the end of the map
         * @return Iterator to the the position following the last element
         */
        typename std::map<Key, Value>::iterator end();

        /**
         * @brief Returns an iterator to the begin of the map
         * @return Iterator to the first element
         */
        typename std::map<Key, Value>::const_iterator begin() const;

        /**
         * @brief Returns an iterator to the end of the map
         * @return Iterator to the the position following the last element
         */
        typename std::map<Key, Value>::const_iterator end() const;

        /**
         * @brief Accesses the element at input key (non const)
         * Creates a new entry with a default constructed value if the key does not exist
         * @param key The key whose value is to be returned
         * @return Reference to the value
         */
        Value& operator[](const Key& key);

        /**
         * @brief Accesses the element at input key (const)
         * @throw std::invalid_argument if key is not found
         * @param key The key whose value is to be returned
         * @return Const reference to the value
         */
        const Value& operator[](const Key& key) const;

    private:
        std::map<Key, Value> map_; /**< Internal std::map container*/

};

template <class Key, class Value>
Map<Key, Value>::Map(){};

template <class Key, class Value>
Map<Key, Value>::~Map(){};

template <class Key, class Value>
typename std::map<Key, Value>::iterator Map<Key, Value>::begin() {
    return map_.begin();
}

template <class Key, class Value>
typename std::map<Key, Value>::iterator Map<Key, Value>::end() {
    return map_.end();
}

template <class Key, class Value>
typename std::map<Key, Value>::const_iterator Map<Key, Value>::begin() const{
    return map_.begin();
}

template <class Key, class Value>
typename std::map<Key, Value>::const_iterator Map<Key, Value>::end() const{
    return map_.end();
}

template <class Key, class Value>
Value& Map<Key, Value>::operator[](const Key& key){
    return map_[key];
}

template <class Key, class Value>
const Value& Map<Key, Value>::operator[](const Key& key) const{
    typename std::map<Key, Value>::const_iterator iterator = map_.find(key);
    if(iterator != map_.end()){
        return iterator -> second;
    }else{
        throw std::invalid_argument("Key not found");
    }
}

#endif