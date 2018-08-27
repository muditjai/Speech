// C11Features.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SmartPointers.h"

int main()
{
    {
        SmartPtrNode* left = new SmartPtrNode(nullptr, nullptr, -10);
        SmartPtrNode* right = new SmartPtrNode(nullptr, nullptr, 10);
        std::shared_ptr<SmartPtrNode> root = std::make_shared<SmartPtrNode>(left, right, 1);
    }
    return 0;
}

