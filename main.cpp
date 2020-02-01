//
//  main.cpp
//  OOP proj2
//
//  Created by 梁 一 on 2019/12/7.
//  Copyright © 2019年 梁 一. All rights reserved.
//

//

#include "BUILDING.hpp"

int main()
{
    while(1){
        building* programmer_tower=new building;
        programmer_tower->execute();
        init();//create a new building each round
    while(1){
        if((princess_with&&cur==size-1)||death_flag) {
            programmer_tower->ending();
            delete programmer_tower;
            break;
        }// mark the end of one round
        programmer_tower->execute_rooms(cur);//wander in the building
    }
    }
}
