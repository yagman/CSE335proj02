/******************************************************
** FILE: barista.cpp
**
** CLASS:
** CSE335
**
** PROJECT02
**
** AUTHOR:
** Ian Bacus and Yousef Gtat
**
** CREATION DATE:
** 02/16/2015
**
** NOTES:
** N/A
*******************************************************/

#include "barista.h"
#include <iostream>
#include <map>
using std::map;
using std::cout;
using std::endl;

void print(vector<Drink*> &vec)
//external subroutine for printing out the contents of vectors stored in the maps
{
    for (auto ptr : vec)
	{
		ptr->confirmOrder();
	}
    cout<<endl<<endl;
}

/////////////////////////////Begin Barista Class Implementation///////////////////////////

// 
void CoolBarista::deliverDrinks(AbstractOrderListFactory *OrderListPtr) const
{
    map<string, vector<Drink*>> nameOrderListMap;
    Drink* objectPtr;
    string name;
    
    //This segment of code will index different elements in the concrete Orderlist through overridden virtual accessors methods
    //Name entries are stored as keys in a map. The values of this map are vectors of Drink*. This allows vectors of drinks in the order to be 
    // binned by the name of the drink orderer.
    for (int i=0; i<OrderListPtr->getOrderListSize(); i++)
    {
        objectPtr = OrderListPtr->getDrinkObject(i);
        name = objectPtr->getCustomerName();
        nameOrderListMap[name].push_back(objectPtr);
    }
    
//Internally, the elements in a map are always sorted by its key
    
    cout<< "Cool Barista: Order's up!"<<endl;
    for (auto it=nameOrderListMap.begin(); it!=nameOrderListMap.end(); it++)
    {
        cout << "I have "<< it->second.size()<< " drinks for "<< it->first;
        print(it->second);
    }
}


// 
void NewbieBarista::deliverDrinks(AbstractOrderListFactory *OrderListPtr) const
{
    map<int, vector<Drink*>> sizeOrderListMap;
    Drink* objectPtr;
    int size;
    
    //This segment of code will index different elements in the concrete Orderlist through overridden virtual accessors methods
    //Size entries are stored as keys in a map. The values of this map are vectors of Drink*. This allows vectors of drinks in the order to be 
    // binned by the drink size of each object in the order.
    for (int i=0; i<OrderListPtr->getOrderListSize(); i++)
    {
        objectPtr = OrderListPtr->getDrinkObject(i);
        size = objectPtr->getDrinkSize();
        sizeOrderListMap[size].push_back(objectPtr);
    }
    cout<< "Newbie Barista: Order's up!"<<endl;
    
//Internally, the elements in a map are always sorted by its key
    
    for (auto it=sizeOrderListMap.begin(); it!=sizeOrderListMap.end(); it++)
    {
        cout << "I have "<< it->second.size()<< " drinks of size "<< it->first;
        print(it->second);
        
    }
    
}
