//
//  OBJ.cpp
//  OOP proj2
//
//  Created by 梁 一 on 2019/12/19.
//  Copyright © 2019年 梁 一. All rights reserved.
//

#include "OBJ.hpp"

elevator::elevator(string next_floor,int mark):basic_block(mark,next_floor){}

void elevator::change_instruction(string& s)
{
    property_1=!property_1;
    property_2=s;
}

void elevator::welcome()
{
    cout<<endl;
    cout<<"A few seconds later..."<<endl<<"Welcome to the "<<property_2<<" floor."<<endl;
    cout<<"Press W to get out of the elevator."<<endl;
    cout<<endl;
}

bool elevator::direction()
{
    char c;
    cin>>c;
    if(c=='w'||c=='W') return true;
    return false;
}

void elevator::execute()
{
    welcome();
    while(!direction());
}

void obj::welcome()
{
    cout<<endl;
    if(property_1==0) {
        cout<<"The gorgeous princess "<<property_2<<" is standing in the centre of the room!"<<endl<<"It seems like the princess has something to talk to you."<<endl<<endl;
        cout<<property_2<<":"<<words<<endl<<endl;
        cout<<"Okay...Anyway, you're half way to success!"<<endl<<"Take "<<property_2<<" to lobby to complete the rescue ";
        cout<<property_2<<"."<<endl;
    }
    else if(property_1==1){
        cout<<"You've found the magical medicine."<<endl<<"It can help you recover from a fatal disease."<<endl;
    }
    else if(property_1==2){
        cout<<"OH NO!"<<endl<<"You suffer from "<<property_2<<"."<<endl;
    }
    else{
        cout<<"You've found "<<property_2<<" for the princess."<<endl;
    }
    cout<<endl;
}

obj::obj(int mark,string name,string ws):basic_block(mark,name),words(ws){}

bool obj::direction(){
    return 1;
}//a dummy function to instantiate.

void obj::execute()
{
    welcome();
    if(property_1==0) princess_with=1;
    else if(property_1==1) medicine_with=1;
    else if(property_1==2){
        if(medicine_with) {
            medicine_with=0;
            cout<<"Fortunately,you take the medicine and get back to health."<<endl;
        }
        else{
            death_flag=1;
            cout<<"Gradually,you die..."<<endl;
            cout<<endl<<endl;
        }
    }
    else if(property_1==3){
        if(princess_with){
            if(!boss_vis[this_round_boss]){
                tot_cnt++;
                boss_vis[this_round_boss]=1;
            }
            success_flag=1;
            cout<<"She gives you a kiss(an offer) and will love you forever!"<<endl;
        }
        else cout<<"But the you haven't found the princess yet..."<<endl;
    }
    cout<<endl;
}
