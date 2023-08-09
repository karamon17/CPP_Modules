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
       res += line;
    }
	if (res.empty()) {
		std::cerr << "File is empty." << std::endl;
		exit(1);
	}
    inputFile.close();
	this->file_content = res;

};

replaser::~replaser()
{

};

void replaser::replace(void) {
	size_t pos;
	pos = file_content.find(s1);
	while (pos != std::string::npos) {
		file_content = file_content.substr(0, pos) + s2 + file_content.substr(pos + s1.length());
		pos = file_content.find(s1);
	}
}

void replaser::create_new_file(void) {
	std::string filename = this->filename + ".replace";
	std::ofstream outputFile(filename);
	if (outputFile.is_open()) {
        outputFile << file_content;
        outputFile.close();
    } else {
        std::cerr << "Unable to open the file." << std::endl;
		exit(1);
    }
}

int validation(std::string filename)
{
	std::ifstream inputFile(filename);
	if (!inputFile.is_open()) {
		std::cerr << "Unable to open the file." << std::endl;
		exit(1);
    }
	inputFile.close();
	return 0;
}