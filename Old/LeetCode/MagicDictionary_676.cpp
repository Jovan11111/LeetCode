#include "string"
#include "vector"

class MagicDictionary {
public:
    MagicDictionary() {}

    void buildDict(std::vector<std::string> dictionary) {
        for(int i = 0; i < dictionary.size();i++) words.push_back(dictionary[i]);
    }

    bool search(std::string searchWord) {
        for(int i = 0; i <words.size();i++){
            if(searchWord.size() != words[i].size()) continue;
            bool oneChar = false;
            bool secChar = false;
            for(int j = 0; j < searchWord.size();j++){
                if(searchWord[j] != words[i][j] and oneChar) secChar = true;
                if(searchWord[j] != words[i][j]) oneChar = true;
            }
            if(oneChar and !secChar) return true;
        }
        return false;
    }

private:
    std::vector<std::string> words;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */