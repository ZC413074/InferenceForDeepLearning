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

		OPenCVInference::OPenCVInference(const ModelParam& model_param)
		{

			debug_ = model_param.debug_;
		}

#pragma endregion OPenCVInference
	}
}