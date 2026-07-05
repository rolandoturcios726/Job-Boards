#include <format>
#include "job_posting.hpp"


std::string JobPosting::fingerprint() const {
        return std::format("{}::{}", firm, external_id);
    }

bool valid_job_posting(JobPosting& job) {
    return !job.firm.empty() && !job.external_id.empty() && !job.title.empty();
}

/// Apparently C++ 20 has a one liner for this function. Come back to this.
void ScrapeResult::job_posting_cleanup() {
    std::vector<JobPosting> normalized_jobs;
    normalized_jobs.reserve(jobs.size());
    for (auto& job : jobs) {
        if (valid_job_posting(job)) {
            normalized_jobs.push_back(std::move(job));
        }
    }
    jobs = std::move(normalized_jobs);
}
