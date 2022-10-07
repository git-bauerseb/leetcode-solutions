#include <bits/stdc++.h>

using namespace std;

class Encrypter {
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        m_keys = keys;
        m_values = values;
        m_dictionary = dictionary;
    }
    
    string encrypt(string word1) {
        string s;

        for(auto& c : word1) {
            int i = search_keys(c);
            s += m_values[i];
        }

        return s;
    }
    
    int decrypt(string word2) {
        for (int i = 0; i < word2.size(); i += 2) {
            search_values
        }


        return 0;
    }

private:
    vector<char> m_keys;
    vector<string> m_values;
    vector<string> m_dictionary;

    vector<int> m_indices;

    void search_values(std::string_view s) {
        int l = 0;
        int r = m_values.size()-1;

        while (l < r) {
            if (m_values[l] == s) {m_indices.push_back(l);}
            if (m_values[r] == s) {m_indices.push_back(r);}

            l++;
            r--;
        }
    }

    int search_keys(char c) {
        int l = 0;
        int r = m_keys.size()-1;

        while (l < r) {
            if (m_keys[l] == c) {return l;}
            if (m_keys[r] == c) {return r;}

            l++;
            r--;
        }

        return l;
    }
};

int main(int argc, char** argv) {

    vector<char> keys{'a', 'b', 'c', 'd'};
    vector<string> values{"ei", "zf", "ei", "am"};
    vector<string> dictionary{"abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"};

    Encrypter encrypter(keys, values, dictionary);
    string encr = encrypter.encrypt("abcd");

    cout << encr << "\n";
    cout << encrypter.decrypt(encr) << "\n";

    return 0;
}