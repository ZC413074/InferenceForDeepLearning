#include"./DataDefine.h"
namespace Algorithm
{
#pragma region JsonParamRecogNumber
	JsonParamRecogNumber::JsonParamRecogNumber()
	{
		is_openvino_       = false;
		pad_size_          = 0.0;
		model_path_        = " ";
		net_size_.resize(2, 0);
		anchor_nums_       = 9;
		net_grid_.resize(3, 0);
		anchors_.resize(9, {0});
		class_nums_         = 0;
		class_names_.resize(1, { " " });
		cof_threshold_      = 1.0;
		nms_area_threshold_ = 1.0;
		debug_              = false;
	}
	
	JsonParamRecogNumber::JsonParamRecogNumber(const JsonParamRecogNumber&json_param_recogNumber)
	{
		is_openvino_         = json_param_recogNumber.is_openvino_;
		pad_size_            = json_param_recogNumber.pad_size_;
		model_path_          = json_param_recogNumber.model_path_;
		net_size_.resize(2, 0); 
		net_size_.assign(json_param_recogNumber.net_size_.cbegin(), json_param_recogNumber.net_size_.cend());
		anchor_nums_         = json_param_recogNumber.anchor_nums_;
		net_grid_.resize(3, 0);
		net_grid_.assign(json_param_recogNumber.net_grid_.cbegin(), json_param_recogNumber.net_grid_.cend());
		anchors_.resize(9, { 0 });
		anchors_.assign(json_param_recogNumber.anchors_.cbegin(), json_param_recogNumber.anchors_.cend());
		class_nums_          = json_param_recogNumber.class_nums_;
		class_names_.resize(1, { " " });
		class_names_.assign(json_param_recogNumber.class_names_.cbegin(), json_param_recogNumber.class_names_.cend());
		cof_threshold_       = json_param_recogNumber.cof_threshold_;
		nms_area_threshold_  = json_param_recogNumber.nms_area_threshold_;
		debug_               = json_param_recogNumber.debug_;
	}
	
	JsonParamRecogNumber& JsonParamRecogNumber::operator=(const JsonParamRecogNumber& json_param_recogNumber)
	{
		is_openvino_       = json_param_recogNumber.is_openvino_;
		pad_size_          = json_param_recogNumber.pad_size_;
		model_path_        = json_param_recogNumber.model_path_;
		net_size_.resize(2, 0);
		net_size_.assign(json_param_recogNumber.net_size_.cbegin(), json_param_recogNumber.net_size_.cend());
		anchor_nums_       = json_param_recogNumber.anchor_nums_;
		net_grid_.resize(3, 0);
		net_grid_.assign(json_param_recogNumber.net_grid_.cbegin(), json_param_recogNumber.net_grid_.cend());
		anchors_.resize(9, { 0 });
		anchors_.assign(json_param_recogNumber.anchors_.cbegin(), json_param_recogNumber.anchors_.cend());
		class_nums_         = json_param_recogNumber.class_nums_;
		class_names_.resize(1, { " " });
		class_names_.assign(json_param_recogNumber.class_names_.cbegin(), json_param_recogNumber.class_names_.cend());
		cof_threshold_      = json_param_recogNumber.cof_threshold_;
		nms_area_threshold_ = json_param_recogNumber.nms_area_threshold_;
		debug_              = json_param_recogNumber.debug_;
		return *this;
	}
#pragma endregion JsonParamRecogNumber

#pragma region ObjectRect
	ObjectRect::ObjectRect(int x, int y, int width, int height)
	{
		x_ = x;
		y_ = y;
		height_ = height;
		width_ = width;
	}
	
	ObjectRect& ObjectRect::operator=(const ObjectRect& object_rect)
	{
		x_ = object_rect.x_;
		y_ = object_rect.y_;
		width_ = object_rect.width_;
		height_ = object_rect.height_;
		return *this;
	}
	
	ObjectRect::ObjectRect(const ObjectRect& object_rect)
	{
		x_ = object_rect.x_;
		y_ = object_rect.y_;
		width_ = object_rect.width_;
		height_ = object_rect.height_;
	}
	
	ObjectRect& ObjectRect::operator+(const ObjectRect& object_rect)
	{
		x_ += object_rect.x_;
		y_ += object_rect.y_;
		return *this;
	}
#pragma endregion ObjectRect
}