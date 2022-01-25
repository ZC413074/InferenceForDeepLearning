#include"./inference_define.h"
#include<iostream>
#include<./opencv2/dnn/dnn.hpp>
#include"./inference_commom.h"
namespace Algorithm
{
	namespace Inference
	{
#pragma region ModelParam

		void ModelParam::ModelParamInit(const int& class_nums,
			const std::vector<std::string>& class_names,
			const float& cof_threshold,
			const float& nms_area_threshold,
			const bool& debug)
		{
			debug_ = debug;
			class_names_.assign(class_names.begin(), class_names.end());
			class_nums_ = class_nums;
			cof_threshold_ = cof_threshold;
			nms_area_threshold_ = nms_area_threshold;
		}

		ModelParam::ModelParam()
		{
			ModelParamInit(1, {"null"}, 0.0, 0.0);
		}

		ModelParam::ModelParam(const int& class_nums,
			const std::vector<std::string>& class_names,
			const float& cof_threshold,
			const float& nms_area_threshold,
			const bool& debug)
		{
			ModelParamInit(class_nums, class_names, cof_threshold, nms_area_threshold, debug);
		}

		ModelParam::ModelParam(const ModelParam& model_param)
		{
			ModelParamInit(model_param.class_nums_, model_param.class_names_, model_param.cof_threshold_, model_param.nms_area_threshold_, model_param.debug_);
		}

		ModelParam& ModelParam::operator=(const ModelParam& model_param)
		{
			ModelParamInit(model_param.class_nums_, model_param.class_names_, model_param.cof_threshold_, model_param.nms_area_threshold_, model_param.debug_);
			return *this;
		}

		void ModelParam::print_param()
		{
			std::cout << "Base Model Param:\n";
			std::cout << "\debug:\t" << debug_ << "\n";
			std::cout << "\tclass nums:\t" << class_nums_ << "\n";
			std::cout << "\tclass_names:\t\n"; vector_cout(class_names_);
			std::cout << "\cof_threshold:\t" << cof_threshold_ << "\n";
			std::cout << "\nms_area_threshold:\t" << nms_area_threshold_ << "\n";
		}

#pragma endregion ModelParam

#pragma region YoLoV5Param

		void YoLoV5Param::YoLoV5ParamInit(const int& anchor_nums,
			const std::vector<std::vector<int>>& anchors,
			const std::vector<int>& net_size,
			const std::vector<int>& net_grid)
		{
			anchors_.resize(anchor_nums);
			net_size_.resize(2);
			net_grid_.resize(anchor_nums);
			anchor_nums_ = anchor_nums;
			anchors_.assign(anchors.begin(), anchors.end());
			net_size_.assign(net_size.begin(), net_size.end());
			net_grid_.assign(net_grid.begin(), net_grid.end());
		}

		YoLoV5Param::YoLoV5Param():ModelParam()
		{
			YoLoV5ParamInit(3, { {0, 0, 0}, {0, 0, 0}, {0, 0, 0} }, { 640, 640 }, { 80, 40, 20 });
		}

		YoLoV5Param::YoLoV5Param(const int& class_nums,
			const std::vector<std::string>& class_names,
			const float& cof_threshold,
			const float& nms_area_threshold, const int& anchor_nums,
			const std::vector<std::vector<int>>& anchors,
			const std::vector<int>& net_size,
			const std::vector<int>& net_grid,
			const bool& debug): ModelParam(class_nums, class_names, cof_threshold, nms_area_threshold, debug)
		{
			YoLoV5ParamInit(anchor_nums, anchors, net_size, net_grid);
		}

		YoLoV5Param::YoLoV5Param(const YoLoV5Param& yolov5_param): ModelParam(yolov5_param)
		{
			YoLoV5ParamInit(yolov5_param.anchor_nums_, yolov5_param.anchors_, yolov5_param.net_size_, yolov5_param.net_grid_);
		}

		YoLoV5Param& YoLoV5Param::operator=(const YoLoV5Param& yolov5_param)
		{
			YoLoV5ParamInit(yolov5_param.anchor_nums_, yolov5_param.anchors_, yolov5_param.net_size_, yolov5_param.net_grid_);
			return *this;
		}

		void YoLoV5Param::print_param()
		{
			ModelParam::print_param();
			std::cout << "YOLOv5 Model Param:\n";
			std::cout << "\anchor_nums:\t" << anchor_nums_ << "\n";
			std::cout << "\tanchors:\t\n";vector_cout(anchors_);
			std::cout << "\tnet_size:\t\n"; vector_cout(net_size_);
			std::cout << "\net_grid:\t\n";vector_cout(net_grid_);
		}

#pragma endregion YoLoV5Param

	}
}