#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef map<char, int> letterMap;

typedef map<string, int> WordMap;

typedef set<string> setValue;

void createLetterMap(letterMap& letter_map)
{
  int i;
  char letter;  
  int letterValue[26] = {1, 3, 3, 2, 1, 4, 2, 4, 2, 8, 
    5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

  for(i = 0; i < 26; i++) // create LetterMap
  {
    letter = i + 'a';
    letter_map.insert(pair<char, int>(letter, letterValue[i]));
  } // for loop

} // createLetterMap()

int scrabbleValue(string word, letterMap& letter_map)
{  
  int total = 0;
  int temp;
  string::iterator itr;

  for(itr = word.begin(); itr < word.end(); itr++)
  {
    temp = letter_map.find(*itr)->second;
    total += temp;
  } // for loop

  return total;
} // scrabbleValue()

void createWordMap(WordMap& word_map, letterMap& letter_map)
{
  int wordValue;
  string word;
  ifstream inf;
  inf.open("words.txt");

  while(! inf.eof())
  {
    getline(inf, word);
     
    wordValue = scrabbleValue(word, letter_map);
    word_map.insert(pair<string, int> (word, wordValue));
  } // while loop 

  inf.close();
} // createWordMap()

int insWords(int maxVal, string subWord, WordMap& word_map, setValue& set_value)
{
  WordMap::iterator it;

  if((it = word_map.find(subWord)) != word_map.end())
  {

    if(it->second > maxVal)
    {

       while(!set_value.empty())
         set_value.erase(set_value.begin());
       set_value.insert(subWord);
       maxVal = it->second;
     } // if statement to replace max value and its related strings
      else // else statement 
        if (it->second == maxVal) // if its equal
          set_value.insert(subWord);
    
  } // if statement

  return maxVal;
} // insertWords()


int insSpace(int maxVal, string subWord, WordMap& word_map, 
             setValue& set_value, int temp)
{
  WordMap::iterator it;
  int number;

  if((it = word_map.find(subWord)) != word_map.end())
  {
    number = it->second - temp;

    if(number > maxVal)
    {

       while(!set_value.empty())
         set_value.erase(set_value.begin());
       set_value.insert(subWord);
       maxVal = number;
     } // if statement to replace max value and its related strings
      else // else statement 
        if (number == maxVal) // if its equal
          set_value.insert(subWord);

  } // if statement

  return maxVal;
} // insSpace()


void printWords(int maxVal, string wordcpy, setValue& set_value)
{
  set<string>::iterator iter;

  if (maxVal > 9)
    cout << maxVal << ' ' << wordcpy << ":";
  else // done
    cout << ' ' << maxVal << ' ' << wordcpy << ":";

  if(set_value.size())
  {

    for(iter = set_value.begin(); iter != set_value.end(); ++iter)
      cout << ' ' << (*iter);
  }//if statement for printing 
  else // did not find anything
    cout << " No words found.";
  cout << endl;

} // printWords()

void findWords(string word, WordMap& word_map)
{
  int i, n, maxVal = 0;
  setValue set_value;
  string subWord, wordcpy;
  wordcpy = word;

  for(n = 0; n < 6000; n++)
  {

   for(i = 0; (unsigned)i <= word.size(); i++)
   {     
     subWord = word.substr(0, i);
   
     if(subWord.compare("\0"))
       maxVal = insWords(maxVal, subWord, word_map, set_value);
   } // for loop
  
  next_permutation(word.begin(), word.end());

  } // for loop

  printWords(maxVal, wordcpy, set_value);

  while(! set_value.empty())
    set_value.erase(set_value.begin());

} // findWords()


void findSpace(string word, WordMap& word_map, letterMap& letter_map)
{
  int i, n, j, temp, maxVal = 0;
  char letter;
  setValue set_value;
  string subWord, wordcpy = word;
  letterMap::iterator it;

  for(j = 0; j < 26; j++)
  {
    letter = j + 'a';
    replace(word.begin(), word.end(), ' ', letter);
    it = letter_map.find(letter);
    temp = it->second;

    for(n = 0; n < 6000; n++)
    {

      for(i = 0; (unsigned)i <= word.size(); i++)
      {
        subWord = word.substr(0, i);     

        if(subWord.compare("\0"))
          maxVal = insSpace(maxVal, subWord, word_map, set_value, temp);       
      } // for loop
      
     next_permutation(word.begin(), word.end());
    } // for loop

   word = wordcpy;
  } //for loop

  printWords(maxVal, wordcpy, set_value);

  while(! set_value.empty())
    set_value.erase(set_value.begin()); 
} //findSpace()

void readWords(char** argv, WordMap& word_map, letterMap& letter_map)
{
  ifstream inf;
  inf.open(*(argv + 1));
  string word;
   
  while(! inf.eof())
  {
    getline(inf, word);

    if(inf.eof())
      break;


   if(word.find(' ') != string::npos)
     findSpace(word, word_map, letter_map);
   
   else // else
    findWords(word, word_map);
  } // while loop
    
  inf.close();
} // readWords()

int main(int argc, char** argv)
{
  letterMap letter_map;
  createLetterMap(letter_map);

  WordMap word_map;
  createWordMap(word_map, letter_map);

  readWords(argv, word_map, letter_map);

  return 1;
} // main()



