#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

char toLowerChar(char inputChar) {
    return tolower(inputChar);
}

void toLowerString(std::string& extension) {
    std::transform(extension.begin(), extension.end(), extension.begin(), toLowerChar);
}

// Lambda function: Same as upper.
//void toLowerString(std::string& extension) {
//    std::transform(extension.begin(), extension.end(), extension.begin(), [](char inputChar){
//        return tolower(inputChar);
//        });
//}

std::unordered_map<std::string, std::string> readMimeTypesFronInput(
        int & filesCount) {
    int mimesCount = 0;
    std::cin >> mimesCount >> filesCount;

    std::unordered_map<std::string, std::string> mimeTypes(mimesCount);
    std::pair<std::string, std::string> extensionAndMime;

    for (int i = 0; i < mimesCount; ++i) {
        std::cin >> extensionAndMime.first >> extensionAndMime.second;
        toLowerString(extensionAndMime.first);
        mimeTypes.insert(extensionAndMime);
    }

    return mimeTypes;
}

std::vector<std::string> readFilesFromInput(int filesCount) {
    std::vector<std::string> files(filesCount);

    for (auto& file : files) {
        std::cin >> file;
    }

    return files;
}

bool isExtensionFound(const std::string file, size_t& foundIdx) {
    const char extensionDelimiter = '.';
    foundIdx = file.rfind(extensionDelimiter);

    return foundIdx != std::string::npos;
}

std::vector<std::string> produceAnswer(
        const std::vector<std::string>& files,
        const std::unordered_map<std::string, std::string>& mimeTypes) {
    const std::string unknownType = "UNKNOWN";

    std::vector<std::string> answer;
    answer.reserve(files.size());
    std::string currExtension;
    size_t foundIdx = 0;

    for (const auto& file : files) {
        const bool foundExtension = isExtensionFound(file, foundIdx);

        if (!foundExtension) {
            answer.push_back(unknownType);
            continue;
        }
        
        currExtension = file.substr(foundIdx + 1);
        toLowerString(currExtension);
        auto it = mimeTypes.find(currExtension);

        if (it == mimeTypes.end()) {
            answer.push_back(unknownType);
            continue;
        }
        
        answer.push_back(it->second);
    }

    return answer;
}

void printAnswer(const std::vector<std::string>& answer) {
    for (const auto& elem : answer) {
        std::cout << elem << '\n';
    }
}

int main() {
    int filesCount = 0;
    const auto mimeTypes  = readMimeTypesFronInput(filesCount);
    const auto files = readFilesFromInput(filesCount);
    const auto answer = produceAnswer(files, mimeTypes);
    printAnswer(answer);

    return 0;
}

//3
//3
//html text / html
//png image / png
//gif image / gif
//animated.gif
//portrait.png
//index.html