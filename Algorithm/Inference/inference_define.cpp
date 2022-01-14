#include"./inference_define.h"
#include<iostream>
#include<./opencv2/dnn/dnn.hpp>
namespace Algorithm
{
	namespace Inference
	{
	#pragma region InferenceParam
		InferenceParam::InferenceParam()
		{
			debug_              = false;
			model_net_          = nullptr;
			class_nums_         = 0;
			cof_threshold_      = 0.0;
			nms_area_threshold_ = 0.0;
		}
		InferenceParam::InferenceParam(const InferenceParam& model_param)
		{
			debug_              = model_param.debug_;
			model_net_          = model_param.model_net_;
			model_out_layers_.resize(model_param.model_out_layers_.size());
			model_out_layers_.assign(model_param.model_out_layers_.begin(), model_param.model_out_layers_.end());
			class_names_.resize(model_param.class_names_.size());
			class_names_.assign(model_param.class_names_.begin(), model_param.class_names_.end());
			class_nums_         = model_param.class_nums_;
			cof_threshold_      = model_param.cof_threshold_;
			nms_area_threshold_ = model_param.nms_area_threshold_;
		}

		InferenceParam& InferenceParam::operator=(const InferenceParam& model_param)
		{
			debug_              = model_param.debug_;
			model_net_          = model_param.model_net_;
			model_out_layers_.resize(model_param.model_out_layers_.size());
			model_out_layers_.assign(model_param.model_out_layers_.begin(), model_param.model_out_layers_.end());
			class_names_.resize(model_param.class_names_.size());
			class_names_.assign(model_param.class_names_.begin(), model_param.class_names_.end());
			class_nums_         = model_param.class_nums_;
			cof_threshold_      = model_param.cof_threshold_;
			nms_area_threshold_ = model_param.nms_area_threshold_;
			return *this;
		}
	#pragma endregion InferenceParam
	}
}