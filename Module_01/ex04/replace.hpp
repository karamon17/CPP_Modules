#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>

class replaser
{
	private:
		std::string filename;
		std::string s1;
		std::string s2;
		std::string file_content;
	public:
		replaser(std::string filename, std::string s1, std::string s2);
		~replaser();

		void replace(void);
		void create_new_file(void);
};
	int validation(std::string filename);

#endif