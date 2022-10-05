
#include "wordList.h"

static std::vector<std::string> exception_words = {"etc.", "i.e."};

bool wordList::check_word(std::string &word){
    auto iter = std::find_if(word_info_vec.begin(), word_info_vec.end(), 
               [&](const word_info_s& ws){return ws.word == word;});

    if(iter != word_info_vec.end()){
        iter->sentence++;
        iter->freq.push_back(current_sentence);
    }

    return iter != word_info_vec.end();
}

void wordList::insert(std::string &word){
    word_info_s word_info;
    auto i = 0;

    word_info.sentence = 1;        
    word_info.freq.push_back(current_sentence);
    word_info.word = word;

    if(word_info_vec.empty())
        word_info_vec.push_back(word_info);
    else{
        for(auto wi : word_info_vec){
            if((word < wi.word)){
                word_info_vec.insert(word_info_vec.begin() + i, word_info);
                return;
            }
            i++;
        }
        word_info_vec.push_back(word_info);
    }
}

void wordList::erase_punc(std::string &word){
    auto last_ch = word.back();

    if (std::find(exception_words.begin(), exception_words.end(), word) != exception_words.end())
        return;

    if(last_ch =='.' || last_ch == '?' || last_ch == '!')
        total_sentence++;  

    if(ispunct(last_ch))
        word.pop_back();
}

void wordList::make_lower(std::string &word){
    std::transform(word.begin(), word.end(), word.begin(),
            [](unsigned char c){ return std::tolower(c); });
}

void wordList::update_list(std::string &word){
    erase_punc(word);
    make_lower(word);

    if(!check_word(word))
        insert(word);

    current_sentence = total_sentence;
}

void wordList::print(){
    for(auto wi : word_info_vec){
        std::cout << std::setw(20) << wi.word << std::setw(20) << "{" << wi.sentence << ":";
        std::cout << wi.freq[0];
        for(auto i=1; i<wi.freq.size(); ++i)
            std::cout << "," << wi.freq[i];
        std::cout << "}" << "\n";
    }
}