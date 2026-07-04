#pragma once

#include <string>
#include<string_view>
#include <unordered_set>
#include <vector>

#include "job_posting.hpp"
class BaseScraper {
public:
	virtual ~BaseScraper() = default;
	BaseScraper(const BaseScraper&) = delete;
	BaseScraper& operator = (const BaseScraper&) = delete;

	ScrapeResult fetch();

protected:
	BaseScraper(std::string firm, std::unordered_set<std::string> cached_fps);
	virtual void collect_jobs(std::vector<JobPosting>& out);
	virtual std::vector<JobPosting> fetch_jobs();
	virtual std::string_view ats() const = 0;

	std::string firm_;
	std::unordered_set<std::string> cached_description_fingerprints_;

};