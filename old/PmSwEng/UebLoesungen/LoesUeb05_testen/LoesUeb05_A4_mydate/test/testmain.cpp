
#include <cppunit/CompilerOutputter.h>
#include <cppunit/ui/text/TextTestRunner.h>
#include <cppunit/extensions/TestFactoryRegistry.h>

// define compile time symbol BRIEF_RESULTS to get brief results
// as tests proceed
#define BRIEF_RESULTS

#ifdef BRIEF_RESULTS
	#include <cppunit/TestResult.h>
	#include <cppunit/TestResultCollector.h>
	#include <cppunit/BriefTestProgressListener.h>
#endif

int main(int argc, char **argv) {
#ifdef BRIEF_RESULTS
	// Add a listener that print messages as test run:
    CppUnit::TestResult controller;
    CppUnit::BriefTestProgressListener progress;
    controller.addListener( &progress );
#endif
	// Test-Runner erzeugen:
    CppUnit::TextTestRunner runner;

    // TestSuite erzeugen:
    CppUnit::Test *suite = CppUnit::TestFactoryRegistry::getRegistry().makeTest();

    runner.addTest(suite);

    // Outputformatierung festlegen:
    runner.setOutputter(new CppUnit::CompilerOutputter(&runner.result(), std::cerr));

    // Tests durchfuehren und 0 oder im Fehlerfall 1 zurueckmelden:
    bool res;
#ifdef BRIEF_RESULTS
    runner.run(controller);
    res = runner.result().wasSuccessful();
#else
    res = runner.run();
#endif
    return res ? 0 : 1;
}
