#ifndef INTERP_H
#define INTERP_H
#include <iostream>
#include <string>
#include <curses.h>
#include <vector>

#include <chrono>
#include <thread>

class Interpreter {
public:
	char mem[300] = {0};

	char data_pointer = 0;

	std::string source;

	void load(std::string program);
	void load_file(std::string path);
	void run();
private:

	char current = 0;
};

#endif