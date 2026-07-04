#include <iostream>
#include <string>
#include <format>
#include <vector>
#include "job_posting.hpp"


struct JobPosting {
    std::string firm;
    std::string external_id;
    std::string title;
    std::string location;
    std::string url;
    std::string description;
    std::string posted_at;

    std::string fingerprint() const {
        return std::format("{}::{}", firm, external_id);
    }
};

bool valid_job_posting(JobPosting& job) {
    return !job.firm.empty() && !job.external_id.empty() && !job.title.empty();
}

struct ScrapeResult {
    std::string firm;
    std::vector<JobPosting> jobs;
    std::string error;
    
    
    /// Apparently C++ 20 has a one liner for this function. Come back to this.
    void job_posting_cleanup() {
        std::vector<JobPosting> normalized_jobs;
        normalized_jobs.reserve(jobs.size());
        for (auto& job : jobs) {
            if (valid_job_posting(job)) {
                normalized_jobs.push_back(std::move(job));
            }
        }
        jobs = std::move(normalized_jobs);
    }
};
