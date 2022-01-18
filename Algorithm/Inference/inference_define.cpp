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
			debug_ = false;
			model_net_ = nullptr;
			class_nums_ = 0;
			cof_threshold_ = 0.0;
			nms_area_threshold_ = 0.0;
		}

		void InferenceParam::InferenceParamInit(std::shared_ptr<void*>model_net,
			std::vector<std::string> model_out_layers,
			std::vector<std::string> class_names,
			int class_nums,
			float cof_threshold,
			float nms_area_threshold,
			bool debug)
		{
			debug_ = debug;
			model_net_ = model_net;
			model_out_layers_.resize(model_out_layers.size());
			model_out_layers_.assign(model_out_layers.begin(), model_out_layers.end());
			class_names_.resize(class_names.size());
			class_names_.assign(class_names.begin(), class_names.end());
			class_nums_ = class_nums;
			cof_threshold_ = cof_threshold;
			nms_area_threshold_ = nms_area_threshold;
		}

		InferenceParam::InferenceParam(std::shared_ptr<void*>model_net,
			std::vector<std::string> model_out_layers,
			std::vector<std::string> class_names,
			int class_nums,
			float cof_threshold,
			float nms_area_threshold,
			bool debug)
		{
			InferenceParamInit(model_net, model_out_layers, class_names, class_nums, cof_threshold, nms_area_threshold, debug);
		}

		InferenceParam::InferenceParam(const InferenceParam& model_param)
		{
			InferenceParamInit(model_param.model_net_, model_param.model_out_layers_, model_param.class_names_, model_param.class_nums_, model_param.cof_threshold_, model_param.nms_area_threshold_, model_param.debug_);
		}

		InferenceParam& InferenceParam::operator=(const InferenceParam& model_param)
		{
			InferenceParamInit(model_param.model_net_, model_param.model_out_layers_, model_param.class_names_, model_param.class_nums_, model_param.cof_threshold_, model_param.nms_area_threshold_, model_param.debug_);
			return *this;
		}

	#pragma endregion InferenceParam

#pragma region InferenceParamYoLoV5
		InferenceParamYoLoV5::InferenceParamYoLoV5():InferenceParam()
		{

		}
		InferenceParamYoLoV5::InferenceParamYoLoV5(const InferenceParamYoLoV5& model_param)
		{
		}

		InferenceParamYoLoV5& InferenceParamYoLoV5::operator=(const InferenceParamYoLoV5& model_param)
		{
			return *this;
		}
#pragma endregion InferenceParamYoLoV5

	}
}