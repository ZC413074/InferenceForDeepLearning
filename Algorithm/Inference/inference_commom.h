#ifndef INFERENCE_COMMON_H
#define INFERENCE_COMMON_H
#include<vector>
#include<string>
namespace Algorithm
{
	namespace Inference
	{
		void vector_cout(const std::vector<std::string>& datas);
		void vector_cout(const std::vector<int>& datas);
		void vector_cout(std::vector<std::vector<int>> & datas);
	} ///> Inference
} ///> Algorithm
#endif