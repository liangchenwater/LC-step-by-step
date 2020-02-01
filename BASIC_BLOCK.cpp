//
//  BASIC_BLOCK.cpp
//  OOP proj2
//
//  Created by 梁 一 on 2019/12/19.
//  Copyright © 2019年 梁 一. All rights reserved.
//

#include "BASIC_BLOCK.hpp"

int tot_cnt,cur,size;
bool princess_with,medicine_with,success_flag,death_flag;

string princess[17]={"Bill Gaytes","Feifei Ren","Cloud Ma","Red Li","Pony Ma","Feifei Ren","Cloud Ma","Red Li","Pony Ma","Feifei Ren","Cloud Ma","Red Li","Pony Ma","Feifei Ren","Cloud Ma","Red Li","Pony Ma"};
string this_round_boss;
string monster[3]={"Heart Attack","Leukemia","Prostatic Cancer"};
map<string,string> boss_talk={{"Cloud Ma","996 is XIUFUBAO(supreme happiness)!"},{"Red Li","What's your problem?"},{"Bill Gaytes","I'll give the whole steam to you."},{"Pony Ma","How can you get stronger with out topping up?"},{"Feifei Ren","After 5G is developed, America would no longer be a developed country!"}};
map<string,string> boss_love={{"Cloud Ma","Money(which the princess is not interested in)"},{"Red Li","Mineral Water"},{"Bill Gaytes","The Art of Computer Programming by Donald Knuth"},{"Pony Ma","Money"},{"Feifei Ren","251"}};
map<string,bool> boss_vis={{"Clound Ma",false},{"Bill Gaytes",false},{"Red Li",false},{"Pony Ma",false},{"Feifei Ren",false}};

basic_block:: basic_block(int pr1,string& pr2):property_1(pr1),property_2(pr2){}

int basic_block::return_1(){return property_1;}

string basic_block::return_2(){return property_2;}


void init()
{
    cur=size-1;// the amount of rooms are size*size-(size-1)
    princess_with=medicine_with=success_flag=death_flag=0;
    this_round_boss="\0";
}
