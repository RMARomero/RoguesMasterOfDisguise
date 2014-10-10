#include "stdafx.h"
#include "RandomValue.h"
#include <cstdlib>
#include <ctime>
#include <random>


using namespace std;

// Implementation 
RandomValue* RandomValue::_instance = nullptr;

RandomValue::RandomValue(){
	srand((unsigned int)time(NULL));
}

RandomValue* 
RandomValue::getInstance() {
	if (_instance == nullptr) {
		_instance = new RandomValue;
	}
	return _instance;
}

int 
RandomValue::getRandom(int min, int max){
	return (rand() % max) + min;
}

RandomValue::~RandomValue(){
	//delete _instance;
}