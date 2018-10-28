#!/bin/bash
echo > output
for varible1 in {1..10000}
do
  ./test >> output
done
