#include"./inference_commom.h"
#include<iostream>
namespace Algorithm
{
	namespace Inference
	{
		void vector_cout(const std::vector<std::string>& datas)
		{
			std::cout.setf(std::ios::right);
			for (auto& data : datas)
			{
				std::cout << data <<"\t";
			}
			std::cout << "\n";
		}

		void vector_cout(const std::vector<int>& datas)
		{
			std::cout.setf(std::ios::right);
			for (auto& data : datas)
			{
				std::cout << data << "\t";
			}
			std::cout << "\n";
		}

		void vector_cout(std::vector<std::vector<int>> & datas)
		{
			std::cout.setf(std::ios::right);
			for (auto& data : datas)
			{
				for (auto& i : data)
				{
					std::cout << i << "\t";
				}
				std::cout << "\n";
			}
			std::cout << "\n";
		}
	} ///> Inference
} ///> Algorithm