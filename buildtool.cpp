#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

struct BuildConfig {
    std::string compiler;
    std::string inputFile;
    std::string outputFile;
    bool saveOutput;
};

BuildConfig readConfig(const std::string& filename) {
    BuildConfig config;
    std::ifstream file(filename);
    std::string line;
    while (std::getline(file, line)) {
        if (!line.empty() && line[0] != '#') { // Ignore empty lines and lines starting with #
            std::stringstream ss(line);
            std::string key, value;
            if (std::getline(ss, key, '=')) {
                if (std::getline(ss, value)) {
                    if (key == "compiler") {
                        config.compiler = value;
                    } else if (key == "SAVE_OUTPUT") {
                        config.saveOutput = true;
                    } else if (key == "inputFile") {
                        config.inputFile = value;
                    } else if (key == "outputFile") {
                        config.outputFile = value;
                    }
                           }
            }
        }
    }
    return config;
}

int main() {
    // Reads build.inf file
    BuildConfig config = readConfig("build.inf");

    std::string command = config.compiler;
    if (config.saveOutput && !config.outputFile.empty()) {
        command += " -o " + config.outputFile;
    }
    command += " " + config.inputFile;

    std::cout << "Buildtool 0.2 Alpha " << std::endl;
    std::system(command.c_str());

    return 0;
}
