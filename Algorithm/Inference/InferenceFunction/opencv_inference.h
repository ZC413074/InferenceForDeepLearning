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

			OPenCVInference(const ModelParam& model_param);

			~OPenCVInference() {}

		public:
			bool           debug_;
			//ModelParam&    model_param_;
		};
	}
}
#endif