#ifndef __STRING_UTIL_H__
#define __STRING_UTIL_H__

#include <string>
#include <vector>
#include <algorithm>
#include <utility>

class StringUtil 
{
  public:
  static std::vector<std::string> split(const std::string& s, char delim)
  {
    std::vector<std::string> list;
    size_t start_index = 0;
    size_t delim_index = s.find(delim);
    while(delim_index != std::string::npos)
    {
      list.emplace_back(s.substr(start_index, delim_index - start_index));
      start_index = delim_index + 1;
      delim_index = s.find(delim, start_index);
    }
    list.emplace_back(s.substr(start_index));

    return list;
  }

  static std::pair<std::string, std::string> get_pair(const std::string& s, char delim)
  {
    size_t delim_index = s.find(delim);
    std::string first, second;
    if(delim_index != std::string::npos)
    {
      first = s.substr(0, delim_index);
      second = s.substr(delim_index+1);
    }
    else
    {
      first = s;
      second = "";
    }
    trim(first);
    trim(second);
    return std::make_pair(first, second);
  }

  static void ltrim(std::string& s)
  {
    s.erase(s.begin(), std::find_if(s.begin(), s.end(), 
          [](char c){ return !std::isspace(c); }));
  }

  static void rtrim(std::string& s)
  {
    s.erase(std::find_if(s.rbegin(), s.rend(), 
          [](char c){ return !std::isspace(c); }).base(), s.end());
  }

  static void trim(std::string& s)
  {
    ltrim(s);
    rtrim(s);
  }

};
#endif //__STRING_UTIL_H__
