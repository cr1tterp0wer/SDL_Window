#include<iostream>
#include "MyGame.h"

using namespace std;

int main(int argc, char** argv){

	cout << "**************" << endl;
	cout << "*WINDOW__OPEN*" << endl;
	cout << "**************" << endl;
	cout << endl;

	if( argc > 1){
  	MyGame g(stoi(argv[1]), stoi(argv[2]));
  	g.start();
	} else {
  	MyGame g;
  	g.start();
	}

  return 0;
}

