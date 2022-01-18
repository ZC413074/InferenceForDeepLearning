#include"RWJsonInclude.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include"CJson.h"
#include"CJsonObject.hpp"
namespace Algorithm
{
	bool load_single_model_param(CJsonObject json_object, JsonParamRecogNumber & json_param, const bool& is_openvino = false)
	{
		json_param.is_openvino_ = is_openvino;
		/// pad size
		if (json_object["PadSize"].IsEmpty())
		{
			std::cout << "the key word of PadSize is not exist!";
			return false;
		}
		json_object.Get("PadSize", json_param.pad_size_);

		/// model full path
		if (json_object["ModelPath"].IsEmpty())
		{
			std::cout << "the key word of ModelPath is not exist!";
			return false;
		}
		json_object.Get("ModelPath", json_param.model_path_);

		/// debug
		if (json_object["Debug"].IsEmpty())
		{
			std::cout << "the key word of Debug is not exist!";
			return false;
		}
		json_object.Get("Debug", json_param.debug_);

		/// NetSize
		json_param.net_size_.resize(2);
		if (json_object["NetSize"].IsEmpty())
		{
			std::cout << "the key word of NetSize is not exist!";
			return false;
		}
		for (int i = 0; i < 2; ++i)
			json_object["NetSize"].Get(i, json_param.net_size_[i]);

		/// AnchorNums
		if (json_object["AnchorNums"].IsEmpty())
		{
			std::cout << "the key word of AnchorNums is not exist!";
			return false;
		}
		json_object.Get("AnchorNums", json_param.anchor_nums_);

		/// NetGrid
		json_param.net_grid_.resize(json_param.anchor_nums_);
		if (json_object["NetGrid"].IsEmpty())
		{
			std::cout << "the key word of NetGrid is not exist!";
			return false;
		}
		for (int i = 0; i < json_param.anchor_nums_; ++i)
			json_object["NetGrid"].Get(i, json_param.net_grid_[i]);

		/// Anchors
		json_param.anchors_.resize(json_param.anchor_nums_);
		if (json_object["Anchors"].IsEmpty())
		{
			std::cout << "the key word of Anchors is not exist!";
			return false;
		}

		std::vector<std::string> anchor_name = { "p3_8","p4_16","p5_32" };
		for (int i = 0; i < json_param.anchor_nums_; ++i)
		{
			CJsonObject sub_jsonin = json_object["Anchors"][anchor_name[i]];
			json_param.anchors_[i].resize(6);
			for (int j = 0; j < 6; ++j)
			{
				sub_jsonin.Get(j, json_param.anchors_[i][j]);
			}
		}

		/// ClassNums
		if (json_object["ClassNums"].IsEmpty())
		{
			std::cout << "the key word of ClassNums is not exist!";
			return false;
		}
		json_object.Get("ClassNums", json_param.class_nums_);

		/// ClassName
		json_param.class_names_.resize(json_param.class_nums_);
		if (json_object["ClassName"].IsEmpty())
		{
			std::cout << "the key word of ClassName is not exist!";
			return false;
		}
		for (int i = 0; i < json_param.class_nums_; ++i)
			json_object["ClassName"].Get(i, json_param.class_names_[i]);

		/// CofThreshold
		if (json_object["CofThreshold"].IsEmpty())
		{
			std::cout << "the key word of CofThreshold is not exist!";
			return false;
		}
		json_object.Get("CofThreshold", json_param.cof_threshold_);

		/// NmsAreaThreshold
		if (json_object["NmsAreaThreshold"].IsEmpty())
		{
			std::cout << "the key word of NmsAreaThreshold is not exist!";
			return false;
		}
		json_object.Get("NmsAreaThreshold", json_param.nms_area_threshold_);
		return true;
	}

	bool load_models_param(const std::string json_full_path, int& image_row, int& image_col, std::vector<JsonParamRecogNumber> & json_param)
	{
		bool ret = false;
		std::ifstream fin(json_full_path, std::ios::in);
		if (!fin.is_open())
		{
			std::cout << "Failed to open json file! " << json_full_path << "\n";
			return ret;
		}
		std::stringstream json_stream;
		json_stream << fin.rdbuf();
		fin.close();

		std::string json_file = json_stream.str();
		CJsonObject jsonin(json_file);

		/// input image rows  
		if (jsonin["InputImageRows"].IsEmpty())
		{
			std::cout << "the key word of InputImageRows is not exist!";
			return ret;
		}
		jsonin.Get("InputImageRows", image_row);

		/// input image cols 
		if (jsonin["InputImageCols"].IsEmpty())
		{
			std::cout << "the key word of InputImageCols is not exist!";
			return ret;
		}
		jsonin.Get("InputImageCols", image_col);

		/// model nums 
		int model_nums = 0;
		if (jsonin["ModelNums"].IsEmpty())
		{
			std::cout << "the key word of ModelNums is not exist!";
			return ret;
		}
		jsonin.Get("ModelNums", model_nums);

		/// model names
		std::vector<std::string> model_names; model_names.resize(model_nums);
		if (jsonin["ModelName"].IsEmpty())
		{
			std::cout << "the key word of ModelName is not exist!";
			return ret;
		}
		for (int i = 0; i < model_nums; ++i)
			jsonin["ModelName"].Get(i, model_names[i]);

		/// is openvino
		bool is_openvino = false;
		if (jsonin["IsOpenvino"].IsEmpty())
		{
			std::cout << "the key word of IsOpenvino is not exist!";
			return ret;
		}
		jsonin.Get("IsOpenvino", is_openvino);

		json_param.resize(model_nums);
		for (int k = 0; k < model_nums; ++k)
		{
			if (jsonin[model_names[k]].IsEmpty())
			{
				std::cout << "the key word of "<< model_names[k] <<" is not exist!";
				return false;
			}	
			CJsonObject json_subobject = jsonin[model_names[k]];
			ret = load_single_model_param(json_subobject, json_param[k], is_openvino);
			if(!ret)
				return ret;
		}

		return ret;
	}

	bool check_model_param(const JsonParamRecogNumber & json_param)
	{
		bool ret = false;
		//if (json_param.model_path_ == nullptr)
		//{
		//	std::cout << "The model is null, please check!" << std::endl;
		//	return ret;
		//}
		if (json_param.net_size_[0] <1e-6 || json_param.net_size_[1] < 1e-6)
		{
			std::cout << "net size not true, please check!" << std::endl;
			return ret;
		}

		if (json_param.anchor_nums_ != json_param.net_grid_.size() || json_param.anchor_nums_ != json_param.anchors_.size())
		{
			std::cout << "anchor size not match, please check!" << std::endl;
			return ret;
		}

		if (json_param.class_nums_ != json_param.class_names_.size())
		{
			std::cout << "classify size not match, please check!" << std::endl;
			return ret;
		}

	}
}