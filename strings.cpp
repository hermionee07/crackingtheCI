#include "strings.h"

#include <string>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
#include <unordered_set>
#include <cstring>

using namespace std;

bool IsUnique(const std::string& str)
{
    if (str.length() > 128) // Ascii 128 character.
        return false;
    bool chars[128] = {false};
    for (const char& c: str)
    {
        if (!chars[c])
        {
            chars[c] = true;
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool IsUniqueNoBuffer(const std::string &str)
{
    unsigned int buffer = 0;
    if (str.length() > 128)
        return false;
    for (const char& a: str)
    {
        unsigned int temp = 1 << (a - 97);
        unsigned int andResult = temp & buffer;
        if (andResult != temp) // not set
        {
            buffer = buffer | temp;
            continue;
        }
        else
            return false;
    }
    return true;
}

void stringReverse(char* str)
{  // to do it in place
    char* ptr = str;
    int length = 0;
    while(*ptr != '\0')
    {
        ptr++;
        length++;
    }
    for (int i = 0, j = length-1; i < length/2;)
    {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

bool areAnagrams( string str1, string str2)
{  // uses std::sort
    if (str1.length() != str2.length())
        return false;
    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());
    if (str1.compare(str2) == 0)
        return true;
    return false;
}

bool areAnagramsWithoutSort(const string& str1, const string& str2)
{
    if (str1.length() != str2.length())
        return false;
    map<char, int> charCountMap;
    for (const char&a : str1)
    {
        charCountMap[a] = charCountMap[a] + 1;
    }
    for (const char& a: str2)
    {
         charCountMap[a] = charCountMap[a] - 1;
         if (charCountMap[a] < 0)
            return false;
    }
    /*map<char,int>::const_iterator itr = charCountMap.begin();
    while (itr != charCountMap.end())
    {
        if (itr->second != 0)
            return false;
        itr++;
    }*/
    return true;
}


bool isCyclicSubstring(const string& str1, const string& str2)
{ // we can use substr to find this.
    string cStr1 = str1;
    string cStr2 = str2;
    if (str1.length() != str2.length())
        return false;
    string temp = "";
    for (const char& a: str2)
    {
        temp = temp + a;
        if (strstr(cStr1.c_str(), temp.c_str()) == NULL)
        {
            break;
        }
    }
    string partString = cStr2.erase(0, temp.length());
    if (strstr(str1.c_str(), partString.c_str()) == NULL)
        return false;
    else
        return true;
}

void URLify(char* str)
{ // do it inplace and think there is sufficient space at the end
    char* ptr = str;
    int length = 0, noOfSpaces = 0;
    while (*ptr != '\0')
    {
        length++;
        if (*ptr == ' ')
            noOfSpaces++;
        ptr++;
    }
    int finalLength = length + 2 * noOfSpaces;
    str[finalLength] = '\0';
    for (int i = 1, j = 1; i <= finalLength;)
    {
        if (str[length-j] == ' ')
        {
            str[finalLength-i] = '0';
            str[finalLength-i-1] = '2';
            str[finalLength-i-2] = '%';
            i+=3;
            j++;
        }
        else
        {
            str[finalLength-i] = str[length-j];
            j++;
            i++;
        }
    }
}

