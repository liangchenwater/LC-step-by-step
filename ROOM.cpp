//
//  ROOM.cpp
//  OOP proj2
//
//  Created by 梁 一 on 2019/12/19.
//  Copyright © 2019年 梁 一. All rights reserved.
//

#include "ROOM.hpp"

room::room(string floor,int room_number,elevator* el, building_without_room* bwr):basic_block(room_number,floor),now_obj_amt(0),e(el),b(bwr){}

void room::check_obj()
{
    for(int i=0;i<now_obj_amt;i++){
        obj[i]->execute();
        now_obj_amt--;
        if(obj[i]->return_1()==2) break;
    }
}

void room::welcome(){
    cout<<"Welcome to room "<<property_1<<" on the "<<property_2<<" floor."<<endl;
    if(property_1!=1&&property_1!=size&&property_1!=0) cout<<"You can go either left or right."<<endl<<endl;
    else if(property_1==1)  cout<<"You can go right."<<endl;
    else  if(property_1==size) cout<<"You can go left."<<endl;
    else cout<<"This floor only have one big room."<<endl<<"The billboard in the hall says:"<<endl<<"Now you have won the love of "<<tot_cnt<<" princess(es)"<<endl<<endl;
    if(e)  {
        if(property_1!=0) cout<<"And y";
        else cout<<"Y";
        cout<<"ou can take the elevator."<<endl<<"The elevator would take you to the "<<e->property_2<<" floor."<<endl;
    }
}

bool room::direction()
{
    char c;
    cin>>c;
    if((c=='a'||c=='A')&&property_1!=1&&property_1!=0){
        cur--;
        return true;
    }
    else if((c=='d'||c=='D')&&property_1!=size&&property_1!=0) {
        cur++;
        return true;}
    else if((c=='w'||c=='W')&&e){
        e->execute();
        if(e->property_1==0)cur+=size;
        else cur-=size;
        if(property_1) b->turn_elevator((property_2[0]-'0'-1)*size-size+1,property_2,e->property_2);
        //pay special attention! you need change the states of all the elevators in the same floor instead of just changing the state of the one you took.
        else e->change_instruction(property_2);
        return true;
    }
    return false;
}

void room::execute()
{
    welcome();
    check_obj();
    if(death_flag) return;
    while(!direction());
}

room::~room(){
    for(int i=0;i<now_obj_amt;i++) {
        delete  obj[i];
        obj[i]=NULL;
    }
    if(e){
        b->assist_des((property_2[0]-'0'-1)*size-size+1+property_1-1);
        delete e;
        e=NULL;
    }//pay special attention! two rooms share one elevator!Calling assist_des is necessary
}
