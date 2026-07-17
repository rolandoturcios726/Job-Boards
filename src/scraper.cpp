#include <string>
#include<string_view>
#include <unordered_set>
#include <vector>
#include <stdexcept>
#include "jobboards/job_posting.hpp"
#include "jobboards/scraper.hpp"


BaseScraper::BaseScraper(std::string firm, std::unordered_set<std::string> cached_fps):
	firm_(std::move(firm)), cached_description_fingerprints_(std::move(cached_fps)) {}

ScrapeResult BaseScraper::fetch() {
	std::vector<JobPosting> jobs;
	try{
		collect_jobs(jobs);
	}
	catch (const std::exception& e) {
		return ScrapeResult{
			.firm = firm_,
			.jobs = std::move(jobs),
			.error = std::string(ats()) + "fetch failed: " + std::string(e.what())};
	}
	return ScrapeResult{ .firm = firm_,.jobs = std::move(jobs) };
}

void BaseScraper::collect_jobs(std::vector<JobPosting>& out) {
	for (auto& job : fetch_jobs()) {
		out.push_back(std::move(job));
	}

}

std::vector<JobPosting> BaseScraper::fetch_jobs() {
	throw std::logic_error(std::string(ats()) + ": fetch_jobs not overriden");
}