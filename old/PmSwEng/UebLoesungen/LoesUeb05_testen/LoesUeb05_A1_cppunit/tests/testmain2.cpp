// File 'tests/testmain2.cpp', 22.3.2012 ple

#include <iostream>
#include <ios>
#include <stdexcept>

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/TextTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/TextOutputter.h>
//#include <cppunit/TextTestRunner.h>


int main( int argc, char* argv[] )
{
#if 0
   //std::ios_base::sync_with_stdio( true );

   std::string testPath = (argc > 1) ? std::string(argv[1]) : "";

   // Create the event manager and test controller
   CppUnit::TestResult controller;

   // Add a listener that colllects test result
   CppUnit::TestResultCollector result;
   controller.addListener( &result );

   // Add a listener that print dots as test run.
   // --- doesn't work!
   CppUnit::TextTestProgressListener progress;
   controller.addListener( &progress );

   // Add the top suite to the test runner
   CppUnit::TestRunner runner;
   runner.addTest( CppUnit::TestFactoryRegistry::getRegistry().makeTest() );
   try
   {
     std::cout << "Running "  <<  testPath;
     runner.run( controller, testPath );

     std::cerr << std::endl;

     // Print test in a compiler compatible format.
     CppUnit::CompilerOutputter outputter( &result, std::cerr );
     outputter.write();
   }
   catch ( std::invalid_argument &e )  // Test path not resolved
   {
     std::cerr  <<  std::endl
                <<  "ERROR: "  <<  e.what()
                << std::endl;
     return 0;
   }

   return result.wasSuccessful() ? 0 : 1;
#else
   namespace CU = CppUnit;

   CU::TestResult controller;

   // Listener zum Sammeln der Testergebnisse bei 'controller' registrieren:
   CU::TestResultCollector collectedResults;
   controller.addListener (&collectedResults);

   // Listener zur Ausgabe der Ergebnisse einzelner Tests bei 'controller'
   // registrieren:
   CU::BriefTestProgressListener progress;
   controller.addListener (&progress);

   // Testssuite erzeugen welche aus registrierten Tests besteht:
   CU::TestFactoryRegistry &registry = CU::TestFactoryRegistry::getRegistry();
   // 'makeTest()' returns a new TestSuite that contains the registered tests.
   CU::Test * tsuite = registry.makeTest();

   // TestRunner-Objekt
   CU::TestRunner runner;
   runner.addTest(tsuite);

   std::cout << "-- \"runner.run()\" :" << std::endl;
   runner.run (controller);

#if 0
   std::cout << "-- from 'CompilerOutputter':" << std::endl;
   CU::CompilerOutputter compOutputter(&collectedResults, std::cout);
   compOutputter.write();
#endif
#if 1
   std::cout << "-- from 'TextOutputter':" << std::endl;
   CU::TextOutputter textOutputter(&collectedResults, std::cout);
   textOutputter.write();
#endif
   return collectedResults.wasSuccessful() ? 0 : 1;
#endif


}
