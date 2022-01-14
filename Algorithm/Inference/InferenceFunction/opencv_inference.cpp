#include"./opencv_inference.h"
namespace Algorithm
{
	namespace Inference
	{
#pragma region OPenCVInference
		OPenCVInference::OPenCVInference()
		{
			debug_ = false;
		}

		OPenCVInference::OPenCVInference(const InferenceParam& inference_param):inference_param_(inference_param)
		{
			debug_ = inference_param.debug_;
		}

#pragma endregion OPenCVInference
	}
}