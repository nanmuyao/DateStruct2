//
//  List.hpp
//  DateStruct
//
//  Created by hanzhiqiang on 16/8/15.
//  Copyright © 2016年 hanzhiqiang. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>

template<typename Object>
class List
{
private:
    struct Node
    {
        Object data;
        Node *prev;
        Node *next;
        Node(const Object &d = Object(),Node *p=NULL,Node *n = NULL)
        :data(d),
         prev(p),
         next(n)
        {
            
        }
    };
public:
    class const_iterator
    {
    public:
        const_iterator()
        :current(NULL)
        {
            
        }
        
        //前置++ const_iterator 位移了
        const_iterator & operator++()
        {
            current = current->next;
            return current;
        }
        
        //后置++ 值并没有动
        const_iterator operator++(int)
        {
            const_iterator old = *this;
            ++(*this);
            return  old;
        }
        
        bool operator==(const const_iterator & rhs)const
        {
            return (current == rhs.current);
        }
        
        bool operator!=(const const_iterator & rhs)const
        {
            return !(*this==rhs);
        }
    protected:
        Node *current;
        
        Object & retrieve() const
        {
            return current->data;
        }
        
        const_iterator(Node *p)
        :current(p)
        {
            
        }
        
        friend class List<Object>;
    };
    
    class iterator : public const_iterator
    {
 
        
    };
};

#endif /* List_hpp */
