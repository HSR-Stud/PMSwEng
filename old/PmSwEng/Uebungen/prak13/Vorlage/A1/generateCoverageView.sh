#!/bin/bash
#generateCoverageView.sh

if [ $# -ne 1 ]
then
  echo "wrong argument list."
  echo "Use" $0 "ExecutableName"
  exit 1
fi

#define coverage output variables
COVFILENAME="coverage.info"
HTMLFOLDER="coverage"
#define output folder
BUILD="build"
TARGET=$1

#remove all coverage relevant files
rm -rf $BUILD

# remove all compile-ouput files and make it again inclusive qmake
qmake -spec linux-g++ CONFIG+=debug TARGET=Test -o $BUILD/Makefile 
cd $BUILD
make clean
make qmake_all
make all -j4
cd ..

# execute the program
echo $B
$BUILD/$TARGET

# capture covarage
lcov --capture --directory $BUILD --output-file $BUILD/$COVFILENAME #--rc lcov_branch_coverage=1
# remove not interesting files
lcov --remove $BUILD/$COVFILENAME "ui_*.h" --output-file $BUILD/$COVFILENAME
lcov --remove $BUILD/$COVFILENAME "moc_*.cpp" --output-file $BUILD/$COVFILENAME
lcov --remove $BUILD/$COVFILENAME "googletest/*" --output-file $BUILD/$COVFILENAME
lcov --remove $BUILD/$COVFILENAME "googlemock/*" --output-file $BUILD/$COVFILENAME
lcov --remove $BUILD/$COVFILENAME "qt/*" --output-file $BUILD/$COVFILENAME
lcov --remove $BUILD/$COVFILENAME "Qt*" --output-file $BUILD/$COVFILENAME
lcov --remove $BUILD/$COVFILENAME "/usr/include/*" --output-file $BUILD/$COVFILENAME
lcov --remove $BUILD/$COVFILENAME "/usr/local/include/*" --output-file $BUILD/$COVFILENAME
lcov --remove $BUILD/$COVFILENAME "VoltageDividerWidgetTest.cpp" --output-file $BUILD/$COVFILENAME
# generate html output from coverage
genhtml --demangle-cpp $BUILD/$COVFILENAME -o $BUILD/$HTMLFOLDER #--rc lcov_branch_coverage=1
# open firefox and open the coverage index.html mainpage
firefox $BUILD/$HTMLFOLDER"/index.html" &

