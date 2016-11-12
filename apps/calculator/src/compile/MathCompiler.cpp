//
// Created by Michael Fong on 2016/11/12.
//
#include <iostream>
#include <fstream>
#include <vector>

#include "compile/MathCompiler.h"
#include "compile/MathInterpretor.h"

MathCompiler::MathCompiler() {

}

MathCompiler::~MathCompiler() {

}

bool MathCompiler::compile(std::string &fname) {

    try {
        std::ifstream file(fname);
        std::string line;
        std::vector<std::string> content;
        while (std::getline(file, line)) {
            content.push_back(line + "\n");
        }
        file.close();

        compile(content);
    } catch (Exception& e) {
        LOG_ERROR(e.what());
    }

}

bool MathCompiler::compile(std::vector<std::string> content) {
    MathInterpretor interpretor;
    interpretor.startInterpret();

    try {
        RuntimeData answer = nullptr;

        for(int i = 0; i < content.size(); i++) {
            std::string line = content[i];
            answer = interpretor.interpret(line);
        }

        if(answer != nullptr) {
            double value = answer.get<double>();
            std::cout << "ANS : " << util::Converts::numberToString(value) << std::endl;
        }
    } catch (Exception& e) {
        LOG_ERROR(e.what());
    }

    interpretor.stopInterpret();
}