#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <memory>
#include "wordList.h"

void read_file(wordList &wordList){
    std::fstream file;
    std::string word;

    file.open("example/test.txt", std::ios::in);

    while (file >> word)
    {
        wordList.update_list(word);
    }

    wordList.print();

    file.close();
}

int main(void){
    wordList wordList;
    
    read_file(wordList);

    return 0;
}
