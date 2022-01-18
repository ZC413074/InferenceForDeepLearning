#ifndef APPLY_JSON  
#define APPLY_JSON
#include"./../DataDefine.h"
namespace Algorithm
{
	bool ALGORITHM_API load_models_param(const std::string json_full_path, int& image_row, int& image_col, std::vector<JsonParamRecogNumber> & json_param);

	bool ALGORITHM_API check_model_param(const JsonParamRecogNumber & json_param);
}

#endif