#include "replace.hpp"

replaser::replaser(std::string filename, std::string s1, std::string s2)
{
	this->filename = filename;
	this->s1 = s1;
	this->s2 = s2;
	std::ifstream inputFile(filename);
    std::string line;
	std::string res;
    while (std::getline(inputFile, line)) {
       res += line;;
    }
    inputFile.close();
	this->file_content = res;

};

replaser::~replaser()
{

};

void replace(void) {
	
	}
void create_new_file(void) {

	}

int validation(std::string filename)
{
	std::ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		std::cout << "Не удалось открыть файл." << std::endl;
		return 1;
    }
	inputFile.close();
	return 0;
}