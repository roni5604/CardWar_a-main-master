#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
using namespace doctest;

const int MIN_TESTS = 20;

int return_code = -1;

struct ReporterCounter: public ConsoleReporter {
    ReporterCounter(const ContextOptions& input_options)
            : ConsoleReporter(input_options) {}

    void test_run_end(const TestRunStats& run_stats) override {
        if (run_stats.numAsserts >= MIN_TESTS) {
            return_code = 0;
        } else {
            std::cout << "Please write at least " << MIN_TESTS << " tests! " <<  std::endl;
            return_code = 1;
        }
    }
    void test1(const TestCaseData& data) override {
       //chack if test is disabled and return error message if it is
       if (data.m_disabled)
       {
              std::cout << "Test is disabled" << std::endl;
              return_code = 1;
       }
       //chack if test is skipped and return error message if it is
         if (data.m_skipped)
         {
                  std::cout << "Test is skipped" << std::endl;
                  return_code = 1;
         }
         //chack if test is failed and return error message if it is
            if (data.m_should_fail)
            {
                    std::cout << "Test is failed" << std::endl;
                    return_code = 1;
            }
        //call the test
        ConsoleReporter::test_run_end(data);
       
        
    }
};



REGISTER_REPORTER("counter", 1, ReporterCounter);

int main(int argc, char** argv) {
    Context context;
    context.addFilter("reporters", "counter");
    context.run();
    return return_code;
}
