#include "IoTClient.hpp"
using namespace std;
using namespace IoT;


void IoTClient::runClient(const std::shared_ptr<HttpRequest>& client){
	//oatpp::async::Executor executor(1, 1, 1);
  oatpp::async::Executor executor(2, 1, 1);

  executor.execute<SendDtoCoroutine>(client, "message1", 10000);
  executor.execute<SendDtoCoroutine>(client, "message2", 10000);
  executor.execute<SendDtoCoroutine>(client, "message3", 10000);
  
  executor.waitTasksFinished();
  executor.stop();
  executor.join();

}