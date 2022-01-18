#ifndef NFERENCE_DEFINE_H
#define NFERENCE_DEFINE_H
#include"./ExportDefine.h"
#include<string>
#include<vector>
namespace Algorithm
{
	namespace Inference
	{
		class ALGORITHM_API InferenceParam
		{

		public:

			InferenceParam();

			InferenceParam(std::shared_ptr<void*>model_net, 
				std::vector<std::string> model_out_layers, 
				std::vector<std::string> class_names,
				int class_nums,
				float cof_threshold,
				float nms_area_threshold,
				bool debug = false);

			InferenceParam(const InferenceParam& model_param);

			InferenceParam& operator=(const InferenceParam& model_param);

			~InferenceParam() {}
		private:
			void InferenceParamInit(std::shared_ptr<void*>model_net,
				std::vector<std::string> model_out_layers,
				std::vector<std::string> class_names,
				int class_nums,
				float cof_threshold,
				float nms_area_threshold,
				bool debug = false);

		public:
			bool                                  debug_;
			std::shared_ptr<void*>                model_net_;
			std::vector<std::string>              model_out_layers_;
			std::vector<std::string>			  class_names_;
			int									  class_nums_;
			float								  cof_threshold_;
			float								  nms_area_threshold_;
		};
		class ALGORITHM_API InferenceParamYoLoV5 : public InferenceParam
		{
		public:
			InferenceParamYoLoV5();
			InferenceParamYoLoV5(const InferenceParamYoLoV5& model_param_yolov5);
			InferenceParamYoLoV5& operator=(const InferenceParamYoLoV5& model_param_yolov5);
			~InferenceParamYoLoV5() {}

		public:
			std::shared_ptr<void *>               model_net_;
			std::vector<int>			          net_size_;
			std::vector<int>			          net_grid_;
			int							          anchor_nums_;
			std::vector<std::vector<int>>         anchors_;
		};
	}
}
#endif