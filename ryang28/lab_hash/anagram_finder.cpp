/**
 * @file anagram_finder.cpp
 * Implementation of the AnagramFinder class.
 *
 * @author Chase Geigle
 * @date Spring 2011
 * @date Summer 2012
 */

#include "anagram_finder.h"

using std::string;
using std::vector;
using std::ofstream;
using std::endl;

/**
 * Constructs an AnagramFinder based on a filename to read potential
 * anagrams from.
 *
 * @param ifilename The name of the file to read in.
 */
template <template <class K, class V> class Dict>
AnagramFinder<Dict>::AnagramFinder(const string& ifilename)
    : file(true), filename(ifilename)
{
    /* nothing */
}

/**
 * Constructs an AnagramFinder based on a set of strings instead of a
 * filename.
 *
 * @param istrings The set of strings to use for this finder.
 */
template <template <class K, class V> class Dict>
AnagramFinder<Dict>::AnagramFinder(const vector<string>& istrings)
    : file(false), strings(istrings)
{
    /* nothing */
}

/**
 * Determines if the given word is an anagram of the test word.
 *
 * @param word Word that is possibly an anagram.
 * @param test Word to check against.
 * @return A boolean value indicating whether word is an anagram of test.
 */
template <template <class K, class V> class Dict>
bool AnagramFinder<Dict>::checkWord(const string& word, const string& test)
{
    /**
     * @todo Implement this function! You should use the provided
     * templated hashtable class Dict.
     */
    if (word.length() != test.length())
        return false;

    int length = word.length();

    Dict<char, int>wordHash(length);
    for(unsigned long i = 0; i < word.length(); i++)
    {
        wordHash[word[i]]++;
    }
    Dict<char, int>testHash(length);
    for (unsigned long i = 0; i < test.length(); i++)
    {
        testHash[test[i]]++;
    }
   
    for (int i = 0; i < length; i++)
    {
        if (testHash.find(word[i]) != wordHash.find(word[i]))
            return false;
    }
    return true;
    // if(word.length() != test.length())
    //     return false;

    // Dict<char, int> wordTable(256); 
    // Dict<char, int> testTable(256);
    // for(size_t i=0; i< word.length(); i++){
    //     wordTable[word[i]]++;
    // }
    //  for(size_t i=0; i< test.length(); i++){
    //     testTable[test[i]]++;
    // }
    
    // for(int i=0; i<256; i++){
    //     if(wordTable[i] != testTable[i])
    //         return false;
    // }
    // // vector<int> wordVector;
    // // vector<int> testVector;

    // // typename Dict<char, int>::iterator it;
    // // for (it = wordTable.begin(); it != wordTable.end(); it++){
    // //     wordVector.push_back(it->second);
    // // }
    // // for(it = testTable.begin(); it!= wordTable.end(); it++){
    // //     testVector.push_back(it->second);
    // // }
    // // for(unsigned long i=0; i< wordVector.size(); i++){
    // //     if(wordVector[i] != testVector[i])
    // //         return false;
    // // }
    // //(void) word; // prevent warnings... When you implement this function, remove this line.
    // //(void) test; // prevent warnings... When you implement this function, remove this line.
    // return true;
}

/**
 * Retrieves a set of words that are anagrams of a given word.
 *
 * @param word The word we wish to find anagrams of inside the finder.
 */
template <template <class K, class V> class Dict>
vector<string> AnagramFinder<Dict>::getAnagrams(const string& word)
{
    // set up the return vector
    vector<string> ret;

    if (file) {
        TextFile infile(filename);
        string line;
        vector<string> tests;
        while (infile.good()) {
            string test = infile.getNextWord();
            if (checkWord(word, test))
                ret.push_back(test);
        }
    } else {
        for (size_t i = 0; i < strings.size(); i++) {
            if (checkWord(word, strings[i]))
                ret.push_back(strings[i]);
        }
    }
    return ret;
}

/**
 * Retrieves a set of anagrams in the finder of a given words, but writes
 * them out to a file instead of returning a vector.
 *
 * @param word The word we wish to find anagrams of inside the finder.
 * @param output_file The name of the file we want to write to.
 */
template <template <class K, class V> class Dict>
void AnagramFinder<Dict>::writeAnagrams(const string& word,
                                        const string& output_file)
{
    vector<string> anagrams = getAnagrams(word);
    ofstream outfile(output_file.c_str());
    if (outfile.is_open()) {
        for (size_t i = 0; i < anagrams.size(); i++)
            outfile << anagrams[i] << endl;
    }
    outfile.close();
}
