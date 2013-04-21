#include "FileUtils.h"

DirMap_t getDirMap(std::string dir) 
{
	fs::path someDir(dir);
	fs::directory_iterator end_iter;
	DirMap_t result_set;
	if ( fs::exists(someDir) && fs::is_directory(someDir))
	{
		for( fs::directory_iterator dir_iter(someDir) ; dir_iter != end_iter ; ++dir_iter)
		{
			if (fs::is_regular_file(dir_iter->status()))
			{
				result_set.insert(DirMap_t::value_type(fs::last_write_time(dir_iter->path()), dir_iter->path())); 
			}
		}
	}
	return result_set;
}