#include <iostream>
#include "LinkNode.cpp"
#include "DoubleLinkList.cpp"
#include <assert.h>


void TestInsert() 
{
    DoubleLinkList<int>* list = new DoubleLinkList<int>();
    list->Insert(0, 0);
    list->Insert(1, 1);

    assert(list->Count() == 2);
    assert(list->Head->data == 0);
    assert(list->Head->next->data == 1);
    std::cout << "Insert test passed\n";
}

void TestAdd()
{
    DoubleLinkList<int>* list = new DoubleLinkList<int>();
    list->Add(0);
    list->Add(1);
    list->Add(2);
    list->Add(3);
    list->Add(4);
    list->Add(5);

    assert(list->Head->data == 0);
    assert(list->Count() == 6);
    assert(list->Head->next->prev->data == 0);
    assert(list->Head->next->next->prev->prev->data == 0);
    assert(list->Head->next->next->next->next->next->data == 5);
    std::cout << "Add test passed\n";
}

void TestFind()
{
    DoubleLinkList<int>* list = new DoubleLinkList<int>();
    list->Add(0);
    list->Add(1);
    list->Add(2);
    list->Add(3);
    list->Add(4);
    list->Add(5);
    list->Add(5);
    assert(list->Find(10) == nullptr);
    assert(list->Find(5) != nullptr);
    assert(list->Find(0) != nullptr);
    assert(list->Find(-1) == nullptr);
    assert(list->Find(1)->next->data == 2);
    assert(list->Find(1)->next->prev->data == 1);
    assert(list->Find(0)->prev == nullptr);

    assert(list->Find(0,1) != nullptr);
    assert(list->Find(5,2) != nullptr);
    assert(list->Find(5, 2)->prev->data == 5);
    std::cout << "Find test passed\n";
}


void TestRemove()
{
    DoubleLinkList<int>* list = new DoubleLinkList<int>();
    list->Add(0);
    list->Add(1);
    list->Add(2);
    list->Add(3);
    list->Add(4);
    list->Add(5);
    list->Remove(0);
    assert(list->Head->data == 1);
    assert(list->Head->prev == nullptr);
    assert(list->Count() == 5);
    std::cout << "Remove test passed\n";
}

void TestRemoveByData()
{
    DoubleLinkList<int>* list = new DoubleLinkList<int>();
    list->Add(0);
    list->Add(1);
    list->Add(2);
    list->Add(3);
    list->Add(4);
    list->Add(5);
    list->RemoveNode(5);
    assert(list->Count() == 5);
    assert(list->Find(5) == nullptr);
    assert(list->Find(4)->next == nullptr);
    list->RemoveNode(5);
    list->RemoveNode(1);
    list->RemoveNode(2);
    list->RemoveNode(3);
    list->RemoveNode(4);
    list->RemoveNode(0);
    assert(list->Count() == 0);
    std::cout << "Remove by data test passed\n";
}

void TestCount()
{
    DoubleLinkList<int>* list = new DoubleLinkList<int>();
    assert(list->Count() == 0);
    list->Add(0);
    assert(list->Count() == 1);
    list->Add(1);
    assert(list->Count() == 2);
    list->Add(2);
    assert(list->Count() == 3);
    list->Add(3);
    assert(list->Count() == 4);
    list->Add(4);
    assert(list->Count() == 5);
    list->Add(5);
    assert(list->Count() == 6);
    std::cout << "Count test passed\n";
}

int main()
{
    TestAdd();
    TestInsert();
    TestFind();
    TestRemove();
    TestRemoveByData();
    TestCount();
    return 0;
}