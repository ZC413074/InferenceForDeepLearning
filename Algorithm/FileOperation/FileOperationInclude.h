#ifndef FILE_OPERATION_INCLUDE
#define FILE_OPERATION_INCLUDE
#include"./../DataDefine.h"

namespace Algorithm
{
	/// with check
	bool ALGORITHM_API getAllFormatFiles(const std::string& path, const std::string& format, std::vector<std::string>& files);

	void ALGORITHM_API getFormatFiles(const std::string path, const  std::string format, std::vector<std::string>& files);

	std::vector<std::string> ALGORITHM_API splitString(const std::string str, const std::string& pattern = " ");

	std::string ALGORITHM_API timeStamp();

	std::string ALGORITHM_API mkdirDebugPath();

	std::string ALGORITHM_API mkdirDebugPath(const std::string& file_name);
}

#endif