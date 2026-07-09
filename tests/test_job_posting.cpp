#include <catch2/catch_test_macros.hpp>
#include "job_posting.hpp"

TEST_CASE("Job Posting: Intake") {
	 JobPosting JB{
		 .firm = "Goldman Sachs",
		 .external_id = "123",
		 .title = "Software Engineer",
		 .location = "New York",
		 .url = "test.com",
		 .posted_at = "2026-05-12",
	 };

	 REQUIRE(JB.firm == "Goldman Sachs");
	 REQUIRE(JB.external_id == "123");
	 REQUIRE(JB.title == "Software Engineer");
	 REQUIRE(JB.location == "New York");
	 REQUIRE(JB.url == "test.com");
	 REQUIRE(JB.posted_at == "2026-05-12");
}
TEST_CASE("Job Posting: CleanUp") {
	ScrapeResult SR = {
		.firm = "Goldman Sachs",
		.jobs = {
		JobPosting{
		.firm = "Goldman Sachs",
		.external_id = "123",
		.title = "Software Engineer",
		.location = "New York",
		.url = "test.com",
		.posted_at = "2026-05-12",
		},
		JobPosting{
		.firm = "JP Morgan",
		.external_id = "456",
		.title = "",
		.location = "Connecticut",
		.url = "test2.com",
		.posted_at = "2026-06-12",
		},
		JobPosting{
		.firm = "Morgan Stanley",
		.external_id = "789",
		.title = "AI Engineer",
		.location = "Arizona",
		.url = "test3.com",
		.posted_at = "2026-07-12",
		}
		}
	};
	SR.job_posting_cleanup();
	REQUIRE(SR.jobs.size() == 2);
}
