//
//  OBJ.hpp
//Declare the equipment in the rooms

#ifndef _OBJ_HPP_
#define _OBJ_HPP_

#include "BASIC_BLOCK.hpp"

class elevator:public basic_block{
public:
    elevator(string,int=0);//string shows the floor the elevator going to take you to int shows the state(up or down)
    void change_instruction(string&);//change the state
    void welcome();
    bool direction();
    void execute();
    friend class room;
    friend class building;//building and room are "bigger" classes containing the elevator
};

//princess, medicine and diseases and toys are objs
class obj:public basic_block{
private:
    string words;//the words of princess
public:
    obj(int,string="\0",string="\0");
    void welcome();
    void execute();
    bool direction();
};

#endif /* OBJ_hpp */
