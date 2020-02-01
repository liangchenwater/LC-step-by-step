//
//  ROOM.hpp
//  OOP proj2
//
//  Created by 梁 一 on 2019/12/19.
//  Copyright © 2019年 梁 一. All rights reserved.
//

#ifndef _ROOM_HPP_
#define _ROOM_HPP_


#define objamt 30
#include "OBJ.hpp"

class room:public basic_block{
private:
    elevator *e;
    basic_block *obj[objamt];
    int now_obj_amt;//show the amount of objs in one room
    building_without_room* b;//point to the building containing the room
public:
    void welcome();
    bool direction();
    void execute();
    void check_obj();//to execute the objs in the room
    room(string,int,elevator* el=NULL, building_without_room* bwr=NULL);
    friend class building;//building is a "bigger" class containing rooms
    ~room();//pay special attetion to deal with the ptrs!
};

#endif /* ROOM_hpp */
