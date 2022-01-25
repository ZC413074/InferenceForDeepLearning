#include"test.h"
#include<iostream>
#include<ctime>
#include<fstream>
#include<sstream>
#include"./FileOperation/FileOperationInclude.h"
void radar_test()
{
	std::string path = "G:/data/test_20220117/Radar/data3", in = "data3", out = "data3_1";
	std::vector<std::string> files;
	Algorithm::getAllFormatFiles(path, "txt", files);
	std::cout.setf(std::ios::showpoint);///>将小数精度后面的0显示出来
	std::cout.precision(4);
	std::vector<std::vector<float>> datas; datas.reserve(540);
	std::vector<std::vector<float>> datas_average; datas_average.reserve(2000);
	for (auto file : files)
	{
		std::ifstream fin(file, std::ios::in);
		std::string line;
		std::vector<float> line_data; line_data.reserve(3);
		while (std::getline(fin, line))
		{
			std::stringstream le(line);
			while (le >> line)
			{
				line_data.push_back(std::atof(line.c_str()));
			}
			datas.push_back(line_data);
			line_data.clear();
		}
		fin.close();
		std::string::size_type pos = 0;
		while ((pos = file.find(in, pos)) != std::string::npos)
		{
			file.replace(pos, in.size(), out);
			pos += out.size();
		}
		float x = 0.0, y = 0.0;
		for (int i = 266; i < 271; ++i)
		{
			x +=datas[i][0] * std::cos(datas[i][1]);
			y += datas[i][0] * std::sin(datas[i][1]);
		}
		x = x / 5.0; y = y / 5.0;
		datas_average.push_back({ x,y });
		//std::cout << file;
		std::ofstream fout(file, std::ios::out);
		for (int i = 0; i < datas.size(); ++i)
		{
			fout << datas[i][0] * std::cos(datas[i][1]) << "\t";
			fout << datas[i][0] * std::sin(datas[i][1]) << "\t";
			fout << datas[i][2] << "\n";
		}
		fout.close();
		datas.clear();
	}

	//std::ofstream fout(path+"/00.txt", std::ios::out);
	//for (int i = 0; i < datas_average.size(); ++i)
	//{
	//	fout << datas_average[i][0] << "\t";
	//	fout << datas_average[i][1] << "\t";
	//	fout << 0.0 << "\n";
	//}
	//fout.close();

}
