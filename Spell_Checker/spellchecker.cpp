
#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using std::string;
using std::ifstream;
using std::regex;
using std::smatch;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::cout;
using std::endl;

struct word {
    string text;
    int line;
    int column;
};

bool read_words(const string input_file_name, vector<word>& words)
{
    ifstream input_file(input_file_name);
    if (input_file.fail()) {
        return false;
    }
    regex reg_exp("[a-zA-Z]+");
    smatch match;
    string text;
    int line = 0;
    int column = 0;
    while (std::getline(input_file, text)) {
        ++line;
        column = 1;
        while (std::regex_search(text, match, reg_exp)) {
            column += match.position();
            words.push_back({match.str(), line, column});
            column += match.length();
            text = match.suffix().str();
        }
    }
    return true;
}

vector<string> validWords(){

    vector<string> dict;
    ifstream wordsFile("words.txt");
        if (wordsFile.is_open()) {
        string word;
        while (std::getline(wordsFile, word)) {
            dict.push_back(word);
        }

        wordsFile.close();
    } else {
        std::cerr << "Unable to open words.txt\n";
    }
    return dict;

}

/*
void misspelled(const string& word, const vector<string>& dictWords){ //word is the text to check if it's mispelled
    //implementing a hash map and dictionary to store soundexCode words in his code Key example M536600 = Mantarraya, Monterrey
    //this for track the words and their soundexCode
    unordered_map<string, vector<string>> word_soundexCode;

    unordered_set<string> notRepet;

    for (auto newDict: dictWords){
        nes= soundex(newDict);
        notRepet.push_back(nes);
    }


}

*/

string soundex(string word){
    // Save the first letter
    string save_first_letter = word.substr(0, 1);
    // Convertir todas las letras a minúsculas
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);

    // Drop vowels and replace consonants
    word.erase(0, 1); // Remove the first letter
    word.erase(std::remove_if(word.begin(), word.end(), [](char c) { 
        return c == 'h' || c == 'w' || c == 'y' || c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'; 
    }), word.end());

    // Replace consonants
    for(char& c : word){
        if(c == 'b' || c == 'f' || c == 'p' || c == 'v'){
            c = '1';
        }
        else if(c == 'c' || c == 'g' || c == 'j' || c == 'k' || c == 'q' || c == 's' || c == 'x' || c == 'z'){
            c = '2';
        }
        else if(c == 'd' || c == 't'){
            c = '3';
        }else if (c == 'l') {
            c = '4';
        } else if (c == 'm' || c == 'n') {
            c = '5';
        } else if (c == 'r') {
            c = '6';
        }
    }

    // Ensure the length is 7
    while(word.length() < 6){
        word += '0';
    }

    // Truncate if the length exceeds 7
    if(word.length() > 6){
        word = word.substr(0, 6);
    }

    // Concatenate the saved first letter
    word = save_first_letter + word;

    return word;
}



int main(int argc, char* argv[]) {
    string word = "Monterrey";
    std::cout << "Original word: " << word << std::endl;
    std::cout << "Soundex code: " << soundex(word) << std::endl;

    return 0; // Devolver 0 para el éxito
};
