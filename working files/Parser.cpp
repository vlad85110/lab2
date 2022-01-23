#include "Parser.h"

#include "WorkerDescriptor.h"
#include "WorkflowDescriptor.h"

#include <map>
#include <cmath>
#include <fstream>

namespace {

    std::map<std::string, WorkerTag> tags{
            {"readfile",  WorkerTag::Input},
            {"writefile", WorkerTag::Output},
            {"grep",      WorkerTag::Processor},
            {"sort",      WorkerTag::Processor},
            {"replace",   WorkerTag::Processor},
            {"dump",      WorkerTag::Processor}
    };

    bool ValidateWorkflow(WorkflowDescriptorPtr workflow_descriptor, std::string &error_message) {
        if (workflow_descriptor->workflow.empty()) return true;

        auto get_worker_descriptor = [&](WorkerId worker_id) -> std::optional<WorkerDescriptor> {
            auto worker_descriptor_it = workflow_descriptor->workers.find(worker_id);

            if (worker_descriptor_it == workflow_descriptor->workers.end()) {
                error_message = "Unknown workflow id";
                return std::nullopt;
            }

            return std::make_optional(worker_descriptor_it->second);
        };

    }

}


Parser::Parser(std::string & file_name) {
    std::ifstream file;
    file.open(file_name);
    std::string check_str;

    if (file.is_open()) {
        std::getline(file, check_str);
        if (check_str != "desc") {
            error_message_ = "wrong input";
            parse_result_ = nullptr;
            return;
        }
        auto i = 0;
        while (check_str != "csed") {
            std::getline(file, check_str, '=');
            if (check_str == "csed") return;

            auto str_to_int = [](std::string str){
                auto it = str.end();
                int num = 0, i = 0;

                auto char_to_int = [](char sym) {
                        return sym - '0';
                };

                while (it != str.begin()){
                    num += char_to_int(*it) * (int)pow(10, i);
                    i++;
                }

                return num;
            };
            auto worker_id = str_to_int(check_str);
            parse_result_->workflow[i] = worker_id;

            std::getline(file, check_str, ' ');
            auto make_worker_descriptor = [](std::ifstream & file, std::string & check_str) {
                WorkerDescriptor desc;
                desc.worker_name = check_str;
                desc.worker_tag = tags[check_str];
                while (*(check_str.end() - 1) != '\n') {
                    std::getline(file, check_str, ' ');
                    desc.args.push_back(check_str);
                }
                return desc;
            };
            auto desc = make_worker_descriptor(file, check_str);

            parse_result_->workers[worker_id] = desc;
            i++;
        }
    } else {
        error_message_ = "file is not open";
        parse_result_ = nullptr;
    }
}

WorkflowDescriptorPtr Parser::GetParseResult() {
    return parse_result_;
}

std::string_view Parser::GetErrorMessage() {
    return error_message_;
}
