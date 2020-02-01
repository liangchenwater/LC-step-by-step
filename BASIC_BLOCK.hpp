//
//  BASIC_BLOCK.hpp
//  Declare two abstract classes(as the root of all classes), global variables and a global initializing function.

#ifndef _BASIC_BLOCK_HPP_
#define _BASIC_BLOCK_HPP_

#include<iostream>
#include<string>
#include<ctime>
#include<vector>
#include<map>
#include<cstdlib>
#include <stdio.h>
using namespace std;

extern int tot_cnt,cur,size;//tot_cnt shows the number of princess that you conquer.cur shows the current room you in,size is the size of the castle(building)
extern bool princess_with,medicine_with,success_flag,death_flag;

extern string princess[17];//name of the princess(boss)
extern string monster[3];//name of the monsters(diseases)
extern string this_round_boss;

extern map<string,string> boss_talk;
extern map<string,string> boss_love;
extern map<string,bool> boss_vis; //to show whether you win love of a specific boss to update tot_cnt

void init();

class basic_block{
protected:
    int property_1;
    string property_2;
public:
    basic_block(int,string&);
    virtual void welcome()=0;//words printed out when entering sth or using sth
    virtual bool direction()=0;// deal with the input
    virtual void execute()=0;//call execute() to execute all the (significant) methods in the class to complete the interaction.
    virtual ~basic_block(){}
    int return_1();//return property_1
    string return_2();//return property_2
};

class building_without_room{
public:
    virtual void turn_elevator(int,string&,string)=0;//set the states of all elevators in the same floor
    virtual void assist_des(int)=0;//deal with elevator when destructing the building
};


#endif /* BASIC_BLOCK_hpp */
