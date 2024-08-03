#!/bin/bash
mkdir myDirectory
cd myDirectory
mkdir secDirectory
cd secDirectory
touch myNotePaper
cp ~/myDirectory/secDirectory/myNotePaper ~/myDirectory/myNotePaper
mv myNotePaper myOldNotePaper
