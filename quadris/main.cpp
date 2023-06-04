
#include "Grid.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstddef>
#include "level.hpp"
#include "level0.hpp"
using namespace std;
string move_command(string s) {
    if ((s == "left")||(s == "lef"))  {
        return "left";
    } else if ((s == "r")||(s == "ri")||(s == "rig")
        ||(s == "righ")||(s == "right")) {
        return "right";
    } else if (s.front() =='d') {
        if (s.size() > 1) {
            if ((s == "dr") ||(s == "dro") ||(s == "drop")){
                return "drop";
            } else if((s == "do") ||(s == "dow") ||(s == "down")){
                return "down";
            } else {
                return "invalid command";
            }
        } else {
            return "invalid command";
        }
    } else if (s.front() =='c') {
        if (s.size() > 1) {
            if ((s == "clockwise") ||(s == "clockwis")||(s == "clockwi")
                || (s == "clockw") ||(s == "clock") || (s == "cloc")
                || (s == "clo") ||(s == "cl")){
                return "clockwise";
            } else if ((s == "counterclockwise") || (s == "counterclockwis") ||
                       (s == "counterclockwi") || (s == "counterclockw") ||
            (s == "counterclock") || (s == "countercloc") ||
                       (s == "counterclo") || (s == "countercl") ||
            (s == "counterc") || (s == "counter") || (s == "counte") ||
            (s == "count") || (s == "coun") || (s == "cou") ||
                       (s == "co")){
                return "counterclockwise";
            } else {
                return "invalid command";
            }
        } else {
            return "invalid command";
        }
    } else {
        return "invalid command";
    }
}

bool play(Grid &grid, string s) {
    bool play = true;
    if ((s.front() =='1')||(s.front() =='2')||(s.front() =='3')
               ||(s.front() =='4')||(s.front() =='5')||(s.front() =='6')
               ||(s.front() =='7')||(s.front() =='8')||(s.front() =='9')) {
        int found = s.find_first_not_of("1234567890");
        string num;
        for(int i = 0; i<found; i++) {
            num.push_back(s.at(i));
        }
        istringstream ss(s);
        int n;
        ss>>n;
        string c;
        int size = s.size();
        for(int i = num.size(); i < size; i++) {
            c.push_back(s.at(i));
        }
        c = move_command(c);
        for(int i = 0; i< n; i++){
            grid.modify_bolck(c);
        }
    } else if (move_command(s)!="invalid command") {
        grid.modify_bolck(move_command(s));
    } else {
        play = false;
    }
    return play;
}


int main(int argc, char *argv[]) {
    bool text = false;
    int start_level = 0;
    int seed = 0;
    string file = "sequence.txt";
    int pos = 1;
    while(pos < argc){
        string c = argv[pos++];
        if (c == "-text") {
            text = true;
        } else if (c == "-seed") {
            string l = argv[pos++];
            istringstream ll(l);
            ll>>seed;
        } else if (c == "-scriptfile") {
            file = argv[pos++];
        } else if (c == "-startlevel") {
            string l = argv[pos++];
            istringstream ll(l);
            ll>>start_level;
        }
    }
    string s;
    Grid grid;
    cout<<"Enter \"start\" to start a game"<<endl;
    while(1) {
        cin>>s;
        if (s=="start"){
            cout << endl;
            grid.init(text,start_level,seed,file);
            cout << grid << endl;
            break;
        } else {
            cout<<"Enter \"start\" to start a game"<<endl;
        }
    }
    while(cin>>s) {
         if (s== "restart"){
            cout << endl;
            grid.clear();
            grid.init(text,start_level,seed,file);
            cout << grid << endl;
        } else if (s =="random") {
            grid.dorandom();
        } else if (s =="nonrandom") {
            string file;
            cin>>file;
            grid.norandom(file);   
        } else if (s =="levelup") {
            grid.level_up();
            cout << grid << endl;
        } else if (s =="leveldown") {
            grid.level_down();
            cout << grid << endl;
        } else if (s == "hint") {
            grid.hint();
            cout<<"GOOD LUCK!"<<endl;
        } else if (s =="sequence") {
            ifstream infile;
            cin>>s;
            infile.open(s);
            if (!infile) {
                cout << "Unable to open file";
            } else {
                while(infile>>s) {
                    play(grid, s);
                    
                    cout << grid << endl;
                    if (grid.isFull()) {
                        cout<<"game over"<<endl;
                        cout<<"Enter \"restart\" to start a game or \"exit\""<<endl;
                    }
                }
            }
        } else if ((s == "I") || (s == "J")||(s == "L")||(s == "O")
                   ||(s == "T")||(s == "S")||(s == "Z")) {
            
            grid.set_block(s.front());
            cout << grid << endl;
        } else if (s=="exit"){
            break;
        } else {
            if (play(grid, s) == false) {
                cout<<"invalid command"<<endl;
            } else{
                if (grid.getlevel() >= 3) grid.modify_bolck("down");
            }
            cout << grid << endl;
            if (grid.isFull()) {
                cout<<"game over"<<endl;
                cout<<"Enter \"restart\" to start a game or \"exit\""<<endl;
            }
        }
    }
}
