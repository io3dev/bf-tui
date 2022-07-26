#include "interpreter.hpp"

#define DISPLAY_OFFSET 6

int output_chars = 0;

void Interpreter::load(std::string program) {
	// std::cout << program << std::endl;
	this->source = program;
}

void Interpreter::run() {
	this->current = 0;
	this->data_pointer = 0;
	// std::cout << this->source;

	std::vector<char> brackets;

	initscr();
	clear();
	curs_set(0);
	
	noecho();
	refresh();
	
	mvprintw(10, DISPLAY_OFFSET, this->source.c_str());


	// while ( (long unsigned int) this->current != this->source.length()) {
	while (true) {


		char cur_c = this->source[this->current];

		switch ( cur_c ) {
			case '-':
				this->mem[this->data_pointer]--;
				break;
			case '+':
				this->mem[this->data_pointer]++;
				break;

			case '>':
				this->data_pointer++;
				break;
			case '<':
				this->data_pointer--;
				break;

			case ',':
				// Todo: Inputt
				break;

			case '.':
				mvprintw(6, 10, "OUT: ");
				// mvprintw(6, 17 + output_chars, "%d", this->mem[this->data_pointer]);
				mvprintw(6, 17 + output_chars, &this->mem[this->data_pointer]);
				output_chars++;
				refresh();
				break;

			case '[':
				
				brackets.push_back(this->current);
				if (this->mem[this->data_pointer] == 0) {
					int i = 0;
					while (this->source[i + this->current] != ']') {
						i++;
					}
					

					this->current = i;
				}
				break;
			case ']':
				if ( this->mem[this->data_pointer] != 0 ) {
					int i = this->source.length();

					this->current = brackets.back();
					// mvprintw(2, 5, "%d", brackets.back());
				}
				break;


		}

		// Print memory array
		mvprintw(17, 1, "MEM ");
		for (int i = 0; i < sizeof(this->mem); i++) {
			printw("%d ", this->mem[i]);
		}

		mvprintw(11, this->current + DISPLAY_OFFSET, "^");
		refresh();

		
		std::this_thread::sleep_for(std::chrono::milliseconds(20));

		if (this->current != this->source.length()) {
			this->current++;
		}

		mvprintw(11, this->current + DISPLAY_OFFSET - 1, " ");
		refresh();
	}

	endwin();
}

void Interpreter::load_file(std::string path) {

}