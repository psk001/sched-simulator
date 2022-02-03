#!/bin/bash

g++ dummy.cpp scheduler.cpp process-creator.cpp process.cpp comparator.cpp -o dummy

./dummy
exit 0