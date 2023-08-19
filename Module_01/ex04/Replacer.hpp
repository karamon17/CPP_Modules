#ifndef REPLACER_HPP
#define REPLACER_HPP

#include <iostream>
#include <fstream>

class Replacer
{
	private:
		std::string filename;
		std::string s1;
		std::string s2;
		std::string file_content;
	public:
		Replacer(std::string filename, std::string s1, std::string s2);
		~Replacer();

		void replace(void);
		void create_new_file(void);
};

#endif