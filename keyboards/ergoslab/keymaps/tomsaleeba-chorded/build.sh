#!/bin/bash
set -euo pipefail
cd `dirname $0`
thisDir=$PWD

cd ../../../../users/dennytom/chording_engine/

python3 parser.py $thisDir/keymap_def.json $thisDir/keymap.c
