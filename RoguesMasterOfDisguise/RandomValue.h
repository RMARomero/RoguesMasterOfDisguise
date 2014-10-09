#pragma once


// Declaration
class RandomValue {
public:
	static RandomValue* getInstance();
	int getRandom(int min, int max);
	~RandomValue();
private:
	RandomValue();
	static RandomValue* _instance;
};