#ifndef INFERENCE_DEFINE_H
#define INFERENCE_DEFINE_H
#include"./ExportDefine.h"
#include<string>
#include<vector>
namespace Algorithm
{
	namespace Inference
	{
		class ALGORITHM_API ModelParam
		{

		public:

			ModelParam();

			ModelParam(const int& class_nums,
				const std::vector<std::string>& class_names,	
				const float& cof_threshold,
				const float& nms_area_threshold,
				const bool& debug = false);

			ModelParam(const ModelParam& model_param);

			ModelParam& operator=(const ModelParam& model_param);

			virtual void print_param();

			virtual ~ModelParam() {}
		private:
			void ModelParamInit(const int& class_nums,
				const std::vector<std::string>& class_names,
				const float& cof_threshold,
				const float& nms_area_threshold,
				const bool& debug = false);

		public:
			bool                                  debug_;
			std::vector<std::string>			  class_names_;
			int									  class_nums_;
			float								  cof_threshold_;
			float								  nms_area_threshold_;
		};

		class ALGORITHM_API YoLoV5Param : public ModelParam
		{
		public:
			YoLoV5Param();

			YoLoV5Param(const int& class_nums,
				const std::vector<std::string>& class_names,
				const float& cof_threshold,
				const float& nms_area_threshold, const int& anchor_nums,
				const std::vector<std::vector<int>>& anchors,
				const std::vector<int>& net_size,
				const std::vector<int>& net_grid,
				const bool& debug = false);

			YoLoV5Param(const YoLoV5Param& yolov5_param);

			YoLoV5Param& operator=(const YoLoV5Param& yolov5_param);

			void print_param();

			~YoLoV5Param() {}

		private:
			void YoLoV5ParamInit(const int& anchor_nums,
				const std::vector<std::vector<int>>& anchors,
				const std::vector<int>& net_size,
				const std::vector<int>& net_grid);
		public:
			int							          anchor_nums_;
			std::vector<std::vector<int>>         anchors_;
			std::vector<int>			          net_size_;
			std::vector<int>			          net_grid_;
		};

		class ALGORITHM_API InferenceEngine
		{

		};
	}
}
#endif