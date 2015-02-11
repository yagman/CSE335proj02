/*
 * Team: Ian Bacus and Yousef Gtat
 * CSE335
 * Project02
 * Date: 02/16/2015
 *
 *
 *
 */

#ifndef BARISTA_H_
#define BARISTA_H_

#include "drink.h"
#include <vector>
using std::vector;


//Abstract factory class
class OrderList
{
protected:                        //should it be private?
    vector<Drink*> m_Order_List; // follow the naming standards
public:
    //Base class initialization constructor
    OrderList (vector<Drink*> & OL): m_Order_List = OL {}
    
    //Delet the Drink objects inside m_Drinks_list
    virtual ~OrderList();
    
    //pure virtual Accessor function
    virtual vector<Drink*> get_OrderList()=0;
};



class OrangeJuiceOrderList : public OrderList
{
public:
    //In case nothing was passed
    OrangeJuiceOrderList()=default;
    
    //Initialize m_Drinks_list using the base class constructor
    virtual OrangeJuiceOrderList(vector<Drink*> &OJ_OL): OrderList(OJ_OL) {}
    
    //Implements delete OJ and BT objects
    virtual ~OrangeJuiceOrderList();
    
    //Copy constructor which is needed in the main.cpp
    OrangeJuiceOrderList(const OrangeJuiceOrderList &);
    
    //Assignment Operator which is NOT needed in the main.cpp file
    OrangeJuiceOrderList & operator= (const OrangeJuiceOrderList &);
    
    //Virtual accessor function
    virtual vector<Drink*> get_OrderList() {return m_Order_List}
};



class BubbleTeaList : public OrderList
{
public:
    //In case nothing was passed
    BubbleTeaList()=default;
    
    //Initialize m_Drinks_list using the base class constructor
    virtual BubbleTeaList(vector<Drink*> &BT_OL): OrderList(BT_OL) {}
    
    //Implements delete OJ and BT
    virtual ~BubbleTeaList();
    
    //Copy constructor which is needed for the main.cpp
    BubbleTeaList(const BubbleTeaList &);
    
    //Assignment Operator which is NOT needed in the main.cpp file
    BubbleTeaList & operator= (const BubbleTeaList &);
    
    //Virtual accessor function
    virtual vector<Drink*> get_OrderList() {return m_Order_List}
};



//Interface and algorithm class
class Barista
{
	public:
        Barista()=default; //cons for the base class?
		virtual ~Barista()=default;
		virtual void deliverDrinks(OrderList &)=0;
};



class CoolBarista : public Barista
{
	public:
        CoolBarista()=default;
        virtual ~CoolBarista()=default;
		virtual void deliverDrinks(OrderList &) const;
};



class NewbieBarista : public Barista
{
	public:
        NewbieBarista()=default;
        virtual ~CoolBarista()=default;
		virtual void deliverDrinks(OrderList &) const;
};

#endif