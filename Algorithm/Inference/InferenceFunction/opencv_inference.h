#ifndef OPENCV_INFERENCE_H
#define OPENCV_INFERENCE_H
#include"./../inference_define.h"
#include<./opencv2/dnn/dnn.hpp>
namespace Algorithm
{
	namespace Inference
	{
		class OPenCVInference
		{
		public:
			OPenCVInference();
			OPenCVInference(const InferenceParam& inference_param);

			~OPenCVInference() {}

		public:
			bool           debug_;
			InferenceParam inference_param_;
		};
	}
}
#endif