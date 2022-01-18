#ifndef DATA_DEFINE
#define DATA_DEFINE
#include"./ExportDefine.h"
#include<vector>
#include<string>
namespace Algorithm
{
	class ALGORITHM_API JsonParamRecogNumber
	{
	public:
		JsonParamRecogNumber();
		JsonParamRecogNumber(const JsonParamRecogNumber&json_param_recogNumber);
		JsonParamRecogNumber& operator=(const JsonParamRecogNumber& model_param);
	public:
		bool                          is_openvino_;
		int                           pad_size_;
		std::string					  model_path_;
		std::vector<int>			  net_size_;
		int							  anchor_nums_;
		std::vector<int>			  net_grid_;
		std::vector<std::vector<int>> anchors_;
		int                           class_nums_;
		std::vector<std::string>      class_names_;
		float						  cof_threshold_;
		float						  nms_area_threshold_;
		bool						  debug_;
	};

	class ALGORITHM_API ObjectRect
	{
	public:
		ObjectRect() = default;
		ObjectRect(int x, int y, int width, int height);
		ObjectRect& operator=(const ObjectRect& object_rect);
		ObjectRect(const ObjectRect& object_rect);
		ObjectRect& operator+(const ObjectRect& object_rect);

	public:
		int x_;
		int y_;
		int width_;
		int height_;
	};

	class ALGORITHM_API Object
	{
	public:
		float prob_;
		std::string class_name_;
		ObjectRect rect_;
	};

}///> namespace common2

#endif