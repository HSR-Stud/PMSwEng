// File 'testmain.cpp', 18.3.210 ple

#include <cppunit/TextTestProgressListener.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>


int main( int argc, char* argv[] )
{
  // Create the event manager and test controller:
  CppUnit::TestResult controller;

  // Add a listener that colllects test result:
  CppUnit::TestResultCollector result;
  controller.addListener( &result );

  // Add a listener that print dots as test run:
//  CppUnit::TextTestProgressListener progress;
  CppUnit::BriefTestProgressListener progress;
  controller.addListener( &progress );

  // Add the top suite in the registry to the test runner
  CppUnit::TestRunner runner;
  runner.addTest( CppUnit::TestFactoryRegistry::getRegistry().makeTest() );
  // Run the tests:
  runner.run( controller );

  // Print test in a compiler compatible format.
  CppUnit::CompilerOutputter outputter( &result, std::cout );
  outputter.write();

  return result.wasSuccessful() ? 0 : 1;
}

