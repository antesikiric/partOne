#include "downloader.h"
#include <iostream>
#include <fstream>
#include <curl/curl.h>

using namespace std;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, ofstream* userp) {
    size_t totalSize = size * nmemb;
    userp->write((char*)contents, totalSize);
    return totalSize;
}

int downloading(const string &url, const string &outputFileName) {
    CURL* curl;
    CURLcode res;

    ofstream outputFile(outputFileName, ios::binary);
    if (!outputFile.is_open()) {
        cerr << "Could not open the file for writing" << endl;
        return 1;
    }

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &outputFile);
        
        res = curl_easy_perform(curl);

        if (res != CURLE_OK) {
            cerr << "Fetching data failed: " << curl_easy_strerror(res) << endl;
        } else {
            cout << "Content downloaded and saved to " << outputFileName << endl;
        }
        curl_easy_cleanup(curl);
    }
    outputFile.close();
    return 0;
}