#pragma once

#include <optional>
#include <string>
#include <vector>

struct JobPosting {
    std::string firm;
    std::string external_id;
    std::string title;
    std::string location;
    std::string url;
    std::string description;
    std::string posted_at;
    std::string fingerprint() const;
};

bool valid_job_posting(JobPosting& job);

struct ScrapeResult {
    std::string firm;
    std::vector<JobPosting> jobs;
    std::string error;
    void job_posting_cleanup();
};
