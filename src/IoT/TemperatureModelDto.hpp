#ifndef TemperatureModelDto_hpp
#define TemperatureModelDto_hpp

#include "oatpp/core/data/mapping/type/Object.hpp"
#include "oatpp/core/macro/codegen.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

class TemperatureDto : public oatpp::data::mapping::type::Object {
  
  DTO_INIT(TemperatureDto, Object)
  
  DTO_FIELD(String, datetime);
  DTO_FIELD(String, source);
  DTO_FIELD(Int32, value);
  
};

#include OATPP_CODEGEN_END(DTO)
#endif 