#include "IoTClient.hpp"


#include "HttpRequest.hpp"

#include "oatpp-curl/RequestExecutor.hpp"

#include "oatpp/web/client/HttpRequestExecutor.hpp"
#include "oatpp/network/client/SimpleTCPConnectionProvider.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include <iostream>
#include <sys/time.h>

using namespace std;
using namespace oatpp;
using namespace base;
using namespace IoT;

double time_simple_example;
double time_async_example;

std::shared_ptr<oatpp::web::client::RequestExecutor> createExecutor() {
  OATPP_LOGD("App", "Using Oat++ native HttpRequestExecutor.");
  auto connectionProvider = oatpp::network::client::SimpleTCPConnectionProvider::createShared("httpbin.org", 80);
  return oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
}

// std::shared_ptr<oatpp::web::client::RequestExecutor> createCurlExecutor() {
//   OATPP_LOGD("App", "Using oatpp-curl RequestExecutor.");
//   return oatpp::curl::RequestExecutor::createShared("http://httpbin.org/", true /* set verbose=true for dubug info */);
// }

double get_stime(){
	struct timeval current_time;	
	gettimeofday(&current_time,NULL);
	return (double)current_time.tv_sec + (double)current_time.tv_usec/(double)1e6;
}

void run(){
  
  /* Create ObjectMapper for serialization of DTOs  */
  auto objectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();
  
  /* Create RequestExecutor which will execute ApiClient's requests */
  auto requestExecutor = createExecutor();   // <-- Always use oatpp native executor where's possible.
  //auto requestExecutor = createCurlExecutor();  // <-- Curl request executor
  
  /* DemoApiClient uses DemoRequestExecutor and json::mapping::ObjectMapper */
  /* ObjectMapper passed here is used for serialization of outgoing DTOs */
  auto client = HttpRequest::createShared(requestExecutor, objectMapper);
  
  double init_time = get_stime();
  //SimpleExample::runExample(client);
  double end_time = get_stime();
  time_simple_example = end_time - init_time;

  init_time = get_stime();
  IoTClient::runClient(client);
  end_time = get_stime();

  time_async_example = end_time - init_time;
  
}

int main(int argc, const char * argv[]) {

  oatpp::base::Environment::init();
  
  run();
  
  /* Print how much objects were created during app running, and what have left-probably leaked */
  /* Disable object counting for release builds using '-D OATPP_DISABLE_ENV_OBJECT_COUNTERS' flag for better performance */
  std::cout << "\nEnvironment:\n";
  std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount() << "\n";
  std::cout << "objectsCreated = " << oatpp::base::Environment::getObjectsCreated() << "\n\n";

  cout << "Theads = " << Environment::getThreadLocalObjectsCreated() << "\n\n";

  cout << "Times" << "\n" << "Simple Time: " << time_simple_example << "\nAsync Time: " << time_async_example << endl;
  
  oatpp::base::Environment::destroy();
}