#ifndef TemperatureClient_hpp
#define TemperatureClient_hpp

#include "./TemperatureHttpRequest.hpp"

using namespace std;


class Temperature {
	private:
		constexpr static const char* TAG = "Temperature";

	public:
		
		void static run(const shared_ptr<TemperatureHttpRequest>& client){
			{
				auto data = client->Get()->readBodyToString();
				OATPP_LOGD(TAG,"[Get] data='%s'", data->c_str());
				// auto data = client->doGet()->readBodyToString();
				// OATPP_LOGD(TAG, "[doGet] data='%s'", data->c_str());
			}
			
			// {
			// 	auto data = client->doPost("Some data passed to POST")->readBodyToString();
			// 	OATPP_LOGD(TAG, "[doPost] data='%s'", data->c_str());
			// }
			
			// {
			// auto data = client->doGetAnything("path-parameter")->readBodyToString();
			// OATPP_LOGD(TAG, "[doGetAnything] data='%s'", data->c_str());
			// }
			
			// {
			// auto data = client->doPostAnything("path-parameter", "Some body here")->readBodyToString();
			// OATPP_LOGD(TAG, "[doPostAnything] data='%s'", data->c_str());
			// }

		}

};

#endif
