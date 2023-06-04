#include "textdisplay.hpp"
#include "subject.hpp"

using namespace std;
TextDisplay::TextDisplay(vector<vector<char>>&board):board(board)
{}
void TextDisplay::notify(Subject &whoFrom){
    cout << "ss" << endl;
	State state = whoFrom.getState();
	level = state.level;
	score = state.score;
	hscore = state.hscore;
	nextType = state.nextType;
}

std::ostream &operator<<(std::ostream &out, const TextDisplay &td){
	out<<"Level:     "<<td.level<<endl;
	out<<"Score:     "<<td.score<<endl;
	out<<"Hi Score:  "<<td.hscore<<endl;
	out<<"-----------"<<endl;
	for (int i = 17; i >= 0; i --){
        for (int k = 0; k < 11; k ++){
            if (td.board[k][i] == 'S' || td.board[k][i] == 'L' || td.board[k][i] == 'O'||
                td.board[k][i] == 'T' || td.board[k][i] == 'Z' || td.board[k][i] == 'J'
                || td.board[k][i] == 'I' || td.board[k][i] == '?'){
                out << td.board[k][i];
            }
            else out << ' ';
        }
        out << std::endl;
    }	
	out<<"-----------"<<endl;
	out<<"Next:"<<endl;
	switch(td.nextType){
		case 'I':
			out<<"IIII"<<endl;
			break;
		case 'J':
			out<<"J"<<endl;
			out<<"JJJ"<<endl;
			break;
		case 'L':
			out<<"  L"<<endl;
			out<<"LLL"<<endl;
			break;
		case 'O':
			out<<"OO"<<endl;
			out<<"OO"<<endl;
			break;
		case 'S':
			out<<" SS"<<endl;
			out<<"SS"<<endl;
			break;
		case 'Z':
			out<<"ZZ"<<endl;
			out<<" ZZ"<<endl;
			break;
		case 'T':
			out<<"TTT "<<endl;
			out<<" T"<<endl;
			break;
	}
	return out;
}
