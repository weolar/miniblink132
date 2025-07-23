// Generated from gen_validator.py. DO NOT EDIT!
// source: structured.xml

#ifndef GEN_COMPONENTS_METRICS_STRUCTURED_STRUCTURED_METRICS_VALIDATOR_H
#define GEN_COMPONENTS_METRICS_STRUCTURED_STRUCTURED_METRICS_VALIDATOR_H

#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>

#include "base/no_destructor.h"
#include "components/metrics/structured/project_validator.h"

namespace metrics {
namespace structured {
namespace validator {

class Validators final {

public:
    Validators();

    Validators(const Validators&) = delete;
    Validators& operator=(const Validators&) = delete;

    void Initialize();

    const ProjectValidator* GetProjectValidator(std::string_view project_name) const;

    std::optional<std::string_view> GetProjectName(uint64_t project_name_hash) const;

    static Validators* Get();

private:
    friend class base::NoDestructor<Validators>;

    std::unordered_map<std::string_view, std::unique_ptr<ProjectValidator>> validators_;
    std::unordered_map<uint64_t, std::string_view> project_name_map_;
};

} // namespace validator
} // namespace structured
} // namespace metrics

#endif // GEN_COMPONENTS_METRICS_STRUCTURED_STRUCTURED_METRICS_VALIDATOR_H
