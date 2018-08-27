#include "stdafx.h"
#include <memory>
#include <iostream>

class SmartPtrNode
{
    std::shared_ptr<SmartPtrNode> m_next;
    std::shared_ptr<SmartPtrNode> m_prev;
    int m_id;
public:
    SmartPtrNode(SmartPtrNode* prev, SmartPtrNode* next, int id) :m_prev(prev), m_next(next), m_id(id)
    {

    }

    ~SmartPtrNode()
    {
        std::cout << "Destructing SmartPtrNode id " << m_id << std::endl;
    }
};

