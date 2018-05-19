/**
 * @file anagram_dict.cpp
 * Implementation of the AnagramDict class.
 *
 * @author Matt Joras
 * @date Winter 2013
 */

#include "anagram_dict.h"

#include <algorithm> /* I wonder why this is included... */
#include <fstream>
#include <map>
#include <vector>

using std::string;
using std::vector;
using std::ifstream;
using std::sort;

/**
 * Constructs an AnagramDict from a filename with newline-separated
 * words.
 * @param filename The name of the word list file.
 */
AnagramDict::AnagramDict(const string& filename)
{
    /* Your code goes here! */
	vector<string> words;
	ifstream wordsFile(filename);
	string word;
	if (wordsFile.is_open()) {
    	/* Reads a line from `wordsFile` into `word` until the file ends. */
    		while (getline(wordsFile, word)) {
        		words.push_back(word);
    		}
	}
	for(auto& wordItem : words){
		auto lookup = dict.find(wordItem);
		if(lookup == dict.end()){
			vector<char> rearrange;
			for(unsigned long i=0; i< wordItem.length(); i++)			
				rearrange.push_back(wordItem.at(i));

			sort(rearrange.begin(), rearrange.end());
			dict.insert(std::pair<string, std::vector<char>>(wordItem, rearrange));
		}
	}

}

/**
 * Constructs an AnagramDict from a vector of words.
 * @param words The vector of strings to be used as source words.
 */
AnagramDict::AnagramDict(const vector<string>& words)
{
    /* Your code goes here! */
	for(auto& wordItem : words){
		auto lookup = dict.find(wordItem);
		if(lookup == dict.end()){
			vector<char> rearrange;
			for(unsigned long i=0; i< wordItem.length(); i++)			
				rearrange.push_back(wordItem.at(i));

			sort(rearrange.begin(), rearrange.end());
			dict.insert(std::pair<string, std::vector<char>>(wordItem, rearrange));
		}
	}

}

/**
 * @param word The word to find anagrams of.
 * @return A vector of strings of anagrams of the given word. Empty
 * vector returned if no anagrams are found or the word is not in the
 * word list.
 */
vector<string> AnagramDict::get_anagrams(const string& word) const
{
    /* Your code goes here! */
	vector<string> answer;
	auto lookup = dict.find(word);
	if(lookup != dict.end()){
		vector<char> value = lookup->second;
		for(auto& dictItem:dict){
			if(dictItem.second == value)
				answer.push_back(dictItem.first);		
		}
	}
	if(answer.size() > 1)
		return answer;

	else
    		return vector<string>();
}

/**
 * @return A vector of vectors of strings. Each inner vector contains
 * the "anagram siblings", i.e. words that are anagrams of one another.
 * NOTE: It is impossible to have one of these vectors have less than
 * two elements, i.e. words with no anagrams are ommitted.
 */
vector<vector<string>> AnagramDict::get_all_anagrams() const
{
    /* Your code goes here! */
	vector<vector<string>> allAnagrams;
	for(auto& dictItem : dict){
		string key = dictItem.first;
		vector<string> answer = get_anagrams(key);	
		if(answer.size() >1)
			allAnagrams.push_back(answer);
	}

    return allAnagrams;
}
