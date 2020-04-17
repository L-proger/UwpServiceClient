#include <iostream>

#include <winrt/base.h>
#include <winrt/Windows.ApplicationModel.AppService.h>
#include <string>

using namespace winrt::Windows::ApplicationModel::AppService;

int main(){
    winrt::init_apartment();

    AppServiceConnection connection;
    connection.AppServiceName(L"ARG0");
    connection.PackageFamilyName(L"ARG1");

    auto connectionStatus = connection.OpenAsync().get();

    if (connectionStatus == AppServiceConnectionStatus::Success) {
        std::cout << "Connect success!" << std::endl;
        connection.Close();
    } else {
        std::cout << "Connect fail!" << std::endl;
    }
  
    winrt::uninit_apartment();
    return 0;
}