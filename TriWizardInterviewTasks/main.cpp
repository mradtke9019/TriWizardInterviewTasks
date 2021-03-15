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
    assert(list->FindByData(10) == nullptr);
    assert(list->FindByData(5) != nullptr);
    assert(list->FindByData(0) != nullptr);
    assert(list->FindByData(-1) == nullptr);
    assert(list->FindByData(1)->next->data == 2);
    assert(list->FindByData(1)->next->prev->data == 1);
    assert(list->FindByData(0)->prev == nullptr);

    assert(list->FindByData(0,1) != nullptr);
    assert(list->FindByData(5,2) != nullptr);
    assert(list->FindByData(5, 2)->prev->data == 5);
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
    list->RemoveByIndex(0);
    assert(list->Head->data == 1);
    assert(list->Head->prev == nullptr);
    assert(list->Count() == 5);
    list->RemoveByIndex(4);
    assert(list->Count() == 4);
    assert(list->FindByData(5) == nullptr);
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
    list->RemoveByData(5);
    assert(list->Count() == 5);
    assert(list->FindByData(5) == nullptr);
    assert(list->FindByData(4)->next == nullptr);
    list->RemoveByData(5);
    list->RemoveByData(1);
    list->RemoveByData(2);
    list->RemoveByData(3);
    list->RemoveByData(4);
    list->RemoveByData(0);
    assert(list->Count() == 0);
    list->Insert(1);
    assert(list->Count() == 1);
    list->RemoveByIndex(0);
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
    DoubleLinkList<std::string>* list = new DoubleLinkList<std::string>();
    list->Add("123");
    auto node = list->FindByData("123");
    node->data;
    return 0;
}