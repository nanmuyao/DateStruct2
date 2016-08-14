//
//  Vector.hpp
//  DateStruct
//
//  Created by hanzhiqiang on 16/8/13.
//  Copyright © 2016年 hanzhiqiang. All rights reserved.
//

#ifndef Vector_hpp
#define Vector_hpp

#include <stdio.h>


template <typename Object>
class Vector
{
public:
    
    enum
    {
        SPARE_CAPACITY = 16
    };
    
    explicit Vector(int intSize = 0)
    :theSize(intSize)
    ,theCapacity(intSize + SPARE_CAPACITY)
    {
        objects = new Object[theCapacity];
    }
    
    Vector(const Vector &rhs)
    :objects(NULL)
    {
        operator=(rhs);
    }
    
    ~Vector()
    {
        delete [] objects;
    }
    
    const Vector & operator=(const Vector &rhs)
    {
        if (*this != rhs) {
            delete []objects;
            theSize = rhs.theSize;
            theCapacity = rhs.theCapacity;
            
            objects = new Object[theCapacity];
            for (int i = 0; i<theSize; i++) {
                objects[i] = rhs.objects[i];
            }
        }
        return *this;
    }
    
    void reSize(int newSize)
    {
        if (theSize < newSize) {
            reserve(newSize*2 +1);
            theSize = newSize;
        }
    }
    
    //重新分配数组vector大小
    void reserve(int newCapcacity)
    {
        if (newCapcacity < theSize)
            return;
        Object *oldArray = objects;
        objects = new Object[newCapcacity];
        for (int i = 0; i<theSize; i++) {
            objects = oldArray[i];
        }
        theCapacity = newCapcacity;
        delete [] oldArray;
    }

    Object &operator[](int index)
    {
        return objects[index];
    }
    
//    const Object &operator[](int index)
//    {
//        return objects[index];
//    }
    
    bool empty()const
    {
        return size() == 0;
    }
    
    int size()
    {
        return theSize;
    }
    
    int capacity() const
    {
        return theCapacity;
    }
    
    void push_back(Object& rhs)
    {
        if (theSize > theCapacity) {
            reserve(2*theCapacity + 1);
        }
        objects[theSize++] = rhs;
    }
    
    void pop_back()
    {
        theSize--;
    }
    
    const Object& back()
    {
        return objects[theSize - 1];
    }
    
    typedef Object* iterator;
    typedef const Object* const_iterator;
    
    iterator begin()
    {
        return &objects[0];
    }
    
    const_iterator began()const
    {
        return &objects[0];
    }
    
    iterator end()
    {
        return &objects[theSize-1];
    }
    
    const_iterator end()const
    {
        return &objects[theSize-1];
    }
    
    
public:
    int theSize;//当前vector大小
    int theCapacity;//容量vector的大小
    Object* objects;//
};



#endif /* Vector_hpp */
