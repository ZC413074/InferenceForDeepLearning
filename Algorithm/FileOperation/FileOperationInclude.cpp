#include"FileOperationInclude.h"
#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#ifdef _MSC_VER
	#include<io.h>
	#include<direct.h> // it is a c/C++ header file provided by Microsoft Windows, so ti cannot works in linux
#endif
#ifdef __GNUC__
	#include <unistd.h>
	#include <sys/types.h>
	#include <sys/stat.h>
#endif
namespace Algorithm
{
	//void str_tok(char *str) //分离文件目录
	//{
	//	char *p = NULL;
	//	char delims[] = "\\";
	//	p = strtok(str, delims);
	//	while (p != NULL)
	//	{
	//		strcpy(result, p);
	//		p = strtok(NULL, delims);
	//	};
	//}
	bool getExtension(char* full_path, const  std::string format)
	{
		std::string str(full_path);
		std::string suffix_str = str.substr(str.find_last_of('.') + 1);
		return format == suffix_str ? true : false;
	}

	void getFormatFiles(const std::string path, const  std::string format, std::vector<std::string>& files)
	{
		if (files.size() < 1)
			files.reserve(5000);
		long long hFile = 0;
		struct _finddata_t fileinfo;
		std::string p;
		if ((hFile = _findfirst(p.assign(path).append("/*.*").c_str(), &fileinfo)) != -1)
		{
			do
			{
				if (strcmp(fileinfo.name, ".") == 0 || strcmp(fileinfo.name, "..") == 0)
					continue;
				else if ((fileinfo.attrib & _A_SUBDIR))
				{
					getFormatFiles(p.assign(path).append("/").append(fileinfo.name), format, files);
				}
				else
				{
					if (!getExtension(fileinfo.name, format))
						continue;
					files.push_back(p.assign(path).append("/").append(fileinfo.name));
				}
			} while (_findnext(hFile, &fileinfo) == 0);
			_findclose(hFile);
		}
		files.shrink_to_fit();
	}

	bool getAllFormatFiles(const std::string& path, const std::string& format, std::vector<std::string>& files)
	{
		bool ret = false;

		if (0 != access(path.c_str(), 0))
		{
			std::cout << "the path : " << path << "  is not exsit" << std::endl;
			return ret;
		}
		getFormatFiles(path, format, files);
		int size = files.size();
		ret = size > 1e-6 ? true : false;

		if (!ret)
			std::cout << " the Image is None, please checp path and format!" << std::endl;

		if (false)
		{
			for (int i = 0; i < size; i++)
			{
				std::cout << files[i] << std::endl;
			}
		}
		return ret;
	}

	std::vector<std::string> splitString(const std::string str, const std::string& pattern)
	{
		std::vector<std::string> str_splited;

		if ("" == str)
		{
			return str_splited;
		}
		std::string strs = str + pattern;

		size_t pos = strs.find(pattern);
		size_t size = strs.size();

		while (pos != std::string::npos)
		{
			std::string x = strs.substr(0, pos);
			str_splited.push_back(x);
			strs = strs.substr(pos + 1, size);
			pos = strs.find(pattern);
		}

		return str_splited;
	}

	std::string timeStamp()
	{
		time_t time_stamp;
		time(&time_stamp);

		struct tm *p;
		p = localtime(&time_stamp);

		char buff[120] = { 0 };
		strftime(buff, 64, "%Y_%m_%d_%H_%M_%S", p);
		//std::chrono::high_resolution_clock::time_point microseconds_time = std::chrono::high_resolution_clock::now();
		return buff;
	}

	std::string mkdirDebugPath()
	{
		std::string debug_flie = "debugzc";
		if (0 != access(debug_flie.c_str(), 0))
		{
		#ifdef _MSC_VER
			mkdir(debug_flie.c_str());
		#endif
		#ifdef __GNUC__
			mkdir(debug_flie.c_str(), 0777);
		#endif 
		}
		return debug_flie;
	}

	std::string mkdirDebugPath(const std::string& file_name)
	{
		if (0 != access(file_name.c_str(), 0))
		{
		#ifdef _MSC_VER
			mkdir(file_name.c_str());
		#endif
		#ifdef __GNUC__
			mkdir(file_name.c_str(), 0777);
		#endif 
		}
		return file_name;
	}
}

