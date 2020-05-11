#ifndef TemperatureHttpRequest_hpp
#define TemperatureHttpRequest_hpp

#include "TemperatureModelDto.hpp"

#include "oatpp/web/client/ApiClient.hpp"
#include "oatpp/core/macro/codegen.hpp"



class TemperatureHttpRequest : public oatpp::web::client::ApiClient {
#include OATPP_CODEGEN_BEGIN(ApiClient)

	API_CLIENT_INIT(TemperatureHttpRequest)
	
	//		("<http-method>", "<path>", <method-name>, <optional param-mappings>)      
	API_CALL("POST", "/temperature", doPostWithDto, BODY_DTO(TemperatureDto::ObjectWrapper, body))
	
	API_CALL("GET", "/api/breads", Get)

#include OATPP_CODEGEN_END(ApiClient)
};

#endif