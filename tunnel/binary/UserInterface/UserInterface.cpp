// search:
extern "C" {
//before it add:
#ifdef DISTRIBUTE
#include <curl/curl.h>
#include <curl/easy.h>
#include <curl/curlbuild.h>

#pragma comment (lib, "libcurl_a.lib")
#endif



// search:
int32_t APIENTRY WinMain(HINSTANCE hInstance
// before it add:
#ifdef DISTRIBUTE
static std::wstring WURL = L"http://ip:port/auth.php";
#endif


// search:
int32_t APIENTRY WinMain(HINSTANCE hInstance
// after it add:
#ifdef DISTRIBUTE
    curl_global_init(CURL_GLOBAL_ALL);

    CURL* curl = curl_easy_init();
    if (curl)
    {
        std::wstring strUrl = WURL;
        std::string url(strUrl.begin(), strUrl.end());

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "Aej2BHAbmnb5Qh");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, false);

        CURLcode res = curl_easy_perform(curl);
        if (res == CURLE_OK)
        {
            // all right
        }
        else
        {
            // may contact support
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
#endif