#ifndef NFERENCE_DEFINE_H
#define NFERENCE_DEFINE_H
#ifdef _MSC_VER
#ifdef INFERENCE_EXPORT
#define INFERENCE_API __declspec(dllexport)
#else
#define COMMON2_API __declspec(dllimport)
#endif
#endif // _MSC_VER

#if __GNUC__
#ifdef COMMON2_DLL
#define COMMON2_API __attribute__((visibility("default")))
#else
#define COMMON2_API __attribute__((visibility("default")))
#endif
#endif // __GNUC__
#include<string>
#include<vector>
namespace Algorithm
{
	namespace Inference
	{
		class INFERENCE_API InferenceParam
		{
		public:
			InferenceParam();
			InferenceParam(const InferenceParam& model_param);
			InferenceParam& operator=(const InferenceParam& model_param);
			~InferenceParam() {}

		public:
			bool                                  debug_;
			std::shared_ptr<void*>                model_net_;
			std::vector<std::string>              model_out_layers_;
			std::vector<std::string>			  class_names_;
			int									  class_nums_;
			float								  cof_threshold_;
			float								  nms_area_threshold_;
		};
	}
}
#endif