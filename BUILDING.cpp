//
//  BUILDING.cpp
//  OOP proj2
//
//  Created by 梁 一 on 2019/12/19.
//  Copyright © 2019年 梁 一. All rights reserved.
//

#include "BUILDING.hpp"

void building::create_building()
{
    for(int i=size-1;i<size*size;i++){
        if(i==size-1) mapp.push_back(new room("lobby",0,new elevator("2nd")));
        else mapp.push_back(new room(process(i),i%size+1));
    }
    for(int i=0;i<size*size-size+1;i++)
        mapp[i]->b=this;
    build_elevator();
    set_objs();
}
//dynamic allocating memories

void building::set_objs()
{
    srand((int)time(NULL));
    int random=rand()%(size*size-size);
    while(!random) random=rand()%(size*size-size);//princess cannot be in the lobby
    int random_name=rand()%17;
    mapp[random]->obj[mapp[random]->now_obj_amt++]=new obj(0,princess[random_name],boss_talk[princess[random_name]]);//set boss
    
     this_round_boss=princess[random_name];
    
    random=rand()%(size*size-size);
    mapp[random]->obj[mapp[random]->now_obj_amt++]=new obj(3,boss_love[princess[random_name]]);
    //set the corresponding toys
    
    for(int i=0;i<size;i++){
        random=rand()%(size*size-size);
        random_name=rand()%3;
        mapp[random]->obj[mapp[random]->now_obj_amt++]=new obj(2,monster[random_name]);
    }
    //set size monsters
    
    for(int i=0;i<size/2;i++){
        random=rand()%(size*size-size);
        mapp[random]->obj[mapp[random]->now_obj_amt++]=new obj(1);
    }
    //set size medicine
}

void building::execute_rooms(int i)
{
    mapp[i-size+1]->execute();//pay attention to index
}

void::building::execute()
{
    welcome();
    direction();
    create_building();
}

void building::build_elevator()
{
    mapp[size]->e=mapp[0]->e;
    for(int i=1;i<size*size-2*size;i+=size){
        srand((int)time(NULL));
        for(int j=0;j<size/3;j++){
            int t=rand()%size;
            while(mapp[i+t]->e) t=rand()%size;
            mapp[i+t]->e=new elevator(process(i+t+size*2-1),0);
            mapp[i+size+t]->e=mapp[i+t]->e;
        }
    }
}//set size/3 elevators on each floor

void building::assist_des(int t)
{
    mapp[t-size]->e=NULL;
}//pay special attention!set the elevator of the room beneath(because the rooms are destructed from the last to the first)to zero(because the elev has been released in the current room's destructor)

string building::process(int i)
{
    string s;
    char c=i/size+1+'0';
    s+=c;
    if(c=='1') s+="st";
    else if(c=='2') s+="nd";
    else if(c=='3') s+="rd";
    else s+="th";
    return s;
}

void building::direction()
{
    char c;
    cin>>c;
    while(c>'9'||c<'3') cin>>c;
    size=c-'0';
    cout<<"Press S to start a new game."<<endl<<endl;
    cin>>c;
    while((c!='S')&&(c!='s')) cin>>c;
}

void building::turn_elevator(int t,string& s_room,string s_e)
{
    for(int i=t;i<t+size;i++){
        if(mapp[i]->e&&mapp[i]->e->property_2==s_e)
            mapp[i]->e->change_instruction(s_room);
    }
}

void building::ending()
{
    if(death_flag) return;
    cout<<"You succesfully rescue the princess!"<<endl;
    if(success_flag){
        cout<<"And you win the love of the princess!"<<endl;
        if(tot_cnt==5) {cout<<"Congratulations!"<<endl<<"All the princesses love you."<<endl<<"You are better than the pathetic designer LiangChenWater."<<endl;
            tot_cnt=0;
        }
    }
    else cout<<"But you don't win the love of the princess."<<endl<<"She leaves you without a word......"<<endl;
    cout<<endl<<endl;
}

void building::welcome()
{
    cout<<"Welcome to the Programmer Towers!"<<endl<<"You as a programmer are destinied to find your princess trapped in these towers."<<endl<<"And you need to take her back to the lobby."<<endl<<"Press A or D to move left or right."<<endl<<"Press W to enter the elevator to go up and down."<<endl<<"Monsters may get in your way!"<<endl;
    cout<<endl;
    cout<<"Now choose the index of the tower from 3 to 9."<<endl<<"If the index of the tower is n, then the tower has n floors with n rooms in each floor except for the lobby."<<endl<<"However, a tower with higher index isn't necessary to be a tower harder to get out."<<endl<<"Now choose!"<<endl;
    cout<<endl;
}

building::~building(){
    for(int i=size*size-size;i>=0;i--){
        room* tmp=mapp[i];
        mapp.pop_back();
        delete tmp;
    }
}
// delete the room from the last to the first(because you cannot pop_front)
