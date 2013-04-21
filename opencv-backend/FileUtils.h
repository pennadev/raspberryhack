#ifndef _FILE_UTIL_H_
#define _FILE_UTIL_H_
#include <boost/filesystem.hpp>
#include <map>

namespace fs = boost::filesystem;

typedef std::map<std::time_t, fs::path> DirMap_t;
typedef std::map<std::time_t, fs::path>::iterator	DirMap_iter;
DirMap_t getDirMap(std::string dir);

#endif