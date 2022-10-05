#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>


struct word_info_s
{
    std::string         word;
    unsigned int        sentence;
    std::vector<int>    freq;
};


class wordList
{
private:
    /* data */
    std::vector<word_info_s> word_info_vec;
    int current_sentence = 1;
    int total_sentence = 1;

public:
    bool check_word(std::string &word);
    void insert(std::string &word);
    void erase_punc(std::string &word);
    void make_lower(std::string &word);
    void update_list(std::string &word);
    void count_sentence(char last_ch);
    void print();
};
