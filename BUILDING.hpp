//
//  BUILDING.hpp
//  OOP proj2
//
//  Created by 梁 一 on 2019/12/19.
//  Copyright © 2019年 梁 一. All rights reserved.
//

#ifndef _BUILDING_HPP_
#define _BUILDING_HPP_

#include "ROOM.hpp"

class building:public building_without_room{
private:
    vector<room*> mapp;//a vector containg the addrs of the rooms
public:
    void welcome();
    void create_building();//you can also implement the same function in the ctor
    void ending();//end of one round
    void set_objs();// randomly set objs in rooms
    void direction();
    void build_elevator();//randomly build  elevs in rooms
    void turn_elevator(int,string&,string);
    string process(int);//int to zero
    void execute_rooms(int);//room->execute()
    void assist_des(int);
    void execute();
    ~building();
};

#endif /* BUILDING_hpp */
